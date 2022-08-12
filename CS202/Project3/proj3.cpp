#include <iostream>
#include <fstream>
#include "RentalCar.h"
using namespace std;

//My Functions
void myFileName(struct RentalAgency *pAgency);
void printTerminal(struct RentalAgency *pAgency);
void estimateCost(struct RentalAgency *pAgency);
void mostExpensive(struct RentalAgency *pAgency);
void printAvailable(struct RentalAgency *pAgency);

//String Functions
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);

struct RentalAgency {
    char name[256];
    int zipcode[5] = {0};
    RentalCar inventory[5];
};

int main()
{
    //Initialize variables
    RentalAgency myAgency[3];

    int myChoice;
    bool myUpload = false;

    //User Input - Reuse
    do{
        cout << "1 - Enter the input file name\n";
        cout << "2 - Print data to terminal\n";
        cout << "3 - Car Rental Estimate\n";
        cout << "4 - Most Expensive Car\n";
        cout << "5 - Available Cars\n";
        cout << "6 - Exit Program\n";
        cout << endl;

        cout << "Enter your choice: ";
        cin >> myChoice;
        cout << endl;

        switch(myChoice)
        {
            case 1: {
                myFileName(myAgency);
                myUpload = true;
                break;
            }
            case 2: {
                if (myUpload)
                {
                    printTerminal(myAgency);
                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 3: {
                if (myUpload)
                {
                    estimateCost(myAgency);
                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 4: {
                if (myUpload)
                {
                    mostExpensive(myAgency);
                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 5: {
                if (myUpload) {
                    printAvailable(myAgency);
                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid Option" << endl << endl;
            }
        }
    }while(true);
}

//print available cars
void printAvailable(struct RentalAgency *pAgency)
{
    //Initialize variables
    ofstream myOutStream;
    char outputName[256];

    cout << "Please enter the file's output name:" << endl;
    cin >> outputName;
    cout << endl;

    myOutStream.open(outputName);//Creates output file

    //Initialize variables
    RentalCar *pAgencyCar;
    int *pZipcode;

    for(int x = 0; x < 3; x++)
    {
        pAgencyCar = pAgency->inventory;
        pZipcode = pAgency->zipcode;


        myOutStream << pAgency->name << " ";
        //print zipcode
        for (int i = 0; i < 5; i++)
        {
            myOutStream << *pZipcode;
            pZipcode++;
        }
        myOutStream << "\r\n";

        //print cars
        for (int j = 0; j < 5; j++)
        {
            if(pAgencyCar->getM_available())
            {
                myOutStream << pAgencyCar->getM_year() << " ";
                myOutStream << pAgencyCar->getM_make() << " ";
                myOutStream << pAgencyCar->getM_model() << ", $";
                myOutStream << pAgencyCar->getM_price() << " per day, Available: ";
                myOutStream << boolalpha << pAgencyCar->getM_available();
                myOutStream << "\r\n";
            }
            pAgencyCar++;
        }
        myOutStream << "\r\n";
        pAgency++;
    }

    myOutStream << "\r\n";
}

//Finds most expensive car
void mostExpensive(struct RentalAgency *pAgency)
{
    //intialize variables
    RentalAgency* myTempAgency;
    myTempAgency = pAgency;
    RentalCar *pAgencyCar;
    pAgencyCar = pAgency->inventory;

    int myAgency = 0, myCar = 0;
    float myPrice, highestPrice = 0.0;

    for (int i = 0; i < 3; i++)
    {
        pAgencyCar = pAgency->inventory;
        for (int j = 0; j < 5; j++)
        {
            myPrice = pAgencyCar->getM_price();
            if(myPrice > highestPrice)
            {
                highestPrice = myPrice;
                myAgency = i;
                myCar = j;
            }
            pAgencyCar++;
        }
        pAgency++;
    }
    pAgency = myTempAgency;
    pAgency += myAgency;
    pAgencyCar = pAgency->inventory;
    pAgencyCar += myCar;


    cout << "The most expensive car is " << pAgencyCar->getM_year() << " " << pAgencyCar->getM_make() << " " << pAgencyCar->getM_model();
    cout << endl << endl;
}


//Estimate car cost
void estimateCost(struct RentalAgency *pAgency)
{
    //Initialize variables
    int myAgency, myCar, myDays;
    RentalCar *pAgencyCar;
    pAgencyCar = pAgency->inventory;

    cout << "Which Agency would you like to rent your car? ";
    cout << "(0-" << pAgency->name << ", ";
    cout << "1-" << (pAgency+1)->name << ", ";
    cout << "2-" << (pAgency+2)->name << ")\n";
    cin >> myAgency;
    cout << endl;
    pAgency += myAgency;

    pAgencyCar = pAgency->inventory;

    cout << "Which car would you like to rent? ";
    cout << "(0-" << pAgencyCar->getM_make() << " " << pAgencyCar->getM_model() << ", ";
    cout << "1-" << (pAgencyCar+1)->getM_make() << " " << (pAgencyCar+1)->getM_model() << ", ";
    cout << "2-" << (pAgencyCar+2)->getM_make() << " " << (pAgencyCar+2)->getM_model() << ", ";
    cout << "3-" << (pAgencyCar+3)->getM_make() << " " << (pAgencyCar+3)->getM_model() << ", ";
    cout << "4-" << (pAgencyCar+4)->getM_make() << " " << (pAgencyCar+4)->getM_model() << ")\n";
    cin >> myCar;
    cout << endl;
    pAgencyCar += myCar;

    cout << "How many days do you want to rent the car?\n";
    cin >> myDays;
    cout << endl;

    cout << "Total Estimate Cost: $" << pAgencyCar->estimateCost(myDays) << endl << endl;
}

//Prints to terminal ALL data
void printTerminal(struct RentalAgency *pAgency)
{
    //Initialize variables
    RentalCar *pAgencyCar;
    int *pZipcode;

    for(int x = 0; x < 3; x++)
    {
        pAgencyCar = pAgency->inventory;
        pZipcode = pAgency->zipcode;


        cout << pAgency->name << " ";
        //print zipcode
        for (int i = 0; i < 5; i++)
        {
            cout << *pZipcode;
            pZipcode++;
        }
        cout << endl;

        //print cars
        for (int j = 0; j < 5; j++)
        {
            pAgencyCar->print();
            pAgencyCar++;
        }
        cout << endl;
        pAgency++;
    }

    cout << endl;
}


//Inputs from file
void myFileName(struct RentalAgency *pAgency)
{
    //Intialize variables
    fstream myInStream;
    char inputName[256];
    RentalCar *pAgencyCar;
    int *pZipcode;

    //Local variables
    int myZipcode;

    cout << "Please enter the file's input name:" << endl;
    cin >> inputName;
    cout << endl;

    myInStream.open(inputName); //Opens File
    for(int x = 0; x < 3; x++)
    {
        //Initialize variables
        myInStream >> pAgency->name;



        //Input zipcode in array
        myInStream >> myZipcode;
        pZipcode = pAgency->zipcode;
        pZipcode += 4;

        for (int x = 0; x < 5 ; x++)
        {
            *pZipcode = myZipcode % 10;
            myZipcode = myZipcode / 10;
            pZipcode--;
        }

        pAgencyCar = pAgency->inventory;
        //Set Cars
        for (int y = 0; y < 5; y++)
        {
            //Initialize Local Variables
            int tempYear;
            char tempModel[256];
            char tempMake[256];
            float tempPrice;
            bool tempAvailable;

            //Read file
            myInStream >> tempYear;
            myInStream >> tempMake;
            myInStream >> tempModel;
            myInStream >> tempPrice;
            myInStream >> tempAvailable;


            //Setting values
            pAgencyCar->setM_year(tempYear);
            pAgencyCar->setM_model(tempModel);
            pAgencyCar->setM_make(tempMake);
            pAgencyCar->setM_price(tempPrice);
            pAgencyCar->setM_available(tempAvailable);

            pAgencyCar++; //increment to next car
        }
        pAgency++;
    }
    myInStream.close();
}

/** Counts characters in str array until a NULL-character '\0' is
found, then it returns that number excluding the '\0' one **/
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