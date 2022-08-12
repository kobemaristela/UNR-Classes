//
// Created by Kobe on 11/3/2018.
//

#ifndef PROJX_SMARTPTR_H
#define PROJX_SMARTPTR_H

#include "DataType.h"

class SmartPtr {

public:

    //Constructors
    SmartPtr( );
    SmartPtr( DataType * data );
    SmartPtr( const SmartPtr & other );

    //Deconstruct
    ~SmartPtr( );

    //Operators
    SmartPtr & operator=( const SmartPtr & rhs );

    DataType & operator*( );
    DataType * operator->( );

private:

    size_t * m_refcount;
    DataType * m_ptr;

};


#endif //PROJX_SMARTPTR_H
