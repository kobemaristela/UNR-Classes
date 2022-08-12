
#include "Car.h"

Car::Car() {
    setM_make(" ");
    setM_model(" ");
    setM_year(0);
    setM_baseprice(0.0);
    setM_available(false);
    setM_owner(" ");



    //Loop
    Sensor *mySensor = m_sensors;
    for (int x = 0; x < 3; x++, mySensor++) {
        Sensor default_sensor;
        *mySensor = default_sensor;
    }
}

Car::Car(int year, char *make, char *model, float baseprice, Sensor *sensors) {
    setM_make(make);
    setM_model(model);
    setM_baseprice(baseprice);
    setM_year(year);

    //Loop
    Sensor *mySensor = m_sensors;
    for (int x = 0; x < 3; x++, mySensor++, sensors++) {
        *mySensor = *sensors;
    }
}

Car::Car(const Car &copy){
    setM_make(copy.getM_make());
    setM_model(copy.getM_model());
    setM_year(copy.getM_year());
    setM_baseprice(copy.getM_baseprice());
    m_finalprice = copy.getM_finalprice();
    setM_available(copy.getM_available());
    setM_owner(copy.getM_owner());

    Sensor *mySensor = m_sensors;
   const Sensor *copySensor = copy.m_sensors;
    //Loop
    for (int x = 0; x < 3; x++, mySensor++, copySensor++) {
        *mySensor = *copySensor;
    }

}

int Car::getM_year() const {
    return m_year;
}

const char *Car::getM_make() const {
    return m_make;
}

const char *Car::getM_model() const {
    return m_model;
}

float Car::getM_baseprice() const {
    return m_baseprice;
}

float Car::getM_finalprice() const {
    return m_finalprice;
}

bool Car::getM_available() const {
    return m_available;
}

const Sensor *Car::getM_sensors() const {
    return m_sensors;
}

const char *Car::getM_owner() const {
    return m_owner;
}

void Car::setM_year(int m_year) {
    Car::m_year = m_year;
}

void Car::setM_baseprice(float m_baseprice) {
    Car::m_baseprice = m_baseprice;
}

void Car::setM_available(bool m_available) {
    Car::m_available = m_available;
}

void Car::setM_make(const char* source){
    myStringCopy(Car::m_make, source);
}

void Car::setM_model(const char* source){
    myStringCopy(Car::m_model, source);
}

void Car::setM_owner(const char* source){
    myStringCopy(Car::m_owner, source);
}

void Car::updatePrice() {
    //initialize variables
    Sensor *ptrSensor = m_sensors;
    float extraCost = 0.0;

    //Add up extra cost
    for (int x = 0; x < ptrSensor->sensorCount(); x++, ptrSensor++) {
        extraCost += ptrSensor->getM_extracost();
    }
    m_finalprice = getM_baseprice() + extraCost;
}

void Car::print(){
    cout << getM_year() << " ";
    cout << getM_make() << " ";
    cout << getM_model() << ", $";
    cout << getM_finalprice() << " per day, Sensors: ";

    Sensor *ptrSensor = m_sensors;
    //Prints Sensors
    for (int x = 0; x < 3; x++, ptrSensor++) {
        if (myStringCompare(ptrSensor->getM_type(), "none") != 0)
        {
            cout << ptrSensor->getM_type();
            cout << ", ";
        }
    }

    cout << "Available: ";
    cout << boolalpha << getM_available();
    //Print out Lessee if available
    if(getM_available())
    {
        cout << " Lessee: " << getM_owner();
    }
}

float Car::estimateCost(int days){
    return m_finalprice * days;
}

Car& Car::operator+(Sensor &rhs)
{
    Sensor *ptrSensor = m_sensors;
    if (ptrSensor->sensorCount()== 3 )
    {
        cout << "You already have 3 sensors!" << endl;
    }
    else
        {
            for (int x = 0; x < ptrSensor->sensorCount(); x++, ptrSensor++) {
                if (*ptrSensor == rhs) {
                    cout << "You already have that sensor!" << endl;
                }
            }
        *ptrSensor = rhs;
    }
    return *this;
}

Car& Car::operator+(char* owner)
{
    myStringCopy(m_owner, owner);
    setM_available(false);
    return *this;
}
