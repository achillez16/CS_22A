// Created by Preetesh Barretto on 5/10/20.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool hasOnlyABC();
bool getAnswer();
void printIndentation();
float getAverageScore();

// 1. Write a function named “hasOnlyABC” that accepts a string as a parameter. It
//returns true if the string contains only ‘A’, ‘B’, ‘C’ characters. It returns false
//otherwise.
//For example, these strings of “A”, “ABC”, “AAA”, or “ABA” will return true and
//“D”, “ABD”, “ADA”, or “AAD” will return false.

bool hasOnlyABC(){
    string str;
    cout << "Enter a string of CAPITAL letters: ";
    cin >> str;
    int length = str.length() ;
    for (int i=0; i<length; i++) {
        char ch = str[i];
        if (ch == 'A' or ch == 'B' or ch == 'C')
            continue;
        else {
            return false;
        }
    }
    cin.clear();
    return true;
}

//2. Write a function named “getAnswer” that reads in a response (char) from the user. If
//the answer is not ‘Y’, ‘y’, “N’, or ‘n’, it will continue to ask the user for a new
//response until a valid response is entered.
//It will return true if the user enters ‘Y’ or ‘y’ and false otherwise.

bool getAnswer() {
    while (true) {
        char ch;
        cout << "Enter a character: ";
        cin >> ch;
        if (ch == 'Y' or ch == 'y' or ch == 'N' or ch =='n') {
            return true;
        }
        else {
            cout << "Invalid Input, Please try again." << endl;
            cin.clear();
            cin.ignore(32676,'\n');
            continue;
        }
    }
}

////3. Write a method named “getAverageScore” that will read in a list of non-negative
////scores (integer) from the user until the user enters a negative number to end. It will
////throw away the largest and smallest number in the list and return the average of the
////rest of the list (total / the number of scores). If the user has entered less than 3
////numbers, it will return -1.
////For example, if the user enters 100, 10, 0, -1, it will return 10.
////If the list is 100, -1, it will return -1 (as it does not have at least 3 numbers)
////Or the list of 100, 10, -1 will also return -1 because it has only 2 numbers.
////If the list is 100, 80, 90, 0, -1, then the total is 85 as it does not count 100 (the
////maximum) and 0 (the minimum).
////Similarly, if the list is 80, 90, 100, 70, 60, -1, then the average is 80 as 100 and 60 do
////not count toward the total.

float getAverageScore(){

    int highest, smallest;
    float sum, number;
    float average;

    cout << "Enter list of integers, program will exit after entering number less than 0: " << endl;
    int count = 0;
    while (true) {
        cin >> number;
        if (number < 0) {
            break;
        }
        count += 1;
        if (count == 1) {
            highest = smallest = number;
  //          cout << "Highest / smallest: " << highest << smallest << endl;
            sum = number;
            continue;
        }
        else {
            if (number > highest) {
                highest = number;
  //              cout << "Highest: " << highest << endl;
            } else if (number < smallest) {
                smallest = number;
  //              cout << "Smallest: " << smallest << endl;
            }
            sum = sum + number;
        }
    }
    if (count < 3)
        return -1;

  //  cout << "Sum, Highest, Smallest, Count: " << sum << "," << highest << "," << smallest << "," << (count-2) << endl;
    average = (sum - highest - smallest) / (count - 2);

    cout << "Skipping Highest & Smallest numbers and calculating the average: " << endl;
    return average;
}

//4. Write a function named "printIndentation" that accepts a string and an integer for
//the number of blanks to be printed in front of that string.
//It will print out that many blanks first before it prints out the given string.
//For example, printIndentation(“Hello”, 5) will print as follows
// Hello
//while printIdentation(“Hello”, 0) will print
//Hello
//And printIdentation(“Hello”, 10) will print
// Hello

void printIndentation() {
    string alpha;
    int offset;
    cout << "Enter a string: ";
    cin >> alpha;
    cout << "Enter the offset:";
    cin >> offset;
    cout << setw(offset) << alpha << endl;
}

//5. Write a complete C++ program named “TestDriver.cpp” that shows how you would
//test the functions that you implement in question 1-4.
//Please show various function calls that show different results, conditions and return
//values.
//Note: if you have written main() and test each method separately, you don’t need to
//answer this question.

int main(){
//    cout << boolalpha << hasOnlyABC() << endl;
//    cout << boolalpha << getAnswer() << endl;
    cout << getAverageScore() << endl;
//    printIndentation();

}