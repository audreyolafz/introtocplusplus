#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    // Initialize game variables, puzzle, and player money
    int playerMoney = 0;
    string puzzle = "example puzzle"; // Replace with the puzzle
    int player = 0;

    // Main game loop
    while (true) {
        cout << "Player's Turn" << endl;
        int spinValue = SpinWheel();
        cout << "Spin Value: " << spinValue << endl;

        // Code player’s turn logic using the above functions
        if (player == 0)
            player = 1;
        else if (player == 1)
            player = 0;

        // Check for Bankrupt, Lose a Turn, or other special spaces
        if (playerMoney <= 0) {
            cout << "You ran out of money:(" << endl;
            break;
        }

        // Prompt for player's letter guess, vowel purchase, or puzzle solving
        // Update 'money' and game state accordingly
        char player_guess;
        cout << "Goess a letter" << endl;
        cin >> player_guess;
        GuessLetter(puzzle, player_guess, playerMoney)

        // Check for win or loss conditions and end the game if needed
        getWinner(playerMoney, ..., ...);

        // Repeat for the next player's turn (if multiple players)
    }

    return 0;
}
