//
// Created by Kobe on 10/9/2018.
//

#ifndef PROJ5_VEHICLE_H
#define PROJ5_VEHICLE_H

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Vehicle {
public:
    //Constructor
    Vehicle();
    Vehicle(const int vin, const float *lla);
    Vehicle(const Vehicle &copy);

    //Destructor
    ~Vehicle();

    //Getters
    const float *getM_lla() const;
    const int getM_vin() const;
    static int getIdgen();

    //Setters
    void setLla(const float *lla);
    void setIdgen();

    //Operators
    Vehicle& operator = (const Vehicle &rhs);
    friend ostream & operator<<(ostream &os, const Vehicle &copy);

    //Method
    void move(const float *lla);


protected:
    float m_lla[3];
    const int m_vin;

private:
    static int s_idgen;

};


#endif //PROJ5_VEHICLE_H
