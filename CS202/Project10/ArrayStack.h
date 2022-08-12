#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;

const size_t MAX_STACKSIZE = 1000;

template <class T>
class ArrayStack;

template <class T>
std::ostream & operator<<(ostream & os, const ArrayStack<T> &arrayStack);

template <class T>
class ArrayStack {
    friend ostream & operator<< <T>(ostream & os, const ArrayStack<T> &arrayStack);

public:
    ArrayStack();
    ArrayStack(size_t count, const T &value);
    ArrayStack(const ArrayStack<T> &other);
    ~ArrayStack();

    //Operators
    ArrayStack<T> & operator= (const ArrayStack<T> &rhs);

    //Functions
    T &top();
    const T &top() const;
    void push(const T &value);
    void pop();
    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(ostream & os) const;

private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
};

#endif //ARRAYSTACK_H_

//Templates
template <class T>
ArrayStack<T>::ArrayStack() {
    m_top = 0;
}

template <class T>
ArrayStack<T>::ArrayStack(size_t count, const T &value) {
    m_top = count;
    for (size_t x = 0; x < m_top; x++) {
        m_container[x] = value;
    }
}

template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> &other) {
    this->m_top = other.m_top;

    size_t x;
    for (x = 0; x < m_top; x++) {
        this->m_container[x] = other.m_container[x];
    }
}

template <class T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <class T>
ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> &rhs) {
    if(this !=&rhs){
        this->m_top = rhs.m_top;

        for (size_t x = 0; x < m_top; x++) {
            this->m_container[x] = rhs.m_container[x];
        }
    }
    return *this;
}

template <class T>
T & ArrayStack<T>::top() {
    if (!empty()) {
        return m_container[m_top - 1];
    }
}

template <class T>
T & ArrayStack<T>::top() const {
    if (!empty()) {
        return m_container[m_top - 1];
    }
}

template <class T>
void ArrayStack<T>::push(const T &value) {
    if (full()) {
        cout << "ArrayStack is full" << endl;
    }
    else if(!full()) {
        m_container[m_top++] = value;
    }
}

template <class T>
void ArrayStack<T>::pop() {
    if (empty()) {
        cout << "ArrayStack is empty" << endl;
    }
    else if(!empty()) {
        m_top--;
    }
}

template <class T>
size_t ArrayStack<T>::size() const {
    return m_top - 1;
}

template <class T>
bool ArrayStack<T>::empty() const {
    return m_top == 0 ? true : false;
}

template <class T>
bool ArrayStack<T>::full() const {
    return m_top == MAX_STACKSIZE;
}

template <class T>
void ArrayStack<T>::clear()
{
    m_top = 0;
}

template <class T>
void ArrayStack<T>::serialize(ostream &os) const {
    if(!empty()){
        for (size_t x = m_top - 1; x > 0; x) {
            os << m_container[x]<< ",";
        }
    }
}

template <typename T>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack)
{
    arrayStack.serialize(os);
    return os;
}