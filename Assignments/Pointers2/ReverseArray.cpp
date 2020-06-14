// Created by Preetesh Barretto on 6/9/20.

//Question #10: Reverse Array
//Write a function that accepts an int array and the array’s size as arguments. The function should create a copy of the
//array, except that the element values should be reversed in the copy. The function should return a pointer to the new
//array. Demonstrate the function in a complete program.

#include <iostream>
using namespace std;
int getValidInput(int input);
void getArrayElements(int array[], int elements);
void putArrayElements(int array[], int elements);
int * reverseArray(int array[], int elements);

int main(){
    int elements =0;
    cout << "Enter the number of elements: ";
    elements = getValidInput(elements);
    int *pArray = new int[elements];
    int *newArray = reverseArray(pArray, elements);
    putArrayElements(newArray, elements);
}

int * reverseArray(int array[], int elements){
    getArrayElements(array, elements);
    int *tempArray = new int[elements];
    for (int i = 0, j = elements; i < elements; i++){
        *(tempArray + j - 1) = *(array + i);
        j--;
    }
    return tempArray;
}

int getValidInput(int input){
    while (!(cin >> input) or input < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid option: ";
    }
    return input;
}

void getArrayElements(int array[], int elements){
    for (int i =0; i < elements; i++) {
        cout << "Enter element " << i << ": ";
        cin >> array[i];
    }
}

void putArrayElements(int array[], int elements){
    cout << "{";
    for (int i = 0; i < elements; i++) {
        if (i !=0) cout << ",";
        cout << *(array+i);
    }
    cout << "}" << endl;
}