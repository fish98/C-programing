#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

int main(){

    char operator;
    clock_t start, finish;
    double time;

    Matrix * M1 = malloc(sizeof(Matrix));
    Matrix * M2 = malloc(sizeof(Matrix));
    Matrix * M3 = malloc(sizeof(Matrix));
    
    ReadMatrix("./matrix1", M1);
    ReadMatrix("./matrix2", M2);

    printf("Load Matrix Done\n");

    printf("Choose Operator : '+ or * or f'(enter q for quit)\n");

    scanf("%c", &operator);
    while(operator != 'q'){
        switch(operator){

        case '+': start = clock(); 
            AddMatrix(M1, M2, M3);
            finish  = clock();
            printf("Use %f Seconds To Finish Add Operation\n", (double)(finish-start)/1000);
            break;
        
        case '*': start = clock(); 
            MiltiplyMatrix(M1, M2, M3); 
            finish  = clock();
            printf("Use %f Seconds To Finish Multiply Operation\n", (double)(finish-start)/1000);
        break;

        case 'f': start = clock(); 
        FunctionMatrix(M1, M3); 
        finish  = clock();
        printf("Use %f Seconds To Finish MeanWise Operation\n", (double)(finish-start)/1000);
        break;  

        default : break;
    }
        scanf("%c", &operator);
    }
}