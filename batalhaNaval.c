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
int posicaoValida(int linha, int coluna, int tamanho, int orientacao, int tabuleiro[TAMANHO][TAMANHO]) {
    if (orientacao == 0) { // Horizontal
        if (coluna + tamanho > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Sobreposição
        }
    } else { // Vertical
        if (linha + tamanho > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Sobreposição
        }
    }
    return 1;
}

// Função para posicionar um navio
void posicionarNavio(int linha, int coluna, int tamanho, int orientacao, int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = NAVIO;
        } else { // Vertical
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Definição das coordenadas dos navios
    int linha1 = 2, coluna1 = 3, orientacao1 = 0; // Horizontal
    int linha2 = 5, coluna2 = 6, orientacao2 = 1; // Vertical
    
    // Validação e posicionamento dos navios
    if (posicaoValida(linha1, coluna1, NAVIO, orientacao1, tabuleiro)) {
        posicionarNavio(linha1, coluna1, NAVIO, orientacao1, tabuleiro);
    }
    
    if (posicaoValida(linha2, coluna2, NAVIO, orientacao2, tabuleiro)) {
        posicionarNavio(linha2, coluna2, NAVIO, orientacao2, tabuleiro);
    }
    
    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
