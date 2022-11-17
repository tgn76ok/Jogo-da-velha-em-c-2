#ifndef verificar
#define verificar

char verificartabela(char tabela[3][3]){
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
#endif
