
#include "../Funcoes/Mensagens.h"
#include "..\Funcoes\verficar.h"
#include "../logs/OrdernarORank.h"
#include "../logs/rank.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
int jogosolo(){
	char continuar;
	char opcao, opcaopc;
	char nomePlayer[30];
	int contX =0,contO =0;
	int linha1,coluna1;
        int next=0, empate=0;
	int linhapc,colunapc;
	int vezesWins=0;
        int cont=0;
	int turno;

	char lista[3][3] = {
        {' ', ' ',  ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},};
        odernar();
        while(1){

            continuar = 's';

            while(1){

                printf("\t|----------------------|\n");
                printf("\t|   QUAL SEU NOME:     |\n");
                printf("\n\t |-> ");
                scanf("%s",&nomePlayer);

                printf("\t|----------------------|\n");
                printf("\t| Voce que ser X ou O? |");
                printf("\n\n\t |-> ");
                scanf("%s",&opcao);

                tolower(opcao);

                if(opcao != 'x' && opcao !='o'){
                    printf("valor voce digitou eh invalido\n");
                }else{
                    break;
                }
            }

            if(opcao == 'x'){
                opcaopc ='o';
            }else{
                opcaopc ='x';
            }

            while(1){
                /*quem ganha e quantas vezes ganharam*/
                    if (verificartabela(lista)=='x'){
                            MensagemWins('x');
                            contX++;
                    }else if(verificartabela(lista)=='o'){
                            MensagemWins('o');
                            contO++;
                    }else{
                        //empate
                        cont =0;
                        for(int linha=0; linha<3;linha++){
                            for(int coluna =0; coluna<3;coluna++){
                                if (lista[linha][coluna]!=' '){
                                        cont++;
                                }
                                if (cont==9){
                                    for(int linhaR=0; linhaR<3;linhaR++){
                                        for(int colunaR=0; colunaR<3;colunaR++){
                                            lista[linhaR][colunaR] = ' ';
                                        }
                                    }
                                    empate++;
                                }
                            }
                        }

                    }

                    //verificar esse possivel error o  next no caso do perdedor
                    if (contX + contO >next || empate == 1){
                        printf("\nQuer continuar?[s/n] ");
                        scanf("%s",&continuar);

                        for(int l=0; l<=3;l++){
                            for(int c=0; c<=3;c++){
                                lista[l][c] = ' ';
                            }
                        }
                        if (empate !=1){
                            next++;
                        }
                        empate =0;
                        tolower(continuar);
                        if(continuar == 'n'){
                            if(opcao == 'x'){
                                vezesWins = contX;
                            }else{
                                vezesWins = contO;
                            }
                            int record = PegarRecorde();
                            if(vezesWins>record){
                                escreverNoArquivo(nomePlayer,vezesWins);
                                RecordeWins();

                            }
                            break;

                        }
                    }

                    TelaDoJogoSolo(lista,contX,contO,nomePlayer);

                    if (turno%2 ==0){

                        printf("\tQual a linha que voce quer[1-3]?\n ");
                        printf("\t |->");
                        fflush(stdin);

                        while(scanf("%d",&linha1)!=1){
                            system("cls");
                            TelaDoJogoSolo(lista,contX,contO,nomePlayer);

                            printf("\tO VALOR QUE VOCE DIGITOU ESTA FORA DA NOSSA ZONA USUAL\n");
                            printf("\tQual a linha que voce quer[1-3]?\n ");
                            printf("\t |->");
                            scanf("%d",&linha1);
                            fflush(stdin);
                         }


                        printf("\tQual coluna voce quer[1-3]? ");
                        printf("\n\t |->");
                        fflush(stdin);
                        while(scanf("%d",&coluna1)!=1){
                            system("cls");
                            TelaDoJogoSolo(lista,contX,contO,nomePlayer);
                            printf("\tO VALOR QUE VOCE DIGITOU ESTA FORA DA NOSSA ZONA USUAL\n");
                            printf("\tQual a coluna que voce quer[1-3]?\n ");
                            printf("\t |->");
                            scanf("%d",&coluna1);
                            fflush(stdin);
                        }


                        if((1<=linha1<=3) &&(1<=coluna1<=3)){
                            if (lista[linha1-1][coluna1-1] == ' '){
                                lista[linha1-1][coluna1-1] = opcao;
                                turno+=1;
                            }else{
                                MensagemErrosCasaOcupada();
                            }
                        }else{
                            MensagemErrosValorMAiorQue3EMenoQue1();
                        }
                    }else{
                        linhapc =rand() %2;
                        colunapc =rand() %2;
                        while(1){
                            if((1<=linha1<=3) && (1<=coluna1<=3)){
                                if(lista[linhapc][colunapc]== ' '){
                                    lista[linhapc][colunapc] = opcaopc;
                                    turno+=1;
                                    break;
                                }else{
                                    linhapc = rand() %3;
                                    colunapc =rand() %3;
                                }
                            }
                        }
                    }
                }
            if(continuar == 'n'){
                break;
            }
    }
}

