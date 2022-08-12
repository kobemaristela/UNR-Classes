//
// Created by Kobe on 10/16/2018.
//

#ifndef PROJ6_VEHICLE_H
#define PROJ6_VEHICLE_H

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Vehicle {
public:
    //Constructor
    Vehicle();
    Vehicle(float *lla);
    Vehicle(const Vehicle &copy);

    //Destructor
    virtual ~Vehicle();

    //Operators
    Vehicle& operator = (const Vehicle &rhs);
    friend ostream & operator<<(ostream &os, const Vehicle &copy);

    //Getters and Setters
    const float *getM_lla() const;
    void SetLLA(const float *lla);

    //Methods
    virtual void Move(float *lla) = 0;

protected:
    //Variables
    float m_lla[3];

private:
    //Methods
    virtual void serialize(ostream &os)const;
};


#endif //PROJ6_VEHICLE_H
