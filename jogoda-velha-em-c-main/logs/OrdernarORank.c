#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
    char nome[20];
    int NumDeVitorias;
};

int compararIdade (const void *x, const void *y) {
    int pri = ((struct pessoa *)x)->NumDeVitorias;
    int seg = ((struct pessoa *)y)->NumDeVitorias;
    return (seg - pri);
}



int PrintRank(){
    int NumDeVitorias[]={0,0,0,0,0,0,0,0,0,0};
    char nomes[][20] =  {"empty","empty","empty","empty","empty","empty","empty","empty","empty","empty"};
    struct pessoa item[10];

    FILE *arq_cliente;
    int indice=0;
    char var_arquivo_aux;
    char nom[20];
    char l;
    int vezesDeVitoria;
    int cont=0;
    int num =0;
    arq_cliente = fopen("logs/rank.txt", "r+");
    if (arq_cliente == NULL){
            printf("\nArquivo CLIENTE.TXT nao pode ser aberto.");
            printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
        }else{
            var_arquivo_aux = fscanf(arq_cliente, "%s %c %d",&nom,&l, &vezesDeVitoria);
            while (var_arquivo_aux != EOF){
                strcpy(nomes[cont], nom);
                NumDeVitorias[cont] = vezesDeVitoria;
                cont++;
                indice = indice + 1;
                var_arquivo_aux = fscanf(arq_cliente, "%s %c %d",&nom,&l, &vezesDeVitoria);

        }
        fclose (arq_cliente);

    }


   qsort(item, 10, sizeof(struct pessoa), compararIdade);

   printf("  NOME   || WINS  \n");
   for (int i = 0; i < 10; i++) {
     strcpy(item[i].nome, nomes[i]);
     item[i].NumDeVitorias = NumDeVitorias[i];
     printf("%d-%s  : %d\n",num+=1, item[i].nome, item[i].NumDeVitorias);
   }

}