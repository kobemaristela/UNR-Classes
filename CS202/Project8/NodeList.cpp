//
// Created by Kobe on 11/13/2018.
//

#include "NodeList.h"

//Default Constructor
NodeList::NodeList(){
    m_head = nullptr;
}

//Parameterized Constructor
NodeList::NodeList(size_t count, const DataType & value){
    if(count <= 0){
        m_head = nullptr;
    } else{
        m_head = new Node(value, nullptr);
        Node * curr = m_head;
        for (int x = 1; x < count ; x++, curr = curr->m_next) {
            curr-> m_next = new Node(value, nullptr);
        }
        curr->m_next = nullptr;
    }
}

//Copy Constructor
NodeList::NodeList(const NodeList & other){
    if(other.m_head != nullptr){
        m_head = new Node(other.m_head->data(), NULL);

        Node* curr = m_head;
        Node* tempHead = other.m_head;
        for (Node* tempHead = other.m_head; (tempHead != NULL) && (tempHead->m_next != NULL); curr = curr->m_next ) {
            tempHead = tempHead->m_next;
            curr->m_next = new Node(tempHead->data(), NULL);
        }
        curr->m_next = NULL;
    }
}

//Deconstructor
NodeList::~NodeList(){
    //Deletes the Node
    //clear();
    cout << "NodeList deleted." << endl;
}

//Operator
NodeList & NodeList::operator= (const NodeList & rhs){
    Node* curr = m_head;
    if(this->size() < rhs.size()){
        //Deallocate
        clear();
        DataType dataTemp;
        NodeList nodeTemp(rhs.size(), dataTemp);
        curr = nodeTemp.m_head;
    }

    for (Node* tempHead = rhs.m_head; tempHead != NULL ; tempHead = tempHead->m_next, curr = curr->m_next) {
        curr->m_data = tempHead->data();
    }
    return *this;
}


const DataType & NodeList::operator[] (size_t position) const{
    if(position >= 0 && position < size()){
        Node* curr = m_head;
        for (int count = 0 ;  curr != NULL && count < position; curr = curr->m_next, count++) {
        }
        return curr->data();
    }
}

DataType & NodeList::operator[] (size_t position){
    if(position >= 0 && position < size()){
        Node* curr = m_head;
        for (int count = 0 ;  curr != NULL && count < position; curr = curr->m_next, count++) {
        }
        return curr->data();
    }
}

ostream & operator<<(std::ostream & os, const NodeList & nodeList){
    for (int x = 0; x < nodeList.size(); x++) {
        os << nodeList[x];
    }
    return os;
}

//Functions
Node * NodeList::front(){
    return m_head == NULL ? NULL : m_head;
}

Node * NodeList::back()	{
    if(m_head == NULL)
    {
        return NULL;
    } else{
        Node * curr;
        for (curr = m_head; curr != nullptr && curr->m_next != NULL ; curr = curr->m_next) {
        }
        return curr;
    }
}

Node * NodeList::find(const DataType & target,	Node * & previous, const Node * start){
    Node* curr = m_head;
    //Checks first Node
    if((curr->data() == target))
    {
        previous = NULL;
        return curr;
    }

    //Checks the NodeList
    for (; (curr != NULL); curr = curr->m_next) {
        if((curr->m_next->data() == target)){
            previous = curr;
            return  curr-> m_next;
        }
    }
    previous = NULL;
    return NULL;
}

Node * NodeList::insertAfter(const DataType & target, const DataType & value){
    for(Node* curr = m_head; curr != NULL; curr = curr->m_next){
        if(curr->data() == target){
            curr->m_next = new Node(value,curr->m_next);
            return curr->m_next;
        }
    }
    return NULL;
}

Node * NodeList::insertBefore(const DataType & target, const DataType & value){
    //Checks if first Node is targer
    if(m_head->data() == target){
        Node* curr = new Node(value, NULL);
        curr->m_next = m_head;
        return curr;
    }else{
        Node* tempNode = NULL;
        for (Node* curr = m_head; curr != NULL ; curr = curr->m_next) {
            if(curr->data() == target){
                tempNode->m_next = new Node(value, curr);
                return tempNode->m_next;
            }
            tempNode = curr;
        }
    }
    return NULL;
}

Node * NodeList::erase(const DataType & target){
    for (Node* curr = m_head;  curr != NULL ; curr = curr->m_next) {
        if (curr->data() == target)
        {
            m_head = m_head->m_next;
            return m_head;
        }
    }
}

size_t NodeList::size() const{
    size_t count = 0;
    for (Node* curr = m_head; curr != NULL; curr = curr->m_next, count++) {
    }
    return count;
}

bool NodeList::empty() const{
    return m_head == nullptr;
}

void NodeList::clear(){
    Node* prev = m_head;
    for (Node* curr = m_head;  curr != NULL ; curr = curr->m_next) {
        delete prev;
        prev = curr;
    }
    m_head = NULL;
}

