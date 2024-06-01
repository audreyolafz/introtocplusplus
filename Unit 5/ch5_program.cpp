// Audrey Wang
// 3/27/2024
// Ch 6 Program
// This program writes all the k combinations of n items.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// recursive function for running combinations
void combination(vector<vector<int>>& result, vector<int>& combo, int n, int left, int k) {
	// base case: pushes 1 combo to result vector
	if (k == 0) {
		result.push_back(combo);
		return;
	}
	// iterate through rest of values
	for (int i = left; i <= n; i++)
	{
		// insert 1st value into new combo
		combo.push_back(i);
		// call combination to get the next value
		combination(result, combo, n, i + 1, k - 1);
		// removes last item
		combo.pop_back();
	}
}

// create vector of vector of combinations
vector<vector<int>> combination(int n, int k) {
	vector<vector<int>> result;
	vector<int> combo;
	// runs combinations with given inputs
	combination(result, combo, n, 1, k);
	return result;
}

int main() {
	// set default n and k values
	int n = 5;
	int k = 3;
    
    cout << k << " combinations of " << n << endl;
	vector<vector<int>> result = combination(n, k);
	// iterate through 2D vector to print combinations
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
		}
        cout << ", ";
	}
    
	return 0;
}
