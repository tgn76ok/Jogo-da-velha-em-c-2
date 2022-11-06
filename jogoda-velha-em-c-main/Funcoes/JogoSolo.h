#include "Mensagens.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int jogosolo(){
	char continuar;
	char opcao, opcaopc;
	int opcao1,opcao2;
	int contX =0,contO =0;
	int linha1,coluna1;
	int linha2,coluna2;
    int next=0;
    int empate=0;
	int linhapc,colunapc;
	int opc;
    int cont=0;

	int turno;
	char lista[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},};

        while(1){

            continuar = 's';

            while(1){
                printf("voce que ser X ou O?");
                scanf("%s",&opcao);
                if(opcao != 'x' && opcao !='o'){
                    printf("valor voce digitou uma letra que nao aceitamos");
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

                        next++;
                        if(continuar == 'n'){
                            break;
                        }
                    }

                    TelaDoJogo(lista,contX,contO);


                    if (turno%2 ==0){

                        printf("\tQual a linha que voce quer[1-3]?\n ");
                        printf("\t |->");
                        scanf("%d",&linha1);

                        printf("\tQual coluna voce quer[1-3]? ");
                        printf("\n\t |->");
                        scanf("%d",&coluna1);



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
                                    linhapc =rand() %3;
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

