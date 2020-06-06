// Created by Preetesh Barretto on 5/22/20.

#include<iostream>
#include <iomanip>
using namespace std;

double calculateRetail(double , double);

int main() {
    double cost, markup;
    cout << "Enter the cost & the markup: ";
    while (true){
        cin >> cost >> markup;
        if (cin.fail() or cost < 0 or markup < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Cost or Markup has to be a positive integer." << endl;
            cout << "Enter the cost & the markup: ";
        }
        else break;
    }

    cout << fixed << showpoint << setprecision(2);
    cout << "Total cost: $" << calculateRetail(cost, markup);
}

double calculateRetail(double cost, double markup) {
    double retail = cost + cost*(markup/100);
    return retail;
}
