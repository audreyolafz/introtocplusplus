// Audrey Wang
// 11/2/2023
// Program 6.20
// This program creates a magic square given n dimensions.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

void generate_magic_suare(int n) {
    // initialize 2D vector 
    vector<vector<int>> magic_square(n, vector<int>(n, 0));
    
    // set initial given row + column positions
    int row = n - 1;
    int col = n / 2;

    for (int k = 1; k <= n * n; ++k) {
        // place k at current position
        magic_square[row][col] = k;
        // increment row and column, if it's n, make the value zero
        row = (row + 1) % n;
        col = (col + 1) % n;

        // if value is not filled, set it to the value of the previous row and column
        if (magic_square[row][col] != 0) {
            row = (row - 1 + n) % n;
            col = (col - 1 + n) % n;
            row = (row - 1 + n) % n;
        }
    }

    // print magic square
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << magic_square[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    // asks for size of magic square
    int n;
    cout << "Enter the size of the magic square (odd): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "It must be odd.";
    } else {
        generate_magic_suare(n);
    }

    return 0;
}
