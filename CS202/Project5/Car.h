//
// Created by Kobe on 10/9/2018.
//

#ifndef PROJ5_CAR_H
#define PROJ5_CAR_H

#include "Vehicle.h"

class Car : public Vehicle{
public:
    //Constructor
    Car();
    Car(const char *m_plates, int VIN,const float *LLA);
    Car(const Car &copy);

    //Destructor
    virtual ~Car();

    //Getters
    const char *getM_plates() const;
    int getM_throttle() const;

    //Setters
    void setM_throttle(int m_throttle);
    void setM_plates(const char* source);

    //Operators
    Car& operator= (const Car &rhs);
    friend ostream & operator<<(ostream &os, const Car &copy);

    //Method
    void drive(int value);
    void move(const float *mylla);


private:
    char m_plates[256];
    int m_throttle;


};


#endif //PROJ5_CAR_H
