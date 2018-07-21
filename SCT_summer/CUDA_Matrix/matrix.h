#ifndef MATRIX_H_
#define MATRIX_H_  

#define N 6

typedef struct matrix {
    double *data;
    int row;
    int col;
} Matrix;

__global__ void Test(double * data);

__global__ void AddMatrix(double * data1, double * data2, double * data3, int row, int col);

__global__ void FunctionMatrix(double * data1, double * data3, int row, int col);

__host__ void CUDA_AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

__host__ void CUDA_FunctionMatrix(Matrix * M1, Matrix * M3);

void PrintMatrix(Matrix * M);

void ReadMatrix(const char* Filename, Matrix * M);

__global__ void MultiplyMatrix(double * data1, double * data2, double * data3, int row1, int col1, int row2, int col2);

__host__ void CUDA_MultiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

#endif