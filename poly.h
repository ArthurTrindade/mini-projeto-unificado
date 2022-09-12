typedef struct polynomio {
    char id[128+1];
    int p;
    //double * coef;
} Poly;

/**
 * @brief Aloca um vetor com n espaços na memoria
 * 
 * @param n numero de elementos
 * @return Poly* o retorna o endereço do vetor;
 */
Poly * poly_new( int n );

Poly * poly_read( int n );

void poly_free( Poly * P );

void poly_print( Poly * P, int n );

int char_to_int( char ch );

/**
 * @brief Retorna o maior expoente de um polinomio
 * 
 * @param str polinomio que se deseja obter o grau
 * @return int o valor do maior expoente (grau)
 */
int poly_grau(char *str);