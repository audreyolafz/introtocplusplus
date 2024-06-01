// Audrey Wang
// 3/10/2024
// Unit 5 Lab
// This program finds the gcd of two integers as well as the coefficients that make the bezout property true.

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b, vector<int>& remainders, vector<int>& coefficients) {
    // base case: if second int is zero, gcd would be the first int
    if (b == 0) 
        return a;
    
    // calculates remainder and quotient and stores them in vectors
    int remainder = a % b;
    int quotient = a / b;
    remainders.push_back(remainder);
    coefficients.push_back(quotient);

    // recursively runs gcd function until base case is reached
    return gcd(b, remainder, remainders, coefficients);
}

vector<int> bezout(int a, int b, int gcd) {
    // sets up values to divide
    int dividend = a, divisor = b;
    // coefficient for int a and temp value
    int temp_1 = 0, coefficient1 = 1;
    // coefficient for int b and temp value
    int temp_2 = 1, coefficient2 = 0;

    while (divisor != 0) {
        // finds the quotient
        int quotient = dividend / divisor; 

        // saves divisor
        int temp = divisor;
        // finds remainder
        divisor = dividend - quotient * divisor;
        // sets up dividend to the previous divisor
        dividend = temp;

        // repeats process above to find coefficient 1
        temp = temp_1;
        temp_1 = coefficient1 - quotient * temp_1;
        coefficient1 = temp;

        // repeats process above to find coefficient 2
        temp = temp_2;
        temp_2 = coefficient2 - quotient * temp_2;
        coefficient2 = temp;
    }
    return {coefficient1, coefficient2};
}

int main() {
    // define two int
    int a = 56;
    int b = 40;
    // set up remainder and coefficients vectors
    vector<int> remainders, coefficients;

    // run gcd function and stores gcd
    int gcd_result = gcd(a, b, remainders, coefficients);
    cout << "GCD of " << a << " and " << b << ": " << gcd_result << endl;

    // prints out all remainders
    cout << "Remainders: ";
    for (int i = 0; i < remainders.size(); i++) {
        cout << remainders[i] << " ";
    }
    cout << endl;

    // prints out all coefficients
    cout << "Coefficients: ";
    for (int i = 0; i < coefficients.size(); i++) {
        cout << coefficients[i] << " ";
    }
    cout << endl;

    // runs bezout function and stores coefficients in a vector
    vector<int> bezout_result = bezout(a, b, gcd_result);
    // outputs coefficients with original a and b ints
    cout << "Linear combination: " << bezout_result[0] << " * " << a << " + " << bezout_result[1] << " * " << b << " = " << gcd_result << endl;

    return 0;
}
