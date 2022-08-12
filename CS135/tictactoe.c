//Name: tictactoe.c
//Purpose: Create an tictactoe game
//Author: Kobe Maristela

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 3

//Prototype
void clear_table(char board [SIZE][SIZE]);
void display_table(char board [SIZE][SIZE]);
bool check_table_full(char board [SIZE][SIZE]);
void update_table(char board [SIZE][SIZE], int row, int col, char myToken);
bool check_legal_option(char board [SIZE][SIZE], int row, int col);
void generate_player2_move(char board [SIZE][SIZE], int row, int col);
int check_three_in_a_row(char board [SIZE][SIZE]);
bool check_end_of_game(char board [SIZE][SIZE]);
void get_player1_move(char board [SIZE][SIZE], int row, int col);
void print_winner(char board [SIZE][SIZE]);

int main ()
{
	//Declare the tic-tac-toe board
 	char board[SIZE][SIZE];
 	//The row and column of the move for either player 1 or 2
	int row, col;
	char playAgain; //Loop game

	while(1)
	{
 		//Clear the table
 		clear_table(board);
 		//Display the table
 		display_table(board);
 		do
 		{
	 		//Have player 1 enter their move
	 		get_player1_move(board, row, col);
		 	//Generate player 2 move
			generate_player2_move(board, row, col);
		 	//Do this while the game hasn't ended
	 	}
	 	while(check_end_of_game(board) == false);
	 	//After the game is over, print who won
	 	print_winner(board);

	 	printf("Would you like to play again (Y/N):");
	 	scanf(" %c", &playAgain);
	 	if (playAgain == 'N')
	 	{
	 		return 0;
	 	}
 	}
}

//Displays the board ***
void display_table(char board[SIZE][SIZE])
{
	printf("The current state of the game is:\n");
	for(int row = 0; row < SIZE; row++)
	{
		for(int col = 0; col < SIZE; col++)
		{
			printf("%c ", board[row][col]);
		}
		printf("\n");
	}
	return;
}

//Clears the board ***
void clear_table(char board[SIZE][SIZE])
{
	for(int row = 0; row < SIZE; row++)
	{
		for(int col = 0; col < SIZE; col++)
		{
			board [row] [col] = '_'; //Assigns "_" to the board
		}
	}
	return;
}

//Checks if table is full ***
bool check_table_full(char board [SIZE][SIZE])
{
	for(int row = 0; row < SIZE; row++)
	{
		for(int col = 0; col < SIZE; col++)
		{
			if (board [row][col] == '_')
			{
				return false;
			}
		}
	}
	return true;
}

//Updates the table ***
void update_table(char board [SIZE][SIZE], int row, int col, char myToken)
{
	board [row] [col] = myToken;
	return;
}

//Checks if the move is valid ***
bool check_legal_option(char board [SIZE][SIZE], int row, int col)
{
	if (row >= 0 && row < 3  && col < 3 && col >= 0)
	{
		if (board [row][col] == '_')
			{
				return true;
			}
			else
			{
				return false;
			}
	}
	else
	{
		return false;
	}
}

//Generate P2 move ???
void generate_player2_move(char board [SIZE][SIZE], int row, int col)
{
	time_t myT;
	if(check_end_of_game(board) == false )
	{
		do
		{
		srand(time(0));
		row = rand() % 3;
		col = rand() % 3;
		}while(check_legal_option(board, row, col) == false);

			update_table(board, row, col, 'X');	
			printf("Player 2 has entered [row, col]: %d, %d\n", row + 1 , col + 1 );
			display_table(board);
	}
}

//Check for winner ***
int check_three_in_a_row(char board [SIZE][SIZE])
{
	for(int x = 0; x < SIZE; x++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (board[x][0] == board[1][1] && board[1][1] == board[i][2]) //Check Diaganol
			{
				if (board[x][0] == 'X') //Player 2 has won
				{
					return 2;
				}
				else if (board[x][0] == 'O') //Player 1 has won
				{
					return 1;
				}
			}		
			else if(board[x][0] == board[x][1] && board[x][1] == board[x][2]) //Check row
			{
				if (board[x][0] == 'X') //Player 2 has won
				{
					return 2;
				}
				else if (board[x][0] == 'O') //Player 1 has won
				{
					return 1;
				}
			}
			else if (board[0][x] == board[1][x] && board[1][x] == board[2][x]) //Check Column
			{
				if (board[0][x] == 'X') //Player 2 has won
				{
					return 2;
				}
				else if (board[0][x] == 'O') //Player 1 has won
				{
					return 1;
				}
			}	
		}
	}
	return 0;
}

//Checks if the game has ended ***
bool check_end_of_game(char board [SIZE][SIZE]) 
{
	if (check_three_in_a_row(board) != 0 || check_table_full(board) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Get P1 move ???
void get_player1_move(char board [SIZE][SIZE], int row, int col)
{
	if (check_end_of_game(board) == false)
	{
		do
		{
			printf("Player 1 enter you selection [row, col]: ");
			scanf("%d, %d", &row, &col);
		}while(check_legal_option(board, row - 1 , col - 1) == false);
		
			update_table(board, row - 1, col - 1, 'O');
			display_table(board);
	}
}

//Prints out winner ***
void print_winner(char board [SIZE][SIZE]) 
{
	if (check_three_in_a_row(board) == 1)
	{
		printf("Congratulations, Player 1 wins!\n");
	}
	else if (check_three_in_a_row(board) == 2)
	{
		printf("Congratulations, Player 2 wins!\n");
	}
	else
	{
		printf("Game over, no player wins.\n");
	}
	return;
}