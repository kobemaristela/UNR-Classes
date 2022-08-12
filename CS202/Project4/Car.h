#ifndef PROJECT4_CAR_H
#define PROJECT4_CAR_H
#include "Sensor.h"

class Car {
public:
    //Constructors
    Car();
    Car(int year, char *make, char *model, float baseprice, Sensor *sensors);
    Car(const Car &copy);

    //Getters
    int getM_year() const;
    const char *getM_make() const;
    const char *getM_model() const;
    float getM_baseprice() const;
    float getM_finalprice() const;
    bool getM_available() const;
    const Sensor *getM_sensors() const;
    const char *getM_owner() const;

    //Setters
    void setM_year(int m_year);
    void setM_baseprice(float m_baseprice);
    void setM_available(bool m_available);
    void setM_make(const char* source);
    void setM_model(const char* source);
    void setM_owner(const char* source);

    //Functions
    void updatePrice();
    void print();
    float estimateCost(int days);

    //Operators
    Car& operator+(Sensor &rhs);
    Car& operator+(char* owner);

private:
    int m_year;
    char m_make[256];
    char m_model[256];
    float m_baseprice;
    float m_finalprice;
    bool m_available;
    Sensor m_sensors[3];
    char m_owner[256];
};


#endif //PROJECT4_CAR_H
