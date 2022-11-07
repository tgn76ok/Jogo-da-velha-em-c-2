#ifndef metodosDeRank
#define metodosDeRank

#include <stdio.h>
#include <string.h>

int escreverNoArquivo(char nome[30],int NumDeVitorias){
    char tudo[90]="",nums[10];


    FILE *file;

    file = fopen("logs/rank.txt","a");

    sprintf(nums, "%d", NumDeVitorias);

    strcat(tudo, "\n");
    strcat(tudo, nome);
    strcat(tudo, "|");
    strcat(tudo, nums);

    fprintf(file,tudo);

    fclose(file);

}
#endif // metodosDeRank
