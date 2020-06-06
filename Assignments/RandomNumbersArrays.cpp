//Extend your random generating program to make sure that the numbers are unique.
//This time, you simply ask the user for how many random numbers that they want to generate. Then you will generate that
//many numbers but these numbers must be unique (e.g. no duplicate). In another words, if the number has been generated
//and appeared early, the program should continue to find the next random number until the number is unique.
//Hint: You can limit the number of random numbers to be between 0 to 1000 and use the array of booleans to check whether
//the number has been generated.

// Created by Preetesh Barretto on 5/27/20.

#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
bool numberExists(int array[], int, int);
void printArray(int array[], int);

int main() {
    /* get the current system time and use it as the seed   */
    srand(time(0));    /* retrieve the next random number */
    int total_nums = 0, lower = 0, upper = 0, range;
    int array[INT_MAX];

    while (true) {
        while (true) {
            cout << "How many numbers that you want to generate? ";
            cin >> total_nums;
            if (total_nums > 0)
                break;
            cout << "Number cannot be negative. Please try again.\n";
        }

        while (true) {
            cout << "What is the lower limit? ";
            cin >> lower;
            if (lower > 0)
                break;
            cout << "Number cannot be negative. Please try again.\n";
        }

        while (true) {
            cout << "What is the upper limit? ";
            cin >> upper;
            if (upper > 0 && upper > lower)
                break;
            else if (upper < 0)
                cout << "Number cannot be negative. Please try again.\n";
            else if (upper <= lower)
                cout << "Upper cannot be less than / equal to lower. Please try again.\n";
        }
        range = (upper - lower) + 1;
        if (range < total_nums) {
            cout << "Total numbers exceed the range, unique random numbers cannot be generated." << endl;
            cout << "Please try again." << endl;
        }
        else
            break;
    }
    for (int i =0 ; i < total_nums; i++) {
        int random_num = rand() % range + lower;
        if (!numberExists(array, i, random_num)) array[i] = random_num;
        else i--;
    }
    printArray(array, total_nums);
}

bool numberExists(int array[], int i, int random_num){
    for (int j = 0; j < i; j++)
        if (array[j] == random_num) return true;
    return false;
}

void printArray(int array[], int total_nums){
    for (int i = 0; i < total_nums; i++) {
        cout << "Number" << i+1 << ": ";
        cout << array[i] << endl;
    }
}