// HEADERS-----------------
#include <stdio.h>
#include "estrutura.h"
#include <string.h>
#include <stdlib.h>
// ------------------------
// PROTOTYPES--------------
char menu(void);
void carregar_file(FILE *file, struct dados_programa *armazem_dados);
int error_msg(void);
// ------------------------
// DECLARATIONS------------
char menu(void) {
    char opc;
    printf("1 - EXIBIR\n");
    printf("2 - NOVO\n");
    printf("3 - SAIR\n");
    printf("Digite a opcao e tecle enter: ");
    //scanf("%c", &opc);
    return opc=getchar();
}

void carregar_file(FILE *file, struct dados_programa *armazem_dados) {
    
    if (file != NULL) {
        struct dados_programa temp;
        char linha_completa[510];
        char campo_linha[250];
        int number_campo, posicao_caracter_linha;
        int n=0;

        while (fgets(linha_completa, 510, file) != NULL)
        {
            n++;
        }
            printf("%d\n",n);
    } else
        error_msg();
}

int error_msg(void) {
    printf("Not possible open file");
    return 0;
}
// ------------------------