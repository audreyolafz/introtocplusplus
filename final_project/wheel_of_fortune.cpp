#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int money = 1000;
const int vowel_price = 700;
const int consonant_price = 200;

/** Spins the wheel to return a random value
 @ param void, no input
 @ return value, random output */
int spin_outcome() {
  int paid_amount = 0;

  // Generate a random number between 1 and 5
  int randomValue = rand() % 5 + 1;
  switch (randomValue) {
  // we can add more money values like wheel of fortune
  case 1:
    paid_amount = 100;
    cout << "Nice Spin! You get $100 for every correct consonant!" << endl;
    break;
  case 2:
    paid_amount = 200;
    cout << "Spectacular! You get $200 for every correct consonant!" << endl;
    break;
  case 3:
    paid_amount = 500;
    cout << "Awesome! You get $500 for every correct consonant!" << endl;
    break;
  case 4:
    paid_amount = 600;
    cout << "Fantastic! You get $600 for every correct consonant!" << endl;
    break;
  case 5:
    paid_amount = 1000;
    cout << "WOW! You get $1000 for every correct consonant!" << endl;
    break;
  default:
    paid_amount = 0;
    cout << "Error" << endl;
  }
  return paid_amount;
}

/**
Allows users to choose a category and will pick a random puzzle
@param puzzle, string puzzle that is empty
@return puzzle, the puzzle that is selected
*/
string pick_puzzle(string &puzzle) {
  cout << "Here are the categories you can choose to play: " << endl;
  cout << "1. Movies" << endl;
  cout << "2. Food and Drinks" << endl;
  cout << "3. Phrases" << endl;
  cout << "4. Song Lyrics" << endl;

  int choice;
  cout << "Enter your choice (1, 2, 3, 4): ";
  cin >> choice;

  if (choice == 1) {
    vector<string> movies = {
        "Red, White, and Royal Blue",
        "Hidden Figures",
        "Jurassic Park",
        "The Whale",
        "The Greatest Showman",
        "A Beautiful Mind",
    };
    int randIndex =
        rand() %
        movies.size(); // use a different variable name for random index
    puzzle = movies[randIndex]; // use the new variable name
  }

  else if (choice == 2) {
    // code for other options
    vector<string> food_and_drinks = {
        "Boba Milk Tea",    "Chocolate Chip Cookies", "Peking Duck",
        "Margherita Pizza", "Chicken Alfredo Pasta",  "Butter Chicken",
        "Ice Cream Cake",   "Fish and Chips",
    };

    int randIndex =
        rand() % food_and_drinks
                     .size(); // use a different variable name for random index
    puzzle = food_and_drinks[randIndex]; // use the new variable name
  } else if (choice == 3) {
    // code for other options
    vector<string> phrases = {
        "A Piece of Cake",           "In The Nick Of Time",
        "All's Well That Ends Well", "All That Glitters is Not Gold",
        "Only Time Will Tell",       "The Early Bird Gets the Worm",
        "Time Heals All Wounds",     "The Calm Before The Storm",
    };

    int randIndex =
        rand() %
        phrases.size(); // use a different variable name for random index
    puzzle = phrases[randIndex]; // use the new variable name
  } else if (choice == 4) {
    // code for other options
    vector<string> song_lyrics = {
        "Hello from the other side",
        "Yeah, it's a party in the USA",
        "Cause you're a sky full of stars",
        "Shut up and dance with me",
        "You are the dancing queen",
        "Do you remember the 21st night of September?"};

    int randIndex =
        rand() %
        song_lyrics.size(); // use a different variable name for random index
    puzzle = song_lyrics[randIndex]; // use the new variable name
  }

  else {
    cout << "Invalid choice." << endl;
    return "";
  }

  cout << "Great! You've picked the category: " << choice
       << ", and your puzzle is ready!" << endl;
  return puzzle;
}

/** Allows user to buy vowels which each cost 700
 @ param char vowel is the vowel of choice
 @ return boolean if it is a vowel or not
*/
bool is_vowel(char letter) {
  if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
      letter == 'u') {
    return true;
  } else {
    return false;
  }
}

/** Allows user to buy a vowel if they have enough money
 @ param puzzle is the puzzle that is selected
 @ phrase is the phrase that is selected
 @ money is 
*/
void buy_vowel(string &puzzle, const string &phrase, int &money) {
  if (money < vowel_price) {
    cout << "You don't have enough money to buy a vowel.";
    return;
  }

  money -= vowel_price;
  for (int i = 0; i < puzzle.size(); i++) {
    if (puzzle[i] == '_') {
      if (is_vowel(phrase[i])) {
        puzzle[i] = phrase[i];
        cout << "You bought a vowel! It cost " << vowel_price << endl;
        break;
      }
    }
  }
}

