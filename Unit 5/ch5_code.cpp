// Audrey Wang
// 3/27/2024
// Ch 6 Program
// This program writes all the k combinations of n items.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// print all values in combination
void print_combs(int combs[], int c_size) {
    for (int i = 0; i < c_size; i++) {
        cout << combs[i];
    }
    cout << ", ";
}

// bool found(int combs[], int i, int last) {
//     for (int j = 0; j < last; j++) {
//         if (combs[j] == i) {
//             return true;
//         }
//     }
//     return false;
// }

// recursively finds n factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    // initialize combinations array, n, and k
    int combs[100];
    int n = 5;
    int k = 3;
    // count total num of combinations and print 
    int num_combinations = factorial(n) / (factorial(k) * factorial(n - k));
    cout << "Number of combinations of C(" << n << ", " << k << "): " << num_combinations << endl;

    // initialize and print first combination (1, 2, ..., n)
    for (int i = 0; i < k; i++) {
        combs[i] = i + 1;
    }
    print_combs(combs, k);

    // iterate for total num of combinations times
    for (int i = 1; i < num_combinations; i++) {
        // find rightmost element
        int anchor = k - 1;
        // continue iterating when anchor is the largest number
        while (anchor >= 0 && combs[anchor] == n-(k-1-anchor)) {
            anchor--;
        }
        // increment anchor
        combs[anchor]++;

        // fill number before anchor with remaining numbers
        for (int j = anchor + 1; j < k; j++) {
        combs[j] = combs[j-1] + 1;
        }

        // print new combo
        print_combs(combs, k);
    }
    return 0;
}