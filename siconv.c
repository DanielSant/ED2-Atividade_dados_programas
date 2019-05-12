    //#include <stdio.h> // printf() e outras
//#include <stdlib.h> // Para usar o system("clear || cls");
#include "funcoes.h"

int main(void)
{
    system("clear || cls");
    char ans;
    struct dados_programa vetor_dados[10];

    switch (ans = menu())
    {
        case '1':
            system("clear || cls");
            FILE *file;
            file = fopen("siconv_programa.dat", "r");
            
            if (file == NULL)
                error_msg();
            else {
                printf("Entrei para carregar o arquivo\n");
                carregar_file(file, vetor_dados);
                fclose(file);
            }
            
            break;
        
        default:
            break;
    }

    return 0;
}