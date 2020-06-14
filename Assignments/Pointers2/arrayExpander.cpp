// Created by Preetesh Barretto on 6/9/20.

//Question #11: Array Expander
//Write a function that accepts an int array and the array’s size as arguments. The function should create a new array
//that is twice the size of the argument array. The function should copy the contents of the argument array to the new
//array and initialize the unused elements of the second array with 0. The function should return a pointer to the new
//array.

#include <iostream>
using namespace std;

int * arrayExpander(int array[], int elements);
void getArrayElements(int array[], int elements);
int getValidInput(int input);
void putArrayElements(int array[], int elements);

int main(){
    int elements =0, new_elements = 0;
    cout << "Enter the number of elements: ";
    elements = getValidInput(elements);
    new_elements = 2*elements;
    int *pArray = new int[elements];
    int *newArray = arrayExpander(pArray, elements);
    putArrayElements(newArray, new_elements);
}

int * arrayExpander(int array[], int elements){
    getArrayElements(array, elements);
    int new_elements = elements*2;
    int *tempArray = new int[new_elements];
    for (int i = 0; i < new_elements; i++){
        if (i >= elements)
            *(tempArray + i) = 0;
        else
            *(tempArray + i) = *(array + i);
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