#ifndef MATRIX_H_
#define MATRIX_H_  

typedef struct matrix {
    double *data;
    int row;
    int col;
} Matrix;

void initMatrix(Matrix * M);

void TransposeMatrix(Matrix * M);

void ReadMatrix(char* Filename, Matrix * M);

void AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

void MPIAddMatrix(Matrix * M1, Matrix * M2, Matrix * M3,int world_rank, int world_size);

void MPIMultiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3, int world_rank, int world_size);

void MPIFunctionMatrix(Matrix * M1, Matrix * M3, int world_rank, int world_size);

void PrintMatrix(Matrix * M);

void MultiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

void FunctionMatrix(Matrix * M1, Matrix * M3);

#endif