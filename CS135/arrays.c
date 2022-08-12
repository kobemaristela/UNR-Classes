//Name: Arrays.c
//Purpose: Create an array list
//Author: Kobe Maristela

#include <stdio.h>

int main(void)
{
	//Initialize variables
	int myRow, myCol;
	int myCount [10] = {0};


	printf("This program counts occurrences of digits 0 through 9 in an NxM array.\n");
	printf("Enter the size of the array (Row Column): ");
	scanf("%d %d", &myRow, &myCol);

	int myList [myRow] [myCol];

	//Nested User Input (For Loop)
	for (int r = 0; r < myRow; r++)
	{
		printf("Enter row %d: ", r );
		for (int c = 0; c < myCol; c++)
		{
			scanf("%d", &myList[r][c]);
			myCount[myList[r][c]]++;
		}
	}

	//Prints count of digit
	printf("Total counts for each digit:\n");
	for (int d = 0; d < 10; d++)
	{
		printf("Digit %d occurs %d times\n", d, myCount[d]);
	}

	//Prints out 1D array
	printf("The digit counts directly from the 1D array:\n");
	for (int myDOne = 0;  myDOne< 10; myDOne++)
	{
		printf("%d ", myCount[myDOne]);
	}

	printf("\n");

	//Prints out 2D array
	printf("The original 2D array entered by the user:\n");
	for (int r = 0; r < myRow; r++)
	{
		for (int c = 0; c < myCol; c++)
		{
			printf("%d ", myList[r] [c]);
		}

		printf("\n");
	}


	return 0;

}