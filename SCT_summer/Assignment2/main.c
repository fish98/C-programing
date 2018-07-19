#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#include "matrix.h"

int main(int argc, char** argv){

    // char operator;
    clock_t start, finish;
    double time;

    int world_rank; 
    int world_size;

    Matrix * M1 = malloc(sizeof(Matrix));
    Matrix * M2 = malloc(sizeof(Matrix));
    Matrix * M3 = malloc(sizeof(Matrix));
    
    ReadMatrix("./matrix1", M1);
    ReadMatrix("./matrix2", M2);

    MPI_Init(NULL, NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);


    // printf("")
    // printf("Choose Operator : '+ or * or f'(enter q for quit)\n");

    // scanf("%c", &operator);
    // while(operator != 'q'){
    //     switch(operator){

    //     case '+': 
            //start = clock(); 
            MPIAddMatrix(M1, M2, M3, world_rank, world_size);
            //finish  = clock();
            if(world_rank == 0){
                printf("The result of the add operation is:\n");
                PrintMatrix(M3);
            }

            MPI_Barrier(MPI_COMM_WORLD);

            MPIMultiplyMatrix(M1, M2, M3, world_rank, world_size);

            if(world_rank == 0){
                printf("The result of the multiply operation is:\n");
                PrintMatrix(M3);
            }

            MPI_Barrier(MPI_COMM_WORLD);

            MPIFunctionMatrix(M1, M3, world_rank, world_size);

            if(world_rank == 0){
                printf("The result of the power operation is:\n");
                PrintMatrix(M3);
            }

            //printf("Use %f Seconds To Finish Add Operation\n", (double)(finish-start)/1000);
            // break;
        
        // case '*': start = clock(); 
        //     MiltiplyMatrix(M1, M2, M3); 
        //     finish  = clock();
        //     printf("Use %f Seconds To Finish Multiply Operation\n", (double)(finish-start)/1000);
        // break;

        // case 'f': start = clock(); 
        // FunctionMatrix(M1, M3); 
        // finish  = clock();
        // printf("Use %f Seconds To Finish MeanWise Operation\n", (double)(finish-start)/1000);
        // break;  

    //     default : break;
    // }
    //     scanf("%c", &operator);
    //     }
    
    MPI_Finalize();
}