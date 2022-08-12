//
// Created by Kobe on 10/16/2018.
//

#include "Car.h"

Car::Car() : Vehicle(){
    setM_throttle(0);
    cout << "Car: Default-ctor" << endl;
}

Car::Car(float *lla) : Vehicle(lla) {
    SetLLA(lla);
    setM_throttle(0);

    cout << "Car: Parametrized-ctor" << endl;
}

Car::Car(const Car &copy) : Vehicle(copy){
    setM_throttle(copy.getM_throttle());
    SetLLA(copy.getM_lla());

    cout << "Car: Copy-ctor" << endl;
}

int Car::getM_throttle() const {
    return m_throttle;
}

void Car::setM_throttle(int m_throttle) {
    Car::m_throttle = m_throttle;
}

Car::~Car() {
    cout << "Car: Dtor" << endl;
}

Car& Car::operator = (const Car &rhs){
    SetLLA(rhs.getM_lla());
    setM_throttle(rhs.getM_throttle());

    cout << "Car: Assignment" << endl;
    return *this;
}

void Car::drive(int throttle){
    setM_throttle(throttle);
}

void Car::Move(float *lla){

    cout << "Car: DRIVE to destination, with throttle @ 75" << endl;
    drive(75);
    SetLLA(lla);
}

void Car::serialize(ostream &os) const{
    os << "Car: Throttle: " << getM_throttle() << " @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]";
}
