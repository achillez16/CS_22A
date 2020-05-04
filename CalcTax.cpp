// Program to calculate Tax.

// Created by Preetesh Barretto on 5/3/20.

#include <iostream>
using namespace std;


int main(){
    int pin = 0;
    const int MAX_ATTEMPTS = 3;
    int attempts_left = MAX_ATTEMPTS;

    cout << "Welcome to my tax calculation program.\n";
    while(true) {
        cout << "Please enter the PIN code:";
        cin >> pin;
        if (pin == 5678 or pin == 8765)
            break;
        attempts_left-= 1;
        if (attempts_left > 0)
            cout << "Invalid pin code. Please try it again. You have " << attempts_left << " attempts left. \n";
        else {
            cout << "Invalid pin code. You have reached the maximum number of retries.";
            break;
        }
    }

}

