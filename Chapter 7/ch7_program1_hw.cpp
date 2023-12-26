// Audrey Wang
// 12/6/2023
// Program P7.2
// This program compares two values and returns the value that has the smaller pointer.

#include <iostream>
using namespace std;

double replace_if_greater(double* p, double x) {
    double p_val = *p;
    if (x > p_val) {
        *p = x;
    }
    return p_val;
}

int main() {
    double data_val = 3;
    double* val_ptr = &data_val;
    double x = 6;

    double old_value = replace_if_greater(val_ptr, x);
    cout << "old value: " << old_value << endl;
}