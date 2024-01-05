#include <stdio.h>

int main() {
    char playagain;
    do {
        int health = 10;
        printf("\t\t\t\t       A KING's DUTY\n");
        printf("\t\t\t\t--Rescue Your Queen, KING!--\n");
        printf(" 'K' -> King (Your character)\n");
        printf(" 'Q' -> Queen \n");
        printf(" 'L' -> Lava,'O' -> Unknown Danger,'E' -> Enemies \n");
        char board[11][11] = {
            {'K', '_', 'E', '_', 'O', '_', '_', 'L', 'L', 'L'},
            {'_', '_', 'E', '_', '_', 'O', '_', '_', 'L', 'L'},
            {'O', 'E', '_', '_', 'O', '_', 'O', '_', '_', 'L'},
            {'_', 'O', '_', '_', '_', '_', 'E', 'E', '_', 'L'},
            {'_', '_', '_', '_', '_', 'E', 'E', 'E', '_', 'L'},
            {'_', '_', 'E', '_', 'O', 'E', 'Q', 'E', 'O', 'L'},
            {'_', 'E', '_', 'E', '_', 'E', 'E', 'E', '_', 'L'},
            {'_', 'E', '_', 'E', '_', 'E', 'E', '_', '_', 'L'},
            {'_', '_', '_', '_', '_', '_', 'O', '_', 'L', 'L'},
            {'L', '_', 'L', '_', 'L', '_', 'L', '_', 'L', 'L'},
            {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'}
        };

        printf("Initial board:\n");
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                printf("\t%c ", board[i][j]);
            }
            printf("\n\n");
        }

        int kingRow, kingCol;

        // Find the initial position of the king
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (board[i][j] == 'K') {
                    kingRow = i;
                    kingCol = j;
                }
            }
        }

        int win = 0;
        int gameover = 0;
        while (!win && !gameover) {
            char move;
            printf("Enter Action for King (W/S/A/D or Q/E/Z/C): ");
            scanf(" %c", &move);

            // Save the current king position
            int prevKingRow = kingRow;
            int prevKingCol = kingCol;

            // Update king position based on the move
            switch (move) {
                case 'd':
                    if (kingCol < 10) kingCol++;
                    break;
                case 'a':
                    if (kingCol > 0) kingCol--;
                    break;
                case 'w':
                    if (kingRow > 0) kingRow--;
                    break;
                case 's':
                    if (kingRow < 10) kingRow++;
                    break;
                case 'q':
                    if (kingRow > 0 && kingCol > 0) {
                        kingRow--;
                        kingCol--;
                    }
                    break;
                case 'e':
                    if (kingRow > 0 && kingCol < 10) {
                        kingRow--;
                        kingCol++;
                    }
                    break;
                case 'z':
                    if (kingRow < 10 && kingCol > 0) {
                        kingRow++;
                        kingCol--;
                    }
                    break;
                case 'c':
                    if (kingRow < 10 && kingCol < 10) {
                        kingRow++;
                        kingCol++;
                    }
                    break;
                default:
                    printf("Invalid move\n");
                    continue;
            }

            // Clear the previous king position
            board[prevKingRow][prevKingCol] = '_';

            char newCell = board[kingRow][kingCol];
            if (newCell == 'O' || newCell == 'L' || newCell == 'E') {
                health--;
                if (newCell == 'O') {
                    printf("\t\t\t\tFaced a Hidden Obstacle! Health Depleted\n");
                } if (newCell == 'L') {
                    printf("\t\t\t\tTouched Lava! Health Depleted\n");
                } if (newCell == 'E') {
                    printf("\t\t\t\tBattled an Enemy! Health Depleted\n");
                }
                if (health == 0) {
                    gameover = 1;
                }
            } else if (newCell == 'Q') {
                win = 1;
            }

            // Update the board with the new king position
            board[kingRow][kingCol] = 'K';

            printf("Updated board:\n");
            for (int i = 0; i < 11; i++) {
                for (int j = 0; j < 11; j++) {
                    printf("\t%c ", board[i][j]);
                }
                printf("\n\n");
            }

            printf("Health remaining: %d\n", health);
        }

        if (win) {
            printf("\t\t\t\tQueen Rescued\n");
            printf("\t\t\t\t   You win!\n");
        } else {
            printf("\t\t\t\tKing Died! ");
            printf("Game Over\n");
        }
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playagain);
    } while (playagain == 'y' || playagain == 'Y');
    return 0;
}
