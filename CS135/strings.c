//Name: strings.c
//Purpose: Implement four of the string library functions using pointers
//Author: Kobe Maristela

#include <stdio.h>

#define myLength 50

int strlength(char *myString);
int strcomp(char *myOne, char *myTwo);
char * strconcat(char *myFinal, const char *mySource);
char * strcopy(char *myFinal, const char *mySource);

int main(void)
{
	//Initialize Variables
	char myStringOne[myLength + 1];
	char myStringTwo[myLength + 1];

	//User Input
	printf("Please enter the first string: ");
	gets(myStringOne);

	printf("Please enter the second string: ");
	gets(myStringTwo);

	//String Length
	printf("The length of string 1 is: %d\n", strlength(myStringOne));
	printf("The length of string 2 is: %d\n", strlength(myStringTwo));

	//String Comparison
	switch(strcomp(myStringOne, myStringTwo))
	{
		case 1:
			printf("String 1 comes before string 2 alphabetically.\n");
			break;

		case -1:
			printf("String 2 comes before string 1 alphabetically.\n");
			break;

		case 0:
			printf("The two strings are the same.\n");
			break;
	}
	//String Concatentation
	printf("String 1 after concatenation: %s\n", myStringOne);
	printf("String 2 after concatenation: %s\n", strconcat(myStringTwo, myStringOne));

	//String Copy
	printf("String 1 after copying: %s\n", myStringOne);
	printf("String 2 after copying: %s\n", strcopy(myStringTwo, myStringOne));

	return 0;	
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

		if (myOne[x] == '\0')
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