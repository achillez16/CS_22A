// Created by Preetesh Barretto on 5/19/20.

#include <iostream>
#include <string>
using namespace std;

bool areFirstTwoTheSameAsLastTwoChars(string str);

int main() {

    string alpha;
    cout << "Enter the string: ";
    cin >> alpha;
    cout << "First 2 letters match last 2 ?: " << boolalpha << areFirstTwoTheSameAsLastTwoChars(alpha);
}

//Write a function named “areFirstTwoTheSameAsLastTwoChars” that accepts
//a string. It returns true if the first two characters and the last two characters of the
//string are the same. It returns false otherwise. In addition, if the string is empty or
//has only one character, it also returns false.

bool areFirstTwoTheSameAsLastTwoChars(string str) {
    int i = 0, length = str.length();
    int j = (length-1);

    if ((str[0] >= 'A' && str[0] <= 'Z') or (str[0] >= 'a' && str[0] <= 'z'))
        return ((str[i + 1] == str[j]) && (str[i] == str[j-1]));
    else
        return false;
}

// OUTPUTS
//Enter the string: ABCABV
//First 2 letters match last 2 ?: false
//Process finished with exit code 0

//Enter the string: A
//First 2 letters match last 2 ?: false

//Enter the string: ""
//First 2 letters match last 2 ?: false
//Process finished with exit code 0

//Enter the string: ABBAAB
//First 2 letters match last 2 ?: true