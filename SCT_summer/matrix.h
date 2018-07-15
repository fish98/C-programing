#ifndef MATRIX_H_
#define MATRIX_H_  

typedef struct matrix {
    double *data;
    int line;
    int width;
} Matrix;

void initMatrix(Matrix * M);

// void getMatrix(Matrix1, Matrix2);

// void addMatrix(Matrix1, Matrix2, Matrix3);

// void plusMatrix(Matrix1, Matrix2, Matrix3);

#endif