/** Checks if a guessed consonant is in the puzzle and update money
 @ param string of the puzzle
 @ param guessed_letter, guessed letter
 @ param money, current amount of money
 @ param paid, the money that the player spun to get per consonant
 @ return occurrences, the number of occurrences of the guessed letter in the
 puzzle
*/
void guess_consonant(string &puzzle, const string &phrase, char letter,
                     int paid_amount, int &money) {
  int occurrences = 0;

  if (money < consonant_price) {
    cout << "You don't have enough money to guess a consonant.";
    return;
  }

  if (is_vowel(letter)) {
    cout << "You must guess a consonant." << endl;
    return;
  }

  for (int i = 0; i < puzzle.length(); i++) {
    if (tolower(phrase[i]) == tolower(letter)) {
      puzzle[i] = phrase[i];
      occurrences++;
    }
  }

  // Count occurrences of the guessed letter in the puzzle
  if (occurrences > 0) {
    // Update money based on the number of occurrences
    money += paid_amount * occurrences;
    cout << "You guessed a consonant! You get $" << (paid_amount * occurrences)
         << " for " << occurrences << " correct consonant." << endl;
  } else {
    money -= consonant_price;
    cout << "Oops, the letter is not in the puzzle." << endl;
  }
}

string winning_prizes() {
  vector<string> prizes = {
      "Trip to Hawaii", "New Car",    "Shopping Spree", "Luxury Cruise",
      "Big Screen TV",  "Cash Prize", "Dream Vacation", "Home Theater System"};
  int index = rand() % prizes.size();
  string random_prize = prizes[index];
  return random_prize;
}

bool string_iequal(const string &first, const string &second) {
  if (first.length() != second.length()) {
    return false;
  }
  for (int i = 0; i < first.length(); i++) {
    if (tolower(first[i]) != tolower(second[i])) {
      return false;
    }
  }
  return true;
}

bool is_game_over(const string &phrase, const string &guess, string &puzzle,
                  bool force_quit) {

  if (string_iequal(phrase,
                    guess)) // they get a prize if their guess is correct
  {
    cout << "Correct! The answer is: " << phrase
         << ". Thank you for playing Wheel of Fortune. You've won: "
         << winning_prizes() << "." << endl;
    return true;
  } else if (force_quit || money < 0) {
    cout << "You are bankrupt. The answer is: " << phrase
         << ". Thank you for playing Wheel of Fortune." << endl;
    return true;
  }

  return false;
}

int main() {
  // Initialize random seed
  srand(time(0));

  string puzzle = "";
  string guess = "";
  string guessed_letters = "";

  cout << "Welcome to Wheel of Fortune! Let's begin. Spinning wheel..." << endl;
  int paid_amount = spin_outcome();

  string phrase;
  while (phrase.empty()) {
    phrase = pick_puzzle(puzzle);
  }

  puzzle = phrase;
  for (int i = 0; i < puzzle.length(); i++) {
    string symbols = " ,\'.!?;";
    if (symbols.find(puzzle[i]) == string::npos) {
      puzzle[i] = '_';
    }
  }

  // // Main game loop
  while (true) {
    //   // Prompt for player's letter guess, vowel purchase, or puzzle solving
    //   // Update 'money' and game state accordingly

    bool final_guess = false;

    cout << "You have $" << money << "." << endl;
    cout << puzzle << endl;
    cout << "1) Guess a consonant - $" << consonant_price << "," << endl;
    cout << "2) Buy a vowel - $" << vowel_price << "," << endl;
    cout << "3) Guess the whole phrase - Win Prize OR Bankrupt" << endl;
    cout << "Choose your action: ";
    int guess_type;
    cin >> guess_type;

    string guess;

    if (guess_type == 1) {
      char letter;
      cout << "Guess a consonant: " << endl;
      cin >> letter;

      // letter has not been guessed before OR there have been no letters
      // guessed yet
      if ((guessed_letters.find(letter) == string::npos)) {
        guess_consonant(puzzle, phrase, letter, paid_amount, money);
        guess = puzzle;
        if (!guessed_letters.empty()) {
          cout << "Your already guessed consonants: " << guessed_letters
               << endl;
        }
      } else {
        cout << "Your already guessed consonants: " << guessed_letters << endl;
        cout << "Enter a new guess." << endl;
      }

      guessed_letters += letter;
    } else if (guess_type == 2) // vowel purchase
    {
      buy_vowel(puzzle, phrase, money);
      guess = puzzle;
    } else if (guess_type == 3) // guess whole phrase
    {
      cout << "Guess the phrase" << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      getline(cin, guess);
      cout << "You entered " << guess << endl;
      final_guess = true;
    } else {
      cout << "Wrong choice entered." << endl;
    }

    if (is_game_over(phrase, guess, puzzle, final_guess)) {
      break;
    }
  }
  return 0;
}