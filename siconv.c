    //#include <stdio.h> // printf() e outras
//#include <stdlib.h> // Para usar o system("clear || cls");
#include "funcoes.h"
#include <ctype.h>

int main(void)
{
    system("clear || cls");
    char ans, opc;

    struct dados_programa *vetor_dados = malloc(sizeof(struct dados_programa) * 91000);

    FILE *file;
    file = fopen("siconv_programa.dat", "r");
            
    if (file == NULL)
        error_msg();
    else {
        carregar_file(file, vetor_dados);
        fclose(file);
    }

    do {
        system("clear || cls");
        switch (ans = menu())
        {
            case '1':
                exibir(vetor_dados);
                getchar();
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
    
    return 0;
}