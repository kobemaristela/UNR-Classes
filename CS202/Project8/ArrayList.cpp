//
// Created by Kobe on 11/13/2018.
//

#include "ArrayList.h"

//Default Constructor
ArrayList::ArrayList(){
    m_size = 0;
    m_maxsize = 0;
    m_array = new DataType;
    m_array = nullptr;
}

//Parameterized Constructor
ArrayList::ArrayList(size_t count, const DataType & value){
    m_maxsize = count;
    m_size = count;
    m_array = new DataType[m_size];
    for (int x = 0; x < m_size; x++) {
        m_array[x] = value;
    }
}

//Copy Constructor
ArrayList::ArrayList(const ArrayList & other){
    m_size = other.m_size;
    m_maxsize = other.m_maxsize;
    m_array = new DataType[m_size];
    for (int x = 0; x < m_size; x++) {
        m_array[x] = other.m_array[x];
    }
}

//Deconstructor
ArrayList::~ArrayList(){
    clear();
    cout << "ArrayList deleted." << endl;
}

//Operator
ArrayList & ArrayList::operator= (const ArrayList & rhs){
    if(this != &rhs){
        delete [] m_array;
        m_array = nullptr;
        m_maxsize = rhs.m_maxsize;
        m_size = rhs.m_size;
        m_array = rhs.m_array;
        if(rhs.m_array == nullptr){
            m_array = new DataType[m_size];
            for (int x = 0; x < m_size; x++) {
                m_array[x] = rhs.m_array[x];
            }
        }
    }
    return *this;
}

DataType & ArrayList::operator[] (size_t position){
    return m_array[position];
}

ostream & operator<<(std::ostream & os, const ArrayList & arrayList){
    os << "Array: ";
    for (int x = 0; x < arrayList.m_size; x++) {
        os << arrayList.m_array[x];
    }
    return os;
}

//Functions
DataType * ArrayList::front(){
    DataType *front = m_array;
    return front == nullptr ? nullptr : front;
}

DataType * ArrayList::back(){
    DataType *back = m_array;
    for (int x = 0; x < size() - 1; x++, back++) {
    }
    return back == nullptr ? nullptr : back;
}

DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start){
    for(int count = 0;m_array != nullptr; m_array++, count++){
        if(*m_array == target){
            if(count != 0){
                previous = (m_array - 1);
            }else{
                previous = nullptr;
            }
            return m_array;
        }
    }
    previous = NULL;
    return NULL;
}

DataType * ArrayList::insertAfter(const DataType & target, const DataType & value){

    for (int x = 0; x < m_size; x++) {
        if(m_array[x] == target) {
            //Resizes
            m_size++;
            if(m_size > m_maxsize){
                resize(m_size);
            }

            //Assigns
            for (int y = 1, z = 2; y < m_size; y++, z++) {
                m_array[x + z] = m_array[x + y];
                m_array[x + 1] = value;
            }
            return &m_array[x + 1];
        }
    }
    return NULL;
}

DataType * ArrayList::insertBefore(const DataType & target, const DataType & value){


    for (int x = 0; x < m_size; x++) {
        if(m_array[x] == target){
            //Resizes
            m_size++;
            if(m_size > m_maxsize) {
                resize(m_size);
            }

            //Copies
            DataType *tempPtr;
            tempPtr = new DataType[m_size];
            for (int x = 0; x < m_size; x++) {
                tempPtr[x] = m_array[x];
            }

            //Assigns
            for (int tempX = x; tempX < m_size; tempX++) {
                m_array[tempX + 1] = tempPtr[tempX];
            }
            m_array[x] = value;
            return &m_array[x];
        }
    }
    return NULL;
}

DataType * ArrayList::erase(const DataType & target){
    for (int x = 0; x < m_size; x++) {
        if(m_array[x] == target){
            //Copies
            DataType *tempPtr;
            tempPtr = new DataType[m_size];
            for (int x = 0; x < m_size; x++) {
                tempPtr[x] = m_array[x];
            }
            m_size--;
            resize(m_size);

            //Assigns
            for (int tempX = x; tempX < m_size; tempX++) {
                m_array[tempX] = tempPtr[tempX + 1];
            }
            return &m_array[x];
        }
    }
    return NULL;
}


size_t ArrayList::size() const{
    return m_size;
}

bool ArrayList::empty() const{
    return m_size == 0;
}

void ArrayList::clear(){
    delete [] m_array;
    m_array = nullptr;
    m_size = 0;
    m_maxsize = 0;

    cout << "ArrayList is cleared" << endl;
}

void ArrayList::resize(size_t count){
    //Copies data over
    DataType defaultCtor;
    DataType *tempPtr;
    tempPtr = new DataType[m_size];
    for (int x = 0; x < m_size; x++) {
        tempPtr[x] = m_array[x];
    }

    //Allocate new size
    m_maxsize = count;
    m_size = count;
    m_array = new DataType[m_maxsize];
    for (int x = 0; x < m_maxsize; x++) {
        if (tempPtr[x] == defaultCtor){
            m_array[x] = defaultCtor;
        }else{
            m_array[x] = tempPtr[x];
        }
    }

    delete [] tempPtr;
    tempPtr = nullptr;
}