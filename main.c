#include <stdio.h>
#include <string.h>

char codificador(int imagem[1024][768], int linha_inicio, int coluna_inicio, int altura, int largura){
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

        //chama a função de novo e calcula para os 4 quadrantes em ordem (sup. esq; sup. dir; inf. esq; inf. dir)

    }
}


int main(){
    //uso de uma matriz imagem[][] para armazenar a imagem
    return 0;
}