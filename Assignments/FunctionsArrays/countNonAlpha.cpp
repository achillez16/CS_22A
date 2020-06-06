// Created by Preetesh Barretto on 5/25/20.

//3. Write a function named "countNonAlpha" that accepts a string. It will return the number of non-alphabet characters
//(excluding blanks) in the string.
//For example, if the string is "Hello, World!", it will return 2 for ',' and '!" in the string.

#include <iostream>
#include <string>
using namespace std;
int countNonAlpha(string);

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin,str);
    cout << "Non Alpha Characters: " << countNonAlpha(str);
}

int countNonAlpha(string str){
    char c; int count = 0;
    for (int i=0; i< str.length(); i++) {
        char c = str[i];
        if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c == ' ')) continue;
        else count += 1;
    }
    return count;
}

// OUTPUT

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/countNonAlpha
//Enter a string: Hello, World!
//Non Alpha Characters: 2
//Process finished with exit code 0

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/countNonAlpha
//Enter a string: H#L!0 W0$L&
//Non Alpha Characters: 6
//Process finished with exit code 0