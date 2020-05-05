/* Program to calculate Tax.
   Created by Preetesh Barretto on 5/3/20.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int TAX_RATE1 = 25;
const int TAX_RATE2 = 50;
float income, interest, deduction, paid_tax, tax_amount, final_amount, due, refund;
bool isDue = false, isRefund = false;

void getTaxInfo() {
    cout << "Lets gather some information on your finances this year.\n";
    while(true) {
        cout << "Please enter the amount from W2 form: ";
        cin >> income;
        if (income < 0) {
            cout << "Invalid amount. Income cannot be negative.\n";
            continue;
        }
        else
            break;
    }

    while(true) {
        cout << "Please enter the Interest income: ";
        cin >> interest;
        if (interest < 0) {
            cout << "Invalid amount. Interest income cannot be negative.\n";
            continue;
        }
        else
            break;
    }

    while(true){
        cout << "Please enter the Paid tax amount: ";
        cin >> paid_tax;
        if (paid_tax > income) {
            cout << "Invalid amount. Paid tax cannot be greater than your total income.\n";
            continue;
        }
        else if (paid_tax < 0){
            cout << "Invalid amount. Paid tax cannot be negative.\n";
            continue;
        }
        else
            break;
    }

    while(true){
        cout << "Please enter the amount for deduction: ";
        cin >> deduction;
        if (deduction < 0) {
            cout << "Invalid amount. Deduction cannot be negative.\n";
            continue;
        }
        else
            break;
    }
}

void calcTax(float TAX_RATE) {
    tax_amount = (income + interest - deduction) * TAX_RATE/100;
    final_amount = (tax_amount - paid_tax);
    if (final_amount < 0) {
        due = fabs(final_amount);
        isDue = true;
     }
    else {
        refund = final_amount;
        isRefund = true;
    }
}

void taxResult() {
    cout << "Tax Report\n";
    cout << "------------------------\n";
    cout << "Income: $" << fixed << setprecision(2) << income << endl;
    cout << "Interest: $" << fixed << setprecision(2) << interest << endl;
    cout << "Deduction: $" << fixed << setprecision(2) << deduction << endl;
    cout << "Paid Tax: $" << fixed << setprecision(2) << paid_tax << endl;
    cout << "Tax Amount: $" << fixed << setprecision(2) << tax_amount << endl;
    cout << "------------------------\n";
    if (isDue)
        cout << "Due: $" << fixed << setprecision(2) << due << endl;
    else if (isRefund)
        cout << "Refund: $" << fixed << setprecision(2) << refund << endl;
}

void processTax() {
    char tax_again;
    while(true){
        getTaxInfo();
        if (income <= 10000)
            calcTax(TAX_RATE1);
        else
            calcTax(TAX_RATE2);
        taxResult();
        cout << "Do you want to calculate tax for another income (y/n)?";
        cin >> tax_again;
        cout << endl << endl;
        if (tax_again == 'y' or tax_again == 'Y'){
            continue;
        }
        else if (tax_again == 'n' or tax_again == 'N'){
            break;
        }
        else {
            cout << "Not a valid input, please try again";
            continue;
        }
    }
}
int main(){
    int pin;
    const int MAX_ATTEMPTS = 3;
    int attempts_left = MAX_ATTEMPTS;

    cout << "Welcome to my tax calculation program.\n";
    cout << "-------------------------------------- \n";
    while(true) {
        cout << "Please enter the PIN code: ";
        cin >> pin;
        cout << endl;
        if (pin == 5678 or pin == 8765) {
            processTax();
            cout << "Thank you for using my program.";
            break;
        }
        attempts_left-= 1;
        if (attempts_left > 0)
            cout << "Invalid pin code. Please try it again. You have " << attempts_left << " attempts left. \n";
        else {
            cout << "Invalid pin code. You have reached the maximum number of retries.\n\n\n";
            cout << "Thank you for using my program.";
            break;
        }
    }

}

/*
 * Sample Outputs:

Welcome to my tax calculation program.
--------------------------------------
Please enter the PIN code: 5678

Lets gather some information on your finances this year.
Please enter the amount from W2 form: 130587.98
Please enter the Interest income: 3472.972
Please enter the Paid tax amount: 52872.23
Please enter the amount for deduction: 17832.44
Tax Report
------------------------
Income: $130587.98
Interest: $3472.97
Deduction: $17832.44
Paid Tax: $52872.23
Tax Amount: $58114.26
------------------------
Refund: $5242.03
Do you want to calculate tax for another income (y/n)?n



Thank you for using my program.
Process finished with exit code 0

 */