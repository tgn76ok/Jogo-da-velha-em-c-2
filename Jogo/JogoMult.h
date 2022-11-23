

#include "../Funcoes/Mensagens.h"
#include "..\Funcoes\verficar.h"
#include "../logs/OrdernarORank.h"


#include "../logs/rank.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


int jogomult(){

    char continuar;
    char nome1[20],nome2[20];
    char nomeDoVencedor[25]="";
	int opcao1='x',opcao2='o';
	int contX =0,contO =0;
	int linha1,coluna1;
	int linha2,coluna2;
    int next=0;
	int turno=0;
	int cont=0,numDeVitorias=0;
	int empate=0;


	char lista[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},};
		continuar = 's';
        odernar();

		// inicio do menu para o jogo multiplayer
        printf("/******************************************************|\n");
        printf("/                                                      |\n");
        printf("/                   Jogo da velha                      |\n");
        printf("/                                                      |\n");
        printf("/       Esse modo o jogador 1 ficar como o X           |\n");
        printf("/                   por tanto jogador 2 fica com o O   |\n");
        printf("/******************************************************/\n");
        system("pause");
        system("cls");
        fflush(stdin);
        //entrada para os usuarios digitarem o nome
        printf("\n|-------------------------------|\n");
        printf("|   DIGITE O NOME DO JOGADOR 1: |\n");;
        printf("|-> ");
        gets(nome1);
        fflush(stdin);

        printf("\n|-------------------------------|\n");
        printf("|  DIGITE O NOME DO JOGADOR 2:  |\n");;
        printf("|-> ");
        gets(nome2);
        fflush(stdin);

		while(1){
                    /*correçao do um bug--
                    quando um jogo acaba, o jogador 2 inica com a variavel opcao vazia-- */
                    for(int lin=0; lin<=3;lin++){
                        for(int col=0; col<=3;col++){
                                if (lista[lin][col] == 0){
                                    lista[lin][col] = 'o';
                                }
                        }
                    }
                opcao2='o';
                /*quem ganha e quantas vezes ganharam*/
		        if (verificartabela(lista)=='x'){
                        MensagemWins('x');
                        contX++;
                }else if(verificartabela(lista)=='o'){
                        MensagemWins('o');
                        contO++;


		        }else{

                        //em caso de empate, termina a partida e renicai o jogo
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
                        cont =0;
                    }
                    //Quando termina a partida pergunta aos jogadores se querem continuar.
                    //Nisso tive que criar a variavel next que vai aumentando comforme a quantidade de vitorias
		        if (contX > next || contO >next || empate == 1){

		            printf("\nQuer continuar?[s/n] ");
		            scanf("%s",&continuar);

                    if (empate !=1){
                            next++;
                        }
                    empate = 0;

                    for(int l=0; l<=3;l++){
                        for(int c=0; c<=3;c++){
                            lista[l][c] = ' ';
                        }
                    }

                    int recorde= PegarRecorde();
                    tolower(continuar);
                    //aqui chamo a funçao pegarecorde para poder fazer um limiar, para evitar redundancia na hora de salvar no rank
                    if(continuar == 'n'){
                        if(contX > contO && contX>recorde){
                                strcat(nomeDoVencedor,nome1);
                                numDeVitorias = contX;
                                escreverNoArquivo(nomeDoVencedor,numDeVitorias);
                                RecordeWins();

                        }else if(contX < contO && contO>recorde){
                                strcat(nomeDoVencedor,nome2);
                                numDeVitorias = contO;
                                escreverNoArquivo(nomeDoVencedor,numDeVitorias);
                                RecordeWins();
                        }
                        break;
		            }

		        }

                TelaDoJogoMult(lista,contX,contO,nome1,nome2);
                //entrada do usario
				if ((turno % 2) == 0){

					printf("\tO Jogador 1 sua vez \n\n\n");

					printf("\tQual a linha que voce quer[1-3]? ");
                    printf("\n\t |->");
					while(scanf("%d",&linha1)!=1){
                            system("cls");
                            TelaDoJogoMult(lista,contX,contO,nome1,nome2);
                            printf("\tO VALOR QUE VOCE DIGITOU ESTA FORA DA NOSSA ZONA USUAL\n");
                            printf("\tQual a linha que voce quer[1-3]?\n ");
                            printf("\t |->");
                            scanf("%d",&linha1);
                            fflush(stdin);
                        }



					printf("\tQual coluna voce quer[1-3]? ");
                    printf("\n\t |->");
                    while(scanf("%d",&coluna1)!=1){
                            system("cls");
                            TelaDoJogoMult(lista,contX,contO,nome1,nome2);
                            printf("\tO VALOR QUE VOCE DIGITOU ESTA FORA DA NOSSA ZONA USUAL\n");
                            printf("\tDigite novamente a coluna que voce quer[1-3]?\n ");
                            printf("\t |->");
                            scanf("%d",&coluna1);
                            fflush(stdin);
                        }

					if ((1<=linha1<=3) &&(1<=coluna1<=3)){
						if (lista[linha1-1][coluna1-1] == ' ' ){
							lista[linha1-1][coluna1-1] = opcao1;
							turno++;
						}else {
                            MensagemErrosCasaOcupada();
						}
					}else{
                           MensagemErrosValorMAiorQue3EMenoQue1();
						}
                }else{
                    printf("\tO Jogador 2 sua vez \n\n\n");

					printf("\tQual a linha que voce quer[1-3]? ");
                    printf("\n\t |->");
                    while(scanf("%d",&linha2)!=1){
                            system("cls");
                            TelaDoJogoMult(lista,contX,contO,nome1,nome2);
                            printf("\tO VALOR QUE VOCE DIGITOU ESTA FORA DA NOSSA ZONA USUAL\n");
                            printf("\tDigite novamente a linha que voce quer[1-3]?\n ");
                            printf("\t |->");
                            scanf("%d",&linha2);
                            fflush(stdin);
                        }



					printf("\tQual coluna voce quer[1-3]? ");
                    printf("\n\t|->");
                    while(scanf("%d",&coluna2)!=1){
                            system("cls");
                            TelaDoJogoMult(lista,contX,contO,nome1,nome2);
                            printf("\tO VALOR QUE VOCE DIGITOU ESTA FORA DA NOSSA ZONA USUAL\n");
                            printf("\tDigite novamente a coluna que voce quer[1-3]?\n ");
                            printf("\t |->");
                            scanf("%d",&coluna2);
                            fflush(stdin);
                        }

                    if(((1<=linha2)&&(linha2<=3)) &&((1<=coluna2)&&(coluna2<=3))){

                        if (lista[linha2-1][coluna2-1] == ' '){
                            lista[linha2-1][coluna2-1] = opcao2;
                            turno++;

                        }else{
                            MensagemErrosCasaOcupada();
                        }
                    }else{
                        MensagemErrosValorMAiorQue3EMenoQue1();
                    }
			 }


		}
	}

