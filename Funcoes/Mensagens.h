#ifndef Mensagens
#define Mensagens

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int MensagemWins(char jog){
         system("cls");
    if(jog == 'x'){
        printf("\n\n\t|----------------|\n");
       printf("\t|   O X venceu   |\n");
       printf("\t|----------------|\n\n");
    }else if(jog == 'o'){
         printf("\n\n\t|-------------------------|\n");
        printf("\t| A letra O foi o vencedor|\n");
        printf("\t|-------------------------|\n\n");
    }

}

int MensagemErrosCasaOcupada(void){
     system("cls");


     printf("|------------------------------------------------------|\n");
     printf("|                                                      |\n");
     printf("|             Essa casa ja foi ocupada                 |\n");
     printf("|                                                      |\n");
     printf("|------------------------------------------------------|\n");
                         system("pause");

}
int MensagemErrosValorMAiorQue3EMenoQue1(void){
    system("cls");
    printf("|------------------------------------------------------|\n");
    printf("|                                                      |\n");
    printf("|             O valor digitado e invalido              |\n");
    printf("|     Digite valores menores que 3 e maiores que 1     |\n");
    printf("|                                                      |\n");
    printf("|------------------------------------------------------|\n");
                         system("pause");


}
int TelaDoJogoSolo(char lista[3][3], int contX,int contO,char nome[30] ){

                 system("cls");

printf("    |-----------------------------------------------------|");
printf("\n         O %s ganhou %d | | O PC ganhou %d     \n ",nome,contX,contO);
printf("   |                                                     |");
printf("\n                           %c | %c | %c                       ",lista[0][0],lista[0][1],lista[0][2]);
printf("\n    |                    ------------                     |");
printf("\n                           %c | %c | %c                      ",lista[1][0],lista[1][1],lista[1][2]);
printf("\n    |                    ------------                     |");
printf("\n                           %c | %c | %c                       \n",lista[2][0],lista[2][1],lista[2][2]);
printf("    |-----------------------------------------------------|\n\n\n");

}

int TelaDoJogoMult(char lista[3][3], int contX,int contO,char nome1[30],char nome2[30] ){

                 system("cls");

printf("    |-----------------------------------------------------|");
printf("\n         O %s ganhou %d | | O %s ganhou %d     \n ",nome1,contX,nome2,contO);
printf("   |                                                     |");
printf("\n                           %c | %c | %c                       ",lista[0][0],lista[0][1],lista[0][2]);
printf("\n    |                    ------------                     |");
printf("\n                           %c | %c | %c                      ",lista[1][0],lista[1][1],lista[1][2]);
printf("\n    |                    ------------                     |");
printf("\n                           %c | %c | %c                       \n",lista[2][0],lista[2][1],lista[2][2]);
printf("    |-----------------------------------------------------|\n\n\n");

}
void RecordeWins(){
printf("    |-----------------------------------------------------|\n");
printf("    |                                                     |\n");
printf("    |        PARABENS VOCE QUEBROU O RECORDE DA MAQUINA   |\n");
printf("    |                                                     |\n");
printf("    |-----------------------------------------------------|\n");
                system("pause");





}
#endif
