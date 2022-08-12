//Name: Combine Strings
//Purpose: Asks the user to enter two strings
//Author: Kobe Maristela

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define myLength 30

int strlength(char *myString);
int strcomp(char *myOne, char *myTwo);
char* strconcat(char *myFinal, const char *mySource);

char* intersperse(char* myFirstString, char* mySecondString);
char* widen_stars(char* myFirstString, char* mySecondString);

int main(int argc, char *argv[])
{
	
	char* myFirst = (char*) malloc((myLength + 1) * sizeof(char));
	char* mySecond = (char*) malloc((myLength + 1) * sizeof(char));
	printf("Please enter a string of maximum 30 characters: ");
	scanf("%s", myFirst);
	printf("Please enter a string of maximum 30 characters: ");
	scanf("%s", mySecond);

	
	//Checks for command line arguments
	if(strcomp("-i" , argv[1]) == 0)
	{
		printf("%s\n", intersperse(myFirst, mySecond));
	}
	else if (strcomp("-w", argv[1]) == 0)
	{
		printf("%s\n", widen_stars(myFirst, mySecond));
	}
	
	free(myFirst);
	free(mySecond);
	return 0;
}

char* intersperse(char *myFirstString, char *mySecondString)
{
	int myX = 0, myI = 0;
	char* myString = (char*) malloc((myLength + 1) * sizeof(char));

	while(myFirstString[myI] != '\0' && mySecondString[myI] != '\0') 
	{
		myString[myX] = myFirstString[myI];
		myString[myX + 1] = mySecondString[myI];

		myX = myX + 2;
		myI++;
	}

	if (myFirstString[myI] == '\0')
	{
		while(mySecondString[myI] != '\0')
		{
			myString[myX++] = mySecondString[myI++];
		}
	}
	else if (mySecondString[myI] == '\0')
	{
		while(myFirstString[myI] != '\0')
		{
			myString[myX++] = myFirstString[myI++];
		}
	}
	return myString;
	free(myString);
}

char* widen_stars(char* myFirstString, char* mySecondString)
{
	int myX = 0, myI = 0;
	char* myString = (char*) malloc((100) * sizeof(char));
	char* myString2 = (char*) malloc((100) * sizeof(char));
	myString = strconcat(myFirstString, mySecondString);

	while(myString[myI] != '\0')
	{
		myString2[myX] = myString[myI];
		myString2[myX + 1] = '*';

		myX = myX + 2;
		myI++;
	}

	myString2[myX - 1] = '\0';

	
	return myString2;
	free(myString);
	free(myString2);
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
