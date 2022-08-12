//	Name: Circle.c
//	Purpose: Prints out computations to a circle's parameters
//	Author: Kobe Maristela

#include <stdio.h>

#define myPi 3.14f

int main(void)
{
	//Initialize variables
	int myRadius, myDiameter, myAreaS, myPerimeter;
	float  myCircumference, myAreaC, myDifference;

	//Text to the user
	printf("This Program computes values related to an inscribed circle.\n");

	//Input from the user
	printf("Enter the value of the radius: ");
	scanf("%d", &myRadius);

	//Calculations
	myDiameter = myRadius * 2;
	myCircumference = 2 * myPi * myRadius;
	myAreaC = myPi * myRadius * myRadius;
	myPerimeter = myDiameter * 4;
	myAreaS = myDiameter * myDiameter;
	myDifference = myAreaS - myAreaC;

	//Output to screen
	printf("The diameter of the circle is: %d\n", myDiameter );
	printf("The circumference of the circle is: %.3f\n", myCircumference);
	printf("The area of the circle is: %.3f\n", myAreaC);
	printf("The perimeter of the square is: %d\n", myPerimeter);
	printf("The area of the square is: %d\n", myAreaS);
	printf("The difference between the area of the square and the circle is: %.3f\n", myDifference);

	return 0;
}