// Audrey Wang
// 8/29/2023
// Program P2.6
// This program takes a user input for number of meters, and converts that to miles, feet, and inches.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int x; 
    cout << "Input a measurement in meters: ";
    cin >> x; 

    double meters_miles_conversion = 0.000621; 
    double meters_feet_conversion = 3.281;
    double meters_inches_conversion = 39.37;

    double miles = x * meters_miles_conversion;
    double feet = x * meters_feet_conversion;
    double inches = x * meters_inches_conversion;

    cout << x << " meters in miles is: " << miles << endl; 
    cout << x << " meters in feet is: " << feet << endl; 
    cout << x << " meters in inches is: " << inches << endl; 
}