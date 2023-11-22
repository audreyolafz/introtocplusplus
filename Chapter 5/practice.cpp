#include <iostream>
#include <cmath>

using namespace std;

double k(double x) { return 2 * (x+1); }
double h(double x) { return x * x + k(x) -1; }
double g(double x) { return 4 * h(x); }
double f(double x) { return g(x) + sqrt(h(x)); }

int main() {
    cout << f(-1) << endl;
    cout << g(-1) << endl;
    cout << h(-1) << endl;
    cout << k(-1) << endl;
    
    // cout << f(0) + f(1) + f(2) << endl;
    // cout << f(-1) + g(-1) + h(-1) + k(-1) << endl;
}