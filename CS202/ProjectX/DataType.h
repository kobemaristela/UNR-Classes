//
// Created by Kobe on 11/3/2018.
//

#ifndef PROJX_DATATYPE_H
#define PROJX_DATATYPE_H

#include <iostream>
using namespace std;


class DataType{

    friend std::ostream & operator<<(std::ostream & os, const DataType & dataType);
    friend std::istream & operator>>(std::istream & is, DataType & dataType);

public:
    DataType();
    DataType(int intVal, double doubleVal);
    DataType(const DataType & other);

    bool operator==(const DataType & rhs) const;
    DataType & operator= (const DataType & rhs);

    int getIntVal() const;
    void setIntVal(int i);
    double getDoubleVal() const;
    void setDoubleVal(double d);

private:
    int m_intVal;
    double m_doubleVal;
};

#endif //PROJX_DATATYPE_H
