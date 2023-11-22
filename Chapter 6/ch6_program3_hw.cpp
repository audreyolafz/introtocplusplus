// Audrey Wang
// 11/3/2023
// Program 6.27
// This program merges 2 vectors.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

vector<int> merge(vector <int> a, vector<int> b) {
    vector<int> temp;
    // figure out which vector is smaller
    int smaller_vector = a.size();
    if (b.size() < a.size())
        smaller_vector = b.size();
    int difference = a.size()-b.size();
    int pos_diff = abs(difference);

    // iterates through the length of the smaller array and adds values
    for (int i = 0; i < smaller_vector; i++) {
        temp.push_back(a[i]);
        temp.push_back(b[i]);
    }
    // iterates through remaining elements in larger vector
    if (smaller_vector == a.size()) {
        for (int i = smaller_vector; i < b.size(); i++) {
                temp.push_back(b[i]);
        } 
    }
    else {
        for (int i = smaller_vector; i < a.size(); i++) {
                temp.push_back(a[i]);
        }
    }
    
    return temp;
}

int main() {
    // create both vectors
    vector <int> v1, v2;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(9);
    v1.push_back(16);

    v2.push_back(9);
    v2.push_back(7);
    v2.push_back(4);
    v2.push_back(9);
    v2.push_back(11);

    // run and iterate through vectors
    vector<int> merged_vectors = merge(v1, v2);
    for (int i = 0; i < merged_vectors.size(); i++) {
        cout << merged_vectors[i] << " ";
    }
}