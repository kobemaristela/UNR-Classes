//Name: proj2.cpp
//Purpose: Car Rental - implement use of structures
//Author: Kobe Maristela

#include <iostream>
#include <fstream>
using namespace std;

size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
//My Functions
void myFileName(struct RentalCar myCars[]);
void printTerminal(struct RentalCar myCars[]);
void printOutFile(struct RentalCar myCars[]);
void sortCars(struct RentalCar myCars[]);
void estimateCost(struct RentalCar myCars[]);
void rentCar(struct RentalCar myCars[]);

//Rental car structure
struct RentalCar
{
	int year;
	char make[10];
	char model[10];
	float price;
	bool available;
};

int main()
{
	//Intializing Variables
	int myChoice;
	bool myUpload = false;
	RentalCar myCars[5];

	//User Input
	do
	{
		cout << "1 - Enter the input file name" << endl;
		cout << "2 - Print data to terminal" << endl;
		cout << "3 - Print data to output file" << endl;
		cout << "4 - Sorts Cars (Ascending Price)" << endl;
		cout << "5 - Car Rental Estimate and Availability" << endl;
		cout << "6 - Rent Car" << endl;
		cout << "7 - Exit Program" << endl << endl;

		cout << "Enter your choice: ";
		cin >> myChoice;
		cout << endl;

		//User Menu
		switch(myChoice)
		{
			case 1:
			{
				myFileName(myCars);
				myUpload = true;
				break;
			}
			case 2:
			{
				if (myUpload == true)
				{
					printTerminal(myCars);
				}
				else
				{
					cout << "Please input a file first." << endl << endl;
				}
				break;
			}
			case 3:
			{
				if (myUpload == true)
				{
					printOutFile(myCars);
				}
				else
				{
					cout << "Please input a file first." << endl << endl;
				}
				break;
			}
			case 4:
			{
				if (myUpload == true)
				{
					sortCars(myCars);
				}
				else
				{
					cout << "Please input a file first." << endl << endl;
				}
				break;
			}
			case 5:
			{
				if (myUpload == true)
				{
					estimateCost(myCars);
				}
				else
				{
					cout << "Please input a file first." << endl << endl;
				}
				break;
			}
			case 6:
			{
				if (myUpload == true)
				{
					rentCar(myCars);
				}
				else
				{
					cout << "Please input a file first." << endl << endl;
				}
				break;
			}
			case 7:
			{
				return 0;
			}
			default:
			{
				cout << "Invalid Option" << endl << endl;
			}
		}

	}while (1);
}

//Rent Car
void rentCar(struct RentalCar myCars[])
{
	//Initialize variables
	int myCar, myDays;

	cout << "Which car do you want to rent? (Provide index number)" << endl;
	cin >> myCar;
	cout << "How many days do you want to rent the car?" << endl;
	cin >> myDays;

	cout << endl;

	if (myCars[myCar].available == 0)
	{
		cout << "Warning: This car is not available to rent!" << endl << endl;
	}
	else
	{
		myCars[myCar].available = 0;
		cout << "Success: You have rented the ";
		cout << myCars[myCar].year << " " << myCars[myCar].make << " " << myCars[myCar].model;
		cout << " for $" << myDays * myCars[myCar].price << endl << endl;
	}
}

//Prints estimate cost
void estimateCost(struct RentalCar myCars[])
{
	//Intialize variables
	RentalCar myOrder[5];
	int myDays;
	int myCount = 0;

	cout << "How many days do you want to rent the car?" << endl;
	cin >> myDays;
	cout << endl;

	for (int x = 0; x < 5; x++)
	{
		if (myCars[x].available == 1)
		{
			myOrder[myCount++] = myCars[x];
		}
	}
	sortCars(myOrder);

	for (int i = 0; i < myCount; i++)
	{
		cout << myOrder[i].year << " ";
		cout << myOrder[i].make << " ";
		cout << myOrder[i].model << ", ";
		cout << "Total Cost: $";
		cout << (myDays * myOrder[i].price) << endl;
	}
	cout << endl;
}

