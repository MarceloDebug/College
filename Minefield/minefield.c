#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher a matriz do tabuleiro
void preencherTabuleiro(int linhas, int colunas, int **tabuleiro, char **tabuleiroExibicao, int *numBombas){
    int i, j, x, y;

    // Colocar as bombas
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(rand()%9 == 0){
                tabuleiro[i][j] = -1;
                (*numBombas)++; //Salvar a quantidade de bombas
            }
            else{
                tabuleiro[i][j] = 0;
            }
        }
    }

    // Colocar os valores ao redor
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            if(tabuleiro[i][j] == -1){
                for(x = -1; x <= 1; x++){
                    for(y = -1; y <= 1; y++){
                        int linhaX = i + x;
                        int columY = j + y;
                        if(linhaX >= 0 && linhaX < linhas && columY >= 0 && columY < colunas && tabuleiro[linhaX][columY] != -1){
                            tabuleiro[linhaX][columY] += 1;
                        }
                    }
                }
            }
        }
    }

    // Preencher tabuleiro de exibição
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            tabuleiroExibicao[i][j] = '.';
        }
    }
}

//Função para mostrar o tabuleiro final
void mostrarTabuleiroFinal(int linhas, int colunas, int **tabuleiro){
    int i, j;
    printf("    ");
    
    //Indice das colunas
    for(j = 0; j < colunas; j++) {
        printf("%3d", j);
    }
    printf("\n");

    printf("--------------------------------------------------------------------\n");

    for(i = 0; i < linhas; i++){
        printf(" %2d |", i);
        for(j = 0; j < colunas; j++){
            if(tabuleiro[i][j] == -1)
                printf("  *");
            else
                printf("%3d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


//Função para exibir o tabuleiro com os campos escolhidos pelo usuário
void exibirTabuleiro(int linhas, int colunas, char **tabuleiroExibicao){
    int i, j;
    printf("    ");
    for(j = 0; j < colunas; j++) {
        printf("%3d", j);
    }
    printf("\n");

    for(i = 0; i < linhas; i++){
        printf("%2d |", i);
        for(j = 0; j < colunas; j++){
            printf("%3c", tabuleiroExibicao[i][j]);
        }
        printf("\n");
    }
}

//Função para ler coordenadas
void lerCoordenada(int linhas, int colunas, int *x, int *y){
    
    //loop para tratamento de erro
    while(1){
        printf("Número da linha: ");
        scanf("%d", x);
        printf("Número da coluna: ");
        scanf("%d", y);
        
        if(*x>=linhas || *x<0 || *y>=colunas || *y<0){
            printf("Coordenadas invalidas, tente novamente\n\n");
        }
        else{
            break;
        }
    }
}


//Função para revelar campo 
void revelarCampos(int linhas, int colunas, int **tabuleiro, char **tabuleiroExibicao, int x, int y) {
    //Verificando se esta nos limites da matriz
    if(x < 0 || y < 0 || x >= linhas || y >= colunas){
    return;
    }

    
    //Verificando se a "casa" ja foi revelada
    if(tabuleiroExibicao[x][y] !='.'){
        return;
    }
    
    if(tabuleiro[x][y]==0){
        tabuleiroExibicao[x][y]='0';
    }
    else{ //Revelando o número se for diferente de 0
        tabuleiroExibicao[x][y] = tabuleiro[x][y] + '0';
        return;        
    }
    
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
         if (dx != 0 || dy != 0) { // evitando chamar o próprio campo 
             revelarCampos(linhas, colunas, tabuleiro, tabuleiroExibicao, x + dx, y + dy);
        }
    }
}
    
}

int main() {
    int opcao;
    int linhas, colunas;
    int x, y, i, j;
    int bomba = 0;
    int numBombas=0, numBombasAchadas=0;
    
    //Criacao dos ponteiros 
    int **tabuleiro; // Tabuleiro base para implementação das bombas
    char **tabuleiroExibicao; //Tabuleiro que o usuário vai ver

    //Iniciando a função de número aleatório baseado no horário do sistema
    srand(time(0));
                      
    printf("\n");
    printf("░█████╗░░█████╗░███╗░░░███╗██████╗░░█████╗░  ███╗░░░███╗██╗███╗░░██╗░█████╗░██████╗░░█████╗\n");
    printf("██╔══██╗██╔══██╗████╗░████║██╔══██╗██╔══██╗  ████╗░████║██║████╗░██║██╔══██╗██╔══██╗██╔══██╗\n");
    printf("██║░░╚═╝███████║██╔████╔██║██████╔╝██║░░██║  ██╔████╔██║██║██╔██╗██║███████║██║░░██║██║░░██║\n");
    printf("██║░░██╗██╔══██║██║╚██╔╝██║██╔═══╝░██║░░██║  ██║╚██╔╝██║██║██║╚████║██╔══██║██║░░██║██║░░██\n");
    printf("╚█████╔╝██║░░██║██║░╚═╝░██║██║░░░░░╚█████╔╝  ██║░╚═╝░██║██║██║░╚███║██║░░██║██████╔╝╚█████\n\n");
    

    printf("Escolha uma opção:\n");
    printf("1 - Tabuleiro 10x10\n");
    printf("2 - Tabuleiro 20x20\n");
    printf("3 - Tabuleiro 30x30\n");

    scanf("%d", &opcao);

    //Esolha do tamanho do tabuleiro
    switch(opcao){
        case 1:
            linhas = 10;
            colunas = 10;
            break;
        case 2:
            linhas = 20;
            colunas = 20;
            break;
        case 3:
            linhas = 30;
            colunas = 30;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Alocação dinâmica
    //ponteiros passam a apontar para ponteiros
    tabuleiro = (int **)malloc(linhas * sizeof(int *));
    tabuleiroExibicao = (char **)malloc(linhas * sizeof(char *));
    
    //os ponteiros das linhas 
    for(i = 0; i < linhas; i++){
        tabuleiro[i] = (int *)malloc(colunas * sizeof(int));
        tabuleiroExibicao[i] = (char *)malloc(colunas * sizeof(char));
    }

    //Chamando funções para pareencher os dois tabuleiros
    preencherTabuleiro(linhas, colunas, tabuleiro, tabuleiroExibicao, &numBombas);
    exibirTabuleiro(linhas, colunas, tabuleiroExibicao);
    printf("\n");

    //Enquanto não achar bomba, continuar jogando
    do{
        int jogada;
        printf("1 - Colocar Marcação de bomba\n");
        printf("2 - Revelar campo\n");
        scanf("%d", &jogada);
        

        //Opções da jogada seguinte
        switch(jogada){

            case 1:
                printf("Em que campo deseja colocar a marcação?\n");
                lerCoordenada(linhas, colunas, &x, &y);
                
                //Tratamento de erro
                if(x>=linhas || x<0 || y>=colunas || y<0){
                    printf("Coordenadas inválidas");
                    break;
                }
                
                //Colocar marcação de bomba
                if(tabuleiro[x][y] = -1 ){
                    numBombasAchadas++;
                }
    
                //Verificar se todas as bombas ja foram achadas
                if(numBombasAchadas == numBombas){
                    printf("Parabéns, você ganhou!!!");
                    mostrarTabuleiroFinal(linhas, colunas, tabuleiro);
                }
                else{
                    tabuleiroExibicao[x][y] = '#';
                    exibirTabuleiro(linhas, colunas, tabuleiroExibicao);
                    printf("Bombas restantes: %d\n\n ", numBombas - numBombasAchadas);
                }
                
                break;

            case 2:
                printf("Que campo deseja revelar?\n");
                lerCoordenada(linhas, colunas, &x, &y);
                
                //Tratamento de erro
                if(x>=linhas || x<0 || y>=colunas || y<0){
                    printf("Coordenadas inválidas");
                    break;
                }
                
                //Se achar bomba, perdeu
                if(tabuleiro[x][y] == -1){
                    bomba = -1;
                    printf("Você perdeu!!!\n");
                    mostrarTabuleiroFinal(linhas, colunas, tabuleiro);
                } 
                else if(tabuleiro[x][y]==0){ //se é campo vazio, liberar ao redor
                    revelarCampos(linhas, colunas, tabuleiro, tabuleiroExibicao, x, y);
                    exibirTabuleiro(linhas, colunas, tabuleiroExibicao);
                }
                else { //Se for número liberar o número
                    tabuleiroExibicao[x][y] = tabuleiro[x][y] + '0';
                    exibirTabuleiro(linhas, colunas, tabuleiroExibicao);
                }
                printf("Bombas restantes: %d\n\n", numBombas - numBombasAchadas);
                break;
                
            default:
                printf("Digite uma opção válida\n\n");
                break;
        }

    } while(bomba != -1);

    // Liberação da memória
    //Liberação dos ponteiros de linha
    for(i = 0; i < linhas; i++){
        free(tabuleiro[i]);
        free(tabuleiroExibicao[i]);
    }
    //Liberação dos ponteiros de coluna
    free(tabuleiro);
    free(tabuleiroExibicao);

    return 0;
}
