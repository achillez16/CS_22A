// Created by Preetesh Barretto on 5/29/20.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void showAll(string description[], double amount[], int);
void addSpending(string description[],double amount[], int);
void searchString(string description[], double amount[], int);
void searchAmount(string description[], double amount[], int);
string convertToLower(string str);

int main() {
    const int MAX_ENTRIES = 1000;
    int count = 0;
    int option;
    string description[MAX_ENTRIES];
    double amount[MAX_ENTRIES];
    cout << "Welcome to my expense tracker.\n";

    do {
        cout << "Expense Tracking Menu:\n"
             << "  1. show all\n"
             << "  2. spend\n"
             << "  3. search expenses containing this string\n"
             << "  4. search expenses with greater than or equal to this amount\n"
             << "  5. exit\n";

        bool check = true;
        while (check) {
            cout << "Enter your option: ";
            cin >> option;
            if (cin.fail() or option < 1 or option > 5) {
                cout << "Please enter a valid option.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                check = false;
            }
        }

        switch(option) {
            case 1:
                showAll(description, amount, count);
                break;
            case 2:
                addSpending(description, amount, count);
                count++;
                break;
            case 3:
                searchString(description, amount, count);
                break;
            case 4:
                searchAmount(description, amount, count);
                break;
            case 5:
                cout << "Thank you for using MyExpenses program.\n";
                break;
            default:
                cout << "Please enter a valid option.\n";
                break;
        }
    } while (option != 5);
}

void showAll(string description[], double amount[], int count) {
    if (count == 0) {
        cout << "\nThere is no expense entry available. \n\n";
    }
    else {
        cout << "Expenses:" << endl;
        for (int i=0; i< count; i++) {
            cout << "AMOUNT(" << amount[i] <<")" << " " << "DESC(" << description[i] << ")\n";
        }
    }
}

void addSpending(string description[], double amount[], int count) {
    cout << "Please enter the description for the expense: ";
    getline(cin, description[count]);
    cout << "Please enter the amount: ";
    cin >> amount[count];
    while (amount[count] < 0 or cin.fail()) {
        cout << "Invalid amount. Amount cannot be negative or string. Please try it again.\n";
        cout << "Please enter the amount: ";
        cin >> amount[count];
        }
}

void searchString(string description[], double amount[], int count) {
    string search;
    bool found = false;
    cout << "Please enter the search string: ";
    getline(cin, search);
    search = convertToLower(search);
    if (count == 0) {
        cout << "There is no expense entry available." << endl;
    }
    for (int i=0; i< count; i++) {
        string str = description[i];
        string temp[1000];
        temp[i] = convertToLower(str);
        if (temp[i].find(search, 0) !=std::string::npos) {
            found = true;
            cout << "AMOUNT(" << amount[i] <<")" << " " << "DESC(" << description[i] << ")\n";
        }
    }
    if (!found) cout << "No match found for entered search string.\n";
}


void searchAmount(string description[], double amount[], int count) {
    int search;
    bool found = false;
    cout << "Please enter the amount: ";
    cin >> search;
    for (int i =0; i < count; i++) {
        if (amount[i] >= search) {
            cout << "AMOUNT(" << amount[i] << ")" << " " << "DESC(" << description[i] << ")\n";
            found = true;
        }
    }
    if (!found) cout << "No expense greater than the entered amount.\n";
}

string convertToLower(string str){
    int str_len = str.length();
    for (int i = 0; i<= str_len; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
    return str;
}

// OUTPUTS

///Users/preetesh/CLionProjects/CS_22A/cmake-build-debug/TrackMyExpensesUsingArray
//        Welcome to my expense tracker.
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 1
//
//There is no expense entry available.
//
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 2
//Please enter the description for the expense: netflix membership
//Please enter the amount: 15
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 2
//Please enter the description for the expense: Prime Membership
//Please enter the amount: 120
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 2
//Please enter the description for the expense: Gym membership
//Please enter the amount: 35
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 2
//Please enter the description for the expense: Phone Bill
//Please enter the amount: 24
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 2
//Please enter the description for the expense: Electricity bill
//Please enter the amount: 120
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: Water and Trash
//Please enter a valid option.
//Enter your option: 2
//Please enter the description for the expense: Water and Trash
//Please enter the amount: 89
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 3
//Please enter the search string: bill
//        AMOUNT(24) DESC(Phone Bill)
//AMOUNT(120) DESC(Electricity bill)
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 4
//Please enter the amount: 20
//AMOUNT(120) DESC(Prime Membership)
//AMOUNT(35) DESC(Gym membership)
//AMOUNT(24) DESC(Phone Bill)
//AMOUNT(120) DESC(Electricity bill)
//AMOUNT(89) DESC(Water and Trash)
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 4
//Please enter the amount: 25
//AMOUNT(120) DESC(Prime Membership)
//AMOUNT(35) DESC(Gym membership)
//AMOUNT(120) DESC(Electricity bill)
//AMOUNT(89) DESC(Water and Trash)
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: -20
//Please enter a valid option.
//Enter your option: asdc
//        Please enter a valid option.
//Enter your option: -1
//Please enter a valid option.
//Enter your option: 1
//Expenses:
//AMOUNT(15) DESC(netflix membership)
//AMOUNT(120) DESC(Prime Membership)
//AMOUNT(35) DESC(Gym membership)
//AMOUNT(24) DESC(Phone Bill)
//AMOUNT(120) DESC(Electricity bill)
//AMOUNT(89) DESC(Water and Trash)
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 4
//Please enter the amount: -20
//AMOUNT(15) DESC(netflix membership)
//AMOUNT(120) DESC(Prime Membership)
//AMOUNT(35) DESC(Gym membership)
//AMOUNT(24) DESC(Phone Bill)
//AMOUNT(120) DESC(Electricity bill)
//AMOUNT(89) DESC(Water and Trash)
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 4
//Please enter the amount: 1000
//No expense greater than the entered amount.
//Expense Tracking Menu:
//1. show all
//2. spend
//3. search expenses containing this string
//4. search expenses with greater than or equal to this amount
//5. exit
//        Enter your option: 5
//Thank you for using MyExpenses program.
//
//Process finished with exit code 0
