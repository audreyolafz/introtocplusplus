// Audrey Wang
// 10/5/2023
// Program P4.26
// This program runs 1000 simulations on whether the user will switch their "door vote" for a car given that a door they did not pick has goats.

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    // initialize default values for the chosen and alternate counters, as well as the doors
    int chosen_win = 0;
    int alt_win = 0;
    int car_door, player_door, goat_door, switch_door; 

    // run 1000 iterations
    for (int i = 0; i < 1000; i++) {
        // pick a random number between 1 and 3 for the door with a car
        car_door = rand() % 3 + 1;
        // player picks a random number between 1 and 3
        player_door = rand() % 3 + 1;
        if (car_door == 1) {
            // determine door besides 1 to show goat
            goat_door = rand() % 2 + 2;
            // randomize whether player with switch doors
            switch_door = rand() % 2;
            if (switch_door == 0) {
                chosen_win++;
            } else if (switch_door == 1) {
                alt_win++;
            }
        } else if (car_door == 2) {
            goat_door = rand() % 2 + 1.5;
            switch_door = rand() % 2;
            if (switch_door == 0) {
                chosen_win++;
            } else if (switch_door == 1) {
                alt_win++;
            }
        } else if (car_door == 3) {
            goat_door = rand() % 2 + 1;
            switch_door = rand() % 2;
            if (switch_door == 0) {
                chosen_win++;
            } else if (switch_door == 1) {
                alt_win++;
            }
        }
    }
    cout << "Switching counter: " << alt_win << endl;
    cout << "Sticking counter: " << chosen_win << endl;
}