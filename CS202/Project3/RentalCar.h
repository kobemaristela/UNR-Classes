//
// Created by Kobe on 9/18/2018.
//

#ifndef PROJECT3_RENTALCAR_H
#define PROJECT3_RENTALCAR_H

class RentalCar {
public:
    RentalCar();

    RentalCar(int m_year, char *m_make, char *m_model, float m_price, bool m_available);

    //Getters
    int getM_year() const;
    const char *getM_make() const;
    const char *getM_model() const;
    float getM_price() const;
    bool getM_available() const;

    //Setters
    void setM_year(int m_year);
    void setM_price(float m_price);
    void setM_available(bool m_available);
    void setM_make(const char* source);
    void setM_model(const char* source);

    //Methods
    void print();
    float estimateCost(int &myDays);

private:
    int m_year;
    char m_make[256];
    char m_model[256];
    float m_price;
    bool m_available;

};


#endif //PROJECT3_RENTALCAR_H
