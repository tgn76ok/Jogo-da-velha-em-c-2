#ifndef Mensagens
#define Mensagens

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int MensagemWins(char jog){
    if(jog == 'x'){
        printf("\n/****************|\n");
        printf("/   O X venceu   |\n");
        printf("/****************|\n");
    }else if(jog == 'o'){
        printf("\n/*************************|\n");
        printf("/ A letra O foi o vencedor|\n");
        printf("/*************************|\n");
    }

}

int MensagemErrosCasaOcupada(void){
     system("cls");


     printf("/******************************************************|\n");
     printf("/                                                      |\n");
     printf("/             Essa casa ja foi ocupada                 |\n");
     printf("/                                                      |\n");
     printf("/******************************************************/\n");
                         system("pause");

}
int MensagemErrosValorMAiorQue3EMenoQue1(void){
    system("cls");
    printf("/******************************************************|\n");
    printf("/                                                      |\n");
    printf("/             O valor digitado e invalido              |\n");
    printf("/     Digite valores menores que 3 e maiores que 1     |\n");
    printf("/                                                      |\n");
    printf("/******************************************************/\n");
                         system("pause");


}
int TelaDoJogo(char lista[3][3], int contX,int contO ){

                 system("cls");

printf("    |-----------------------------------------------------|");
printf("\n    |    O Jogador X ganhou %d ||| O jogador O ganhou %d    |\n ",contX,contO);
printf("   |                                                     |");
printf("\n    |                      %c | %c | %c                      |",lista[0][0],lista[0][1],lista[0][2]);
printf("\n    |                    ------------                     |");
printf("\n    |                      %c | %c | %c                      |",lista[1][0],lista[1][1],lista[1][2]);
printf("\n    |                    ------------                     |");
printf("\n    |                      %c | %c | %c                      |\n",lista[2][0],lista[2][1],lista[2][2]);
printf("    |-----------------------------------------------------|\n\n\n");

}
#endif
