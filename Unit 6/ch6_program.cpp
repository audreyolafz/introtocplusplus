// Audrey Wang
// 4/30/2024
// Ch 6 Program
// This program determines the two closest points on the coordinate grid using selection sort and the Pythagorean Theorem.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// perform selection sort with 2d array by the x value
void selection_sort(double points[][2], int n) {
    // base case if there is only 1 pair
    if (n == 1)
        return;
    int max_index = 1;

    // iterate through remaining array
    for (int i = 2; i < n; i++) {
        // if current point is greater than previous greater point, change max index to the current one
        if (points[i][0] > points[max_index][0]) 
            max_index = i;
        swap(points[i], points[max_index]);
    }
}

// calculate distance between two points using distance formula
double distance(double p1[], double p2[]) {
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}

// calculate the closest pair of coordinates
pair<double*, double*> closest_pair(double points[][2], int n) {
    // run data points through selection sort
    selection_sort(points, n);

    // set arbitrary minimum distance and empty pair
    double min_dist = 0;
    pair<double*, double*> closest;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
        double current_dist = distance(points[i], points[j]);
            // if current dist is less than previous min dist, switch
            if (current_dist < min_dist) {
                min_dist = current_dist;
                closest = make_pair(points[i], points[j]);
            }
        }
    }
    return closest;
}

int main() {
    // define points
    int n = 5;
    double points[][2] = {{1, -2}, {5, 3}, {-2, 9}, {7, 0}, {0, 4}, {6, 8}};

    // run closest pair function
    pair<double*, double*> closest = closest_pair(points, n);
    cout << "Closest points: (" << closest.first[0] << ", " << closest.first[1] << ") and (" << closest.second[0] << ", " << closest.second[1] << ")" << endl;

}