// Audrey Wang
// 9/14/2023
// Program P3.19
// This program calculates the original income tax of 1913 given user income.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int x; 
    cout << "Please enter your income in dollars: ";
    cin >> x; 

    double tax; 

    if (x <= 50000) {
        tax = x * 0.01;
    } else if (x <= 75000) {
        tax = 50000 * 0.01 + (x - 50000) * 0.02;
    } else if (x <= 100000) {
        tax = 50000 * 0.01 + 25000 * 0.02 + (x - 75000) * 0.03;
    } else if (x <= 250000) {
        tax = 50000 * 0.01 + 25000 * 0.02 + 25000 * 0.03 + (x - 100000) * 0.04;
    } else if (x <= 500000) {
        tax = 50000 * 0.01 + 25000 * 0.02 + 25000 * 0.03 + 150000 * 0.04 + (x - 250000) * 0.05;
    } else {
        tax = 50000 * 0.01 + 25000 * 0.02 + 25000 * 0.03 + 150000 * 0.04 + 250000 * 0.05 + (x - 500000) * 0.06;

    }

    cout << "Your tax amounts to: " << tax << endl;
}