// Audrey Wang
// 9/14/2023
// Program P3.23
// This program converts integers between 1 and 3999 into Roman numerals.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int x; 
    cout << "Please enter an integer between 1 and 3999: ";
    cin >> x; 
    int x_copy = x;
    string roman_version;
    int word_len = to_string(x).length();
    
    while (x > 0) {
        if (x >= 1000) {
            roman_version += "M";
            x -= 1000;
        } else if (x >= 900) {
            roman_version += "CM";
            x -= 900;
        } else if (x >= 500) {
            roman_version += "D";
            x -= 500;
        } else if (x >= 400) {
            roman_version += "CD";
            x -= 400;
        } else if (x >= 100) {
            roman_version += "C";
            x -= 100;
        } else if (x >= 90) {
            roman_version += "XC";
            x -= 90;
        } else if (x >= 50) {
            roman_version += "L";
            x -= 50;
        } else if (x >= 40) {
            roman_version += "XL";
            x -= 40;
        } else if (x >= 10) {
            roman_version += "X";
            x -= 10;
        } else if (x >= 9) {
            roman_version += "IX";
            x -= 9;
        } else if (x >= 8) {
            roman_version += "VIII";
            x -= 8;
        } else if (x >= 7) {
            roman_version += "VII";
            x -= 7;
        } else if (x >= 6) {
            roman_version += "VI";
            x -= 6;
        } else if (x >= 5) {
            roman_version += "V";
            x -= 5;
        } else if (x >= 4) {
            roman_version += "IV";
            x -= 4;
        } else if (x >= 3) {
            roman_version += "III";
            x -= 3;
        } else if (x >= 2) {
            roman_version += "II";
            x -= 2;
        } else if (x >= 1) {
            roman_version += "I";
            x -= 1;
        } 
    }
    cout << x_copy << " in Roman numerals: " << roman_version << endl;
}