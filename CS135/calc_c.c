// Name: calc_c.c
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
			printf("5 - exp(x)\n");
			printf("6 - log(x)\n");
			printf("7 - toggle calculator type\n");
			printf("8 - exit program\n");
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
							while(1)
							{
								printf("Enter first term: ");
								scanf("%lf", &myNOne);
								printf("Enter second term: ");
								scanf("%lf", &myNTwo);

								if(myNTwo == 0)
									{
										printf("Cannot divide by zero!\n");
										break;
									}
								else
									{
										myNValue = myNOne / myNTwo;
										printf("The quotient is: %.15lf\n", myNValue);
										break;
									}

							}
						}
						else
						{
							while(1)
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
						}
						break;
				case 5: //Exponents
						if (myToggle % 2 == 0) //Double
						{
							printf("Enter term: ");
							scanf("%lf", &myNValue);

							printf("The result of exp(%.15lf) is: %.15lf\n", myNValue, exp(myNValue) );
						}
						else
						{
							printf("Cannot calculate with integers.\n");
						}
						break;

				case 6: //Logs
						if (myToggle % 2 == 0) //Double
						{
							printf("Enter term: ");
							scanf("%lf", &myNValue);
							if (myNValue > 0)
							{
								printf("The result of log(%.15lf) is: %.15lf\n", myNValue, log(myNValue) );
							}
							else
							{
								printf("Cannot take the log of that number!\n");
							}
						}
						else
						{
							printf("Cannot calculate with integers.\n");
						}
						break;
				case 7: //Toggle
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
					
				case 8:
					
						return 0;
					
				default:

						printf("Invalid Option.\n");
						break;
		}
	}
}