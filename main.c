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

#include "poly.h"

int main() {
    
    int qtd_poly, qtd_ope;
    Poly * P = NULL;
    
    printf("Digite a quantidade de polinômios: ");
    scanf("%d", &qtd_poly);

    P = poly_read( n );

    printf("Digite a quantidade de operações: ");
    scanf("%d", &qtd_ope);

    while ( qtd_ope-- ) {
        
    }

    poly_print_all(P, n);
    

    poly_free(P, n);

    return 0;
}
