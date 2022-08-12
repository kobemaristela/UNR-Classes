//
// Created by Kobe on 11/18/2018.
//

#include "ArrayQueue.h"

//Default Constructor
ArrayQueue::ArrayQueue(){
    m_size = 0;
    m_front = 0;
    m_back = 0;
}

//Parameterized Constructor
ArrayQueue::ArrayQueue(size_t count, const DataType & value){
   if(count <= 0 || count > ARRAY_MAX){
       m_size = 0;
       m_front = 0;
       m_back = 0;
   }else{
       m_size = count;
       m_front = 0;
       for (size_t x = 0; x < m_size ; x++) {
           m_back = x;
           m_array[x] = value;
       }
   }
}

//Copy Constructor
ArrayQueue::ArrayQueue(const ArrayQueue & other){
    m_size = other.m_size;
    m_front = other.m_front;
    m_back = other.m_back;

    for (size_t x = m_front; x < m_size; x++) {
        m_array[x] = other.m_array[x];
    }
}

//Destructor
ArrayQueue::~ArrayQueue(){
    clear();
    cout << "ArrayQueue deleted." << endl;
}

//Operators
ArrayQueue & ArrayQueue::operator= (const ArrayQueue & rhs){
    if(this != &rhs){
        if(!empty()){
            clear();
        }
        m_size = rhs.m_size;
        m_front = rhs.m_front;
        m_back = rhs.m_back;

        for (size_t x = m_front; x < m_size; x++) {
            m_array[x] = rhs.m_array[x];
        }
    }
    return *this;
}

ostream &operator<<(std::ostream & os, const ArrayQueue & arrayQueue){
    arrayQueue.serialize(os);
    return os;
}

//Functions
DataType &ArrayQueue::front(){
    if(m_front < 0){
        DataType* nullData = new DataType;
        return *nullData;
    } else{
        return m_array[m_front];
    }
}

const DataType &ArrayQueue::front() const{
    if(m_front < 0){
        DataType* nullData = new DataType;
        return *nullData;
    } else{
        return m_array[m_front];
    }
}

DataType &ArrayQueue::back(){
    if(m_back > ARRAY_MAX){
        DataType* nullData = new DataType;
        return *nullData;
    } else{
        return m_array[m_back];
    }
}

const DataType &ArrayQueue::back() const{
    if(m_back > ARRAY_MAX){
        DataType* nullData = new DataType;
        return *nullData;
    } else{
        return m_array[m_back];
    }
}

void ArrayQueue::push(const DataType & value){
    if(full()){
        cout << "Array is full..." << endl;
    } else{
        m_back = (m_back + 1) % ARRAY_MAX;
        m_size++;
    }
    m_array[m_back] = value;
}

void ArrayQueue::pop(){
    if(empty()){
        cout << "Array is empty..." << endl;
    }else{
        m_front = (m_front + 1) % ARRAY_MAX;
        m_size--;
    }
}

size_t ArrayQueue::size() const{
    return m_size;
}

bool ArrayQueue::empty() const{
    return m_size == 0;
}

bool ArrayQueue::full() const{
    return m_size == ARRAY_MAX;
}

void ArrayQueue::clear(){
    if (empty()){
        cout << "Array already cleared..." << endl;
    }else{
        DataType nullData;
        for (size_t x = 0; x < m_size; x++) {
            m_array[x] = nullData;
        }
        m_size = 0;
        m_front = 0;
        m_back = 0;

        cout << "ArrayQueue cleared..." << endl;
    }
}

void ArrayQueue::serialize(std::ostream & os) const{
 if(empty()){
     cout << "Array is empty..." << endl;
 } else{
     for (size_t x = m_front;  x <= m_back ; x++) {
         os << m_array[x] << endl;
     }
 }
}