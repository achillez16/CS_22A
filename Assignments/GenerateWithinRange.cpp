//Write a C++ program named "GenerateWithinRange" that reads in from the user the following numbers:
// * How many numbers the user wants to generate
// * The lower limit
// * The upper limit
// It makes sure that these numbers are not negative. Then it generates that many random numbers within the user's range.//

// Created by Preetesh Barretto on 5/2/20.

#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
int main() {
    /* get the current system time and use it as the seed   */
    srand(time(0));    /* retrieve the next random number */
    int random_num = rand();    /* print it out */
    int total_nums = 0, lower = 0, upper = 0;

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

    int range = (upper - lower) + 1;
    for (int i =0 ; i <= total_nums; i++) {
        random_num = rand() % range + lower;
        cout << "Random number: " << random_num << endl;
    }

}