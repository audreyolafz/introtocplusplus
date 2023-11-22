// Audrey Wang
// 10/2/2023
// Program P4.1c
// This program computes and prints the powers of 2 from 2^0 to 2^20.

#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int val = 2;
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j < i; j++)
            val *= i;
        cout << pow(2, i) << endl;
    }
}