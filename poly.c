/**
 * @file poly.c
 * @author Arthur Trindade da Silva (trinde_silva@discente.ufg.br | arthsilva500@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright GNU GPLv3 (c) 2022
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "poly.h"

Poly * poly_new( int n ) {
    return (Poly *) malloc( n * sizeof( Poly ) );
}

void poly_free( Poly * P, int n ) {
    int i;
    for ( i = 0; i < n; i++ ) {
        free(P[i].coef);
    }
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

    return maior + 1;
}

double poly_get_coef( char * str ) {
    int i;
    char c[128+1];
    double coef;

    i = 0;
    while ( str[i] != 'x' ) {
        c[i] = str[i];
        i++;
    }

    coef = atof( c );
    
    return coef;
}

char * poly_norm( char * poly ) {
    char * copy = NULL;
    int i, j, m = 0;

    // Conta os caracteres '-'
    for ( i = 0; i < strlen( poly ); i++ ) {
        if ( poly[i] == '-' ) 
        m++;
    }   

    m += strlen( poly );

    // aloca uma string para receber o poly normalizado
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
    int grau = poly_grau( poly );
    double coef;
    double *coefs = NULL;

    coefs = (double *) malloc( grau * sizeof( double ) );

    for ( i = 0; i < grau; i++) {
        coefs[i] = 0.0;
    }

    poly = poly_norm( poly );

    char* token = strtok(poly, "+");

    int tam, indice;
    while (token != NULL) {
        tam = strlen(token);
        coef = poly_get_coef(token);
        indice = char_to_int(token[tam - 1]);
        coefs[indice] = coef;
        token = strtok(NULL, "+");
    }

    free(poly);
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
        P[i].coef = poly_coefs( poly );
    }

    return P;
}

void poly_print( double * c, int n ) {
    int i;
    for ( i = 0; i < n; i++) {
        if ( c[i] != 0.0 ) {
            printf("%+.2lfx^%d", c[i], i);
        }
    }
    printf("\n");
}

void poly_print_all( Poly * P, int n ) {
    int i, j;
    for ( i = 0; i < n; i++ ) {
        printf("%s: ", P[i].id);
        for ( j = 0; j < P[i].p; j++ ) {
            if ( P[i].coef[j] != 0.0 ) {
                printf("%+.2lfx^%d", P[i].coef[j], j); 
            }
        }  
    }

    printf("\n");
}
