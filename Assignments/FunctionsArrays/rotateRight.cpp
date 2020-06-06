// Created by Preetesh Barretto on 5/25/20.

//2. Write a function named "rotateRight" that accepts an array of integers and its size. It will rotate all the values
//to the right and move the value of the last element in the array to the first.
//For example, array of {10, 20, 30} will become {30, 10, 20}.

#include <iostream>
using namespace std;
void rotateRight(int array[], int);
int main(){
    int length;
    cout << "Enter size of Array: ";
    cin >> length;
    int array[length];
    for (int i=0; i<= length-1; i++) {
        cout << "Enter number " << (i+1) <<" : ";
        cin >> array[i];
    }

    rotateRight(array, length);

    for (int i=0; i<= length-1; i++) {
        cout << array[i] << ", ";
    }
}

void rotateRight(int array[],int length)  {
    int last = array[length-1];
    for (int i=length-1; i>=0; i--) {
        array[i] = array[i-1];
    }
    array[0] = last;
}

// OUTPUT

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/rotateRight
//Enter size of Array: 5
//Enter number 1 : 30
//Enter number 2 : 40
//Enter number 3 : 50
//Enter number 4 : 60
//Enter number 5 : 70
//70, 30, 40, 50, 60,
//Process finished with exit code 0
