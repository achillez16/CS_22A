// Created by Preetesh Barretto on 5/24/20.

//Write a function named “GetScoreTotalWithoutHighLow.cpp” that reads in a
//list of scores until the user enters a negative number. It will add all the given
//scores up and subtract the largest and smallest scores to get a true score total. If
//there are only 2 numbers or less entered, the total will be 0.
//Note: please do not use array or vector class. Please use only local variables to
//keep track the total, highest and lowest.

#include <iostream>
using namespace std;
float GetScoreTotalWithoutHighLow();

int main() {
    cout << GetScoreTotalWithoutHighLow() << endl;
}

float GetScoreTotalWithoutHighLow() {
    int highest = INT_MIN, smallest = INT_MAX;
    float sum, number;
    int count = 0;
    while (true) {
        cout << "Please enter non-negative score: ";
        cin >> number;
        if (number < 0) {
            break;
        }
        count += 1;
        if (count == 1) {
            highest = number;
            smallest = number;
            cout << "Highest / smallest: " << highest << smallest << endl;
            sum = number;
            continue;
        }
        else {
            if (number >= highest) {
                highest = number;
                cout << "Highest: " << highest << endl;
            } else if (number <= smallest) {
                smallest = number;
                cout << "Smallest: " << smallest << endl;
            }
            sum = sum + number;
        }
    }
    if (count < 3) {
        cout << "The total is: ";
        return 0;
    }
    cout << "Sum, Highest, Smallest, Count: " << sum << "," << highest << "," << smallest << "," << (count-2) << endl;
    sum = (sum - highest - smallest);
    cout << "The total is: ";
    return sum;
}