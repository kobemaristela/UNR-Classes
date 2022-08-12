//
// Created by Kobe on 12/2/2018.
//

#ifndef PROJ10_NODESTACK_H
#define PROJ10_NODESTACK_H

#include <iostream>
#include <cstring>
#include "string.h"
using namespace std;

template <class T>
class NodeStack;

template <class T>
std::ostream & operator<<(ostream & os, const NodeStack<T> & nodeStack);

template <typename T>
class Node{
    friend class NodeStack<T>;
public:
    Node();
    Node(const T & data, Node<T> * next);
    T & data();
    const T & data() const;
private:
    Node<T> * m_next;
    T m_data;
};

template <class T>
class NodeStack {
    friend ostream & operator<< <T>(ostream & os, const NodeStack<T> & nodeStack);

public:
    NodeStack();
    NodeStack(size_t count, const T & value);
    NodeStack(const NodeStack<T> & other);
    ~NodeStack();

    //Operators
    NodeStack<T> & operator= (const NodeStack<T> & rhs);

    //Functions
    T & top();
    const T & top() const;
    void push(const T & value);
    void pop();
    size_t size() const;
    bool empty() const;
    bool full() const;
    void clear();
    void serialize(ostream & os) const;

private:
    Node<T> * m_top;
};
#endif //PROJ10_NODESTACK_H


//Template Node
template <typename T>
Node<T>::Node() : m_next( NULL ){
}

template <typename T>
Node<T>::Node(const T & data, Node<T> * next) : m_data( data ), m_next( next ){
}

template <typename T>
T & Node<T>::data(){
    return m_data;
}

template <typename T>
const T & Node<T>::data() const{
    return m_data;
}

//Template NodeStack
template <class T>
NodeStack<T>::NodeStack() {
    m_top = NULL;
}

template <class T>
NodeStack<T>::NodeStack(size_t count, const T &value) {
    size_t i;
    m_top = NULL;

    for (i = 0; i < count; i++)
    {
        push(value);
    }

}

template <class T>
NodeStack<T>::NodeStack(const NodeStack<T> &other) {
    Node<T> *otherCurr = other.m_top;
    this->m_top = new Node<T>(otherCurr->m_data);
    Node<T> *curr = this->m_top;

    for (otherCurr = otherCurr->m_next; otherCurr != NULL; otherCurr = otherCurr->m_next) {
        curr->m_next = new Node<T>(otherCurr->m_data);
        curr = curr->m_next;
    }
    otherCurr = NULL;
    curr = NULL;
}

template <class T>
NodeStack<T>::~NodeStack() {
    if (!empty()) {
        clear();
    }
}

template <class T>
NodeStack<T> & NodeStack<T>::operator=(const NodeStack<T> &rhs) {
    if(this != &rhs){
        if (!empty()) {
            clear();
        }

        Node<T> *rhsCurr = rhs.m_top;
        m_top = new Node<T>(rhsCurr->m_data);
        Node<T> *curr = m_top;
        for (rhsCurr = rhsCurr->m_next; rhsCurr != NULL; rhsCurr = rhsCurr->m_next)
        {
            curr->m_next = new Node<T>(rhsCurr->m_data);
            curr = curr->m_next;
        }
        rhsCurr = NULL;
        curr = NULL;
    }
    return *this;
}

template <class T>
T & NodeStack<T>::top()
{
    if (!empty()) {
        return m_top->m_data;
    }
    else if(empty()) {
        cout << "NodeStack is empty" << endl;
    }
}

template <class T>
const T & NodeStack<T>::top() const
{
    if (!empty()) {
        return m_top->m_data;
    }
    else if(empty()) {
        cout << "NodeStack is empty" << endl;
    }

}

template <class T>
void NodeStack<T>::push(const T &value)
{
    if (!empty())
    {
        Node<T> *temp = new Node<T>(value, m_top);
        m_top = temp;
        temp = NULL;
    }
    else if (empty())
    {
        m_top = new Node<T>(value);
    }

}

template <class T>
void NodeStack<T>::pop()
{
    if (empty()) {
        cout << "NodeStack is empty" << endl;
    }
    else if(!empty()) {
        Node<T> *temp = m_top;
        m_top = m_top->m_next;
        delete temp;
        temp = NULL;
    }
}

template <class T>
size_t NodeStack<T>::size() const {
    size_t counter = 0;
    for (Node<T> *curr = m_top; curr != NULL; curr = curr->m_next) {
        counter++;
    }
    return counter;
}

template <class T>
bool NodeStack<T>::empty() const {
    return m_top == NULL;
}

template <class T>
bool NodeStack<T>::full() const {
    return false;
}

template <class T>
void NodeStack<T>::clear() {
    Node<T> *temp = m_top;
    while (m_top != NULL) {
        m_top = m_top->m_next;
        delete temp;
        temp = m_top;
    }

    temp = NULL;
}

template <class T>
void NodeStack<T>::serialize(ostream &os) const {
    if(!empty()){
        for (Node<T>* curr = m_top; curr != NULL; curr = curr->m_next) {
            os << curr->m_data << endl;
        }
    }
}

template <typename T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack) {
    nodeStack.serialize(os);
    return os;
}