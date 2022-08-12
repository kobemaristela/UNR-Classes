//
// Created by Kobe on 10/16/2018.
//

#include "Vehicle.h"

Vehicle::Vehicle() {
    cout << "Vehicle: Default-ctor" << endl;
}

Vehicle::Vehicle(float *lla){
    SetLLA(lla);
    cout << "Vehicle: Parametrized-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle &copy){
    SetLLA(copy.getM_lla());
    cout << "Vehicle: Copy-ctor" << endl;
}

Vehicle::~Vehicle(){
    cout << "Vehicle: Dtor" << endl;
}

const float *Vehicle::getM_lla() const {
    return m_lla;
}

void Vehicle::SetLLA(const float *lla){
    float *tempLla = m_lla;
    for (int x = 0; x < 3; x++) {
        *tempLla++ = *lla++;
    }
}

Vehicle& Vehicle::operator = (const Vehicle &rhs){
        SetLLA(rhs.getM_lla());
    cout << "Vehicle: Assignment";
    return *this;
}

ostream & operator<<(ostream &os, const Vehicle &copy){
    copy.serialize(os);
    return os;
}
void Vehicle::serialize(ostream &os)const{
    os << "Vehicle @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]";
}
