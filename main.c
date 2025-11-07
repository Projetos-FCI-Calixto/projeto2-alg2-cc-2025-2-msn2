#include <stdio.h>
#include <string.h>

void codificador(int imagem[1024][768], int linha_inicio, int coluna_inicio, int altura, int largura){
    //no caso de uma divisão de imagem que fique sem altura inferior ou largura direita, vamos parar a função
    if(altura == 0 || largura == 0){
        return;
    }
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
        //declara as variáveis para novas alturas e alturas;
        int altura_superior, altura_inferior;
        int largura_esquerda, largura_direita;
        
        //Calcula os pontos de divisão (esquerda fica com uma coluna a mais e superior fica com uma linha a mais em caso de ímpar)
        //verifica se o resto da divisão da altura por 2 é diferente de 0
        if (altura % 2 != 0){
            //sendo diferente de 0, então a altura é impar
            //altura superior (ela é igual a altura total dividida por 2 + 1)
            altura_superior = (altura / 2) + 1;
            //altura inferior (ela é igual a altura total dividida por 2)
            altura_inferior = (altura / 2);
        } else {
            //o resto sendo 0, altura total é par
            //altura superior (ela é igual a altura total dividida por 2)
            altura_superior = (altura / 2);
            //altura inferior (ela é igual a altura total dividida por 2)
            altura_inferior = (altura / 2);
        }

        //verifica se o resto da divisão da largura por 2 é diferente de 0
            //sendo diferente de 0, então a altura é impar
        if (largura % 2 != 0){
            //define variavel nova: largura esquerda (ela é igual a largura total dividida por 2 + 1)
            int largura_esquerda = (largura / 2) + 1;
            //define variavel nova: largura direita (ela é igual a largura total dividida por 2)
            int largura_direita = (largura / 2);
        } else {
        //o resto sendo 0, largura total é par
            //define variavel nova: largura esquerda (ela é igual a largura total dividida por 2)
            int largura_esquerda = (largura / 2);
            //define variavel nova: largura direita (ela é igual a largura total dividida por 2)
            int largura_direita = (largura / 2);
        }
        //chama a função de novo e calcula para os 4 quadrantes em ordem (sup. esq; sup. dir; inf. esq; inf. dir)
        //para achar as linhas novas temos que fazer somas da linha inicial com as alturas superior ou inferior e largura direita ou esquerda
        //primeiro quadrante: codificador(linha inicial, coluna inicial, altura superior, largura esquerda)
        codificador(imagem, linha_inicio, coluna_inicio, altura_superior, largura_esquerda);
        //segundo quadrante: codificador(linha inicial, coluna inicial+largura esquerda, altura superior, largura direita)
        codificador(imagem, linha_inicio, coluna_inicio + largura_esquerda, altura_superior, largura_direita);
        //terceiro quadrante: codificador(linha inicial+altura superior, coluna inicial, altura inferior, largura esquerda)
        codificador(imagem, linha_inicio + altura_superior, coluna_inicio, altura_inferior, largura_esquerda);
        //quarto quadrante: codificador(linha inicial+altura superior, coluna inicial+largura esquerda, altura inferior, largura direita)
        codificador(imagem, linha_inicio + altura_superior, coluna_inicio + largura_esquerda, altura_inferior, largura_direita);

    }
}

//função void para menu de ajuda
void ajuda(){
    printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n");
    printf("Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.\n");
    printf("Argumentos:\n");
    printf("-?, --help : apresenta essa orientação na tela.\n");
    printf("-m, --manual: ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem informando-os através do teclado.\n");
    printf("-f, -file: considera a imagem representada no arquivo PBM (Portable bitmap).\n");
    return;
}

int main(int argc, char *argv[]){
    //verifica se a entrada na linha de comando de execução do código é vazia, -? ou --help e chama a função para o menu de ajuda
    if(argc == 1 || strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "--help") == 0){
        ajuda();
    }
    //uso de uma matriz imagem[][] para armazenar a imagem
    return 0;
}