// Created by Preetesh Barretto on 6/5/20.

//Question #9: Median Function
//In statistics, when a set of values is sorted in ascending or descending order, its median is the middle value. If the
// set contains an even number of values, the median is the mean, or average, of the two middle values. Write a function
// that accepts as arguments the following:

//A. An array of integers
//B. An integer that indicates the number of elements in the array
//The function should determine the median of the array. This value should be returned as a double. (Assume the values
// in the array are already sorted.)
//Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.

#include <iostream>
using namespace std;
double medianFunction(int array[], int elements);
int getValidInput(int input);
void getArrayElements(int array[], int elements);
double median;

int main(){
    int input = 0;
    cout << "Enter the number of elements: ";
    input = getValidInput(input);
    int *pArray = new int[input];
    median = medianFunction(pArray, input);
    cout << "Median of the above series is: " << median;
}

double medianFunction(int array[], int elements){
    getArrayElements(array, elements);
    if(elements % 2 == 0) {
        median = (*(array + elements/2 -1) + *(array + elements/2))/2;
    }
    else {
        median =  *(array + elements/2);
    }
    return median;
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
        cin >> *(array+i);
    }
}