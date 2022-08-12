#ifndef PROJ4_AGENCY_H
#define PROJ4_AGENCY_H
#include "Car.h"

class Agency {
public:
    //Constructor
    Agency();

    //Getters
    const char *getM_name() const;
    int getM_zipcode() const;

    //Setters
    void setM_zipcode(int m_zipcode);
    void setM_name(const char* source);

    //Operators
    Car& operator[](int index);

    //Functions
    void readAllData();
    void printAllData();
    void printTotalSensors();
    void printMostExpensive();

private:
    char m_name[256];
    int m_zipcode;
    Car m_inventory[5];
};


#endif //PROJ4_AGENCY_H