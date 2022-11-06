#include "Mensagens.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int jogomult(){
    char continuar;
	char opcao, opcaopc;
	int opcao1='x',opcao2='o';
	int contX =0,contO =0;
	int linha1,coluna1;
	int linha2,coluna2;
    int next=0;
	int linhapc,colunapc;
	int opc;
	int turno;
	int cont=0;
	int empate=0;
	char lista[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},};
		continuar = 's';
		 printf("/******************************************************|\n");
	     printf("/       Grupo:Luan Victor; Murilo Henrique;            |\n");
	     printf("/               Thiago Germano; Gabriel Figueiredo     |\n");
	     printf("/                                                      |\n");
	     printf("/                   Jogo da velha                      |\n");
		 printf("/                                                      |\n");
	     printf("/                                                      |\n");
	     printf("/       Esse modo o jogador1 ficar como o X            |\n");
	     printf("/                   por tanto jogador2 fica com o O    |\n");
	     printf("/******************************************************/\n");
                 system("pause");


		while(1){
                    /*correçao do um bug--
                    quando um jogo acaba, o jogador 2 inica com a variavel opcao vazia-- */
                    for(int g=0; g<=3;g++){
                        for(int d=0; d<=3;d++){
                                if (lista[g][d] == 0){
                                    lista[g][d] = 'o';
                                }
                        }
                    }
                opcao2='o';
			/*quem ganha e quantas vezes ganharam*/
		        if ((lista[0][0] == lista[0][1])&& (lista[0][0]== lista[0][2])&& (lista[0][0]== 'x')){
						contX +=1;
						MensagemWins('x');

				}else if ((lista[0][0] == lista[0][1])&& (lista[0][0]== lista[0][2])&& (lista[0][0]== 'o')){
						MensagemWins('o');
		                contO +=1;

		        }else if ((lista[1][0] == lista[1][1]) && (lista[1][0]== lista[1][2]) && (lista[1][0] == 'x')){
						MensagemWins('x');
			            contX +=1;

		        }else if ((lista[1][0] == lista[1][1]) && (lista[1][0]== lista[1][2]) && (lista[1][0] == 'o')){
						MensagemWins('o');
		                contO++;

		        }else if ((lista[2][0] == lista[2][1]) && (lista[2][0] == lista[2][2]) && (lista[2][0]== 'x')){
						MensagemWins('x');
			            contX +=1;
		        }else if((lista[2][0] == lista[2][1]) && (lista[2][0] == lista[2][2]) && (lista[2][0] == 'o')){
						MensagemWins('o');
		                contO +=1;

		    	}else if ((lista[0][0] == lista[1][0])&&(lista[0][0] == lista[2][0])&&(lista[0][0] == 'x')){
						MensagemWins('x');
		                contX +=1;
		        }else if ((lista[0][0] == lista[1][0])&&(lista[0][0] == lista[2][0])&&(lista[0][0] == 'o')){
						MensagemWins('o');
		                contO +=1;
		        }else if ((lista[0][1] == lista[1][1])&&(lista[0][1] == lista[2][1]) && (lista[0][1] == 'x')){
						MensagemWins('x');

		                contX +=1;
		        }else if ((lista[0][1] == lista[1][1])&&(lista[0][1] == lista[2][1]) && (lista[0][1] == 'o')){
						MensagemWins('o');
		                contO +=1;

		        }else if ((lista[0][2] == lista[1][2])&&(lista[0][2] == lista[2][2])&& (lista[0][2] == 'x')){
						MensagemWins('x');
			            contX +=1;
				}else if ((lista[0][2] == lista[1][2])&&(lista[0][2] == lista[2][2])&& (lista[0][2] == 'o')){
						MensagemWins('o');
		                contO +=1;
		        }else if ((lista[0][0] == lista[1][1])&&(lista[0][0] == lista[2][2]) && (lista[0][0] == 'x')){
						MensagemWins('x');
		                contX +=1;
		        }else if ((lista[0][0] == lista[1][1])&&(lista[0][0] == lista[2][2]) && (lista[0][0] == 'o')){
						MensagemWins('o');
		                contO +=1;
		        }else if ((lista[2][0] == lista[1][1])&& (lista[2][0] == lista[0][2])&&(lista[2][0] == 'x')){
						MensagemWins('x');
		                contX +=1;
		        }else if ((lista[2][0] == lista[1][1])&& (lista[2][0] == lista[0][2])&&(lista[2][0] == 'o')){
						MensagemWins('o');
		                contO +=1;
		        }else{
                        //empate
                        for(int linha=0; linha<=3;linha++){
                            for(int coluna =0; coluna<=3;coluna++){
                                if (lista[linha][coluna]!=' '){
                                        cont++;
                                }else if (cont==9){
                                    for(int linhaR=0; linhaR<=3;linhaR++){
                                        for(int colunaR=0; colunaR<=3;colunaR++){
                                            lista[linhaR][colunaR] = ' ';
                                        }
                                    }
                                    empate++;
                                }
                            }
                        }
                        cont =0;
                    }
		        if (contX > next || contO >next){
		            printf("\nQuer continuar?[s/n] ");
		            scanf("%s",&continuar);

		            int l,c;

                    for(l=0; l<=3;l++){
                        for(c=0; c<=3;c++){
                            lista[l][c] = ' ';
                        }
                    }



                    if(continuar == 'n'){
		                break;
		            }
		            next++;
		        }

                TelaDoJogo(lista,contX,contO);

				if ((turno % 2) == 0){
					printf("O Jogador 1 sua vez \n\n\n");

					printf("Qual a linha que voce quer[1-3]? ");
                    printf("\n |->");
					scanf("%d",&linha1);

					printf("Qual coluna voce quer[1-3]? ");
                    printf("\n |->");
					scanf("%d",&coluna1);

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

			 	printf("O Jogador 2 sua vez \n\n\n");

					printf("Qual a linha que voce quer[1-3]? ");
                    printf("\n |->");
					scanf("%d",&linha2);

					printf("Qual coluna voce quer[1-3]? ");
                    printf("\n |->");
					scanf("%d",&coluna2);


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

