//tictactoe.h – Don't alter this file.
//
//Put this file in the same folder as tictactoe.cc.
//
//Put the following line of code at the top of your 
//tictactoe.cc file if it is not already there.
//
//       #include "tictactoe.h"
//
//You CAN and SHOULD use ROWS and COLS to process the
//board when necessary (i.e. in the clearBoard function).

#define ROWS 3
#define COLS 3
#define NAME_SIZE 20

typedef struct {
  
  //Player 1 info.
  //Note player 1 will be Xs.
  char name1[NAME_SIZE];
  int age1;
  
  //Player 2 info
  //Note player 2 will be Os.
  char name2[NAME_SIZE];
  int age2;
  
  //The tictactoe board
  char board[ROWS][COLS];
  
} gameData_t;

