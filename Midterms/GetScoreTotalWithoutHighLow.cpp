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
            sum = number;
            continue;
        }
        else {
            if (number >= highest) {
                highest = number;
            } else if (number <= smallest) {
                smallest = number;
            }
            sum = sum + number;
        }
    }
    if (count < 3) {
        cout << "The total is: ";
        return 0;
    }
    cout << "Total Sum, Highest, Smallest, Count: " << sum << "," << highest << "," << smallest << "," << (count-2) << endl;
    sum = (sum - highest - smallest);
    cout << "The total is: ";
    return sum;
}

// OUTPUT

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/GetScoreTotalWithoutHighLow
//Please enter non-negative score: 20
//Please enter non-negative score: 40
//Please enter non-negative score: 50
//Please enter non-negative score: 80
//Please enter non-negative score: 10
//Please enter non-negative score: -1
//Total Sum, Highest, Smallest, Count: 200,80,10,3
//The total is: 110
//
//Process finished with exit code 0

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/GetScoreTotalWithoutHighLow
// Please enter non-negative score: -1
//The total is: 0
//
//Process finished with exit code 0

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/GetScoreTotalWithoutHighLow
//Please enter non-negative score: 0
//Please enter non-negative score: 0
//Please enter non-negative score: -1
//The total is: 0
//
//Process finished with exit code 0

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/GetScoreTotalWithoutHighLow
//Please enter non-negative score: 0
//Please enter non-negative score: 10
//Please enter non-negative score: 40
//Please enter non-negative score: 50
//Please enter non-negative score: -1
//Total Sum, Highest, Smallest, Count: 100,50,0,2
//The total is: 50
//
//Process finished with exit code 0
