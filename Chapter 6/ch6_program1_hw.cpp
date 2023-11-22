// Audrey Wang
// 10/27/2023
// Program 6.2C
// This program changes all of the even numbers in the array into 0.

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int* remove_even(int* arr, int size) {
    // creates new array
    int* temp_arr = new int[size];
    // iterates through array
    for (int i = 0; i < size; i++) {
        // changes even numbers to 0
        if (arr[i] % 2 == 0)
            temp_arr[i] = 0;
        // otherwise copy original array value
        else {
            temp_arr[i] = arr[i];
        }
    }
    return temp_arr;
}

int main() {
    // set array values
    int arr[] = {4, 3, 6, 4, 7, 8};
    // run remove_even function
    int* final_arr = remove_even(arr, 6);
    // displays new function values
    for (int i = 0; i < 6; i++) {
        cout << final_arr[i] << " ";
    }
}