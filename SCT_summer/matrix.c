#include "matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
    printf("The Matrix is\n");
    PrintMatrix(M);
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

    printf("The Matrix is\n");
    PrintMatrix(M);
}

void AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3){
    int i;

    // Judge First

    if (M1->col != M2->col || M1->row != M2 ->row){
        printf("Invalid Input of Matrix\n");
        printf("Choose Operator (enter q for quit)\n");
    } else{

    // Init M3

    M3->col = M1->col;
    M3->row = M1->row;
    M3->data = malloc(sizeof(double) * M3->col * M3->row);

    for(i = 0; i<M3->col * M3->row; i++){
        *(M3->data+i) = *(M1->data+i)+*(M2->data+i);
        }
    printf("Output for Add Operation\n");
    PrintMatrix(M3);
    printf("Choose Operator (enter q for quit)\n");
    }
}

void MiltiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3){
    int i, j, k;

    // Judge First

    if (M1->row != M2->col){
        printf("Invalid Input of Matrix\n");
        printf("Choose Operator (enter q for quit)\n");
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
    printf("Output for Miltiply Operation\n");
    PrintMatrix(M3);
    printf("Choose Operator (enter q for quit)\n"); 
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

    printf("enter the power of the operation element\n");

    scanf("%d", &power);
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
    printf("Output for Miltiply Operation\n");
    PrintMatrix(M3);
    printf("Choose Operator (enter q for quit)\n"); 
}
