
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
    for(int x = 0; x < 5; x++)
    {
        //Initialize Local Variables
        int tempYear;
        char tempMake[256];
        char tempModel[256];
        float tempPrice;
        bool tempAvailable;
        char tempType[256];

        //Read File
        myInstream >> tempYear;
        myInstream >> tempMake;
        myInstream >> tempModel;
        myInstream >> tempPrice;

        //Reads within the brackets
        myInstream.getline(tempType, 256, '{');
        myInstream >> noskipws;
        myInstream.getline(tempType, 256, '}');
        myInstream >> skipws;

        //Operator
        //*ptrCar = *ptrCar + tempSensor;





        ptrCar->getM_year();

    }

}
