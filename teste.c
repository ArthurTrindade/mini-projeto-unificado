#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "poly.h"

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

int main() {

    char *s;
    scanf("%s", s);

    int grau = poly_grau( s ) + 1;

    double *coefs = NULL;
    coefs = poly_coefs( s );

    //s = norm_poly( s );


    /* 
        int grau = poly_grau(s) + 1;
    double coefs[grau];
    double coef;

    for ( int i = 0; i < grau; i++) {
        coefs[i] = 0.0;
    }

    char* token = strtok(s, "+");
  
    int tam, g;
    while (token != NULL) {
        tam = strlen(token);
        fun1(token, &coef);
        g = char_to_int(token[tam - 1]);
        coefs[g] = coef;
        token = strtok(NULL, "+");
    }

    */
    
    for (int i = 0; i < grau; i++) {
        printf("%lf\n", coefs[i]);
    }
  
    for (int i = 0; i < grau; i++) {
        if (coefs[i] != 0) {
            printf("%+.2lfx^%d", coefs[i], i);
            if ( i == grau - 1) printf("\n"); 
        }
    }

    free(coefs);
    
    return 0;
}
