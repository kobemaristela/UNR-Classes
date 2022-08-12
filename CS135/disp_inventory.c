//Name: disp_inventory
//Purpose: Reads inventory to a file
//Author: Kobe Maristela

#include <stdio.h>
#include <stdlib.h>

#define myFile "inventory.txt"

int main(void)
{
	//Initialize variables
	FILE *fp;

	int myPart, myQuantity;
	double myPrice;

	fp = fopen(myFile, "rb+");
	printf("Below are the items in your inventory.\n");
	printf("\n");
	printf("Part#\tQuantity\tItem Price\n");

	while(fread(&myPart, sizeof(int), 1, fp) && fread(&myQuantity, sizeof(int), 1, fp) && fread(&myPrice, sizeof(double), 1, fp)  == 1)
	{
		printf("%5d\t%8d\t$%9.2lf\n", myPart, myQuantity, myPrice);
	}

	fclose(fp);

}