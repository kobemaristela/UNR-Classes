//
// Created by Kobe on 11/3/2018.
//

#include "SmartPtr.h"

//Default Ctor
SmartPtr::SmartPtr() {
    m_ptr = new DataType;
    m_refcount = new size_t;
    *m_refcount = 1;

    cout << "SmartPtr Default Constructor for new allocation, RefCount = " << *m_refcount << endl;
}

//Parameterized Ctor
SmartPtr::SmartPtr( DataType * data ) {
    m_ptr = data;
    m_refcount = new size_t;

    (*m_refcount) = data == nullptr ? 0 : 1;

    cout << "SmartPtr Parametrized Constructor from data pointer, RefCount = " << *m_refcount << endl;
}

//Copy Ctor
SmartPtr::SmartPtr( const SmartPtr & other ){
    m_ptr = other.m_ptr;
    if(other.m_ptr == nullptr){
        m_refcount = new size_t;
        (*m_refcount) = 0;
    } else{
        m_refcount = other.m_refcount;
        (*m_refcount)++;
    }

    cout << "SmartPtr Copy Constructor, RefCount = " << *m_refcount << endl;

}

//Deconstructor
SmartPtr::~SmartPtr( ){
    cout << "Deconstructing a smartPtr, RefCount b4 = " << *m_refcount << endl;
    if(*m_refcount > 0)
        (*m_refcount)--;
    if(*m_refcount == 0){
        cout << "SmartPtr Destructor, RefCount = " << *m_refcount << endl;

        delete m_ptr;
        delete m_refcount;
    }
}

//Assignment operator
SmartPtr & SmartPtr::operator=( const SmartPtr & rhs ){
    if (this != &rhs) {
        m_ptr = rhs.m_ptr;
        m_refcount = rhs.m_refcount;
        if(rhs.m_ptr == nullptr){
            m_refcount = new size_t;
            (*m_refcount) = 0;
        } else{
            (*m_refcount)++;
        }
    }
    cout << "SmartPtr Copy Assignment, RefCount=" << *m_refcount << endl;
    return *this;
}

//Pointer operator
DataType & SmartPtr::operator*( ){
    return *m_ptr;
}

//Deference operator
DataType * SmartPtr::operator->( ){
    return m_ptr;
}