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


//uso de uma matriz imagem[][] para armazenar a imagem
    //OBS: seguindo o formato já utilizado no código enviado (linha, coluna)
    int imagem[1024][768] = {0};
    int largura = 0; //colunas
    int altura  = 0; //linhas

    //variáveis de controle de modo e arquivo
    int modo_manual = 0;
    const char *arquivo = NULL;

    //interpretação dos parâmetros -m/--manual e -f/--file
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--manual") == 0){
            modo_manual = 1;
        } else if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0){
            //verifica se há o caminho do arquivo após o parâmetro
            if(i + 1 >= argc){
                fprintf(stderr, "Erro: faltou o caminho do arquivo apos %s\n", argv[i]);
                return 2;
            }
            arquivo = argv[++i];
        } else {
            //parâmetro desconhecido
            fprintf(stderr, "Parametro desconhecido: %s\n", argv[i]);
            ajuda();
            return 2;
        }
    }

    //verificações de consistência dos parâmetros
    if(modo_manual && arquivo != NULL){
        fprintf(stderr, "Erro: use -m OU -f, nao ambos ao mesmo tempo.\n");
        return 2;
    }
    if(!modo_manual && arquivo == NULL){
        fprintf(stderr, "Erro: especifique -m (manual) ou -f ARQ (arquivo PBM).\n");
        ajuda();
        return 2;
    }

    //entrada dos dados conforme o modo selecionado
    if(modo_manual){
        //modo manual: pede largura e altura e depois os pixels
        printf("Largura e altura: ");
        if(scanf("%d %d", &largura, &altura) != 2){
            fprintf(stderr, "Falha lendo as dimensoes.\n");
            return 3;
        }

        //valida limites (largura <= 1024; altura <= 768)
        if(largura <= 0 || altura <= 0 || largura > 1024 || altura > 768){
            fprintf(stderr, "Dimensoes invalidas: %dx%d (max 1024x768)\n", largura, altura);
            return 3;
        }

        printf("Informe %d x %d pixels (0=branco, 1=preto):\n", largura, altura);
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                int v;
                if(scanf("%d", &v) != 1 || (v != 0 && v != 1)){
                    fprintf(stderr, "Pixel invalido em (%d,%d). Use 0 ou 1.\n", i, j);
                    return 3;
                }
                //mantendo o formato do codigo enviado: imagem[linha][coluna]
                imagem[i][j] = v;
            }
        }
    } else {
        //modo arquivo: leitura de PBM (P1 ASCII)
        FILE *f = fopen(arquivo, "r");
        if(f == NULL){
            fprintf(stderr, "Nao foi possivel abrir o arquivo '%s'\n", arquivo);
            return 3;
        }

        //leitura do magic number (deve ser P1)
        char token[64];
        //função local simples para pegar próximo token (ignora espaços e linhas de comentário começando com '#')
        //obs: mantendo tudo dentro do main conforme solicitado, sem criar novas funções
        auto int proximo_token(FILE *fp, char buf[], size_t n) {
            int c;
            //pula espacos e comentarios
            for(;;){
                c = fgetc(fp);
                if(c == EOF) return 0;
                if(isspace(c)) continue;
                if(c == '#'){
                    while((c = fgetc(fp)) != EOF && c != '\n');
                    continue;
                }
                //inicio do token
                size_t k = 0;
                buf[k++] = (char)c;
                while(k + 1 < n){
                    c = fgetc(fp);
                    if(c == EOF || isspace(c) || c == '#'){
                        if(c == '#'){
                            while((c = fgetc(fp)) != EOF && c != '\n');
                        }
                        break;
                    }
                    buf[k++] = (char)c;
                }
                buf[k] = '\0';
                return 1;
            }
        };

        if(!proximo_token(f, token, sizeof(token)) || strcmp(token, "P1") != 0){
            fprintf(stderr, "Formato invalido: esperado P1 no inicio do arquivo.\n");
            fclose(f);
            return 3;
        }

        if(!proximo_token(f, token, sizeof(token))){
            fprintf(stderr, "Largura ausente no arquivo PBM.\n");
            fclose(f);
            return 3;
        }
        largura = atoi(token);

        if(!proximo_token(f, token, sizeof(token))){
            fprintf(stderr, "Altura ausente no arquivo PBM.\n");
            fclose(f);
            return 3;
        }
        altura = atoi(token);

        //valida limites (largura <= 1024; altura <= 768)
        if(largura <= 0 || altura <= 0 || largura > 1024 || altura > 768){
            fprintf(stderr, "Dimensoes invalidas no PBM: %dx%d (max 1024x768)\n", largura, altura);
            fclose(f);
            return 3;
        }

        //leitura dos pixels (0=branco(B), 1=preto(P))
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                if(!proximo_token(f, token, sizeof(token))){
                    fprintf(stderr, "Pixels insuficientes no PBM (esperado %d valores).\n", largura * altura);
                    fclose(f);
                    return 3;
                }
                if(!((token[0] == '0' || token[0] == '1') && token[1] == '\0')){
                    fprintf(stderr, "Pixel invalido em (%d,%d): '%s' (use 0 ou 1)\n", i, j, token);
                    fclose(f);
                    return 3;
                }
                imagem[i][j] = (token[0] - '0');
            }
        }

        fclose(f);
    }

    //gera a codificação da imagem conforme as regras (P, B ou X)
    codificador(imagem, 0, 0, altura, largura);
    printf("\n");

    return 0;
}

