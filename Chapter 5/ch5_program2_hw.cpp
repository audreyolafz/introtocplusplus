// Audrey Wang
// 10/18/2023
// Program P5.28
// This program determines whether the given string is a palindrome or not. 

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool is_palindrome(string str) {
    if (str.length() <= 1) {
        return true;
    }

    if (str.front() != str.back()) {
        return false;
    }

    return is_palindrome(str.substr(1, str.length() - 2));
}

int main() {
    bool result = is_palindrome("racecar");
    if (result)
        cout << "It's a palindrome!" << endl;
    else 
        cout << "It's not a palindrome." << endl;
}