//Write a program named "EvaluateGrade" to read in a grade letter from the user and determine whether the user has
// passed the course or not. It will only accept valid grade character 'A', 'B' or 'C' to have the passing grades and
// 'D' and 'F' for failing grades. If the user has entered any other character, the program will print out an error
// message of "Invalid grade letter. Please try again." and ask the next grade letter again.

// The program should not have multiple "return" statements. In another words, your program should not have any
// "return" statement in the body of the loop.

// Created by Preetesh Barretto on 4/28/20.

#include <iostream>
using namespace std;

int main() {
    char grade;
    bool invalid = true;

    cout << "EvaluateGrade\n";
    do{
        cout << "Please enter your grade:";
        cin >> grade;

        switch (grade) {
            case 'A':
            case 'B':
            case 'C':
                cout << "You have passed the course.";
                invalid = false;
                break;
            case 'D':
            case 'F':
                cout << "You did not pass the course.";
                invalid = false;
                break;
            default:
                cout << "Invalid grade letter. Please try again.\n";
        }
    } while(invalid);
}