// Created by Preetesh Barretto on 5/31/20.

//1. Write a function named "deleteZeros" that takes two arguments:
//(1) an array of integer values;
//(2) an integer for the number of elements in the array;
//The function will return the number of zeros that it has deleted from the array
//        The function should shift the contents of each element in the array whenever a zero
//element is deleted

#include <iostream>
using namespace std;

int deleteZeros(int numList[], int);

int main(){
    int numList[] = {10, 0, 20, 30, 0, 60, 40, 0, 50};
    int array_length = sizeof(numList)/sizeof(numList[0]);
    int zero_count = deleteZeros(numList, array_length);
    int non_zero_count = array_length - zero_count;
    cout << "Modified Array after removing zeros: ";
    for (int i = 0; i< non_zero_count ; i++) {
        cout << *(numList+i) << " ";
    }
    cout << endl;
    cout << "Number of Zeros: " << zero_count;
}

int deleteZeros(int numList[], int array_length) {
    int zero_count = 0;
    for (int i = 0; i < array_length; i++) {
        if (*(numList+i) == 0)
            zero_count++;
    }

    for (int j = 0; j <= zero_count; j++) {
        for (int i = 0; i < array_length - 1; i++) {
            if (*(numList + i) == 0) {
                int temp = *(numList + i);
                *(numList + i) = *((numList + i) + 1);
                *((numList + i) + 1) = temp;
            }
        }
    }
    return zero_count;
}