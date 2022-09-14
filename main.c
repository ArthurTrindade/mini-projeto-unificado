/**
 * @file main.c
 * @author Arthur Trindade da Silva (trinde_silva@discente.ufg.br | arthsilva500@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright GNU GPLv3 (c) 2022
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poly.h"

int main() {
    
    int qtd_poly, qtd_ope;
    Poly * P = NULL;
    Poly poly1;
    Poly poly2;
    char id1[128+1];
    char id2[128+1];
    char ope;

    printf("Digite a quantidade de polinômios: ");
    scanf("%d", &qtd_poly);

    P = poly_read( qtd_poly );
 
    printf("Digite a quantidade de operações: ");
    scanf("%d", &qtd_ope);
    
    while ( qtd_ope-- ) {
        scanf("%s%c%s", id1, &ope, id2);
        poly1 = operacoes(id1, P, qtd_poly);
        poly2 = operacoes(id2, P, qtd_poly);
    }
   
    poly_print(poly1.coef, poly1.p);
    poly_print(poly2.coef, poly2.p);

    poly_print_all(P, qtd_poly);
    
    poly_free(P, qtd_poly);

    return 0;
}

/* 

scanf("%s", id1);
    for ( int i = 0; i < qtd_poly; i++ ) {
        if ( strcmp(id1, P[i].id) ) {
            poly1 = P[i];
        }
    }

    poly_print(poly1.coef, poly1.p);
*/