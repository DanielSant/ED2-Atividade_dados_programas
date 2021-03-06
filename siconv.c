//#include <stdio.h> // printf() e outras
//#include <stdlib.h> // Para usar o system("clear || cls");
#include "funcoes.h"
#include <ctype.h>

int main(void)
{
    system("clear || cls");
    char ans, opc;

    dados_programa *vetor_dados = malloc(sizeof(dados_programa) * 91000);
    dados_programa aux;

    FILE *file;
    FILE *file1;
    file = fopen("siconv_programa.dat", "r");
            
    if (file == NULL)
        error_msg();
    else {
        carregar_file(file, vetor_dados);
    }

    do {
        system("clear || cls");
        switch (ans = menu())
        {
            case '1':
                exibir(vetor_dados);
                getchar();
                break;

            case '2':
                file1 = fopen("siconv_programa.dat", "w");
                novos_cadastros(&aux);
                gravar_alteracoes(file1, vetor_dados, aux);
                fclose(file1);
                break;

            case '3':
                exit(0);
                break;
            
            default:
                break;
        }
        system("clear || cls");
        printf("Again? (s/n): ");
        opc=toupper(getchar());
        scanf("%c");
    } while (opc == 'S');
    fclose(file);
    
    return 0;
}