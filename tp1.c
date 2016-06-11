#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreb+.h"

int main(int argc, char *argv[])
{
    FILE *entrada, *saida, *arv, *reg;
    char *operation, *registro;
    unsigned long long int key;
    int ordem, campos, indice;
    int *raiz;
    int i;
    TipoPagina *pagina;

    arv = fopen("arvore.txt", "w+r");
    reg = fopen("registros.txt", "w+r");
    entrada = fopen(argv[2], "r");
    saida = fopen(argv[1], "w");
    ordem = atoi(argv[3]);
    campos = atoi(argv[4]);
    indice = atoi(argv[5]);

    operation = (char*) malloc(10*sizeof(char));
    registro = (char*) malloc(30*sizeof(char));
    raiz = (int*) calloc(ordem,sizeof(int));
    pagina = AlocaPagina(ordem, campos);

    while(fscanf(entrada, "%s", operation) != EOF)
    {
        if(strcmp(operation, "search") == 0)
        {
            fscanf(reg, "\t%llu", &key);
            // Implementar uma funcao que busca na arvore e juntar o arquivo registro com o arquivo arvore
            BuscaRegistro(reg, saida, ordem, campos, key); // Funcao que busca o registro
        }

        else if(strcmp(operation, "add") == 0)
        {
            for(i = 0; i < campos; i++)
            {
                fscanf(entrada, "%s", registro);
                fprintf(reg, "%s ", registro);

                if(i == indice)
                    key = atoi(registro);
            }
            fprintf(reg, "\n");
            printf("%llu\n", key);
        }

        else if(strcmp(operation, "dump") == 0)
        {
            fprintf(saida, "%s\n", operation);
            // Funcao que imprime
            fprintf(saida, "%s\n\n", operation);
        }
    }

    pagina = DesalocaPagina(pagina, ordem, campos);
    free(operation);
    free(registro);
    free(raiz);
    fclose(arv);
    fclose(reg);
    fclose(entrada);
    fclose(saida);
    remove("registros.txt");
    remove("arvore.txt");

    return 0;
}
