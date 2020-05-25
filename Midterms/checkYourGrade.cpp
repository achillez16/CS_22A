// Created by Preetesh Barretto on 5/24/20

//Write a function named "checkYourGrade" that reads in a character from the
//user and check for the following responses: ‘A’, ‘B’, ‘C’, ‘D’ or ‘F’ and return
//true if the response is ‘A’, ‘B’ or ‘C” and false if ‘D’ or ‘F”. Any other response,
//the function will print out “Invalid grade letter. Please try again.” and allow the
//user to retry up to 3 times, then it will return false.

#include <iostream>
using namespace std;
bool checkYourGrade();
const int MAX_ATTEMPTS = 3;
int main(){
    cout << boolalpha << (checkYourGrade()? "Passed" : "Failed");
}

bool checkYourGrade() {
    char grade;
    int count = 0;
    while (count < MAX_ATTEMPTS) {
        cout << "Please enter your grade: ";
        count += 1;
        cin >> grade;
        if (grade == 'A' or grade == 'B' or grade == 'C')
            return true;
        else if (grade == 'D' or grade == 'F')
            return false;
        else {
            if (count == 3) {
                continue;
            }
            cout << "Invalid grade letter. Please try again." << endl;
            continue;
        }
    }
}