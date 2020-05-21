// Created by Preetesh Barretto on 5/16/20

#include <iostream>
#include<iomanip>
using namespace std;


bool isAscending();
bool hasTheRightKey(int secretKey);
float calculateOneDayPay(float hours, float base_pay);
bool isANumberString(string str);

//Write a function named “isAscending” that has no parameter and it will returns a
//boolean value. It will read in non-negative numbers and return true if these
//numbers are in ascending order (the next number is always equal or greater than
//the previous number). The user will stop the input by entering a negative number.

bool isAscending(){
    int larger = 0, current = 0;

    cout << "Program to find if series of numbers are in Ascending order." << endl;
    cout << "Enter numbers. Program will stop after entering a negative number." << endl;
    while (true) {
        cin >> current;
        if (current < 0) {
            return true;
        }
        else if (current > larger) {
            larger = current;
            continue;
        }
        else
            return false;
    }
}

//Write a function named “hasTheRightKey” that accepts 1 number that represents
//the correct expected secret key. The method will read in a number from the user
//and check whether the user has entered the same expected key or not. If not, it
//will allow the user to try up to 3 times. If the user was able to enter the expected
//key number within 3 tries, it will return true. Otherwise, it returns false.
//bool hasTheRightKey(int secretKey)

bool hasTheRightKey(int secretKey) {
    int internal_secretKey = 42709;
    return internal_secretKey == secretKey;
}

float calculateOneDayPay(float hours, float base_pay) {
    const float BASE8_plus = 1.5;
    const float BASE12_plus = 2;
    float total_pay = 0;

    for (int i = 1; i <= hours; i++) {

        if (hours < 0 or hours > 24)
            return -1;
        else if (i <=8) {
            total_pay += base_pay;
        }
        else if (i >8 and i <= 12) {
            total_pay += BASE8_plus * base_pay;
        }
        else if (i > 12) {
            total_pay += BASE12_plus * base_pay;
        }
    }
    return total_pay;
}

//Write a function named “isANumberString” that accepts a string and returns true
//if that string contains a valid integer number and false otherwise.
//A valid number string is defined as a string starting with an optional sign of ‘+’ or
//‘-“ and contains only digits after that.
//The requirement is that you cannot use any provided conversion function or
//method but do the check yourself by examining each character in the string and
//perform the validity check in the method.
//For example, the following function calls

bool isANumberString(string str) {
    // Check for + / - in the 1st position.

    if (str[0] != '+' && str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
        return false;

    for (int i = 1; i < str.size(); i++){
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
        }
    return true;
}


int main() {

    cout << boolalpha << isAscending() << endl << endl << endl;

    cout << "Program to verify secret key." << endl;
    int incorrect_count = 3;
    while (true) {
        int key;
        cout << "Please enter your key: ";
        cin >> key;
        if (hasTheRightKey(key)) {
            cout << boolalpha << hasTheRightKey(key) << endl << endl << endl;
            break;
        } else if (!hasTheRightKey(key)) {
            cout << "Invalid Key" << endl;
            incorrect_count -= 1;
            if (incorrect_count > 0) {
                cout << "Attempts remaining: " << incorrect_count << endl;
                continue;
            } else {
                cout << "You have exhausted all attempts.\n\n\n";
                break;
            }
        }
    }

    float hours, base_pay;
    cout << "Enter total hours for the day & the base pay: ";
    cin >> hours >> base_pay;
    cout << "$" << fixed << setprecision(2) << calculateOneDayPay(hours, base_pay) << endl << endl << endl;

    string input_string;
    cout << "Enter a string: ";
    cin >> input_string;
    cout << boolalpha << isANumberString(input_string) << endl << endl << endl;
}

