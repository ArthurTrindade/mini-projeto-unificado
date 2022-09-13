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

double fun1( char * str ) {
    int i, t = 0;
    char c[128+1];
    double coef;

    i = 0;
    while ( str[i] != 'x' ) {
        c[t] = str[i];
        t++;
        i++;
    }

    coef = atof( c );
    
    return coef;
}

char * norm_poly( char * poly ) {
    char * copy = NULL;
    int i, j, m = 0;

    for ( i = 0; i < strlen( poly ); i++ ) {
        if ( poly[i] == '-' ) 
        m++;
    }   

    m += strlen( poly );
    copy = (char *) malloc( m * sizeof(char) );

    i = 0;
    j = 0;

    while ( i < strlen( poly ) ) {
        if ( poly[i] == '-' ) {
            copy[j] = '+';
            copy[j + 1] = '-';
            i++;
            j += 2;
        } else {
            copy[j] = poly[i];
            i++;
            j++;
        }
    }
    
    return copy;
}

double * poly_coefs( char * poly ) {
    int i;
    int grau = poly_grau( poly ) + 1;
    double coef;
    double *coefs = NULL;

    coefs = (double *) malloc( grau * sizeof( double ) );

    for ( i = 0; i < grau; i++) {
        coefs[i] = 0.0;
    }

    poly = norm_poly( poly );

    char* token = strtok(poly, "+");

    int tam, g;
    while (token != NULL) {
        tam = strlen(token);
        coef = fun1(token);
        g = char_to_int(token[tam - 1]);
        coefs[g] = coef;
        token = strtok(NULL, "+");
    }

    return coefs;
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
        P[i]->coef = poly_coefs( poly );
    }

    return P;
}

void poly_print( Poly * P, int n ) {
    int i, j;
    for ( i = 0; i < n; i++) {
        printf("%s: ", P[i].id);

        for ( j = 0; j < P[j].p; j++ ) {
            if ( P[j].coef != 0 ) {
                printf("%+.2lfx^%d", P[i].coef[j], j);
                if ( j == P[j].p - 1) printf("\n"); 
            }
        }

    }
}