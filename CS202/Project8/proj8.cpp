#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){

    cout << "************************" << endl;
    cout << "*****ARRAYLIST TEST*****" << endl;
    cout << "************************" << endl;
    cout << endl;

    DataType test1(0, 0.0);
    DataType test2(1, 1.1);
    DataType test3(2, 2.2);
    DataType test4(3, 3.3);

    cout << "Default ctor..." << endl;
    ArrayList deflt_array;
    cout << "Default ctor Test Successful" << endl;

    cout << endl << "Parameterized ctor..." << endl;
    ArrayList parametrized_array(4,test1);
    cout << parametrized_array << endl;
    cout << "Parameterized ctor Test Successful" << endl;

    cout << endl << "Copy ctor..." << endl;
    ArrayList cpyArray(parametrized_array);
    cout << cpyArray << endl;
    cout << "Copy ctor Test Successful" << endl;
    cout << endl;

    cout << "Assignment Operator..." << endl;
    ArrayList bArray(1, test1);
    ArrayList aArray(2, test2);
    cout << "Before Array Assignment" << endl << bArray << endl;
    bArray = aArray;
    cout << "After Array Assignment" << endl << bArray << endl;

    cout << endl <<  "Front Function..." << endl;
    cpyArray[0] = test2;
    cpyArray[3]= test3;
    cout << "First element of array is: " << *(cpyArray.front())<< endl;

    cout << endl << "Back Function..." << endl;
    cout << "Last element of array is: " << *(cpyArray.back())<< endl;

    cout << endl << "Find Function..." << endl;
    DataType* previousData = new DataType();
    cout << "Find test2 data:";
    cout << *(cpyArray.find(test2, previousData)) << endl;

    cout << endl << "InsertAfter Function..." << endl;
    cout << "Insert into node: ";
    cout << *(cpyArray.insertAfter(test1, test4)) << endl;
    cout << cpyArray << endl;

    cout << endl << "InsertBefore Function..." << endl;
    cout << "Insert into array: ";
    cout << *(cpyArray.insertBefore(test1,test3)) << endl;
    cout << cpyArray << endl;

    cout << endl << "Erase Function..." << endl;
    cout << "Next element after erased element: ";
    cout << *(cpyArray.erase(test1)) << endl;
    cout << cpyArray << endl;

    cout << endl << "Index Operator..." << endl;
    cpyArray[2] = DataType(4, 7.8);
    cout << cpyArray << endl;

    cout << endl << "Size Function..." << endl;
    cout << "Size of array is: ";
    cout << cpyArray.size()<< endl;

    cout << endl <<  "Empty Function..." << endl;
    cout << (cpyArray.empty() ? "Array is empty" : "Array is not empty") << endl;

    cout << "************************" << endl;
    cout << "*****NODELIST TEST*****" << endl;
    cout << "************************" << endl;
    cout << endl;

    cout << "Default ctor..." << endl;
    NodeList deflt_node;
    cout << "Default ctor Test Successful" << endl;

    cout << endl << "Parameterized ctor..." << endl;
    NodeList parametrized_node(4,test1);
    cout << parametrized_node << endl;
    cout << "Parameterized ctor Test Successful" << endl;

    cout << endl << "Copy ctor..." << endl;
    NodeList cpyNode(parametrized_node);
    cout << cpyNode << endl;
    cout << "Copy ctor Test Successful" << endl;
    cout << endl;

    cout << "Assignment Operator..." << endl;
    ArrayList bNode(1, test1);
    ArrayList aNode(2, test2);
    cout << "Before Node Assignment" << endl << bNode << endl;
    bNode = aNode;
    cout << "After Node Assignment" << endl << bNode << endl;

    cout << endl <<  "Front Function..." << endl;
    cpyNode[0] = test2;
    cpyNode[3]= test3;
    cout << "First element of node is: " << cpyNode.front()->data()<< endl;

    cout << endl << "Back Function..." << endl;
    cout << "Last element of node is: " << cpyNode.back()->data()<< endl;

    cout << endl << "Find Function..." << endl;
    Node* prev = new Node();
    cout << "Find test2:";
    cout << cpyNode.find(test2, prev)->data() << endl;

    cout << endl << "InsertAfter Function..." << endl;
    cout << "Insert into node: ";
    cout << (cpyNode.insertAfter(test1, test4))->data() << endl;
    cout << cpyNode << endl;

    cout << endl << "InsertBefore Function..." << endl;
    cout << "Insert into node: ";
    cout << (cpyNode.insertBefore(test1,test3))->data() << endl;
    cout << cpyNode << endl;

    cout << endl << "Erase Function..." << endl;
    cout << "Next element after erased element: ";
    cout << (cpyNode.erase(test1))->data() << endl;
    cout << cpyNode << endl;

    cout << endl << "Index Operator..." << endl;
    cpyNode[1] = DataType(4, 7.8);
    cout << cpyNode << endl;

    cout << endl << "Size Function..." << endl;
    cout << "Size of array is: ";
    cout << cpyNode.size()<< endl;

    cout << endl <<  "Empty Function..." << endl;
    cout << (cpyNode.empty() ? "Array is empty" : "Array is not empty") << endl;

    cout << endl << "Deconstructors..." << endl;

    return 0;
}