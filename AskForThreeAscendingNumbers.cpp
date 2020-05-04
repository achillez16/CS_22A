// Write a C++ program named "AskForThreeAscendingNumbers" that will read in from the users 3 numbers.
// It makes sure that the 2nd number is always greater than the 1st and the 3rd number is always greater than the 2nd.
// If it is smaller, it will print out an error message and ask the user to re-enter the number until it is greater.
// Once reading is complete, it will print out all 3 numbers.

// Created by Preetesh Barretto on 4/28/20.

#include <iostream>
using namespace std;
int main() {
    bool ascending = false;
    int first = 0, second = 0, third = 0;

    cout << "Please enter 3 numbers in the ascending order.\n";
    cout << "Please enter 1st number: ";
    cin >> first;
    while (second <= first){
        cout << "Please enter 2nd number: ";
        cin >> second;
        if (second <= first)
            cout << "It is smaller than the first number. Please try again.\n";
    }
    while (third <= second){
    cout << "Please enter 3rd number: ";
    cin >> third;
        if (third <= second)
            cout << "It is smaller than the second number. Please try again.\n";
    }
    cout << "The 3 ascending numbers are: " << first << " " << second << " " << third;
}