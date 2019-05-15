// HEADERS-----------------
#include <stdio.h>
#include "estrutura.h"
#include <string.h>
#include <stdlib.h>
// ------------------------
// PROTOTYPES--------------
char menu(void);
void carregar_file(FILE *file, struct dados_programa armazem_dados[]);
void exibir(struct dados_programa dados[]);
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

void carregar_file(FILE *file, struct dados_programa armazem_dados[]) {
    struct dados_programa temp;
    char linha_completa[465] = "";
    char campo_linha[250] = "";
    int number_campo, posicao_caracter_linha;
    int numero_registro = 0;

    while ((fgets(linha_completa, 465, file) != NULL) && (numero_registro < 1000)) {
        number_campo = 1;
        posicao_caracter_linha = 0;
        int tam_string = strlen(linha_completa);
        while (posicao_caracter_linha <= tam_string) {
            strcpy(campo_linha, "");
            while ((linha_completa[posicao_caracter_linha] < ';') || (linha_completa[posicao_caracter_linha] > ';') && (posicao_caracter_linha <= tam_string)) {
                char aux[2] = "";
                aux[0] = linha_completa[posicao_caracter_linha];
                strcat(campo_linha, aux);
                posicao_caracter_linha++;
            }
            posicao_caracter_linha++;
           
            switch (number_campo) {
                case 1:
                    strcpy(temp.cod_orgs, campo_linha);
                    //printf("%s - ",temp.cod_orgs);
                    break;
                
                case 2:
                    strcpy(temp.desc_orgs, campo_linha);
                    //printf("%s\n", temp.desc_orgs);
                    break;
                
                case 3:
                    strcpy(temp.id, campo_linha);
                    break;

                case 4:
                    strcpy(temp.nome, campo_linha);
                    break;
                
                case 5:
                    strcpy(temp.situacao, campo_linha);
                    break;

                case 6:
                    strcpy(temp.data_disp, campo_linha);
                    break;

                case 7:
                    strcpy(temp.ano_disp, campo_linha);
                    break;

                case 8:
                    strcpy(temp.dt_ini_receb, campo_linha);
                    break;

                case 9:
                    strcpy(temp.dt_fim_receb, campo_linha);
                    break;

                case 10:
                    strcpy(temp.dt_ini_emenda_par, campo_linha);
                    break;

                case 11:
                    strcpy(temp.dt_fim_emenda_par, campo_linha);
                    break;

                case 12:
                    strcpy(temp.dt_ini_benef_esp, campo_linha);
                    break;

                case 13:
                    strcpy(temp.dt_fim_benef_esp, campo_linha);
                    break;

                case 14:
                    strcpy(temp.modalidade, campo_linha);
                    break;

                case 15:
                    strcpy(temp.natureza_juridica, campo_linha);
                    break;

                case 16:
                    strcpy(temp.UF, campo_linha);
                    break;

                case 17:
                    strcpy(temp.acao_orcamento, campo_linha);
                    break;
            }
            number_campo++;
        }
        armazem_dados[numero_registro] = temp;
        numero_registro++;
    }
}

void error_msg(void) {
    printf("Not possible open file\n");
}

void exibir(struct dados_programa dados[]) {
    for(int i = 1; i<1000; i++) {
        printf("%s %50s\n",dados[0].cod_orgs, dados[i].cod_orgs);
        printf("%s %50s\n",dados[0].desc_orgs, dados[i].desc_orgs);
        printf("%s %50s\n",dados[0].id, dados[i].id);
        printf("%s %50s\n",dados[0].nome, dados[i].nome);
        printf("%s %50s\n",dados[0].situacao, dados[i].situacao);
        printf("%s %50s\n",dados[0].data_disp, dados[i].data_disp);
        printf("%s %50s\n",dados[0].ano_disp, dados[i].ano_disp);
        printf("%s %50s\n",dados[0].dt_ini_receb, dados[i].dt_ini_receb);
        printf("%s %50s\n",dados[0].dt_fim_receb, dados[i].cod_orgs);
    }
    scanf("%c");
}
// ------------------------