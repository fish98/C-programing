#ifndef MATRIX_H_
#define MATRIX_H_  

#define MAX_T 8

typedef struct matrix {
    double *data;
    int row;
    int col;
} Matrix;

void initMatrix(Matrix * M);

void ReadMatrix(char* Filename, Matrix * M);

void OMP_AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

void PrintMatrix(Matrix * M);

void OMP_MiltiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

void OMP_FunctionMatrix(Matrix * M1, Matrix * M3);

#endif