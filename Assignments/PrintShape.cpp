//Write a C++ program named "PrintShape" that will read in from the user the shape integer number
// (1 for triangle and 2 for square) and the character used in the printed shape. It then prints out the given shape
// using the given character. If the user did not enter 1 or 2 for the shape number, it will print out an error message.

//For now, the shape can be a simple 3 lines.

// Created by Preetesh Barretto on 4/25/20.

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char C;
    int input;
    cout << " Which shape do you want to display (1 for triangle, 2 for square) ? ";
    cin >> input;
    cout << "Which character do you want to be used in the shape ? ";
    cin >> C;

    if (input == 1) {
        printf("%*c\n", 3, C);
        printf("%*c%c%c\n", 2,  C , C, C);
        printf("%*c%c%c%c%c\n", 1, C , C, C, C, C);
    }

    else if (input == 2) {
        printf("%*c%c%c\n",1,C,C,C);
        printf("%c%*c\n",C,2,C);
        printf("%*c%c%c\n",1,C,C,C);
    }

    else {
        cout << "Unsupported shape number.";
    }
return 0;

}

