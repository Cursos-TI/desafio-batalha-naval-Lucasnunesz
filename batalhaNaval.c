#include <stdio.h>
#define TAM 10  // Tamanho do tabuleiro
#define NAV 3   // Tamanho dos navios

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Tabuleiro 10x10 inicializado com 0 (água)

    // Posiciona navio horizontal em linha 2, colunas 3-5
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Posiciona navio vertical em coluna 7, linhas 5-7
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Exibe o cabeçalho com letras A-J
    printf("Tabuleiro:\n  "); // Espaço para alinhar com os números das linhas
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibe o tabuleiro com números de linhas
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // Número da linha (1 a 10)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
