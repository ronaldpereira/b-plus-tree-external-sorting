#ifndef function_tp1
#define function_tp1
#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados da Árvore B+

typedef unsigned long long int TipoChave;

typedef char *TipoRegistro;

typedef struct TipoPagina
{
    TipoChave Chave;
    TipoRegistro *Registro[30];
} TipoPagina;

// Funcoes do .c

TipoPagina *AlocaPagina(int ordem, int field);

TipoPagina *DesalocaPagina(TipoPagina *Pagina, int ordem, int field);

void BuscaRegistro(FILE *reg, FILE *saida, int ordem, int field, unsigned long long int chave);

#endif
