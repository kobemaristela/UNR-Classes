// Name: Date_c.c
// Purpose: Print out the dates as a table with added 0s
// Author: Kobe Maristela

#include <stdio.h>

int main(void)
{
	//Initialize variables
	int myDayOne, myDayTwo, myDayThree, myDayFour;
	int myMonthOne, myMonthTwo, myMonthThree, myMonthFour;
	int myYearOne, myYearTwo, myYearThree, myYearFour;

	//Recieve input from users
	printf("Enter date 1 (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &myDayOne, &myMonthOne, &myYearOne);
	printf("Enter date 2 (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &myDayTwo, &myMonthTwo, &myYearTwo);
	printf("Enter date 3 (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &myDayThree, &myMonthThree, &myYearThree);
	printf("Enter date 4 (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &myDayFour, &myMonthFour, &myYearFour);

	//Print user input
	printf("Year\tMonth\tDay\n");
	printf("%4.4d\t%2.2d\t%-2.2d\n", myYearOne, myMonthOne, myDayOne );
	printf("%4.4d\t%2.2d\t%-2.2d\n", myYearTwo, myMonthTwo, myDayTwo );
	printf("%4.4d\t%2.2d\t%-2.2d\n", myYearThree, myMonthThree, myDayThree );
	printf("%4.4d\t%2.2d\t%-2.2d\n", myYearFour, myMonthFour, myDayFour );

	return 0;
}