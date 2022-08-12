//Name: proj1.cpp
//Purpose: Sort names
//Author: Kobe Maristela

#include <iostream>
#include <fstream>
using namespace std;

void myStringCopy(char destination [], const char source []);
int myStringLength(const char str []);
int myStringCompare(const char str1 [], const char str2 []);
void mySwap(char myList1 [], char myList2 []);
void myNumSwap(int& myNum1, int&  myNum2);

int main()
{
	//Intializing Variables
	fstream myInStream;
	ofstream myOutStream;

	char InputName[256];
	char OutLengthName[256];
	char OutAlphaName[256];
	int myOrder[10];

	//Original Arrays
	char myOArray[10][9];
	int myONumArray[10];

 	//Stores the names
	char myArray[10][9];
	//Stores the numbers
	int myNumArray[10]; 

	//User Input
	cout << "Please enter the file's input name:" << endl;
	cin >> InputName;
	cout << "Please enter the file's output name for the sorted by length names:" << endl;
	cin >> OutLengthName;
	cout << "Please enter the file's output name for the alphabetically sorted names :" << endl;
	cin >> OutAlphaName;

	myInStream.open(InputName); //Opens file

	for (int i = 0; i < 10; i++)
	{
		myInStream >> myOArray[i];
		myNumArray[i] = i;
		myONumArray[i] = i;
	}

	//Copies Array to Original template
	for (int i = 0; i < 10; i++)
	{
	 	myStringCopy(myArray[i], myOArray[i]);

	}

	myInStream.close();//Closes file

	//Prints out the Orignal Data to terminal
	cout << endl;
	cout << "Unsorted Data (Original Input Order and Name)" << endl;
	cout << "=============================================" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myNumArray[i] << " " << myArray[i] << endl;
	}

	//Prints out Sort by Length to terminal
	cout << endl;
	cout << "Sorted-by-Length Data (Original Input Order and Name)" << endl;
	cout << "=====================================================" << endl;
	for(int x = 0; x < 10; x++)
	{
		myOrder[x] = myStringLength(myArray[x]);
	}
        
	for(int x = 1; x < 10; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (myOrder[y] > myOrder[y + 1])   //OR myStringLength(myArray[y]) > myStringLength(myArray[y + 1]
			{
				//Swaps numbers
				myNumSwap(myNumArray[y], myNumArray[y + 1]);
				//Switches Order for list
				myNumSwap(myOrder[y], myOrder[y + 1]);
				//Switches names array order
				mySwap(myArray[y], myArray[y + 1]);
			}
		}	
	}


	for(int x = 0; x < 10; x++)
	{
		cout << myNumArray[x] << " " << myArray[x] << endl;
	}

	//Writes to File for Sort by Length
	myOutStream.open(OutLengthName);//Opens file
	myOutStream << "Unsorted Data (Original Input Order and Name)" << endl;
	myOutStream << "=============================================" << endl;
	for (int i = 0; i < 10; i++)
	{
		myOutStream << myONumArray[i] << " " << myOArray[i] << endl;
	}

	myOutStream << endl;
	myOutStream << "Sorted-by-Length Data (Original Input Order and Name)" << endl;
	myOutStream << "=====================================================" << endl;

	for(int x = 0; x < 10; x++)
	{
		myOutStream << myNumArray[x] << " " << myArray[x] << endl;
	}

	myOutStream.close();

	//Prints out alphabet data to terminal
	cout << endl;
	cout << "Alphabetcially Sorted Data (Original Input Order and Name)" << endl;
	cout << "==========================================================" << endl;

	for(int x = 1; x < 10; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (myStringCompare(myArray[y],myArray[y + 1]) == 1)
			{
				mySwap(myArray[y], myArray[y + 1]);
				myNumSwap(myNumArray[y], myNumArray[y + 1]);
			}
		}
	}

	for(int x = 0; x < 10; x++)
	{
		cout << myNumArray[x] << " " << myArray[x] << endl;
	}

//Write to file alphabetically sorted names
myOutStream.open(OutAlphaName);
myOutStream << "Unsorted Data (Original Input Order and Name)" << endl;
myOutStream << "=============================================" << endl;
for (int i = 0; i < 10; i++)
	{
		myOutStream << myONumArray[i] << " " << myOArray[i] << endl;
	}

myOutStream << endl;
myOutStream << "Alphabetcially Sorted Data (Original Input Order and Name)" << endl;
myOutStream << "==========================================================" << endl;
for(int x = 0; x < 10; x++)
	{
		myOutStream << myNumArray[x] << " " << myArray[x] << endl;
	}

myOutStream.close();

	return 0;
}

//Swaps the integer values within each array
void myNumSwap(int& myNum1, int& myNum2)
{
	int listTemp;
	listTemp = myNum1;
	myNum1 = myNum2;
	myNum2 = listTemp;
}

//Swaps the strings within each array
void mySwap(char myList1 [], char myList2 [])
{
	char nameTemp[9];
	myStringCopy(nameTemp, myList1);
	myStringCopy(myList1, myList2);
	myStringCopy(myList2, nameTemp);
}

/**Copies characters from source to destination 
until a NULL-character '\0' is found in source,
then it NULL-terminates destination too, and returns**/
void myStringCopy(char destination [], const char source [])
{
	int myX;
	destination[0] = '\0';
	for(myX = 0; source[myX] != '\0'; myX++)
	{
		destination[myX] = source[myX];
	}

	destination[myX] = '\0';
}

/**Counts characters in array str until a 
NULL-character '\0' is found, then it returns 
that number excluding the '\0' one **/
int myStringLength(const char str [])
{
	int myCount = 0;
	while(str[myCount] != '\0')
	{
		myCount++;
	}

	return myCount;

}

/**Returns 0 when the strings match, i.e. their characters
are equal one-by-one until a NULL-character '\0' is found
in both strings and at the same position as well **/
/** returns a value < -1 if the first character that does
not match has a lower value in str1 than in str2 **/
/** returns a value > 1 if the first character that does
 not match has a higher value in str1 than in str2 **/
int myStringCompare(const char str1 [], const char str2 [])
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