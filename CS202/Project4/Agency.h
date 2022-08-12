#ifndef PROJECT4_AGENCY_H
#define PROJECT4_AGENCY_H
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

    //Functions
    void readAllData();

private:
    char m_name[256];
    int m_zipcode;
    Car m_inventory[5];
};


#endif //PROJECT4_AGENCY_H
