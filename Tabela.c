#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char time_casa[50];
    int gols_casa,gols_visit;
    char time_visit[50];
} Partidas;

typedef struct {
    char nome[50];
    int qtd_partidas,vitoria,empates,
    derrotas, gols_total,gols_casa,gols_sofridos;
} Times;

Partidas *carregarPartidas(Times **times,int *qtd_partidas,Partidas*partidas);

int main() {
    Partidas *partidas=NULL;
    Times *times;
    int opcao=0,qtd_partidas=0;
    partidas = carregarPartidas(&times,&qtd_partidas,partidas);
    printf("%s %d\n",partidas[0].time_casa,partidas[0].gols_casa);
    do {
        printf("\n\n==========MENU==========\n");
        printf("[1] Carrega partidas\n[2] Gerar tabela\n[3] Sair\n");
        printf("Escolha uma das opcoes acima: ");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                printf("Obrigado pela preferencia.\n");
                break;
        }
    } while (opcao != 3);
    return 0;
}

Partidas *carregarPartidas(Times **times,int *qtd_partidas,Partidas*partidas) {
    FILE *arq = fopen("partidas.txt","rt");
    char x[3];
    while (!feof(arq)) {
        partidas = (Partidas*) realloc(partidas,((*qtd_partidas)+1)*sizeof(Partidas));
        fscanf(arq," %49[^0-9] ",partidas[*qtd_partidas].time_casa);
        fscanf(arq,"%d",&partidas[*qtd_partidas].gols_casa);
        fscanf(arq," %3[^\n] ",x);
        fscanf(arq,"%d",&partidas[*qtd_partidas].gols_visit);
        fscanf(arq," %49[^\n] ",partidas[*qtd_partidas].time_visit);
        (*qtd_partidas)++;
    }
    fclose(arq);
    return partidas;
}
