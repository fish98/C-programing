#ifndef MATRIX_H_
#define MATRIX_H_  

typedef struct matrix {
    double *data;
    int row;
    int col;
} Matrix;

void initMatrix(Matrix * M);

void AddMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

void PrintMatrix(Matrix * M);

void MiltiplyMatrix(Matrix * M1, Matrix * M2, Matrix * M3);

void FunctionMatrix(Matrix * M1, Matrix * M3);

#endif