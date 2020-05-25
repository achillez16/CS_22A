// Created by Preetesh Barretto on 5/23/20.

//Write a function named "isTheSmallestLast" that reads in from the user inputs a
//list of numbers until the user enters 0. It will return true if the last number is the
// smallest number in that list and false otherwise. In addition, it also returns the
// actual value of the smallest number to the caller in the output parameter.
//For example, if the user enters 50, 30, 40, 10, 0, it will return true and 10 in the
//output parameter. If the user enters 50, 10, 40, 30, 0, it will return false and 10 in the output parameter.
//If the user enters 0 immediately, it will return false and 0 for the smallest.

#include <iostream>
using namespace std;

bool isTheSmallestLast(int &);

int main() {
    int smallest = INT_MAX;
    bool answer = isTheSmallestLast(smallest);
    cout << "Smallest number is: " << smallest << endl;
    cout << "Is the smallest number last: " << boolalpha << answer << endl;
}

bool isTheSmallestLast(int & smallest) {
    int last;
    int number, count = 0;

    while (true) {
        cout << "Enter a number: ";
        count += 1;
        cin >> number;
        if ((number == 0) && (count == 1)) {
            smallest = number;
            break;
        }
        else if (number == 0) {
            break;
        }
        last = number;
        if (last < smallest){
            smallest = last;
            continue;
        }
    }
    return (smallest == last);
}

// OUTPUT

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/isTheSmallestLast
//Enter a number: 50
//Enter a number: 20
//Enter a number: 90
//Enter a number: 0
//Smallest number is: 20
//Is the smallest number last: false


///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/isTheSmallestLast
//Enter a number: 0
//Smallest number is: 0
//Is the smallest number last: false

//Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/isTheSmallestLast

//Enter a number: 40
//Enter a number: 20
//Enter a number: 50
//Enter a number: 10
//Enter a number: 0
//Smallest number is: 10
//Is the smallest number last: true