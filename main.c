#include <stdio.h>
#include <string.h>

void codificador(int imagem[1024][768], int linha_inicio, int coluna_inicio, int altura, int largura){
    //define uma variável para armazenar a cor do primeiro pixel da imagem e usá-lo como padrão na verificação
    int cor_base = imagem[linha_inicio][coluna_inicio];

    //define uma variavel para sabermos se é uniforme ou não
    int uniformidade = 1;
    
    //Criar um loop com dois for para percorrer toda a matriz
    for(int i = linha_inicio; i < linha_inicio+altura; i++){
        for(int j = coluna_inicio; j < coluna_inicio+largura; j++){

            //Leitura de cada pixel comparando com o pixel de cor base
            if(imagem[i][j] != cor_base){
                //sendo diferente da cor base, muda o indice de uniformidade e sai do loop interno
                uniformidade = 0;
                break;
            }
        }
        //verifica se no loop interno teve mudança do indice de uniformidade
        if(uniformidade == 0){
            //se teve, ele sai do loop externo para cair na verificação de caso base ou recursividade
            break;
        }

    }
    //Depois da verificação de uniformidade geral verificamos os tipos 
    if(uniformidade == 1){
        //verifica se é P
        if(cor_base == 1){
            //retorna o P
            printf("P");
        }else{ //não sendo P
            //retorna o B
            printf("B");
        }
    }else{ //se não é uniforme
        //retorna X
        printf("X");
        
        //Calcula os pontos de divisão (esquerda fica com uma coluna a mais e superior fica com uma linha a mais em caso de ímpar)
        //verifica se o resto da divisão da altura por 2 é diferente de 0
        if (altura % 2 != 0){
            //sendo diferente de 0, então a altura é impar
            //define variavel nova: altura superior (ela é igual a altura total dividida por 2 + 1)
            int altura_superior = (altura / 2) + 1
            //define variavel nova: altura inferior (ela é igual a altura total dividida por 2)
            int altura_inferior = (altura / 2)
        } else {
            //o resto sendo 0, altura total é par
            //define variavel nova: altura superior (ela é igual a altura total dividida por 2)
            int altura_superior = (altura / 2)
            //define variavel nova: altura inferior (ela é igual a altura total dividida por 2)
            int altura_inferior = (altura / 2)
        }

        

        //verifica se o resto da divisão da largura por 2 é diferente de 0
            //sendo diferente de 0, então a altura é impar
        if (largura % 2 != 0){
            //define variavel nova: largura esquerda (ela é igual a largura total dividida por 2 + 1)
            int largura_esquerda = (largura / 2) + 1
            //define variavel nova: largura direita (ela é igual a largura total dividida por 2)
            int largura_direita = (largura / 2)
        } else {
        //o resto sendo 0, largura total é par
            //define variavel nova: largura esquerda (ela é igual a largura total dividida por 2)
            int largura_esquerda = (largura / 2)
            //define variavel nova: largura direita (ela é igual a largura total dividida por 2)
            int largura_direita = (largura / 2)
        }
        //chama a função de novo e calcula para os 4 quadrantes em ordem (sup. esq; sup. dir; inf. esq; inf. dir)
        //para achar as linhas novas temos que fazer somas 
        //primeiro quadrante: codificador()
    }
}


int main(){
    //uso de uma matriz imagem[][] para armazenar a imagem
    return 0;
}