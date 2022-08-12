#ifndef PROJ11_VECTORRECURSION_H
#define PROJ11_VECTORRECURSION_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Swap values
template <class T>
void swap(vector<T>&myVector, int x, int y){
    T temp = myVector[x];
    myVector[x]= myVector[y];
    myVector[y]= temp;
}

//Bubble Sort - easiest sorting
template <class T>
void vector_resort(vector<T>&myVector, int n){
    if(n == 1){
        return;
    }

    //Compares the two values and swaps if the next value is bigger
    for (T x = 0; x < n - 1 ; x++) {
        if(myVector[x] > myVector[x+1]){
            swap(myVector, x, x+1);
        }
    }

    vector_resort(myVector, n-1);
}

template <class T>
int vector_research(vector<T>&myVector, int l, int r, const T& value){
    if(r >= l){
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (myVector[mid] == value){
            return mid;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (myVector[mid] > value)
        {
            return vector_research(myVector, l, mid-1, value);
        }
        // Else the element can only be present
        // in right subarray
        return vector_research(myVector, mid+1, r, value);

    }

    return -1;
}

#endif //PROJ11_VECTORRECURSION_H
