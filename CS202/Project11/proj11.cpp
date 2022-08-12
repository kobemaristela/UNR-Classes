#include "VectorRecursion.h"

int main() {
    //Vector creation
    vector<int> vecInt;

    //Vector population with input values
    fstream fin("RandomData.txt");
    int fin_in, count = 0;
    while(fin) {
        fin >> fin_in;
        if (!fin){
            break;
        }
        vecInt.push_back(fin_in);
        count++;
    }

    //Makes copy of vecInt
    vector<int> vecIntCpy(vecInt);

    //Sorts vector
    vector_resort(vecInt, count);

    // Vector indexing and output ( using operator[] or at() )
    cout<< "***************************************************" << endl;
    cout<< "*************BEFORE SORTING************************" << endl;
    cout<< "***************************************************" << endl;
    for(size_t i=0; i<vecIntCpy.size(); ++i) {
        std::cout << vecIntCpy[i] << " same as " << vecIntCpy.at(i) << std::endl;
    }

    cout<< "***************************************************" << endl;
    cout<< "*************AFTER SORTING*************************" << endl;
    cout<< "***************************************************" << endl;
    for(size_t i=0; i < vecInt.size(); ++i) {
        std::cout << vecInt[i] << " same as " << vecInt.at(i) << std::endl;
    }

    cout << endl;

    //User Input - Search
    int userInput;
    cout << "What value do you want to search? " << endl;
    cin >> userInput;
    int result = vector_research(vecInt, 0, count - 1, userInput);

    if(result != -1){
        cout << "Value has been found at index: " << result << endl;
    } else{
        cout << "Value was not found." << endl;
    }

    return 0;
}