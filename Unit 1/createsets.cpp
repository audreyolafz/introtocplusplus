// Audrey Wang
// 1/29/2024
// 2.1-Lab 1-C++ sets
// This program finds the union of two sets, the difference between two sets, and whether one set is a subset of another.

#include <iostream>
#include <set>
#include <string>
using namespace std;

// define int_set as set<int>
typedef set<int> int_set;

// combines the values in the two sets
int_set set_union(int_set setA, int_set setB) {
    int_set combined;
    // start iterator with beginning of setA
    int_set :: iterator iter;
    iter = setA.begin();
    // print first element
    cout << *iter;
    iter++;
    // while haven't reached the end of setA
    while (iter != setA.end())
    {
        // add element to new set
        combined.insert(*iter);
        iter++;
    }
    // repeats same process for setB
    iter = setB.begin();
    while (iter != setB.end())
    {
        combined.insert(*iter);
        iter++;
    }
    return combined;
}

// finds setA - setB (the difference of the two)
int_set set_difference(int_set setA, int_set setB) {
    // initialize new set to copy setA
    int_set diff = setA;
    int_set :: iterator iter;
    // iterate through setB
    iter = setB.begin();
    // if element in setB is found in setA
    if (setA.find(*iter) != setA.end())
    {
        // remove element from new set
        diff.erase(*iter);
        iter++;
    }
    return diff;
}

// determines whether setB is a subset of setA
bool is_subset(int_set setA, int_set setB) 
{
    // starts iterating through setB
    int_set :: iterator iter;
    iter = setB.begin();
    while(iter != setB.end()) 
    {
        // checks if setA contains elements in setB
        if (setA.find(*iter) == setA.end())
            // if an element can't be found, return false
            return false;
        iter++;
    }
    return true;
}

// Display the elements of the set list_set
void list_elements(int_set list_set)
{
    // Create an iterator for the set
    int_set :: iterator iter;
    // Display the elements of the set
    iter = list_set.begin();
    while (iter != list_set.end())
    {
        cout << " " << *iter;
        iter++;
    }
    cout << endl;
}

int main() {
    // define several sets
    int_set a = {3, 4, 5, 6};
    int_set b = {6, 7, 8, 9};
    int_set c = {5, 6};

    // print out original sets
    cout << "set a: ";
    list_elements(a);
    cout << "set b: ";
    list_elements(b);
    cout << "set c: ";
    list_elements(c);

    // find union between int_set a and int_set b
    cout << "Union between integer sets a and b: ";
    int_set combined_set = set_union(a, b);
    list_elements(combined_set);

    // find difference between int_set a and int_set b
    int_set subtracted_set = set_difference(a, b);
    cout << "Difference between integer sets a and b: ";
    list_elements(subtracted_set);

    // determine whether int_set c is a subset of int_set a 
    bool sub_set = is_subset(a, c);
    if (sub_set == 1)
        cout << "True, set c is a subset of set a.";
    else
        cout << "False, set c isn't a subset of set a.";
}