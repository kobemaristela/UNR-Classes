#include <iostream>
#include "ArrayQueue.h"
#include "NodeQueue.h"

int main() {

    DataType Data1(1, 1.1);
    DataType Data2(2, 2.2);

    cout << "************************" << endl;
    cout << "*****ARRAYQUEUE TEST****" << endl;
    cout << "************************" << endl;
    cout << endl;

    //Default Constructor
    ArrayQueue Array_1;
    cout << "Default Constructor" << endl;
    cout << Array_1 << endl;

    //Parameterized Ctor
    ArrayQueue Array_2(3, Data1);
    cout << "Parameterized Constructor" << endl;
    cout << Array_2 << endl;

    //Copy Constructor
    ArrayQueue Array_3(Array_2);
    cout << "Copy Constructor" << endl;
    cout << Array_3 << endl;

    //Assignment Operator
    Array_1 = Array_3;
    cout << "Assignment Operator" << endl;
    cout << Array_1 << endl;

    //Push Function
    cout << "How many items would you want to add? " << endl;
    int myInput;
    cin >> myInput;
    cout << endl;
    for (int x = 0; x < myInput; x++){
        DataType temp(x * 1, x * 2.2);
        Array_2.push(temp);
    }
    cout << "Push Function" << endl;
    cout << Array_2 << endl;

    //Front Function
    cout << "Front Function after push" << endl;
    cout << Array_2.front() << endl;
    cout << endl;

    //Back Function
    cout << "Back Function after push" << endl;
    cout << Array_2.back() << endl;
    cout << endl;

    //Pop Function
    string sInput;
    do{
        cout << "Do you want to remove first item? (yes or no) " << endl;
        cin >> sInput;
        cout << endl;
        if(sInput == "yes"){
            Array_2.pop();
            cout << "Pop Function" << endl;
            cout << Array_2 << endl;
        }else if(sInput == "no")
        {
            break;
        }
        else{
            sInput = "yes";
            cout << "Input wrong..." << endl;
            cout << endl;
        }

    }while(sInput == "yes");

    //Front Function
    cout << "Front Function after push" << endl;
    cout << Array_2.front() << endl;
    cout << endl;

    //Back Function
    cout << "Back Function after push" << endl;
    cout << Array_2.back() << endl;
    cout << endl;

    //Size Function
    cout << "Size Function" << endl;
    cout << Array_2.size() << endl;
    cout << endl;

    //Empty function
    cout << "Empty Function" << endl;
    if(Array_2.empty()){
        cout << "Function is empty..." << endl;
    }else{
        cout << "Function is not empty..." << endl;
    }
    cout << endl;

    //Full Function
    cout << "Full Function" << endl;
    if(Array_2.full()){
        cout << "Function is full..." << endl;
    }else{
        cout << "Function is not full..." << endl;
    }
    cout << endl;

    cout << "************************" << endl;
    cout << "*****NODEQUEUE TEST*****" << endl;
    cout << "************************" << endl;
    cout << endl;

    //Default Constructor
    cout << "Default Constructor" << endl;
    NodeQueue firstNode;
    cout << endl;

    //Parameterized Constructor
    NodeQueue secondNode(2, Data2);
    cout << "Parameterized Constructor" << endl;
    cout << secondNode << endl;

    //Copy Constructor
    cout << "Copy Constructor" << endl;
    NodeQueue thirdNode(secondNode);
    cout << thirdNode << endl;

    //Assignment Operator
    firstNode = thirdNode;
    cout << "Assignment Operator" << endl;
    cout << firstNode << endl;


    //Push Function
    cout << "How many items would you want to add? " << endl;
    int userInput;
    cin >> userInput;
    cout << endl;
    for (int x = 0; x < userInput; x++){
        DataType temp(x * 1, x * 2.2);
        firstNode.push(temp);
    }
    cout << "Push Function" << endl;
    cout << firstNode << endl;

    //Front Function
    cout << "Front Function after push" << endl;
    cout << firstNode.front() << endl;
    cout << endl;

    //Back Function
    cout << "Back Function after push" << endl;
    cout << firstNode.back() << endl;
    cout << endl;

    //Pop Function
    string input;
    do{
        cout << "Do you want to remove first item? (yes or no) " << endl;
        cin >> input;
        cout << endl;
        if(input == "yes"){
            firstNode.pop();
            cout << "Pop Function" << endl;
            cout << firstNode << endl;
        }else if(input == "no")
        {
            break;
        }
        else{
            input = "yes";
            cout << "Input wrong..." << endl;
            cout << endl;
        }

    }while(input == "yes");

    //Front Function
    cout << "Front Function after pop" << endl;
    cout << firstNode.front() << endl;
    cout << endl;

    //Back Function
    cout << "Back Function after pop" << endl;
    cout << firstNode.back() << endl;
    cout << endl;

    //Size Function
    cout << "Size Function" << endl;
    cout << firstNode.size() << endl;
    cout << endl;

    //Empty Function
    cout << "Empty Function" << endl;
    if(firstNode.empty()){
        cout << "Function is empty..." << endl;
    }else{
        cout << "Function is not empty..." << endl;
    }
    cout << endl;

    //Full Function
    cout << "Full Function" << endl;
    if(firstNode.full()){
        cout << "Function is full..." << endl;
    }else{
        cout << "Function is not full..." << endl;
    }

    cout << endl << "**********Deconstructors**********" << endl;

    return 0;
}