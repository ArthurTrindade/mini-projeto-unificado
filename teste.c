#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void fun1( char * str, double * coef ) {
    int i, t = 0;
    char c[128+1];

    i = 0;
    while ( str[i] != 'x' ) {
        c[t] = str[i];
        t++;
        i++;
    }

    *coef = atof(c);
}

int main() {

    char str[] = "1x^2+3x^9-2x^0";
    char s[128+1];

    int i = 0;
    int j = 0;
    while ( i < strlen(str) ) {
        if (str[i] == '-') {
            s[j] = '+';
            s[j + 1] = '-';
            i++;
            j += 2;
        } else {
            s[j] = str[i];
            i++;
            j++;
        }
    }

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

    for (int i = 0; i < grau; i++) {
        printf("%lf\n", coefs[i]);
    }
  

    for (int i = 0; i < grau; i++) {
        if (coefs[i] != 0) {
            printf("%+.2lfx^%d", coefs[i], i);
            if ( i == grau - 1) printf("\n"); 
        }

    }
    return 0;
}
