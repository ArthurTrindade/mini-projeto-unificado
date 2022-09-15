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
    
    int qtd_poly, qtd_ope, i, j;
    Poly * P = NULL;
    Poly poly1;
    Poly poly2;
    char id1[128+1];
    char id2[128+1];
    char ope;

    printf("Digite a quantidade de polinômios: ");
    scanf("%d", &qtd_poly);

    P = poly_read( qtd_poly );

    while ( qtd_ope-- ) {
        scanf("%s %c %s", id1, &ope, id2);
        poly1 = get_poly(id1, P, qtd_poly);
        poly2 = get_poly(id2, P, qtd_poly); 
        poly_operations(poly1, ope, poly2);
    }


    poly_free(P, qtd_poly);

    return 0;
}
