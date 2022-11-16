#ifndef metodosDeRank
#define metodosDeRank

#include <stdio.h>
#include <string.h>
//Essa biblioteca tem a funçao de Manipulando aqruivos
int escreverNoArquivo(char nome[30],int NumDeVitorias){
    char tudo[90]="",nums[10];
    //cria a string para salvar no arquivo rank.txt

    FILE *file;

    file = fopen("logs/rank.txt","a");
    sprintf(nums, "%d", NumDeVitorias);

    strcat(tudo, "\n");
    strcat(tudo, nome);
    strcat(tudo, " | ");
    strcat(tudo, nums);

    fprintf(file,tudo);

    fclose(file);

}
int PegarRecorde(){
   //cria pego os nome e as vezes que esse nome foram usados
    FILE *arq_cliente;
    char var_arquivo_aux;
    char nom[20];
    char l;
    int vezesDeVitoria;
    int num =0;
    arq_cliente = fopen("logs/rank.txt", "r+");
    if (arq_cliente == NULL){
            printf("\nArquivo CLIENTE.TXT nao pode ser aberto.");
            printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
        }else{
            var_arquivo_aux = fscanf(arq_cliente, "%s %c %d",&nom,&l, &vezesDeVitoria);
        }
    return vezesDeVitoria;
}

#endif // metodosDeRank
