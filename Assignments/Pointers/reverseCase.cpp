// Created by Preetesh Barretto on 5/31/20.

//Write a function named "reverseCase" that takes only one argument of the pointer
//to a C-string (an array of characters that terminates with a NULL ('\0') character).
//The function will change all lower cases to upper case and vice server in that given
//string. If it is not alphabet, it will be unchanged.
//The function will return the number of letters that it has changed.
//For example, if the array is defined as
//char greeting[] = " Hello, World! ";
//It will return 10 and change the array to contain
//hEELO, wORLD!

#include <iostream>
using namespace std;
int reverseCase(char array[], int);

int main() {

    char greeting[] = " Hello, World! ";
    int array_size = sizeof(greeting)/sizeof(char);
    int count = reverseCase(greeting, array_size);
    cout << "# of case conversions: " << count << endl;
    cout << "Modified Array: " << greeting;
}

int reverseCase(char array[], int length){
    int count = 0;
    for (int i = 0; i < length; i++) {
        if ((*(array+i) >= 'A' && *(array+i) <= 'Z') or (*(array+i) >= 'a' && *(array+i) <= 'z')) {
            count++;
            if (islower(*(array+i))) {
                *(array + i) = toupper(*(array + i));
            }
            else if (isupper(*(array+i))) {
                *(array + i) = tolower(*(array + i));
            }
        }
    }
    return count;
}
