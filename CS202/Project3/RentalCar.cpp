//
// Created by Kobe on 9/18/2018.
//
#include <iostream>
#include "RentalCar.h"
using namespace std;

//Constants
const int defaultYear = 0;
const char defaultMake[256] = " ";
const char defaultModel[256] = " ";
const float defaultPrice = 0.0;
const bool defaultAvailable = false;


int RentalCar::getM_year() const
{
    return m_year;
}

const char *RentalCar::getM_make() const
{
    return m_make;
}

const char *RentalCar::getM_model() const
{
    return m_model;
}

float RentalCar::getM_price() const
{
    return m_price;
}

bool RentalCar::getM_available() const
{
    return m_available;
}

void RentalCar::setM_year(int m_year)
{

    RentalCar::m_year = m_year;
}

void RentalCar::setM_price(float m_price)
{
    RentalCar::m_price = m_price;
}

void RentalCar::setM_available(bool m_available)
{
    RentalCar::m_available = m_available;
}

void RentalCar::setM_make(const char* source)
{


    char* p_make = m_make;
    while(*source != '\0')
    {
        *p_make++ = *source++;
    }
    *p_make = '\0';
}

void RentalCar::setM_model(const char* source)
{
    char* p_model = m_model;
    while(*source != '\0')
    {
        *p_model++ = *source++;
    }
    *p_model = '\0';
}

RentalCar::RentalCar()
{
    setM_year(defaultYear);
    setM_make(defaultMake);
    setM_model(defaultModel);
    setM_price(defaultPrice);
    setM_available(defaultAvailable);
}

RentalCar::RentalCar(int m_year, char *m_make, char *m_model, float m_price, bool m_available = defaultAvailable)
{
    setM_year(m_year);
    setM_make(m_make);
    setM_model(m_model);
    setM_price(m_price);
    setM_available(m_available);
}

void RentalCar::print()
{
        cout << getM_year() << " ";
        cout << getM_make() << " ";
        cout << getM_model() << ", $";
        cout << getM_price() << " per day, Available: ";
        cout << boolalpha << getM_available() << endl;
}

float RentalCar::estimateCost(int &myDays)
{
    return myDays * getM_price();
}
