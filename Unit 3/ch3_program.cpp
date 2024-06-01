// Audrey Wang
// 2/16/2023
// Insertion Sort
// This program uses insertion sort to sort an array of numbers.

#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size_of_array) {
    // iterate through entire array
    for (int i = 1; i < size_of_array; i++) {
        // set current and j to 2nd and 1st term respectively
        int current = arr[i];
        int j = i - 1;

        // switch current value with the value before if it's greater
        while (j >= 0 && arr[j] > current) {
           arr[j + 1] = arr[j];
           // decrement j to sort from current to beginning
           j--;
        }
        // increment current
        arr[j + 1] = current;
    }
    
};

int main() {
    // define array values and size
    int arr[] = {5, 3, 7, 9, 2, 8};
    int size = 6;

    // display unsorted array
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    // run insertion_sort on array 
    insertion_sort(arr, size);
    cout << "Sorted array via insertion sort: ";
    // display results
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}