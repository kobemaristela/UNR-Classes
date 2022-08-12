
#include "Agency.h"

Agency::Agency() {
    setM_name(" ");
    setM_zipcode(0);
}

const char *Agency::getM_name() const {
    return m_name;
}

int Agency::getM_zipcode() const {
    return m_zipcode;
}

void Agency::setM_zipcode(int m_zipcode) {
    Agency::m_zipcode = m_zipcode;
}

void Agency::setM_name(const char* source){
    myStringCopy(m_name, source);
}

Car& Agency::operator[](int index) {
    return m_inventory[index];
}

void Agency::readAllData(){
    //Initialize variables
    fstream myInstream;
    char inputName[256];

    cout << "Please enter the file's input name:" << endl;
    cin >> inputName;
    cout << endl;

    myInstream.open(inputName); //Opens File
    myInstream >> m_name;
    myInstream >> m_zipcode;

    Car *ptrCar = m_inventory;
    //Read in car files
    for(int x = 0; x < 5; x++, ptrCar++)
    {
        //Initialize Local Variables
        int tempYear;
        char tempMake[256];
        char tempModel[256];
        float tempPrice;
        bool tempAvailable;
        char tempType[256];
        char tempOwner[256];

        //Read File
        myInstream >> tempYear;
        myInstream >> tempMake;
        myInstream >> tempModel;
        myInstream >> tempPrice;

        //Sets to file
        ptrCar->setM_year(tempYear);
        ptrCar->setM_make(tempMake);
        ptrCar->setM_model(tempModel);
        ptrCar->setM_baseprice(tempPrice);

        //Reads within the brackets
        myInstream.getline(tempType, 256, '{');
        myInstream.getline(tempType, 256, '}');

        char oneType[256];
        char *ptrOneType = oneType;
        char *ptrType = tempType;
        for(; true;ptrType++ )
        {
            if(*ptrType != ' ' && *ptrType != '\0' )
            {
                *ptrOneType = *ptrType;
                ptrOneType++;
            }
            else {
                *ptrOneType = '\0';
                ptrOneType = oneType;
                Sensor tempSensor(oneType);

                //cout << "Result: '" << oneType << "'" << endl;
                *ptrCar + tempSensor;
            }
            if(*ptrType == '\0')
            {
                //cout << "New Car" << endl;
                break;
            }
        }

        //Continues reading
        myInstream >> tempAvailable;
        ptrCar->setM_available(tempAvailable);

        //Owner
        if(!tempAvailable)
        {
            myInstream >> tempOwner;
            ptrCar->setM_owner(tempOwner);
        }
        ptrCar->updatePrice();
    }

    //Closes file
    myInstream.close();
}

void Agency::printAllData() {
    //Prints Agency
    cout << getM_name() << " " << getM_zipcode() << endl;

    Car *ptrCar = m_inventory;
    //Loop
    for (int x = 0; x < 5; x++, ptrCar++) {
        ptrCar->print();
    }
    cout << endl;
}

void Agency::printTotalSensors() {
    Car *ptrCar = m_inventory;
    cout << "Total Sensors: " << ptrCar->getSensorCount() << endl << endl;
}

void Agency::printMostExpensive() {
    Car *ptrCar = m_inventory;
    float mostExpensive = 0.0;
    int count = 0;
    for (int x = 0; x < 5; x++, ptrCar++) {
        if(ptrCar->getM_finalprice() > mostExpensive) {
            mostExpensive = ptrCar->getM_finalprice();
            count = x;
        }
    }
    ptrCar = m_inventory;
    int choice;
    char name[256];
    cout << (ptrCar+count)->getM_year() << " " << (ptrCar+count)->getM_make() << " " << (ptrCar+count)->getM_model() << endl;
    cout << "Would you want to rent? (1 - Yes, 0 - No)" << endl;
    cin >> choice;
    if(choice){
        cout << "Whats your name?" << endl;
        cin >> name;
        (ptrCar+count)->setM_available(false);
        (ptrCar+count)->setM_owner(name);
        cout << "Car is rented!" << endl;
    }
}