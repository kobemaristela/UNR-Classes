//
// Created by Kobe on 10/16/2018.
//

#ifndef PROJ6_CAR_H
#define PROJ6_CAR_H

#include "Vehicle.h"

class Car : public Vehicle{
public:
    //Constructor
    Car();
    Car(float *lla);
    Car(const Car &copy);

    //Destructor
    virtual ~Car();

    //Operators
    Car& operator = (const Car &rhs);

    //Getters and Setters
    int getM_throttle() const;
    void setM_throttle(int m_throttle);

    //Method
    void drive(int throttle);
    virtual void Move(float *lla);

private:
    //Variables
    int m_throttle;

    //Methods
    virtual void serialize(ostream &os)const;

};


#endif //PROJ6_CAR_H
