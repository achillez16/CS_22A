//
// Created by Preetesh Barretto on 5/17/20.


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const int profit_margin = 58;
    float sales = 8.6 , profit;
    cout << setprecision(2) << fixed;
    profit = sales*profit_margin/100;
    cout << "Profit is: $" << profit << " million";
}

