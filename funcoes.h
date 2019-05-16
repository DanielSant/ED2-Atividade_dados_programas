// HEADERS-----------------
#include <stdio.h>
#include "estrutura.h"
#include <string.h>
#include <stdlib.h>
// ------------------------
// PROTOTYPES--------------
char menu(void);
void carregar_file(FILE *file, dados_programa armazem_dados[]);
void exibir(dados_programa dados[]);
void error_msg(void);
void novos_cadastros(dados_programa *temp);
void gravar_alteracoes(FILE *file,dados_programa dados[], dados_programa aux);
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

void carregar_file(FILE *file, dados_programa armazem_dados[]) {
    dados_programa temp;
    char linha_completa[465] = "";
    char campo_linha[250] = "";
    int number_campo, posicao_caracter_linha;
    int numero_registro = 0;

    while ((fgets(linha_completa, 465, file) != NULL)/* && (numero_registro < 1000)*/) {
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

void exibir(dados_programa dados[]) {
    for(int i = 1; i<91000; i++) {
        printf("=--------------------------------------------------------------=\n\n");
        printf("%s: %s\n",dados[0].cod_orgs, dados[i].cod_orgs);
        printf("%s: %s\n",dados[0].desc_orgs, dados[i].desc_orgs);
        printf("%s: %s\n",dados[0].id, dados[i].id);
        printf("%s: %s\n",dados[0].nome, dados[i].nome);
        printf("%s: %s\n",dados[0].situacao, dados[i].situacao);
        printf("%s: %s\n",dados[0].data_disp, dados[i].data_disp);
        printf("%s: %s\n",dados[0].ano_disp, dados[i].ano_disp);
        printf("%s: %s\n",dados[0].dt_ini_receb, dados[i].dt_ini_receb);
        printf("%s: %s\n",dados[0].dt_fim_receb, dados[i].dt_fim_receb);
        printf("%s: %s\n",dados[0].dt_ini_emenda_par, dados[i].dt_ini_emenda_par);
        printf("%s: %s\n",dados[0].dt_fim_emenda_par, dados[i].dt_fim_emenda_par);
        printf("%s: %s\n",dados[0].dt_ini_benef_esp, dados[i].dt_ini_benef_esp);
        printf("%s: %s\n",dados[0].dt_fim_benef_esp, dados[i].dt_fim_benef_esp);
        printf("%s: %s\n",dados[0].modalidade, dados[i].modalidade);
        printf("%s: %s\n",dados[0].natureza_juridica, dados[i].natureza_juridica);
        printf("%s: %s\n",dados[0].UF, dados[i].UF);
        printf("%s: %s\n",dados[0].acao_orcamento, dados[i].acao_orcamento);
    }
    getchar();
}

void novos_cadastros(dados_programa *temp) {
    printf("CODIGO: ");
    scanf("%s",temp->cod_orgs);
    printf("\nDESCRICAO: ");
    scanf("%s",temp->desc_orgs);
    printf("\nID: ");
    scanf("%s",temp->id);
    printf("\nNOME: ");
    scanf("%s",temp->nome);
    printf("\nSITUACAO: ");
    scanf("%s",temp->situacao);
    printf("\nDATA DISPONIVEL: ");
    scanf("%s",temp->data_disp);
    printf("\nANO DISPONIVEL: ");
    scanf("%s",temp->ano_disp);
    printf("\nDATA INICIO RECEBER: ");
    scanf("%s",temp->dt_ini_receb);
    printf("\nDATA FIM RECEBER: ");
    scanf("%s",temp->dt_fim_receb);
    printf("\nDATA INICIO EMENDA: ");
    scanf("%s",temp->dt_ini_emenda_par);
    printf("\nDATA FIM EMENDA: ");
    scanf("%s",temp->dt_fim_emenda_par);
    printf("\nDATA INICIO BENEFICIO ESPECIAL: ");
    scanf("%s",temp->dt_ini_benef_esp);
    printf("\nDATA FIM BENEFICIO ESPECIAL: ");
    scanf("%s",temp->dt_fim_benef_esp);
    printf("\nMODALIDADE: ");
    scanf("%s",temp->modalidade);
    printf("\nNATUREZA JURIDICA: ");
    scanf("%s",temp->natureza_juridica);
    printf("\nUNIDADE FEDERATIVA: ");
    scanf("%s",temp->UF);
    printf("\nACAO ORCAMENTARIA: ");
    scanf("%s",temp->acao_orcamento);
}

void gravar_alteracoes(FILE *file, dados_programa dados[], dados_programa aux) {

    for (int i=0; i<91000; i++) {
        fprintf(file,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",dados[i].cod_orgs,";",
            dados[i].desc_orgs,";",dados[i].id,";",dados[i].nome,";",dados[i].situacao,";",dados[i].data_disp,";",
            dados[i].ano_disp,";",dados[i].dt_ini_receb,";",dados[i].dt_fim_receb,";",dados[i].dt_ini_emenda_par,";",
            dados[i].dt_fim_emenda_par,";",dados[i].dt_ini_benef_esp,";",dados[i].dt_fim_benef_esp,";",dados[i].modalidade,";",
            dados[i].natureza_juridica,";",dados[i].UF,";",dados[i].acao_orcamento);
        /*fprintf(file,"%s%s",dados[i].desc_orgs,";");
        fprintf(file,"%s%s",dados[i].id,";");
        fprintf(file,"%s%s",dados[i].nome,";");
        fprintf(file,"%s%s",dados[i].situacao,";");
        fprintf(file,"%s%s",dados[i].data_disp,";");
        fprintf(file,"%s%s",dados[i].ano_disp,";");
        fprintf(file,"%s%s",dados[i].dt_ini_receb,";");
        fprintf(file,"%s%s",dados[i].dt_fim_receb,";");
        fprintf(file,"%s%s",dados[i].dt_ini_emenda_par,";");
        fprintf(file,"%s%s",dados[i].dt_fim_emenda_par,";");
        fprintf(file,"%s%s",dados[i].dt_ini_benef_esp,";");
        fprintf(file,"%s%s",dados[i].dt_fim_benef_esp,";");
        fprintf(file,"%s%s",dados[i].modalidade,";");
        fprintf(file,"%s%s",dados[i].natureza_juridica,";");
        fprintf(file,"%s%s",dados[i].UF,";");
        fprintf(file,"%s",dados[i].acao_orcamento);*/
    }
    fprintf(file,"%s%s",aux.cod_orgs,";");
    fprintf(file,"%s%s",aux.desc_orgs,";");
    fprintf(file,"%s%s",aux.id,";");
    fprintf(file,"%s%s",aux.nome,";");
    fprintf(file,"%s%s",aux.situacao,";");
    fprintf(file,"%s%s",aux.data_disp,";");
    fprintf(file,"%s%s",aux.ano_disp,";");
    fprintf(file,"%s%s",aux.dt_ini_receb,";");
    fprintf(file,"%s%s",aux.dt_fim_receb,";");
    fprintf(file,"%s%s",aux.dt_ini_emenda_par,";");
    fprintf(file,"%s%s",aux.dt_fim_emenda_par,";");
    fprintf(file,"%s%s",aux.dt_ini_benef_esp,";");
    fprintf(file,"%s%s",aux.dt_fim_benef_esp,";");
    fprintf(file,"%s%s",aux.modalidade,";");
    fprintf(file,"%s%s",aux.natureza_juridica,";");
    fprintf(file,"%s%s",aux.UF,";");
    fprintf(file,"%s%s",aux.acao_orcamento,"\n");
}
// ------------------------