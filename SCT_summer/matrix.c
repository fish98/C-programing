#include "matrix.h"

void initMatrix(Matrix * M){

    int i;

    printf("Line\n");
    scanf("%d", &M->line);

    printf("Width\n");
    scanf("%d", &M->width);

    M->data = malloc(sizeof(double) * (&M->line * &M->width));
    for(i = 0; i< (&M->line * &M->width); i++){
        scanf("%lf", M->data + i);
    }
}