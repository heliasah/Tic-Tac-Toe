#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// for displaying the colors of the board
#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"


void setupBoard(char gameBoard[3][3]);
void displayBoard(char gameBoard[3][3]);
void playerMove(char gameBoard[3][3], char symbol);
int checkFreeSpace(char gameBoard[3][3]);
char checkWinner(char gameBoard[3][3]);
int checkDraw(char gameBoard[3][3]);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    
    setupBoard(board); 

    while (1) {
        displayBoard(board);  
        playerMove(board, currentPlayer); 
        char winner = checkWinner(board);
        if (winner != 0) { 
            displayBoard(board);
            printf("Player %c wins!\n", winner);
            break;
        }
        if (checkDraw(board)) {  
            displayBoard(board);
            printf("The game is a draw!\n");
            break;
        }
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
}       else {
            currentPlayer = 'X';
}

    }

    return 0;
}

void setupBoard(char gameBoard[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            gameBoard[i][j] = ' ';
        }
    }
}

void displayBoard(char gameBoard[3][3]) {
    printf("\n");
    printf("     0   1   2  \n");
    printf("   -------------\n");
    for (int i = 0; i < 3; i++) {
        printf(" %d |", i);
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == 'X') {
                printf(" %s%c%s ", RED, gameBoard[i][j], RESET);
            } else if (gameBoard[i][j] == 'O') {
                printf(" %s%c%s ", BLUE, gameBoard[i][j], RESET);
            } else {
                printf(" %c ", gameBoard[i][j]);
            }
            if (j < 2) printf("|");
        }
        printf("|\n");
        if (i < 2) printf("   |---|---|---|\n");
    }
    printf("   -------------\n");
    printf("\n");
}

char checkWinner(char gameBoard[3][3]){

    for(int i = 0; i < 3; i++){
        if(gameBoard[i][0] != ' ' && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]){
            return gameBoard[i][0];
        }
    }

    for(int i = 0; i < 3; i++){
        if(gameBoard[0][i] != ' ' && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]){
            return gameBoard[0][i];
        }
    }

    if(gameBoard[0][0] != ' ' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        return gameBoard[0][0];
    }
    if(gameBoard[0][2] != ' ' && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        return gameBoard[0][2];
    }

    return 0;
}

int checkDraw(char gameBoard[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char gameBoard[3][3], char symbol) {
    int row, col;
    while (1) {
        printf("Enter row and column for %c: ", symbol);
        fflush(stdout);  
        scanf("%d %d", &row, &col);
        if(row >= 0 && row <= 2 && col >= 0 && col <= 2 && gameBoard[row][col] == ' ') {
            gameBoard[row][col] = symbol;
            break;
        } else {
            printf("Invalid move. Try again.\n");
            fflush(stdout); 
        }
    }
}

int checkFreeSpace(char gameBoard[3][3]){
    int freeSpaces = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(gameBoard[i][j] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
