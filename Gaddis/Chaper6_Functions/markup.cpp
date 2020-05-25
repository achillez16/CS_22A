// Created by Preetesh Barretto on 5/22/20.

#include<iostream>
#include <iomanip>
using namespace std;

double calculateRetail(double , double);

int main() {
    double cost, markup, retail;
    cout << "Enter the cost & the markup: ";
    cin >> cost >> markup;

    cout << fixed << showpoint << setprecision(2);
    cout << "Total cost: $" << calculateRetail(cost, markup);
}

double calculateRetail(cost, markup) {
    double retail = cost + cost*(markup/100);
    return retail;
}
