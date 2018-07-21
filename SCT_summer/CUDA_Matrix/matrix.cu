#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

__global__ void AddMatrix(double * data1, double * data2, double * data3, int row, int col){
    int ix = blockIdx.x*4 + threadIdx.x, iy = blockIdx.y*4 + threadIdx.y;
    if (ix < N && iy < N)
        *(data3+row*ix+iy) =  *(data2+row*ix+iy) + *(data2+row*ix+iy);
}

__global__ void FunctionMatrix(double * data1, double * data3, int row, int col){
    int ix = blockIdx.x*4 + threadIdx.x, iy = blockIdx.y*4 + threadIdx.y;
    if (ix < N && iy < N)
        *(data3+row*ix+iy) =  pow(*(data1+row*ix+iy), 2);
}

__host__ void CUDA_AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3){

    dim3 blocks(N/4+1,N/4+1);
    dim3 threads(4,4);

    int area = M1->col * M2->row;
        
    int area1 = M1->col * M1->row;
    int area2 = M2->col * M2->row;

    M3->col = M1->col;
    M3->row = M2->row;

    M3->data = (double *)malloc(sizeof(double) * area);

    double * GPU_data1;
    double * GPU_data2;
    double * GPU_data3;

    int row = M1->row;
    int col = M1->col;

    cudaMalloc((void**)&GPU_data1, sizeof(double) * area1);
    cudaMalloc((void**)&GPU_data2, sizeof(double) * area2);
    cudaMalloc((void**)&GPU_data3, sizeof(double) * area);
    
    cudaMemcpy(GPU_data1, M1->data, sizeof(double) * area1, cudaMemcpyHostToDevice);
    cudaMemcpy(GPU_data2, M2->data, sizeof(double) * area2, cudaMemcpyHostToDevice);

    AddMatrix<<<blocks, threads>>>(GPU_data1, GPU_data2, GPU_data3, row, col);

    cudaMemcpy(M3->data, GPU_data3, sizeof(double) * area, cudaMemcpyDeviceToHost);
    
    cudaDeviceReset();
    
    printf("The result of Add Operation is: \n");

    PrintMatrix(M3);
    
    free(M3->data);
}

__global__ void MultiplyMatrix(double * data1, double * data2, double * data3, int row1, int col1, int row2, int col2){
    int ix = blockIdx.x*4 + threadIdx.x, iy = blockIdx.y*4 + threadIdx.y;
    if (ix < N && iy < N){
        int i, j, k;
        for(i = 0; i< col1; i++){
            for(j = 0; j< row2;j++){
                int result = 0;
                for(k = 0; k < row1; k++){
                    result += *(data1+i*row1+k) * *(data2+k*row2+j);
                }
                *(data3+i*row2+j) = result;
            }
        }
    }
}

__host__ void CUDA_MultiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3){
    
    dim3 blocks(N/4+1,N/4+1);
    dim3 threads(4,4);

    int area = M1->col * M2->row;
        
    int area1 = M1->col * M1->row;
    int area2 = M2->col * M2->row;

    M3->col = M1->col;
    M3->row = M2->row;

    M3->data = (double *)malloc(sizeof(double) * area);

    double * GPU_data1;
    double * GPU_data2;
    double * GPU_data3;

    int row1 = M1->row;
    int col1 = M1->col;

    int row2 = M2->row;
    int col2 = M2->col;

    cudaMalloc((void**)&GPU_data1, sizeof(double) * area1);
    cudaMalloc((void**)&GPU_data2, sizeof(double) * area2);
    cudaMalloc((void**)&GPU_data3, sizeof(double) * area);
    
    cudaMemcpy(GPU_data1, M1->data, sizeof(double) * area1, cudaMemcpyHostToDevice);
    cudaMemcpy(GPU_data2, M2->data, sizeof(double) * area2, cudaMemcpyHostToDevice);

    MultiplyMatrix<<<blocks, threads>>>(GPU_data1, GPU_data2, GPU_data3, row1, col1, row2, col2);

    cudaMemcpy(M3->data, GPU_data3, sizeof(double) * area, cudaMemcpyDeviceToHost);
    
    cudaDeviceReset();
    
    printf("The result of Multiply Operation is: \n");

    PrintMatrix(M3);
    
    free(M3->data);
}

__host__ void CUDA_FunctionMatrix(Matrix * M1, Matrix * M3){

    dim3 blocks(N/4+1,N/4+1);
    dim3 threads(4,4);

    int area = M1->col * M1->row;

    M3->col = M1->col;
    M3->row = M1->row;

    M3->data = (double *)malloc(sizeof(double) * area);

    double * GPU_data1;
    double * GPU_data3;

    int row = M1->row;
    int col = M1->col;

    cudaMalloc((void**)&GPU_data1, sizeof(double) * area);
    cudaMalloc((void**)&GPU_data3, sizeof(double) * area);
    
    cudaMemcpy(GPU_data1, M1->data, sizeof(double) * area, cudaMemcpyHostToDevice);

    FunctionMatrix<<<blocks, threads>>>(GPU_data1, GPU_data3, row, col);

    cudaMemcpy(M3->data, GPU_data3, sizeof(double) * area, cudaMemcpyDeviceToHost);
    
    cudaDeviceReset();
    
    printf("The result of Function Operation is: \n");

    PrintMatrix(M3);

    free(M3->data);
}

void PrintMatrix(Matrix * M){
    int i, j;
    for (i = 0; i < M ->col; i++){
        for (j = 0; j < M->row; j++){
            printf("%lf ", *(M->data+i*M->row + j));
        }
        printf("\n");
    }
}
void ReadMatrix(const char * Filename, Matrix * M){

    FILE * fp;

    int area, prefix = 0;

    fp = fopen(Filename, "r");

    fscanf(fp, "%d", &M->row);
    fscanf(fp, "%d", &M->col);

    area = M->col * M->row;

    M->data = (double *)malloc(sizeof(double) * area);

    while(fscanf(fp, "%lf", M->data+prefix++)!= EOF);
}

void TransposeMatrix(double * data, int row, int col){

    int area = col * row;
    int i, j;

    double * TmpData = (double*)malloc(sizeof(double) * area);

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            *(TmpData+col*i+j) = *(data+row*j+i);
        }
    }

   for(i=0;i<row;i++){
       for(j=0;j<col;j++){
           *(data+col*i+j) = *(TmpData+col*i+j);
       }
   }
    free(TmpData);
}
