#include <stdio.h> //input output
#include <stdbool.h>//boleano
#include <stdlib.h>//sistema


#include "Jogo/JogoSolo.h"
#include "jogo/JogoMult.h"
#include "logs/creditos.h"
#include "logs/OrdernarORank.h"
// Essa parte do projeto esta responsavel em rediricionar o(os) usuarios para o que eles desejam

int main(){
    bool para = true;
    while(para){
        odernar();
        char ops;
         printf("/******************************************************|\n");
         printf("/                                                      |\n");
         printf("/                   Jogo da velha                      |\n");
         printf("/                                                      |\n");
         printf("/******************************************************|\n");
         printf("/(0) - Jogo solo        |\n");
         printf("/(1) - Jogo multiplay   |\n");
         printf("/(2) - Creditos         |\n");
         printf("/(3) - Rank             |\n");
         printf("/(4) - Exit             |\n");
         printf("|-> ");
         scanf("%c",&ops);
         fflush(stdin);

         switch(ops){
            case '0' :
                system("cls");
                jogosolo();
                break;
            case '1' :
                system("cls");
                jogomult();
                break;
            case '2' :
                system("cls");
                creditos();
                system("pause");
                break;
            case '3' :
                system("cls");
                PrintRank();
                system("pause");
                break;
            case '4' :
                para = false;
                break;
            default :
                system("cls");
                printf ("Valor invalido!\n");
                system("pause");

       }
       system("cls");
    }

}
