// Audrey Wang
// 2/11/2024
// Lab 2
// This program determines whether a vector is symmetric, reflexive, both, or neither.

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// struct for each pair
struct Val {
  int x, y;
};

/**
 * Determines whether the relation is reflexive
 *
 * @param domain vector array holding the domain
 * @param relation vector holding the ordered pairs
 * @return true if the relation is reflexive, false otherwise
 */
bool isReflexive(vector<int>& domain, vector<Val>& v) {
  // creates hypothetical pairs with every value in the domain
  for (int i: domain) {
    Val reflexive_pair = {i, i};

    // checks if each ordered pair matches a hypothetical pair, and returns true if they are all true
    for (Val& r: v) {
      if (r.x == reflexive_pair.x && r.y == reflexive_pair.y) {
        return true;
      }
    }
    return false;
    }
}

/**
 * Determines whether the relation is reflexive
 *
 * @param relation vector holding the ordered pairs
 * @return true if the relation is symmetric, false otherwise
 */
bool isSymmetric(vector<Val>& v) {
  // creates pairs with the x and y swapped
  for (Val& p : v) {
    Val reversed_pair = {p.y, p.x};

    // checks if each ordered pair matches a hypothetical pair, and returns true if they are all true
        for (Val& r : v) {
        if (r.x == reversed_pair.x && r.y == reversed_pair.y) {
          return true;
        }
      }
      return false;
  }
}

int main() {
  // define domain of the pairs
  vector<int> domain = {1, 2, 3, 4, 5, 6, 7};

  // define several relation as vectors
  vector<Val> relation1 = {{1, 2}, {2, 1}, {3, 3}, {4, 5}, {5, 4}, {6, 7}, {7, 6}};
  vector<Val> relation2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}};
  vector<Val> relation3 = {{1, 3}, {2, 5}, {3, 7}, {4, 6}, {5, 2}, {6, 1}, {7, 4}};

  // print out relation, then the results for each
  for (Val& p : relation1) {
    cout << "{" << p.x << ", " << p.y << "}, ";
  }
  // convert 0 or 1 into string using ternary operators
  cout << "\nRelation 1 is reflexive: " << (isReflexive(domain, relation1) == 1 ? "true" : "false") << endl;
  cout << "Relation 1 is symmetric: " << (isSymmetric(relation1) == 1 ? "true" : "false") << endl;
  cout << "\n";

  for (Val& p : relation2) {
    cout << "{" << p.x << ", " << p.y << "}, ";
  }
  cout << "\nRelation 2 is reflexive: " << (isReflexive(domain, relation2) == 1 ? "true" : "false") << endl;
  cout << "Relation 2 is symmetric: " << (isSymmetric(relation2) == 1 ? "true" : "false") << endl;
  cout << "\n";

  for (Val& p : relation3) {
      cout << "{" << p.x << ", " << p.y << "}, ";
  }
  cout << "\nRelation 3 is reflexive: " << (isReflexive(domain, relation3) == 1 ? "true" : "false") << endl;
  cout << "Relation 3 is symmetric: " << (isSymmetric(relation3) == 1 ? "true" : "false") << endl;
  
  return 0;
}
