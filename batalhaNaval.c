#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
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
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("X ");
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

// Aplica uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origemLinha + i - offset;
            int coluna = origemColuna + j - offset;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && matriz[i][j] == 1) {
                tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }
}

// Gera a matriz em forma de cone
void gerarCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

// Gera a matriz em forma de cruz
void gerarCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Gera a matriz em forma de octaedro
void gerarOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int dist = abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2);
            matriz[i][j] = (dist <= TAMANHO_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);
    
    // Aplicar habilidades em diferentes pontos do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 3);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);
    
    // Exibir o tabuleiro com as habilidades aplicadas
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
