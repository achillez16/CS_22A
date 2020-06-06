// Created by Preetesh Barretto on 5/24/20.

//1. Write a function named "countPositiveNegative" that accepts an array of integers, its size and return the number
//of positive and negative in the array through the use of parameters. In addition, it also returns the number of 0s in
//the array as the return value. For example, array of {10, 20, -30, -40, 50, 0, 60} will return 4 for positives, 2 for
//negatives and 1 for 0's as the return value.

#include <iostream>
using namespace std;
void countPositiveNegative(int array[], int, int&, int&, int&);

int main() {
    int length, positive = 0, negative =0, zero = 0;
    cout << "Enter size of the array: ";
    cin >> length;
    int array[length];

    for (int i = 0; i<= length-1; i++) {
        cout << "Enter number "<< i+1 <<": ";
        cin >>  array[i];
    }
    countPositiveNegative(array,length, positive, negative, zero);
    cout << "#Positive: " << positive << " #Negative: " << negative << " #Zeros: " << zero;
}

void countPositiveNegative(int array[],int length, int &positive, int &negative, int &zero){

    for (int i=0; i<= length-1; i++) {
        if (array[i] < 0) negative += 1;
        else if (array[i] > 0) positive += 1;
        else zero += 1;
    }
}

// OUTPUTS

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/countPositiveNegative
//Enter size of the array: 6
//Enter number 1: 0
//Enter number 2: 2
//Enter number 3: 50
//Enter number 4: -40
//Enter number 5: 0
//Enter number 6: -30
//#Positive: 2 #Negative: 2 #Zeros: 2
//Process finished with exit code 0


