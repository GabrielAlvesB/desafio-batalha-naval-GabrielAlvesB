#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se a posição do navio é válida
int posicaoValida(int linha, int coluna, int tamanho, int orientacao, int tabuleiro[TAMANHO][TAMANHO], int diagonal) {
    if (diagonal == 0) { // Horizontal ou Vertical
        if (orientacao == 0) { // Horizontal
            if (coluna + tamanho > TAMANHO) return 0;
            for (int i = 0; i < tamanho; i++) {
                if (tabuleiro[linha][coluna + i] != 0) return 0;
            }
        } else { // Vertical
            if (linha + tamanho > TAMANHO) return 0;
            for (int i = 0; i < tamanho; i++) {
                if (tabuleiro[linha + i][coluna] != 0) return 0;
            }
        }
    } else { // Diagonal
        if (linha + tamanho > TAMANHO || coluna + tamanho > TAMANHO || coluna - (tamanho - 1) < 0) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna + (diagonal == 1 ? i : -i)] != 0) return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio
void posicionarNavio(int linha, int coluna, int tamanho, int orientacao, int tabuleiro[TAMANHO][TAMANHO], int diagonal) {
    for (int i = 0; i < tamanho; i++) {
        if (diagonal == 0) {
            if (orientacao == 0) { // Horizontal
                tabuleiro[linha][coluna + i] = NAVIO;
            } else { // Vertical
                tabuleiro[linha + i][coluna] = NAVIO;
            }
        } else { // Diagonal
            tabuleiro[linha + i][coluna + (diagonal == 1 ? i : -i)] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("    ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("--");
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");
            } else {
                printf("N ");
            }
        }
        printf("|\n");
    }
    
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("--");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Definição das coordenadas dos navios
    int linha1 = 2, coluna1 = 3, orientacao1 = 0; // Horizontal
    int linha2 = 5, coluna2 = 6, orientacao2 = 1; // Vertical
    int linha3 = 0, coluna3 = 0, orientacao3 = 0, diagonal1 = 1; // Diagonal principal
    int linha4 = 0, coluna4 = 9, orientacao4 = 0, diagonal2 = -1; // Diagonal secundária
    int linha5 = 7, coluna5 = 2, orientacao5 = 0; // Novo navio horizontal
    int linha6 = 3, coluna6 = 7, orientacao6 = 1; // Novo navio vertical
    
    // Validação e posicionamento dos navios
    if (posicaoValida(linha1, coluna1, NAVIO, orientacao1, tabuleiro, 0)) {
        posicionarNavio(linha1, coluna1, NAVIO, orientacao1, tabuleiro, 0);
    }
    
    if (posicaoValida(linha2, coluna2, NAVIO, orientacao2, tabuleiro, 0)) {
        posicionarNavio(linha2, coluna2, NAVIO, orientacao2, tabuleiro, 0);
    }
    
    if (posicaoValida(linha3, coluna3, NAVIO, orientacao3, tabuleiro, 1)) {
        posicionarNavio(linha3, coluna3, NAVIO, orientacao3, tabuleiro, 1);
    }
    
    if (posicaoValida(linha4, coluna4, NAVIO, orientacao4, tabuleiro, -1)) {
        posicionarNavio(linha4, coluna4, NAVIO, orientacao4, tabuleiro, -1);
    }
    
    if (posicaoValida(linha5, coluna5, NAVIO, orientacao5, tabuleiro, 0)) {
        posicionarNavio(linha5, coluna5, NAVIO, orientacao5, tabuleiro, 0);
    }
    
    if (posicaoValida(linha6, coluna6, NAVIO, orientacao6, tabuleiro, 0)) {
        posicionarNavio(linha6, coluna6, NAVIO, orientacao6, tabuleiro, 0);
    }
    
    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}