#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "poly.h"

Poly * poly_new( int n ) {
    return (Poly *) malloc( n * sizeof( Poly ) );
}

void poly_free( Poly * P ) {
    free(P);
}

int char_to_int( char ch ) {
    return ch - '0';
}

int poly_grau(char *str) {
    int maior = 0, num;
    for (int i = 0; i < strlen(str); i++) {
        if ( str[i] == '^') {
            num = char_to_int(str[i + 1]);
            if (num > maior) maior = num;
        }   
    }

    return maior;
}

Poly * poly_read( int n ) {
    int i;
    char id[128+1], poly[128+1];
    Poly * P = NULL;

    P = poly_new( n );

    printf("\nDigite os polinônimos, ex: 'id: ax^2+bx^1+cx^0'\n");
    
    for ( i = 0; i < n; i++ ) {
        scanf("%[^:]%*c %s", P[i].id, poly);
        P[i].p = poly_grau( poly );
    }

    return P;
}

void poly_print( Poly * P, int n ) {
    int i;
    for ( i = 0; i < n; i++) {
        printf("%s: %d", P[i].id, P[i].p);
    }
    printf("\n");
}