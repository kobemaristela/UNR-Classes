#include <iostream>
#include "MyString.h"

int main() {
    cout << "\n" <<
         "////////////////////////////////\n" <<
         "/////   Constructor Tests  /////\n" <<
         "////////////////////////////////" << endl;

    cout << endl << "TESTING DEFAULT CTOR" << endl;
    MyString ms_default;
    cout << "Default ctor successful!" << endl;

    cout << endl << "TESTING PARAMETRIZED CTOR" << endl;
    MyString ms_parametrized("MyString parametrized constructor!");
    cout << "Parameterized ctor successful!" << endl;

    cout << endl << "TESTING COPY CTOR" << endl;
    MyString ms_copy(ms_parametrized);
    cout << "Copy ctor successful!" << endl;

    //Dtor not really used since already implied in allocation function
    cout << endl << "TESTING DTOR" << endl;
    MyString * ms_Pt = new MyString("MyString to be deleted…");
    delete ms_Pt;
    ms_Pt = NULL;
    cout << "Dtor successful!" << endl;

    cout << "\n" <<
         "/////////////////////////////////\n" <<
         "/////   Function Tests  /////\n" <<
         "/////////////////////////////////" << endl;

    cout << endl << "TESTING SIZE AND LENGTH FUNCTIONS" << endl;
    MyString ms_size_length("Size and length test");
    cout << ms_size_length.size() << endl; //returns sizeof()
    cout << ms_size_length.length() << endl; //returns strlen()

    cout << endl << "TESTING C-STR FUNCTION" << endl;
    MyString ms_toCstring("C-String equivalent successfully obtained!");
    cout << ms_toCstring.c_str() << endl; //return m_buffer pointer

    cout << "\n" <<
         "/////////////////////////////////\n" <<
         "/////   Operator Tests  /////\n" <<
         "/////////////////////////////////" << endl;

    cout << endl << "TESTING COMPARISON OPERATOR" << endl;
    MyString ms_same1("The same"), ms_same2("The same");
    if (ms_same1==ms_same2)
        cout << "Same success" << endl;
    MyString ms_different("The same (NOT)");
    if (!(ms_same1==ms_different))
        cout << "Different success" << endl;

    cout << endl << "TESTING ASSIGNMENT OPERATOR" << endl;
    MyString ms_assign("Before assignment");
    ms_assign = MyString("After performing assignment");
    cout << ms_assign << endl;

    cout << endl << "TESTING CONCATENATING OPERATOR" << endl;
    MyString ms_append1("The first part");
    MyString ms_append2(" and the second");
    MyString ms_concat = ms_append1+ ms_append2;
    cout << ms_concat << endl;

    cout << endl << "TESTING INDEX OPERATOR" << endl;
    MyString ms_access("Access successful (NOT)");
    ms_access[17] = 0;
    cout << ms_access << endl;
}