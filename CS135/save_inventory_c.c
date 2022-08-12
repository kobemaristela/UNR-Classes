//Name: save_inventory
//Purpose: Saves inventory to a file
//Author: Kobe Maristela

#include <stdio.h>
#include <stdlib.h>

#define myFile "inventory.txt"

int main(void)
{
	//Initialize variables
	FILE *fp;

	int myArray[10] = {0};
	int myPart = 0, myQuantity = 0;
	double myPrice = 0.0;

	fp = fopen(myFile, "wb+");

	printf("This program stores a business inventory.\n");
	while(1)
	{
		printf("Please enter item data (part number, quatity, price): ");
		scanf("%d, %d, %lf", &myPart, &myQuantity, &myPrice);


		if (myPart == 0 || myQuantity == 0 || myPrice == 0)
		{
			break;
		}

		if (myArray[myPart]++ > 0)
		{
			printf("This item has been entered before.\n");
		}
		else
		{
			fwrite(&myPart, sizeof(int), 1, fp);
			fwrite(&myQuantity, sizeof(int), 1, fp);
			fwrite(&myPrice, sizeof(double), 1, fp);
		}
	}

	printf("Thank you. inventory stored in file inventory.txt.\n");

	fclose(fp);
	return 0;
}