#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void initMatrix(Matrix * M);

int main(){

    int i;
    char operator;

    Matrix * M1 = malloc(sizeof(Matrix));
    Matrix * M2 = malloc(sizeof(Matrix));
    Matrix * M3 = malloc(sizeof(Matrix));
    
    initMatrix(M1);
    initMatrix(M2);

    printf("Choose Operator (enter q for quit)\n");

    scanf("%c", &operator);
    while(operator != 'q'){
        switch(operator){
        case '+': AddMatrix(M1, M2, M3); break;
        case '*': MiltiplyMatrix(M1, M2, M3); break;
        case 'f': FunctionMatrix(M1, M3); break;
        default : break;
    }
        scanf("%c", &operator);
    }
}