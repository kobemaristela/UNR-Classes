//Name: Dynamic Strings
//Purpose: Asks the user to enter two strings
//Author: Kobe Maristela

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define myLength 30

int strlength(char *myString);
int strcomp(char *myOne, char *myTwo);
char* strconcat(char *myFinal, const char *mySource);
char* strcopy(char *myFinal, const char *mySource);

int main(int argc, char *argv[])
{
	//Intiailize variables
	int myNum = atoi(argv[1]);
	int myCount[myNum], myChoice, myStringO, myStringT;

	char** myString = malloc(myNum * sizeof(char*));

	//User Input Loop
	for(int x = 0; x < myNum; x++)
	{
		myString[x] = (char*) malloc(10 * sizeof(char));

		printf("Enter the length of string %d: ", x + 1);
		scanf("%d", &myCount[x]);

		printf("Please enter string %d: ", x + 1);
		scanf("%s", myString[x]);
	}

	//Loop User Interface
	while(1)
	{
		printf("Your strings are:\n");
		for (int x = 0; x < myNum; x++)
		{
			printf("String number %d - \"%s\" \n", x + 1, myString[x]);
		}
		printf("Options:\n");
		printf("1 – Find string length\n");
		printf("2 – Compare strings\n");
		printf("3 – Copy strings\n");
		printf("4 – Concatenate strings\n");
		printf("5 – Quit\n");

		printf("Please enter your option: ");
		scanf("%d", &myChoice);

		switch(myChoice)
		{
			case 1:
			{
				printf("Enter a string number: ");
				scanf("%d", &myStringO);

				printf("The length of string %d is: %d\n", myStringO, strlength(myString[myStringO - 1]));
				break;
			}
			case 2:
			{
				printf("Enter the number of the first string: ");
				scanf("%d", &myStringO);
				printf("Enter the number of the second string: ");
				scanf("%d", &myStringT);

				if (strcomp(myString[myStringO - 1],myString[myStringT - 1]) == 0)
				{
					printf("“The two strings are the same.\n");
				}
				else if (strcomp(myString[myStringO - 1],myString[myStringT - 1]) == -1)
				{
					printf("String %d comes before string %d alphabetically.\n", myStringO, myStringT);
				}
				else if ((strcomp(myString[myStringO - 1],myString[myStringT - 1]) == 1))
				{
					printf("String %d comes before string %d alphabetically.\n", myStringT, myStringO);
				}

				break;
			}
			case 3:
			{
				printf("Enter the number of the source string: ");
				scanf("%d", &myStringO);
				printf("Enter the number of the destination string: ");
				scanf("%d", &myStringT);

				strcopy(myString[myStringT - 1], myString[myStringO - 1]);

				break;
			}
			case 4:
			{
				printf("Enter the number of the source string: ");
				scanf("%d", &myStringO);
				printf("Enter the number of the destination string: ");
				scanf("%d", &myStringT);

				strconcat(myString[myStringT - 1], myString[myStringO - 1]);

				break;
			}
			case 5:
			{
				free(myString);
				return 0;
			}
			default:
			{
				printf("Invalid Option.\n");
			}
		}
	}
}

int strlength(char *myString)
{
	int myCount = 0;
	while(myString[myCount] != '\0')
	{
		myCount++;
	}

	return myCount;
}


int strcomp(char *myOne, char *myTwo)
{
	for(int x = 0; x < myLength; x++)
	{
		if(myOne[x] != myTwo[x])
		{
			if (myOne[x] < myTwo[x])
			{
				return -1;
			}
			else if (myOne[x] > myTwo[x])
			{
				return 1;
			}

		}

		else if (myOne[x] == '\0')
		{
			return 0;
		}
	}
}


char * strconcat(char *myFinal, const char *mySource)
{
	char* tempFinal = myFinal;

	while(*myFinal != '\0')
	{
		myFinal++;
	}

	do
	{
		*myFinal++ = *mySource++;
	}while(*mySource != '\0');

	*myFinal = '\0';
	
	
	
	return tempFinal;
}

char * strcopy(char *myFinal, const char *mySource)
{
	char* tempFinal = myFinal;

	while(*mySource != '\0')
	{
		*myFinal++ = *mySource++;
	}

	*myFinal = '\0';

	return tempFinal;

}