// Created by Preetesh Barretto on 6/9/20.
//

//Question #12: Element Shifter
//Write a function that accepts an int array and the array’s size as arguments. The function should create a new array
//that is one element larger than the argument array. The first element of the new array should be set to 0. Element 0 of
//the argument array should be copied to element 1 of the new array, element 1 of the argument array should be copied to
//element 2 of the new array, and so forth. The function should return a pointer to the new array.

#include <iostream>
using namespace std;
int getValidInput(int input);
void getArrayElements(int array[], int elements);
void putArrayElements(int array[], int elements);
int * elementShifter(int array[], int elements);

int main(){
    int elements =0, new_elements = 0;
    cout << "Enter the number of elements: ";
    elements = getValidInput(elements);
    new_elements = elements+1;
    int *pArray = new int[elements];
    int *newArray = elementShifter(pArray, elements);
    putArrayElements(newArray, new_elements);
}

int * elementShifter(int array[], int elements){
    getArrayElements(array, elements);
    int new_elements = elements+1;
    int *tempArray = new int[new_elements];
    for (int i = 0; i < new_elements; i++){
        if (i == 0)
            *(tempArray + i) = 0;
        else
            *(tempArray + i) = *(array + i-1);
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