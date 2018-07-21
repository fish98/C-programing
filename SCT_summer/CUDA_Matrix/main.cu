#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include "matrix.h"

int main(int argc, char **argv){

    clock_t start, finish;

    Matrix * M1 = (Matrix *)malloc(sizeof(Matrix));
    Matrix * M2 = (Matrix *)malloc(sizeof(Matrix));
    Matrix * M3 = (Matrix *)malloc(sizeof(Matrix));
    
    ReadMatrix("./matrix1", M1);
    ReadMatrix("./matrix2", M2);

    printf("Load Matrix Done\n\n");
    start = clock(); 
    CUDA_AddMatrix(M1, M2, M3);
    finish  = clock();
    printf("Use %lf Seconds To Finish Add Operation \n\n", (double)(finish-start)/1000000);

    start = clock(); 
    CUDA_MultiplyMatrix(M1, M2, M3);
    finish  = clock();
    printf("Use %lf Seconds To Finish Multiply Operation \n\n", (double)(finish-start)/1000000);

    start = clock(); 
    CUDA_FunctionMatrix(M1, M3);
    finish  = clock();
    printf("Use %lf Seconds To Finish MenberWise Operation \n\n", (double)(finish-start)/1000000);

}
