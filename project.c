#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <stdlib.h>

#define BOARD_SIZE 10
#define MAX_HEALTH 10

// ANSI escape codes for text color
#define BLUE_TEXT "\033[34m"  // Blue
#define LIGHT_BLUE_TEXT "\033[94m"  // Light Blue
#define ORANGE_TEXT "\033[33m"  // Yellow-Orange
#define GREEN_TEXT "\033[32m"  // Green
#define PURPLE_TEXT "\033[35m"  // Purple
#define RED_TEXT "\033[31m"     // Red
#define BROWN_TEXT "\033[0;33m" // Brown
#define DARK_BROWN_TEXT "\033[0;33;40m"  // Dark Brown
#define LIGHT_PINK_TEXT "\033[95m" // Light Pink
#define RESET_TEXT "\033[0m"   // Reset to default color


void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char cell = board[i][j];
            switch (cell) {
                case 'K':
                    printf("\t%s%c%s ", BLUE_TEXT, cell, RESET_TEXT);
                    break;
                case 'Q':
                    printf("\t%s%c%s ", LIGHT_PINK_TEXT, cell, RESET_TEXT);
                    break;
                case 'L':
                    printf("\t%s%c%s ", ORANGE_TEXT, cell, RESET_TEXT);
                    break;
                case 'O':
				    printf("\t%s%c%s ", GREEN_TEXT, cell, RESET_TEXT);
                    break;
				case 'W':
                    printf("\t%s%c%s ", PURPLE_TEXT, cell, RESET_TEXT);
                    break;
                case 'X':
                    printf("\t%s%c%s ", RED_TEXT, cell, RESET_TEXT);
                    break;
                case 'M':
                    printf("\t%s%c%s ", DARK_BROWN_TEXT, cell, RESET_TEXT);
                    break;    
     
                default:
                    printf("\t%c ", cell); 
            }
        }
        printf("\n\n");
    }
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE], int level) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (level == 1) {
        // Level 1 Board Configuration
        char level1[BOARD_SIZE][BOARD_SIZE] = {
            {'K', '_', 'L', '_', '_', '_', 'L', 'L', 'L', 'L'},
            {'_', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'},
            {'_', '_', 'L', '_', 'L', '_', '_', 'L', 'L', 'L'},
            {'L', '_', '_', '_', 'L', '_', '_', 'L', '_', 'L'},
            {'L', '_', 'L', 'L', 'L', 'L', '_', 'L', '_', 'O'},
            {'L', '_', '_', '_', 'L', '_', '_', 'L', '_', 'L'},
            {'L', '_', '_', '_', 'L', 'L', '_', '_', '_', 'L'},
            {'L', 'L', 'L', '_', '_', '_', 'L', '_', 'L', 'L'},
            {'L', 'L', 'L', '_', 'L', 'L', '_', 'L', 'L', 'L'},
            {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'}
        };

        // Copy level1 to the main board
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Pass Through The Lava Cave! And Find The Portal\n");
        printf(" Don't be Scared to take Damage. You are going to get Wounded in your Journey.\n");
        printf("Use The W/A/S/D keys on your keyboard to navigate.");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        Beep(600,100);
        Beep(2000,100);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = level1[i][j];
            }
        }
    } else if (level == 2) {
        // Level 2 Board Configuration
        char level2[BOARD_SIZE][BOARD_SIZE] = {
            {'X', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
            {'_', 'X', '_', 'W', 'X', 'W', '_', '_', '_', '_'},
            {'X', '_', '_', '_', 'M', '_', '_', 'X', '_', 'X'},
            {'_', '_', '_', 'X', 'X', 'X', 'X', '_', 'M', '_'},
            {'_', 'M', '_', 'M', '_', 'W', 'X', '_', 'X', '-'},
            {'_', 'W', 'W', 'W', 'W', '_', 'M', 'X', '_', 'X'},
            {'_', '_', 'X', 'X', 'X', 'O', 'X', 'X', '_', 'W'},
            {'X', '_', '_', 'X', 'M', '_', 'W', 'X', 'W', '_'},
            {'_', '_', 'W', '_', 'W', 'X', '_', 'X', '_', '_'},
            {'K', '_', '_', 'X', '_', 'X', 'X', 'X', '_', 'W'}
        };

        // Copy level2 to the main board
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("Fight The Creepy Creatures And Pass Through The Portal To Procede\n");
        printf("Don't Take Too Much DAMAGE!");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
         Beep(600,100);
        Beep(2000,100);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = level2[i][j];
            }
        }
    } else if (level == 3) {
        // Level 3 Board Configuration
        char level3[BOARD_SIZE][BOARD_SIZE] = {
       		{'M', 'X', 'X', 'X', 'W', 'L', 'L', 'L', 'L', 'L'},
            {'M', 'L', 'L', 'L', 'W', '_', 'L', 'L', 'L', 'L'},
            {'M', 'L', 'Q', 'L', 'W', '_', 'X', 'L', 'L', 'L'},
            {'M', 'L', 'L', 'L', 'W', '_', '_', '_', 'L', 'L'},
            {'M', 'X', 'X', 'X', 'W', '_', '_', '_', '_', 'L'},
            {'L', 'X', '_', '_', '_', 'X', 'X', 'W', 'M', 'L'},
            {'L', 'L', '_', '_', '_', 'W', 'M', '_', 'X', 'L'},
            {'L', 'L', 'L', '_', 'M', 'M', 'X', 'L', 'L', 'L'},
            {'L', 'L', 'L', '_', '_', 'X', '_', 'L', 'K', 'L'},
            {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'}
        };
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\tPass Through All The Obstacles and Fight All The Enemies to Save Your Queen\n");
        printf("\t\t\t Don't DIE!!'");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        Beep(600,100);
        Beep(2000,100);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = level3[i][j];
            }
        }
    }
}
int main() {
	char playagain;
	do{
		system("cls");
    int currentLevel = 1;
    int winCount = 0;
     int kingHealth = MAX_HEALTH;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
        printf("\t\t\t\t\t           A KING's DUTY\n");
        printf("\t\t\t\t\t    --Save Your Queen, KING!--\n");
         SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        int sleeptimer = 2;
        sleep(sleeptimer);
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("\t\t\t\tOnce upon a time, in the magical kingdom of Eldoria,\n");
        sleeptimer = 3;
        sleep(sleeptimer);
        printf("\t\t\t   a nefarious  sorcerer  kidnapped  your  beloved  Queen  and-\n");
        sleep(sleeptimer);
        printf("\t\t\tlocked her away in a mysterious dungeon guarded by deadly obstacles.\n");
        sleeptimer = 4;
        sleep(sleeptimer);
        printf("\t\t     Your  quest, noble King, is  to  navigate through the treacherous  lands,\n");
        sleeptimer = 3;
        sleep(sleeptimer);
        printf("\t\t   overcome  obstacles,  and  rescue  your  Queen  from  the  clutches  of  evil.\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
         sleeptimer = 4;
        sleep(sleeptimer);
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
        printf("\t\t\t\t\t Get  Ready  To  Enter The  Dungeon\n");
        
        sleeptimer = 3;
        sleep(sleeptimer);
        for (int i = 3; i >= 1 ; i--) {
            printf("\t\t\t\t\t\t\t %d\n\n", i);
            sleeptimer = 2;
            sleep(sleeptimer);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    while (currentLevel <= 3 && kingHealth > 0) {
        char board[BOARD_SIZE][BOARD_SIZE];
        printf("\n\n\n\n\n");
        initializeBoard(board, currentLevel);
   
        printf("\t\t\t\t\t\nLevel %d\n", currentLevel);
        displayBoard(board);

        int kingRow, kingCol;

        // Find the initial position of the king
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
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
            printf("Enter Action for King (w/a/s/d): ");
            move = getch(); // Use _getch() to capture key press without the need for Enter

            int prevKingRow = kingRow;
            int prevKingCol = kingCol;

              switch (move) {
                case 'd':
                    kingCol = (kingCol < BOARD_SIZE - 1) ? kingCol + 1 : kingCol;
                Beep(400,100);  // Beep with a frequency of 1000 Hz for 500 milliseconds
                Beep(1000,50);
	                    break;
                case 'a':
                    kingCol = (kingCol > 0) ? kingCol - 1 : kingCol;
                    Beep(400,100);  // Beep with a frequency of 1000 Hz for 500 milliseconds
                    Beep(1000,50);
                    break;
                case 'w':
                    kingRow = (kingRow > 0) ? kingRow - 1 : kingRow;
                    Beep(400,100);  // Beep with a frequency of 1000 Hz for 500 milliseconds
                    Beep(1000,50);
                    break;
                case 's':
                    kingRow = (kingRow < BOARD_SIZE - 1) ? kingRow + 1 : kingRow;
                    Beep(400,100);  // Beep with a frequency of 1000 Hz for 500 milliseconds
                    Beep(1000,50);
                    break;
                default:
                    printf("Invalid move\n");
                    Beep(100,50);
                    continue;
            }
            char newCell = board[kingRow][kingCol];

            if (newCell == 'X' || newCell == 'L' || newCell == 'M' || newCell == 'W') {
                kingHealth--;
                Beep(800,500);

                printf("\t\t\t\t\tLookout!!! King's health: %d\n", kingHealth);

                if (kingHealth <= 0) {
                    gameover = 1;
                    printf("Alas! The King ran out of health.\n");
                    printf("The evil sorcerer's dark magic prevails.\n");
                    break;
                }
            } else if (newCell == 'Q' || newCell == 'O' ) {
                win = 1;
            }

            board[prevKingRow][prevKingCol] = '_';
            board[kingRow][kingCol] = 'K';

          	system("cls");
            printf("\n\n\n\nHealth:%d\n",kingHealth);
            displayBoard(board);
        }

        if (win) {
            printf("Huzzah! You successfully rescued the Queen!\n");
            winCount++;
        } else {
            printf("Game over\n");
        }

        // Move to the next level
        currentLevel++;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    if (winCount == 3) {
        printf("\t\t\tCongratulations! You have successfully cleared all three levels!\n");
        printf("\t\t\t\tThe kingdom rejoices, and peace is restored.\n");
    }
        printf("Do you want to play again? (Y/N): ");
        playagain = getch();
 }while(playagain == 'y' || playagain == 'Y');

    return 0;
}
