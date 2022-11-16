
#include "../Funcoes/Mensagens.h"


#include "../logs/rank.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char verificar(char tabela[3][3]){
        //verificar as linhas
        for(int linhas=0; linhas < 3; linhas++){
            if((tabela[linhas][0] == tabela[linhas][1]) && (tabela[linhas][0] == tabela[linhas][2])){
                return tabela[linhas][0];
            }
        }
        //verificar as colunas

        for(int coluna=0; coluna < 3; coluna++){
            if((tabela[0][coluna] == tabela[1][coluna]) && (tabela[0][coluna] == tabela[2][coluna])){
                return tabela[0][coluna];
            }
        }
        if ((tabela[0][0] == tabela[1][1])&&(tabela[0][0] == tabela[2][2])){
                return tabela[0][0];

        }else if ((tabela[2][0] == tabela[1][1])&& (tabela[2][0] == tabela[0][2])){
                return tabela[2][0];
            }
    return ' ';

}
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
                    if (verificar(lista)=='x'){
                            MensagemWins('x');
                            contX++;
                    }else if(verificar(lista)=='o'){
                            MensagemWins('o');
                            contO++;
                    }else{
                        //empate
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


                    if (contX > next || contO >next || empate == 1){
                        printf("\nQuer continuar?[s/n] ");
                        scanf("%s",&continuar);

                        for(int l=0; l<=3;l++){
                            for(int c=0; c<=3;c++){
                                lista[l][c] = ' ';
                            }
                        }

                        next++;
                        empate =0;
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

