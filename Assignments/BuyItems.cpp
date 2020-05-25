//Write a purchase C++ program named “BuyItems” that performs the following tasks:
//Ask for the following info about the item to be purchased:
//- item's name
//- item's price
//- and the quantity
//
//The program will print out the invoice of the purchase with a nice format of the total + tax of 25%.
//
//Requirements:
//- The program must produce the provided expected sample output.
//- Print out the amount in the currency format with 2 decimal places

// Created by Preetesh Barretto on 4/25/20.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    const int SALES_TAX = 25;
    string item_name;
    float item_price = 0;
    float total = 0;
    float tax = 0;
    float invoice_amount = 0;
    int quantity = 0;


    cout << "Welcome to our store\n";
    cout << "Please enter the item's description: ";
    getline(cin, item_name);
    cout<< "Please enter the item's price: ";
    cin >> item_price;
    cout<< "Please enter the quantity: ";
    cin >> quantity;
    total = item_price * quantity;
    tax = (SALES_TAX * total)/100;
    invoice_amount = total + tax;
    cout << "----------------------------------\n";
    cout << "Invoice\n";
    cout << "Item's description: " << item_name << endl;
    cout << "Unit price: " << item_price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: " << fixed << setprecision(2) << total << endl;
    cout << "Tax(25%): " << tax << endl;
    cout << "Invoice Amount: " << fixed << setprecision(2) << invoice_amount << endl;
    cout << "----------------------------------\n";
    return 0;
}


