// Name: calc.c
// Purpose: Calculator
// Author: Kobe Maristela

#include <stdio.h>
#include <math.h>

int main(void)
{
	int myChoice, myExit;
	int myToggle = 2;
	int myOne, myTwo, myValue;
	double myNOne, myNTwo, myNValue;

	printf("This program implements a calculator.\n");

	while (1)
	{
			printf("Options:\n");
			printf("1 - addition\n");
			printf("2 - subtraction\n");
			printf("3 - multiplication\n");
			printf("4 - division\n");
			printf("5 - toggle calculator type\n");
			printf("6 - exit program\n");
			printf("Please enter your option: \n");
			scanf("%d", &myChoice);

			switch (myChoice)
			{
				case 1: //Addition
					
						if (myToggle % 2 == 0) //Double
						{
							printf("Enter first term: ");
							scanf("%lf", &myNOne);
							printf("Enter second term: ");
							scanf("%lf", &myNTwo);

							myNValue = myNOne + myNTwo;
							printf("The sum is: %.15lf\n", myNValue);
						}
						else
						{
							printf("Enter first term: ");
							scanf("%d", &myOne);
							printf("Enter second term: ");
							scanf("%d", &myTwo);

							myValue = myOne + myTwo;
							printf("The sum is: %d\n", myValue);
						}
						break;

				case 2: //Subtraction
					
						if (myToggle % 2 == 0) //Double
						{
							printf("Enter first term: ");
							scanf("%lf", &myNOne);
							printf("Enter second term: ");
							scanf("%lf", &myNTwo);

							myNValue = myNOne - myNTwo;
							printf("The difference is: %.15lf\n", myNValue);
						}
						else
						{
							printf("Enter first term: ");
							scanf("%d", &myOne);
							printf("Enter second term: ");
							scanf("%d", &myTwo);

							myValue = myOne - myTwo;
							printf("The difference is: %d\n", myValue);
						}
						break;
					
				case 3: //Multiplication
					
						if (myToggle % 2 == 0) //Double
						{
							printf("Enter first term: ");
							scanf("%lf", &myNOne);
							printf("Enter second term: ");
							scanf("%lf", &myNTwo);

							myNValue = myNOne * myNTwo;
							printf("The product is: %.15lf\n", myNValue);
						}
						else
						{
							printf("Enter first term: ");
							scanf("%d", &myOne);
							printf("Enter second term: ");
							scanf("%d", &myTwo);

							myValue = myOne * myTwo;
							printf("The product is: %d\n", myValue);
						}
						break;
					
				case 4: //Division
					
						if (myToggle % 2 == 0) //Double
						{
							
								printf("Enter first term: ");
								scanf("%lf", &myNOne);
								printf("Enter second term: ");
								scanf("%lf", &myNTwo);

								if(myNTwo == 0)
									{
										printf("Cannot divide by zero!\n");
									}
								else
									{
										myNValue = myNOne / myNTwo;
										printf("The quotient is: %.15lf\n", myNValue);
										break;
									}

							
						}
						else
						{
							printf("Enter first term: ");
							scanf("%d", &myOne);
							printf("Enter second term: ");
							scanf("%d", &myTwo);

							if(myTwo == 0)
									{
										printf("Cannot divide by zero!\n");
										break;
									}
								else
									{
										myValue = myOne / myTwo;
										printf("The quotient is: %d\n", myValue);
										break;
									}

						}
						break;
					
				case 5: //Toggle
						++myToggle;
						if(myToggle % 2 == 0)
						{
							printf("Calculator now works with doubles.\n");
						}
						else
						{
							printf("Calculator now works with integers.\n");
						}
						break;
					
				case 6:
					
						return 0;
					
				default:

						printf("Invalid Option.\n");
						break;
		}
	}
}