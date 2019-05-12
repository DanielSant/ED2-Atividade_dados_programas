// HEADERS-----------------
#include <stdio.h>
#include "estrutura.h"
#include <string.h>
#include <stdlib.h>
// ------------------------
// PROTOTYPES--------------
char menu(void);
void carregar_file(FILE *file, struct dados_programa *armazem_dados);
void error_msg(void);
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

    struct dados_programa temp;
    char linha_completa[465] = "";
    char campo_linha[250] = "";
    int number_campo, posicao_caracter_linha;

    printf("Cheguei aqui\n");
    while (fgets(linha_completa, 465, file) != NULL) {
        number_campo = 1;
        posicao_caracter_linha = 0;
        int tam_string = strlen(linha_completa);
        while (posicao_caracter_linha <= tam_string) {
            strcpy(campo_linha, " ");
            while ((linha_completa[posicao_caracter_linha] < ';') || (linha_completa[posicao_caracter_linha] > ';') && (posicao_caracter_linha <= tam_string)) {
                //printf("%c", linha_completa[posicao_caracter_linha]);
                char aux[2] = "";
                aux[0] = linha_completa[posicao_caracter_linha];
                strcat(campo_linha, aux);
                posicao_caracter_linha++;
            }
            posicao_caracter_linha++;
            printf("%s\n", campo_linha);
            switch (number_campo) {
                case 1:
                    strcpy(temp.cod_orgs, campo_linha);
                     break;
                            
                default:
                    break;
            }
        }
                        
    }
}

void error_msg(void) {
    printf("Not possible open file\n");
}
// ------------------------