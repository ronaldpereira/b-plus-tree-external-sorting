#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreb+.h"

TipoPagina *AlocaPagina(int ordem, int field)
{
    TipoPagina *Pagina;

    Pagina = (TipoPagina*) malloc(ordem*sizeof(TipoPagina));
    Pagina->Registro[30] = (TipoRegistro*) malloc((field-1)*sizeof(TipoRegistro));

    return (Pagina);
}

TipoPagina *DesalocaPagina(TipoPagina *Pagina, int ordem, int field)
{
    free(Pagina->Registro[30]);
    free(Pagina);

    return (NULL);
}

void BuscaRegistro(FILE *reg, FILE *saida, int ordem, int field, unsigned long long int chave)
{
    char str[30*field];
    unsigned long long int indice;

    fseek(reg, 0, SEEK_SET);

    while(!feof(reg))
    {
        fscanf(reg, "%llu %[^\n]s", &indice, str);

        if(chave == indice)
        {
            fprintf(saida, "search\n%llu %s\nsearch\n", chave, str);
            fseek(reg, 0, SEEK_END);
            return;
        }
    }
    fprintf(saida, "search\nnull\nsearch\n");
}

// void InsereArvore(/* arguments */)
// {
//     /* code */
//
//     return 0;
// }