//uso de uma matriz imagem[][] para armazenar a imagem
    //OBS: seguindo o formato já utilizado no código enviado (linha, coluna)
    int imagem[1024][768] = {0};
    int largura = 0; //colunas
    int altura  = 0; //linhas

    //variáveis de controle de modo e arquivo
    int modo_manual = 0;
    const char *arquivo = NULL;

    //interpretação dos parâmetros -m/--manual e -f/--file
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--manual") == 0){
            modo_manual = 1;
        } else if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0){
            //verifica se há o caminho do arquivo após o parâmetro
            if(i + 1 >= argc){
                fprintf(stderr, "Erro: faltou o caminho do arquivo apos %s\n", argv[i]);
                return 2;
            }
            arquivo = argv[++i];
        } else {
            //parâmetro desconhecido
            fprintf(stderr, "Parametro desconhecido: %s\n", argv[i]);
            ajuda();
            return 2;
        }
    }

    //verificações de consistência dos parâmetros
    if(modo_manual && arquivo != NULL){
        fprintf(stderr, "Erro: use -m OU -f, nao ambos ao mesmo tempo.\n");
        return 2;
    }
    if(!modo_manual && arquivo == NULL){
        fprintf(stderr, "Erro: especifique -m (manual) ou -f ARQ (arquivo PBM).\n");
        ajuda();
        return 2;
    }

    //entrada dos dados conforme o modo selecionado
    if(modo_manual){
        //modo manual: pede largura e altura e depois os pixels
        printf("Largura e altura: ");
        if(scanf("%d %d", &largura, &altura) != 2){
            fprintf(stderr, "Falha lendo as dimensoes.\n");
            return 3;
        }

        //valida limites (largura <= 1024; altura <= 768)
        if(largura <= 0 || altura <= 0 || largura > 1024 || altura > 768){
            fprintf(stderr, "Dimensoes invalidas: %dx%d (max 1024x768)\n", largura, altura);
            return 3;
        }

        printf("Informe %d x %d pixels (0=branco, 1=preto):\n", largura, altura);
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                int v;
                if(scanf("%d", &v) != 1 || (v != 0 && v != 1)){
                    fprintf(stderr, "Pixel invalido em (%d,%d). Use 0 ou 1.\n", i, j);
                    return 3;
                }
                //mantendo o formato do codigo enviado: imagem[linha][coluna]
                imagem[i][j] = v;
            }
        }
    } else {
        //modo arquivo: leitura de PBM (P1 ASCII)
        FILE *f = fopen(arquivo, "r");
        if(f == NULL){
            fprintf(stderr, "Nao foi possivel abrir o arquivo '%s'\n", arquivo);
            return 3;
        }

        //leitura do magic number (deve ser P1)
        char token[64];
        //função local simples para pegar próximo token (ignora espaços e linhas de comentário começando com '#')
        //obs: mantendo tudo dentro do main conforme solicitado, sem criar novas funções
        auto int proximo_token(FILE *fp, char buf[], size_t n) {
            int c;
            //pula espacos e comentarios
            for(;;){
                c = fgetc(fp);
                if(c == EOF) return 0;
                if(isspace(c)) continue;
                if(c == '#'){
                    while((c = fgetc(fp)) != EOF && c != '\n');
                    continue;
                }
                //inicio do token
                size_t k = 0;
                buf[k++] = (char)c;
                while(k + 1 < n){
                    c = fgetc(fp);
                    if(c == EOF || isspace(c) || c == '#'){
                        if(c == '#'){
                            while((c = fgetc(fp)) != EOF && c != '\n');
                        }
                        break;
                    }
                    buf[k++] = (char)c;
                }
                buf[k] = '\0';
                return 1;
            }
        };

        if(!proximo_token(f, token, sizeof(token)) || strcmp(token, "P1") != 0){
            fprintf(stderr, "Formato invalido: esperado P1 no inicio do arquivo.\n");
            fclose(f);
            return 3;
        }

        if(!proximo_token(f, token, sizeof(token))){
            fprintf(stderr, "Largura ausente no arquivo PBM.\n");
            fclose(f);
            return 3;
        }
        largura = atoi(token);

        if(!proximo_token(f, token, sizeof(token))){
            fprintf(stderr, "Altura ausente no arquivo PBM.\n");
            fclose(f);
            return 3;
        }
        altura = atoi(token);

        //valida limites (largura <= 1024; altura <= 768)
        if(largura <= 0 || altura <= 0 || largura > 1024 || altura > 768){
            fprintf(stderr, "Dimensoes invalidas no PBM: %dx%d (max 1024x768)\n", largura, altura);
            fclose(f);
            return 3;
        }

        //leitura dos pixels (0=branco(B), 1=preto(P))
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                if(!proximo_token(f, token, sizeof(token))){
                    fprintf(stderr, "Pixels insuficientes no PBM (esperado %d valores).\n", largura * altura);
                    fclose(f);
                    return 3;
                }
                if(!((token[0] == '0' || token[0] == '1') && token[1] == '\0')){
                    fprintf(stderr, "Pixel invalido em (%d,%d): '%s' (use 0 ou 1)\n", i, j, token);
                    fclose(f);
                    return 3;
                }
                imagem[i][j] = (token[0] - '0');
            }
        }

        fclose(f);
    }

    //gera a codificação da imagem conforme as regras (P, B ou X)
    codificador(imagem, 0, 0, altura, largura);
    printf("\n");

    return 0;
}

