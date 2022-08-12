#include "NodeQueue.h"

//Default Constructor
NodeQueue::NodeQueue(){
    m_front = nullptr;
    m_back = nullptr;
    cout << "Default Constructor Initialized..." << endl;
}

//Parameterized Constructor
NodeQueue::NodeQueue(size_t count, const DataType & value){
    if(count <= 0){
        m_front = nullptr;
        m_back = nullptr;
    }else{
        m_front = new Node(value);
        Node* curr = m_front;
        for (size_t x = 1 ; x < count; curr = curr->m_next, x++) {
            curr->m_next = new Node(value);
        }
        m_back = curr;
    }
}

//Copy Constructor
NodeQueue::NodeQueue(const NodeQueue & other){
        Node * oCurr = other.m_front;
        m_front = new Node(oCurr->data());
        oCurr = oCurr->m_next;
        Node* curr = m_front;
        for (;  oCurr != nullptr ; oCurr = oCurr->m_next, curr = curr->m_next) {
            curr->m_next = new Node(oCurr->data());
        }
        m_back = curr;
}

//Destructor
NodeQueue::~NodeQueue() {
    clear();
    cout << "NodeQueue deleted." << endl;
}
//Operators
NodeQueue & NodeQueue::operator= (const NodeQueue & rhs){
    if(this != &rhs){
        if(!empty()){
            clear();
        }

        Node * oCurr = rhs.m_front;
        m_front = new Node(oCurr->data());
        oCurr = oCurr->m_next;
        Node* curr = m_front;
        for (; oCurr != nullptr ; oCurr = oCurr->m_next, curr = curr->m_next) {
            curr->m_next = new Node(oCurr->data());
        }
        m_back = curr;
    }
    return *this;
}

ostream &operator<<(std::ostream & os, const NodeQueue & nodeQueue){
    nodeQueue.serialize(os);
    return os;
}

//Functions
DataType &NodeQueue::front(){
    return m_front->data();
}

const DataType &NodeQueue::front() const{
    return m_front->data();
}

DataType &NodeQueue::back(){
    return  m_back->data();
}

const DataType &NodeQueue::back() const{
    return  m_back->data();
}

void NodeQueue::push(const DataType & value){
    if(m_front == nullptr){
        m_front = new Node(value);
        m_back = m_front;
    }else{
        Node* curr = new Node(value);
        m_back->m_next = curr;
        m_back = curr;
    }
}

void NodeQueue::pop(){
    m_front = m_front->m_next;
}

size_t NodeQueue::size() const{
    size_t count = 0;
    for(Node* curr = m_front; curr != nullptr; curr = curr->m_next, count++){
    }
    return count;
}

bool NodeQueue::empty() const{
    return m_front == nullptr;
}

bool NodeQueue::full() const{
    return false;
}

void NodeQueue::clear(){
    if(empty()){
        cout << "NodeQueue already empty..." << endl;
    } else{
        Node* prev = m_front;
        for (Node* curr = m_front;  curr != nullptr ; prev = curr) {
            curr = curr->m_next;
            delete prev;
        }
        cout << "NodeQueue cleared..." << endl;
    }
    m_front = nullptr;
    m_back = nullptr;
}

void NodeQueue::serialize(std::ostream & os) const{
    size_t count = 0;
    for (Node* curr = m_front; count < size(); curr = curr->m_next, count++) {
        os << curr->data() << endl;
    }
}