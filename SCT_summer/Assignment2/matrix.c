#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#include "matrix.h"

void PrintMatrix(Matrix * M){
    int i, j;
    for (i = 0; i < M ->col; i++){
        for (j = 0; j < M->row; j++){
            printf("%lf ", *(M->data+i*M->row + j));
        }
        printf("\n");
    }
}

void initMatrix(Matrix * M){
    int i, row, col, area;

    printf("Row\n");
    scanf("%d", &M->row);
    row = M->row;

    printf("Col\n");
    scanf("%d", &M->col);
    col = M->col;   

    area = col * row;

    M->data = malloc(sizeof(double) * area);

    for(i = 0; i< area; i++){
        scanf("%lf", M->data + i);
    }
}

void ReadMatrix(char * Filename, Matrix * M){

    int i;

    FILE * fp;

    int area, prefix = 0;

    fp = fopen(Filename, "r");

    fscanf(fp, "%d", &M->row);
    fscanf(fp, "%d", &M->col);

    area = M->col * M->row;

    M->data = malloc(sizeof(double) * area);

    while(fscanf(fp, "%lf", M->data+prefix++)!= EOF);
}

void MPIAddMatrix(Matrix * M1, Matrix * M2, Matrix * M3,int world_rank, int world_size){

    int Tmpsize = M1->col * M1->row / world_size; 

    Matrix * Tmp_M1 = malloc(sizeof(Matrix));
    Matrix * Tmp_M2 = malloc(sizeof(Matrix));
    Matrix * Tmp_M3 = malloc(sizeof(Matrix));

    if(world_rank == 0){
        M3->col = M1->col;
        M3->row = M1->row;
        M3->data = malloc(sizeof(double) * M3->col * M3->row);
    }
    Tmp_M1->row = M1->row;
    Tmp_M1->col = M1 ->col / world_size;
    Tmp_M1->data = malloc(sizeof(double) * Tmpsize);
    Tmp_M2->row = M2->row;
    Tmp_M2->col = M2 ->col / world_size;
    Tmp_M2->data = malloc(sizeof(double) * Tmpsize);

    MPI_Scatter(M1->data, Tmpsize, MPI_DOUBLE, Tmp_M1->data,
        Tmpsize, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(M2->data+Tmpsize*world_rank, Tmpsize, MPI_DOUBLE, Tmp_M2->data,
         Tmpsize, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    
    AddMatrix(Tmp_M1, Tmp_M2, Tmp_M3);

    MPI_Gather(Tmp_M3->data, Tmpsize, MPI_DOUBLE, M3->data, Tmpsize, MPI_DOUBLE, 0,
            MPI_COMM_WORLD);
}

void MPIMultiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3,int world_rank, int world_size){

    int Tmpsize = M1->col * M1->row / world_size;

    Matrix * Tmp_M1 = malloc(sizeof(Matrix));
    Matrix * Tmp_M2 = malloc(sizeof(Matrix));
    Matrix * Tmp_M3 = malloc(sizeof(Matrix));

    if(world_rank == 0){
        M3->col = M1->col;
        M3->row = M2->row;
        M3->data = malloc(sizeof(double) * M3->col * M3->row);
    }

    Tmp_M1->row = M1->row;
    Tmp_M1->col = M1 ->col / world_size;
    Tmp_M1->data = malloc(sizeof(double) * Tmpsize);

    TransposeMatrix(M2);

    Tmp_M2->row = M2->row;
    Tmp_M2->col = M2 ->col / world_size;
    Tmp_M2->data = malloc(sizeof(double) * Tmpsize);

    MPI_Scatter(M1->data, Tmpsize, MPI_DOUBLE, Tmp_M1->data,
        Tmpsize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Scatter(M2->data+Tmpsize*world_rank, Tmpsize, MPI_DOUBLE, Tmp_M2->data,
         Tmpsize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    TransposeMatrix(Tmp_M2);
    
    MultiplyMatrix(Tmp_M1, Tmp_M2, Tmp_M3);

    MPI_Gather(Tmp_M3->data, Tmpsize, MPI_DOUBLE, M3->data, Tmpsize, MPI_DOUBLE, 0,
            MPI_COMM_WORLD);
    
    TransposeMatrix(M2);
}

void MPIFunctionMatrix(Matrix * M1, Matrix * M3, int world_rank, int world_size){

    int Tmpsize = M1->col * M1->row / world_size; 

    Matrix * Tmp_M1 = malloc(sizeof(Matrix));
    Matrix * Tmp_M3 = malloc(sizeof(Matrix));

    if(world_rank == 0){
        M3->col = M1->col;
        M3->row = M1->row;
        M3->data = malloc(sizeof(double) * M3->col * M3->row);
    }
    Tmp_M1->row = M1->row;
    Tmp_M1->col = M1 ->col / world_size;
    Tmp_M1->data = malloc(sizeof(double) * Tmpsize);

    MPI_Scatter(M1->data, Tmpsize, MPI_DOUBLE, Tmp_M1->data,
        Tmpsize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    FunctionMatrix(Tmp_M1, Tmp_M3);

    MPI_Gather(Tmp_M3->data, Tmpsize, MPI_DOUBLE, M3->data, Tmpsize, MPI_DOUBLE, 0,
            MPI_COMM_WORLD);
}

void AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3){
    int i;

    // Judge First

    if (M1->col != M2->col || M1->row != M2 ->row){
        printf("Invalid Input of Matrix\n");
        printf("Choose Operator '+ or * or f' (enter q for quit)\n");
    } else{

    // Init M3

    M3->col = M1->col;
    M3->row = M1->row;
    M3->data = malloc(sizeof(double) * M3->col * M3->row);

    for(i = 0; i<M3->col * M3->row; i++){
        *(M3->data+i) = *(M1->data+i)+*(M2->data+i);
        }
    }
}

void MultiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3){
    int i, j, k;

    // Judge First

    if (M1->row != M2->col){
        printf("Inasrgaegargargawrgwrgawrgwrgawgx\n");
    } else
    {
    // Init M3

    M3->col = M1->col;
    M3->row = M2->row;
    M3->data = malloc(sizeof(double) * M3->col * M3->row);
    }
    for(i = 0; i< M3->col; i++){
        for(j = 0; j< M3-> row;j++){
            int result = 0;
            for(k = 0; k < M1->row; k++){
               result += *(M1->data+i*M1->row+k) * *(M2->data+k*M2->row+j);
            }
            *(M3->data+i*M3->row+j) = result;
        }
    }
}

void FunctionMatrix(Matrix * M1, Matrix * M3){

    // Init M3

    int i, power;
    M3->col = M1->col;
    M3->row = M1->row;
    M3->data = malloc(sizeof(double) * M3->col * M3->row);
    for(i = 0; i < M3->col * M3->row; i++){
            *(M3->data+i) = *(M1->data+i);
        }
    
    power = 2;

    if(power > 0){
        for(i = 0; i < M3->col * M3->row; i++){
            *(M3->data+i) = pow(*(M3->data+i), power);
        }
    }
    else if(power == 0){
         for(i = 0; i < M3->col * M3->row; i++){
            *(M3->data+i) = 1;
        }
    }
    else {
        power = -power;
        for(i = 0; i < M3->col * M3->row; i++){
            *(M3->data+i) = 1 / pow(*(M3->data+i), power);
        }
    }
}

void TransposeMatrix(Matrix * M){

    Matrix * TmpMatrix = malloc(sizeof(Matrix));

    int area = M->col * M->row;
    int i, j;

    TmpMatrix->data = malloc(sizeof(double) * area);

    TmpMatrix->row = M->col;
    TmpMatrix->col = M->row;

    for(i=0;i<TmpMatrix->col;i++){
        for(j=0;j<TmpMatrix->row;j++){
            *(TmpMatrix->data+TmpMatrix->row*i+j) = *(M->data+M->row*j+i);
        }
    }
   
   M->row = TmpMatrix->row;
   M->col = TmpMatrix->col;

   for(i=0;i<M->col;i++){
       for(j=0;j<M->row;j++){
           *(M->data+M->row*i+j) = *(TmpMatrix->data+TmpMatrix->row*i+j);
       }
   }
    free(TmpMatrix);
}