//
// Created by Kobe on 10/9/2018.
//

#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(s_idgen++){
    float dLla[3] = {0,0,0};
    setLla(dLla);
    cout << "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

Vehicle::Vehicle(const int vin, const float *lla) : m_vin(vin < s_idgen ? s_idgen++ : vin){
    if (vin >= s_idgen)
    {
        s_idgen = vin + 1;
    }
    setLla(lla);
    cout << "Vehicle #" << m_vin << ": Parametrized-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle &copy) : m_vin(s_idgen++){
    setLla(copy.getM_lla());
    cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle #" << m_vin << ": Dtor" << endl;
}

const float *Vehicle::getM_lla() const {
    return m_lla;
}

const int Vehicle::getM_vin() const {
    return m_vin;
}

void Vehicle::setLla(const float *lla){
    float *tempLla = m_lla;
    for (int x = 0; x < 3; x++) {
        *tempLla++ = *lla++;
    }
}

Vehicle& Vehicle::operator= (const Vehicle &rhs) {
    setLla(rhs.getM_lla());
    cout << "Vehicle #" << m_vin << ": Assignment" << endl;

    return *this;
}

void Vehicle::move(const float *lla){
    cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
}

int Vehicle::getIdgen(){
    return s_idgen;
}

ostream& operator<<(ostream &os, const Vehicle &copy){
    os << "Vehicle #" << copy.m_vin << " @ [";
    os << copy.m_lla[0] << ", " << copy.m_lla[1] << ", " << copy.m_lla[2] << "]";

    return os;
}

void Vehicle::setIdgen(){
    s_idgen++;
}



