#include <stdio.h>
#include <stdlib.h>

#include "poly.h"

int main() {

    int n;
    Poly * P = NULL;
    
    printf("Digite a quantidade de polinômios: ");
    scanf("%d", &n);

    P = poly_read( n );

    poly_print(P, n);

    poly_free(P);

    return 0;
}
