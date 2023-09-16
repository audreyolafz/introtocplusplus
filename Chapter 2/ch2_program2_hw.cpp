// Audrey Wang
// 8/29/2023
// Program P2.18
// This program takes a user input for an integer between 1,000 and 999,999 and removes the comma.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string x; 
    cout << "Please enter an integer between 1,000 and 999,999: ";
    cin >> x; 

    int x_len = x.length();
    string final_string = x.substr(0, x_len-4) + x.substr(x_len-4, 4);
    cout << final_string << endl;
}