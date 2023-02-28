
#include <stdio.h>
#include "tictactoe.h"

void clearBoard(gameData_t* cPtr) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cPtr->board[i][j] = ' ';
        }
    }
    return;
}

void getPlayerInfo(gameData_t* gPtr) 
{
    printf("Player 1 enter your name: ");
    scanf("%s", gPtr->name1);
    printf("Player 1 enter your age: ");
    scanf("%d", &gPtr->age1);
    printf("\n");
    printf("Player 2 enter your name: ");
    scanf("%s", gPtr->name2);
    printf("Player 2 enter your age: ");
    scanf("%d", &gPtr->age2);
    return;
}

void printPlayerInfo(gameData_t player) 
{
    printf("Player 1 is %s age %d and will be Xs\n", player.name1, player.age1);
    printf("Player 2 is %s age %d and will be Os\n", player.name2, player.age2);
    return;
}

void printTurnHeader(gameData_t gameData, char tNum) 
{
    for (int i = 0; i < 50; i++) 
    {
        if (i != 49) 
        {
            printf("-");
        }
        else 
        {
            printf("-\n");
        }
    }
    if (tNum == 'X') 
    {
        printf("---------- %s's Turn --------------------\n", gameData.name1);
        printf("---------- You are Xs --------------------\n");
    }
    else 
    {
        printf("---------- %s's Turn --------------------\n", gameData.name2);
        printf("---------- You are Os --------------------\n");
    }
    for (int i = 0; i < 50; i++) 
    {
        if (i != 49) 
        {
            printf("-");
        }
        else 
        {
            printf("-\n");
        }
    }
    return;
}

void printBoard(gameData_t gameData) 
{
    printf("    C1  C2  C3\n");
    printf("R1  %c | %c | %c \n", gameData.board[0][0], gameData.board[0][1], gameData.board[0][2]);
    printf("   -----------\n");
    printf("R2  %c | %c | %c \n", gameData.board[1][0], gameData.board[1][1], gameData.board[1][2]);
    printf("   -----------\n");
    printf("R3  %c | %c | %c \n", gameData.board[2][0], gameData.board[2][1], gameData.board[2][2]);
    return;
}

void getMove(gameData_t *gameData, char turn) {

    if (turn == 'X') 
    {
        printf("%s, please enter your move in the form RXCY: ", gameData->name1);
    }
    else if (turn == 'O') 
    {
        printf("%s, please enter your move in the form RXCY: ", gameData->name2);
    }

    char r, c;
    char move[5];
    scanf("%4s", move);

    while ((move[0] != 'r' && move[0] != 'R' )|| (move[2] != 'C' && move[2] != 'c')) 
    {
        printf("Input must be in the form RxCy. Try again: ");
        move[0] = '\0';
        scanf("%4s", move);
    }

    while ((move[1] < 49 || move[1] > 51) || (move[3] < 49 || move[3] > 51)) 
    {
        printf("Row and column must be in the range 1 to 3. Try again: ");
        move[0] = '\0';
        scanf("%4s", move);
    }
    
    r = move[1];
    c = move[3];

    while ((gameData->board[r-49][c-49] == 'X') || (gameData->board[r-49][c-49] == 'O')) 
    {
        printf("That space is taken. Try again: ");
        move[0] = '\0';
        scanf("%4s", move);
        r = move[1];
        c = move[3];
    }
    gameData->board[r-49][c-49] = turn;
}

int checkWin(gameData_t gameData, char tNum) 
{
    int win = 0;
    if (gameData.board[0][0] == tNum && gameData.board[0][1] == tNum && gameData.board[0][2] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[1][0] == tNum && gameData.board[1][1] == tNum && gameData.board[1][2] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[2][0] == tNum && gameData.board[2][1] == tNum && gameData.board[2][2] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[0][0] == tNum && gameData.board[1][0] == tNum && gameData.board[2][0] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[0][1] == tNum && gameData.board[1][1] == tNum && gameData.board[2][1] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[0][2] == tNum && gameData.board[1][2] == tNum && gameData.board[2][2] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[0][0] == tNum && gameData.board[1][1] == tNum && gameData.board[2][2] == tNum) 
    {
        win = 1;
    }
    else if (gameData.board[0][2] == tNum && gameData.board[1][1] == tNum && gameData.board[2][0] == tNum) 
    {
        win = 1;
    }
    return win;
}

int checkTie(gameData_t gameData)
{
    int player = 0;
    for(int i = 0; i < 3; i++)
    {
        
        for(int j = 0; j < 3; j++)
        {
            
            if(gameData.board[i][j] == ' ')
            {
                player++;
            }
        }
    }   
    if(player > 0)
    {
        player = 0;
    }
    else
    {
        player = 1;
    }
    return player;
}

void runGame() {
  
  gameData_t gameData;
  
  int win = 0;
  int tie = 0;  
  char turn = 'X';
  
  //Set board to all spaces.
  clearBoard(&gameData);
  
  //Get both players name and age
  getPlayerInfo(&gameData);
  
  //Show the player info
  printf("\n");
  printPlayerInfo(gameData);
  printf("\n");
  
  while (!win && !tie) {
    //int count = 0;
    
    printTurnHeader(gameData, turn); 
    printBoard(gameData);
    getMove(&gameData, turn);    
    
    //Check for win
    win = checkWin(gameData, turn);        
    if (win == 1) {
      printf("--------------------------------------------------\n");      
      if (turn == 'X') {        
        printf("---------- %s WINS! --------------------\n", gameData.name1);
      } else {        
        printf("---------- %s WINS! --------------------\n", gameData.name2);
      }
      printf("--------------------------------------------------\n");      
      printBoard(gameData);
      printf("\n");
    } else {
      tie = checkTie(gameData);        
      if (tie == 1) {
        printf("--------------------------------------------------\n");      
        printf("---------- TIE GAME! --------------------\n");
        printf("--------------------------------------------------\n");      
        printBoard(gameData);
      }
    }
    
    //Toggle turn so other player goes next.
    if (turn == 'X') turn = 'O';
    else turn = 'X';
  }
}