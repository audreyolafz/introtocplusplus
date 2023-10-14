#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int employee_code;
    cout << "Please enter an integer between 1 and 3: ";
    cin >> employee_code; 
    switch (employee_code) { 
        case 3:
            cout << "Programmer";
            break;
        case 2:
            cout << "Department Manager";
            break;
        case 1:
            cout << "CEO";
            break;
        default:
            cout << "Invalid code";
    }
    if (cin.fail()) {
        cout << "Ooops";
    }

}