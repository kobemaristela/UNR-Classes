//
// Created by Kobe on 10/9/2018.
//

#include "Car.h"

Car::Car() {
    setM_plates("\0");
    setM_throttle(0);
    cout << "Car #" << m_vin << ": Default-ctor";
}

Car::Car(const char *plates, const int VIN, const float *LLA) : Vehicle(VIN,LLA){
    setM_plates(plates);
    setLla(LLA);

    cout << "Car #" << m_vin << ": Parametrized-ctor";
}

Car::Car(const Car &copy){
    setM_throttle(copy.getM_throttle());
    setM_plates(copy.getM_plates());
    setLla(copy.getM_lla());

    cout << "Car #" << m_vin << ": Copy-ctor";
}

Car::~Car() {
    cout << "Car #" << m_vin << ": Dtor";
}

const char *Car::getM_plates() const {
    return m_plates;
}

int Car::getM_throttle() const {
    return m_throttle;
}

void Car::setM_throttle(int m_throttle) {
    Car::m_throttle = m_throttle;
}
void Car::setM_plates(const char* source){
    strcpy(m_plates, source);
}

Car& Car::operator= (const Car &rhs) {
    setLla(rhs.getM_lla());
    setM_plates(rhs.getM_plates());
    setM_throttle(rhs.getM_throttle());
    cout << "Car #" << m_vin << ": Assignment" << endl;

    return *this;
}

void Car::drive(int value){
    setM_throttle(value);
}

void Car::move(const float *mylla){
    setLla(mylla);
    cout << "Car #" << m_vin << ": DRIVE to destination with throttle @ 75" << endl;
    drive(75);

}

ostream& operator<<(ostream &os, const Car &copy){
    os << "Car #" << copy.m_vin << " Plates: " << copy.getM_plates() << ", Throttle: " << copy.getM_throttle();
    os << " @ [" << copy.m_lla[0] << ", " << copy.m_lla[1] << ", " << copy.m_lla[2] << "]";

    return os;
}


