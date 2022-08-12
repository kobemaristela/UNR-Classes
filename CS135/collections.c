//Name: Collections.c
//Purpose: Evaluate logical expressions
//Author: Kobe Maristela

#include <stdio.h>

int main(void)
{
	//Initiate variables
	int myColOnePri, myColOneVol, myColTwoPri, myColTwoVol, myColThreeVol, myColThreePri;
	int myBudget, myPrices, myTotalOne, myTotalTwo,myTotalThree;
	int myCount;

	//Inputs
	printf("Enter volumes and price per volume for collection 1: ");
	scanf("%d %d", &myColOneVol, &myColOnePri);

	printf("Enter volumes and price per volume for collection 2: ");
	scanf("%d %d", &myColTwoVol, &myColTwoPri);

	printf("Enter volumes and price per volume for collection 3: ");
	scanf("%d %d", &myColThreeVol, &myColThreePri);

	printf("Enter Bob's budget: ");
	scanf("%d", &myBudget);

	//Calculations
	myTotalOne = myColOneVol * myColOnePri;
	myTotalTwo = myColTwoVol * myColTwoPri;
	myTotalThree = myColThreeVol * myColThreePri;

	//Condition 1
	if (myBudget > 0) 
	{
		printf("(1) Bob has some money to buy collections.\n");
	}
	else
	{
		printf("(1) Bob does not have money to buy anything.\n");
	}
	
	//Condition 2
	if (myBudget >= myTotalOne + myTotalTwo + myTotalThree >= myBudget) 
	{
		printf("(2) Bob has enough money to buy all three collections.\n");
	}
	else
	{
		printf("(2) Bob does not have enough money to buy all three collections.\n");
	}

	//Condition 3
	if (myTotalOne > myBudget && myTotalTwo > myBudget) 
	{
		printf("(3) At least two collections are more expensive than Bob’s budget.\n");
	}
	else if (myTotalOne > myBudget && myTotalThree > myBudget)
	{
		printf("(3) At least two collections are more expensive than Bob’s budget.\n");
	}
	else if (myTotalTwo > myBudget && myTotalThree > myBudget)
	{
		printf("(3) At least two collections are more expensive than Bob’s budget.\n");
	}
	else
	{
		printf("(3) At least two collections are cheaper than or equal to Bob’s budget.\n");
	}

	//Condition 4
	if (myTotalOne == myTotalTwo || myTotalOne == myTotalThree || myTotalTwo == myTotalThree)
	{
		printf("(4) At least two collections cost the same amount of money.\n");
	}
	else
	{
		printf("(4) No two collections have the same price.\n");
	}

	//Condition 5
	if (myTotalOne <= myBudget && myTotalTwo > myBudget && myTotalThree > myBudget)
	{
		printf("(5) Only one collection is cheaper than or equal to Bob’s budget.\n");
	}
	else if (myTotalTwo <= myBudget && myTotalOne > myBudget && myTotalThree > myBudget)
	{
		printf("(5) Only one collection is cheaper than or equal to Bob’s budget.\n");
	}
	else if (myTotalThree <= myBudget && myTotalOne > myBudget && myTotalTwo > myBudget)
	{
		printf("(5) Only one collection is cheaper than or equal to Bob’s budget.\n");
	}
	else
	{
		printf("(5) More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive.\n");
	}

	return 0;

}