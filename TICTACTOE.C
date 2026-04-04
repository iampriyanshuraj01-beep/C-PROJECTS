#include <stdio.h>

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};

// Display Board
void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[1], board[2], board[3]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[4], board[5], board[6]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
    printf("\n");
}

// Check Win
int checkWin() {
    if (board[1]==board[2] && board[2]==board[3]) return 1;
    if (board[4]==board[5] && board[5]==board[6]) return 1;
    if (board[7]==board[8] && board[8]==board[9]) return 1;

    if (board[1]==board[4] && board[4]==board[7]) return 1;
    if (board[2]==board[5] && board[5]==board[8]) return 1;
    if (board[3]==board[6] && board[6]==board[9]) return 1;

    if (board[1]==board[5] && board[5]==board[9]) return 1;
    if (board[3]==board[5] && board[5]==board[7]) return 1;

    return 0;
}

// Check Draw
int checkDraw() {
    for(int i=1;i<=9;i++) {
        if(board[i] != 'X' && board[i] != 'O')
            return 0;
    }
    return 1;
}

int main() {
    int player = 1, choice;
    char mark;

    while(1) {
        printBoard();

        if(player % 2 == 1) {
            printf("Player 1 (X)\n");
            mark = 'X';
        } else {
            printf("Player 2 (O)\n");
            mark = 'O';
        }

        printf("Enter position (1-9): ");
        scanf("%d", &choice);

        // Validate move
        if(choice < 1 || choice > 9 || board[choice]=='X' || board[choice]=='O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[choice] = mark;

        if(checkWin()) {
            printBoard();
            printf("Player %d wins! 🎉\n", player % 2 == 1 ? 1 : 2);
            break;
        }

        if(checkDraw()) {
            printBoard();
            printf("It's a draw! 🤝\n");
            break;
        }

        player++;
    }

    return 0;
}