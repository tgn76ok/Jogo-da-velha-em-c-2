#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Funcoes\JogoSolo.h"
#include "Funcoes\JogoMult.h"
#include "menu\creditos.h"


int main(){
    bool para = true;
    while(para){
        int ops;
         printf("/******************************************************|\n");
         printf("/                                                      |\n");
         printf("/                   Jogo da velha                      |\n");
         printf("/                                                      |\n");
         printf("/******************************************************|\n");
         printf("/(0) - Jogo solo        |\n");
         printf("/(1) - Jogo multiplay   |\n");
         printf("/(2) - Creditos         |\n");
         printf("/(3) - Exit             |\n");
         printf("|-> ");
         scanf("%d",&ops);

         switch(ops){
            case 0 :
                jogosolo();
                break;
            case 1 :
                jogomult();
                break;
            case 2 :
                system("cls");
                creditos();
                system("pause");

                break;
            case 3 :
                para = false;
                break;
            default :
                printf ("Valor invalido!\n");


       }
       system("cls");
    }

}
