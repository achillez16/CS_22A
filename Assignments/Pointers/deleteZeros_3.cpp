// Created by Preetesh Barretto on 5/31/20.

//1. Write a function named "deleteZeros" that takes two arguments:
//(1) an array of integer values;
//(2) an integer for the number of elements in the array;
//The function will return the number of zeros that it has deleted from the array
//The function should shift the contents of each element in the array whenever a zero
//element is deleted

#include <iostream>
using namespace std;
int deleteZeroes(int array[], int numOfElements);

int main(){
    int array_size;
    cout << "Enter the size of the array: ";
    cin >> array_size;
    int *pArray = new int[array_size];

    for(int i = 0; i < array_size; i++) {
        cout << "Array Element " << i << ": ";
        cin >> pArray[i];
    }

    int zeroes = deleteZeroes(pArray, array_size);
    cout << "Number of Zeroes: " << zeroes << endl;
    int non_zero_count = array_size - zeroes;

    cout <<"{";
    for (int i = 0; i < non_zero_count; i++)
    {   if (i !=0) cout << ",";
        cout << pArray[i];
    }
    cout << "}";
}

int deleteZeroes(int array[], int numOfElements){
    int zeroes = 0;
    int i, j;
    for (i = 0, j =0 ; j< numOfElements; j++) {
        if (array[j] !=0) {
            if (i < j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            i++;
        }
        else if (array[j] == 0)
            zeroes++;
    }
    return zeroes;
}

