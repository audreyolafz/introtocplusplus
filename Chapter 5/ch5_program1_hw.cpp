// Audrey Wang
// 10/17/2023
// Program P5.15
// This program sorts three numbers in ascending order and stores them in the respective variables. 

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void sort3(int& a, int& b, int& c) {
    for (int i = 0; i < 2; i++) {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        } else if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        } else if (a > c) {
            int temp = a;
            a = c;
            c = temp;
        }
    }
    cout << "v: " << a << ", w: " << b << ", x: " << c;
}

int main() {
    int v = 3;
    int w = 4;
    int x = 1;
    sort3(v, w, x);
}