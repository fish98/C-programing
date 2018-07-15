#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "matrix.c"

void initMatrix(Matrix * M);

int main(){

    int i, j, z;

    int area1, area2, area3;

    Matrix * M1 = malloc(sizeof(Matrix));
    
    initMatrix(M1);

   // printf("%d", M1->width);

    // for (i = 0; i < 2; i++){
    //     for (j = 0; j < 2; j++){
    //         scanf("%lf", a->data[i][j]);
    //     }
    // }

}


    // Matrix M1 = (Matrix)malloc(sizeof(struct matrix));
    // Matrix M2 = (Matrix)malloc(sizeof(struct matrix));
    // Matrix M3 = (Matrix)malloc(sizeof(struct matrix));

    // M1->data = (double**)malloc(4 * sizeof(double));
    // M2->data = (double**)malloc(4 * sizeof(double));
    // M3->data = (double**)malloc(4 * sizeof(double));

    // printf("M1 line\n");
    // scanf("%d\n", M1->line);
    // printf("M1 width\n");
    // scanf("%d\n", M1->width);
    
    // for(i = 0; i<M1;i++){
    //     M1->data[i] = (double*)malloc(2 * sizeof(double));
    // }
       
    //     a->data[0][0] = 1.0;
        
//    printf("Line : %d\n", M1->line);