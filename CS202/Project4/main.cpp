#include "Agency.h"
using namespace std;

int main()
{
    //Initialize variables
    Agency myAgency;
    int myChoice;
    bool myUpload = false;

    //User Input - Reuse
    do{
        cout << "1 - Enter the input file name\n";
        cout << "2 - Print data to terminal\n";
        cout << "3 - Print Total Sensors\n";
        cout << "4 - Rent: Most Expensive Car\n";
        cout << "5 - Exit Program\n";
        cout << endl;

        cout << "Enter your choice: ";
        cin >> myChoice;
        cout << endl;

        switch(myChoice)
        {
            case 1: {
                myAgency.readAllData();
                myUpload = true;
                break;
            }
            case 2: {
                if (myUpload)
                {

                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 3: {
                if (myUpload)
                {

                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 4: {
                if (myUpload)
                {

                } else {
                    cout << "Please input a file first." << endl << endl;
                }
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Invalid Option" << endl << endl;
            }
        }
    }while(true);
}

