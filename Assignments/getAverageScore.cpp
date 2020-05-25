// Created by Preetesh Barretto on 5/14/20.

//3. Write a method named “getAverageScore” that will read in a list of non-negative
//scores (integer) from the user until the user enters a negative number to end. It will
//throw away the largest and smallest number in the list and return the average of the
//rest of the list (total / the number of scores). If the user has entered less than 3
//numbers, it will return -1.
//For example, if the user enters 100, 10, 0, -1, it will return 10.
//If the list is 100, -1, it will return -1 (as it does not have at least 3 numbers)
//Or the list of 100, 10, -1 will also return -1 because it has only 2 numbers.
//If the list is 100, 80, 90, 0, -1, then the total is 85 as it does not count 100 (the
//maximum) and 0 (the minimum).
//Similarly, if the list is 80, 90, 100, 70, 60, -1, then the average is 80 as 100 and 60 do
//not count toward the total.

#include <iostream>
#include <iomanip>
using namespace std;

int max_num =0, num = 0, num_pos = 0;

int getHighest(int array[]);
int getSmallest(int array[]);
float getAverageScore(int array[]);

int getHighest(int array[]) {
    int highest = array[0];
    for (int count=0; count < num_pos; count++){
        if (array[count] > highest) {
            highest = array[count];
        }
    }
    return highest;
}

int getSmallest(int array[]){
    int smallest = array[0] ;
    for (int count=0; count < num_pos; count++){
        if (smallest > array[count]) {
            smallest = array[count];
        }
    }
    return smallest;
}

float getAverageScore(int array[]) {
    float avg_count = 0;
    float sum = 0;
    int highest = getHighest(array);
    cout << "Highest Number is: " << highest << endl;
    int smallest = getSmallest(array);
    cout << "Smallest Number is: " << smallest << endl;

    for (int count = 0; count < num_pos; count++) {
        if (array[count] == highest or array[count] == smallest) {
            continue;
        }
        else {
            avg_count++;
            sum += array[count];
        }
    }
    float average = sum / avg_count;
    return average;
}
int main () {
    cout << "Enter max numbers: ";
    cin >> max_num;
    int avgList[max_num];

    while (true) {
        cout << "Enter list of integers, program will exit after entering -1 or max count: " << endl;
        for (int count = 0; count < max_num; count++){
            cout << "Num" << count+1 << ": ";
            cin >> num;
            if (num < 1) {
                cout << "Skipping Highest & Smallest numbers and calculating the average." << endl;
                break;
            }
            avgList[count] = num;
            num_pos++;
            cin.clear();
        }
        break;
    }

    float average = getAverageScore(avgList);
    cout << "Average of list is: " << fixed << setprecision(2) << average;
}