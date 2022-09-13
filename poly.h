/**
 * @file poly.h
 * @author Arthur Trindade da Silva (trinde_silva@discente.ufg.br | arthsilva500@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright GNU GPLv3 (c) 2022
 * 
*/

typedef struct polynomio {
    char id[128+1];
    int p;
    double * coef;
} Poly;

/**
 * @brief Aloca um vetor com n espaços na memoria
 * 
 * @param n numero de elementos
 * @return Poly* o retorna o endereço do vetor;
 */
Poly * poly_new( int n );

/**
 * @brief Ler n numero de polinomios
 * 
 * @param n numero de polinomios
 * @return Poly* retorna um ponteiro do tipo Poly
 */
Poly * poly_read( int n );

/**
 * @brief Libera a memoria alocada do vetor de polinomios e de coeficiente
 * 
 * @param P Vetor de polinomios alocado dinamicamente
 */
void poly_free( Poly * P, int n );

/**
 * @brief Mostra os polinomios no terminal
 * 
 * @param P Vetor de polinomios
 * @param n Numero de polinomios
 */
void poly_print_all( Poly * P, int n );

/**
 * @brief Mostra um polinomio no terminal
 * 
 * @param c vetor de coeficentes do polinomio
 * @param n tamano do vetor de coeficientes
 */
void poly_print( double * c, int n );

/**
 * @brief Converte para inteiro o numero referente ao seu valor numerico
 * 
 * @param ch caracter a ser convertido
 * @return int um numero inteiro
 */
int char_to_int( char ch );

/**
 * @brief Retorna o maior expoente de um polinomio
 * 
 * @param str polinomio que se deseja obter o grau
 * @return int o valor do maior expoente (grau)
 */
int poly_grau(char *str);

/**
 * @brief Função que pega os coeficientes da string poly e 
 *        coloca em um vetor de double nos indice que estão
 *        delimitados no polinomio.
 *  
 * @param poly polinomio 
 * @return double* retorna um vetor com os coeficientes de poly.
 */
double * poly_coefs( char * poly );

/**
 * @brief Função que normaliza um polinomio referente ao caracter '-'
 *        adicionando o caracter '+' e colocando na posição seguinte o caracter '-'
 *        com o objeivo de sempre deixar o '-' perto do numero refente. 
 * 
 * @param poly poliniomio
 * @return char* retorna um ponteiro referente a string normalizada 
 */
char * poly_norm( char * poly );

/**
 * @brief Determina o coeficiente de uma string de polinomio e converte para double
 * 
 * @param str polinomio
 * @return double retorna o valor do coeficiente
 */
double poly_get_coef( char * str );