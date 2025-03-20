#include <stdio.h>
#include <stdlib.h> // Para abs()

// Constantes
#define BOARD_SIZE 10
#define SKILL_SIZE 5
#define CENTER (SKILL_SIZE / 2)

// Função para inicializar/resetar o tabuleiro e adicionar navio
void resetBoard(int board[BOARD_SIZE][BOARD_SIZE], int shipX, int shipY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (i == shipX && j == shipY) ? 3 : 0;
        }
    }
}

// Função unificada para criar habilidades
void createSkill(int skill[SKILL_SIZE][SKILL_SIZE], char type) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            skill[i][j] = 0; // Default: não afetado
            switch (type) {
                case 'C': // Cone
                    if (j >= CENTER - i && j <= CENTER + i && i < CENTER + 1)
                        skill[i][j] = 1;
                    break;
                case 'X': // Cruz
                    if (i == CENTER || j == CENTER)
                        skill[i][j] = 1;
                    break;
                case 'O': // Octaedro
                    if (abs(i - CENTER) + abs(j - CENTER) <= CENTER)
                        skill[i][j] = 1;
                    break;
            }
        }
    }
}

// Função otimizada para aplicar habilidade
void applySkill(int board[BOARD_SIZE][BOARD_SIZE], int skill[SKILL_SIZE][SKILL_SIZE], 
                int originX, int originY) {
    int startX = originX - CENTER > 0 ? originX - CENTER : 0;
    int startY = originY - CENTER > 0 ? originY - CENTER : 0;
    int endX = originX + CENTER < BOARD_SIZE ? originX + CENTER : BOARD_SIZE - 1;
    int endY = originY + CENTER < BOARD_SIZE ? originY + CENTER : BOARD_SIZE - 1;

    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            int skillX = i - (originX - CENTER);
            int skillY = j - (originY - CENTER);
            if (skill[skillX][skillY] == 1 && board[i][j] != 3) {
                board[i][j] = 5;
            }
        }
    }
}

// Função para exibir o tabuleiro
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], const char* skillName) {
    printf("%s:\n  ", skillName);
    for (char c = 'A'; c < 'A' + BOARD_SIZE; c++) printf("%c ", c);
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == 0 ? '.' : board[i][j] == 3 ? 'N' : 'X');
        }
        printf("\n"); 
    }
    printf("\n"); 
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int skill[SKILL_SIZE][SKILL_SIZE];
    const int shipX = 4, shipY = 4; // Posição fixa do navio (E5)

    // Teste das habilidades
    char skillTypes[] = {'C', 'X', 'O'};
    const char* skillNames[] = {"Habilidade Cone", "Habilidade Cruz", "Habilidade Octaedro"};

    for (int i = 0; i < 3; i++) {
        resetBoard(board, shipX, shipY);
        createSkill(skill, skillTypes[i]);
        applySkill(board, skill, shipX, shipY);
        printBoard(board, skillNames[i]);
    }

    return 0;
}