//Sorts the cars by ascending price
void sortCars(struct RentalCar myCars[])
{
	//Initialize variables
	RentalCar myTemp;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4-x; y++)
		{
			if (myCars[y].price > myCars[y + 1].price)
			{
				myTemp = myCars[y];
				myCars[y] = myCars[y + 1];
				myCars[y + 1] = myTemp;
			}
		}
	}
}

//Prints data to output file
void printOutFile(struct RentalCar myCars[])
{
	//Initialize variables
	ofstream myOutStream;
	char outputName[256];

	cout << "Please enter the file's output name:" << endl;
	cin >> outputName;
	cout << endl;

	myOutStream.open(outputName);//Creates output file

	for (int x = 0; x < 5; x++)
	{
		myOutStream << myCars[x].year << " ";
		myOutStream << myCars[x].make << " ";
		myOutStream << myCars[x].model << ", ";
		myOutStream << "$" << myCars[x].price << " per day, ";
		myOutStream << "Available: ";
		myOutStream << boolalpha << myCars[x].available << endl;
	}
	myOutStream << endl;

	myOutStream.close();

}

//Prints data set to terminal
void printTerminal(struct RentalCar myCars[])
{
	for (int x = 0; x < 5; x++)
	{
		cout << myCars[x].year << " ";
		cout << myCars[x].make << " ";
		cout << myCars[x].model << ", ";
		cout << "$" << myCars[x].price << " per day, ";
		cout << "Available: ";
		cout << boolalpha << myCars[x].available << endl;
	}
	cout << endl;
}

//Stores data file into array of structs
void myFileName(struct RentalCar myCars[])
{
	//Initialize variable
	fstream myInStream;
	char inputName[256];

	cout << "Please enter the file's input name:" << endl;
	cin >> inputName;
	cout << endl;
	
	myInStream.open(inputName); //Opens file

	for (int x = 0; x < 5; x++)
	{
		myInStream >> myCars[x].year;
		myInStream >> myCars[x].make;
		myInStream >> myCars[x].model;
		myInStream >> myCars[x].price;
		myInStream >> myCars[x].available;
	}
	myInStream.close();//Closes file
}


/** Counts characters in str array until a NULL-character '\0' is 
found, then it returns that number excluding the '\0' one **?
/** The return type size_t represents an unsigned integral number
large enough to contain the maximum possible number of a storage
size that can appear on a target architecture **/
size_t myStringLength(const char * str)
{
	size_t myCount = 0;
	while(str[myCount] != '\0')
	{
		myCount++;
	}

	return myCount;
}

/** Returns 0 when the C-strings match, i.e. their characters are 
equal one-by-one until a NULL-character '\0' is found in both 
strings and at the same position as well **/
/** Returns a value < -1 if the first character that does not 
match has a lower value in str1 than in str2 **/
/** Returns a value > 1 if the first character that does not match 
has a higher value in str1 than in str2 **/
int myStringCompare(const char * str1, const char * str2)
{
	int myX;
	for(myX = 0; (myX <= myStringLength(str1)) || (myX <= myStringLength(str2)); myX++)
	{
		if (str1[myX] != str2[myX])
		{
			if(str1[myX] < str2[myX])
			{
				return -1;
			}
			else if (str1[myX] > str2[myX])
			{
				return 1;
			}
		}
	}

	if ((str1[myX + 1] && str2[myX + 1]) == '\0')
	{
		return 0;
	}
}

/** Copies characters from source to destination array until a 
NULL-character '\0' is found in source, then it NULL-terminates 
destination too **/
/** Returns a pointer to the destination array **/
char *myStringCopy(char * destination, const char * source)
{
	int myX;
	destination[0] = '\0';
	for(myX = 0; source[myX] != '\0'; myX++)
	{
		destination[myX] = source[myX];
	}

	destination[myX] = '\0';

	return destination;
}

/** Appends the content of source to the destination array **/
/** This means that the NULL-terminator of destination is 
overwritten by the first character of source and a NULL-character 
'\0' is appended at the end of the concatenated Cstring in 
destination **/
/**  Returns a pointer to the destination array **/
char * myStringCat(char * destination, const char * source)
{
	char* tempFinal = destination;

	while(*destination != '\0')
	{
		destination++;
	}

	do
	{
		*destination++ = *source++;
	}while(*source != '\0');

	*destination = '\0';
	
	return tempFinal;
}

