// Ryan Ng
// BCS 370: Data Structures
// Module 7 - Extra Credit Assignment

/*

RESOURCES USED FOR LEARNING NEW CONCEPTS:
• https://www.programiz.com/dsa/circular-linked-list#:~:text=A%20circular%20linked%20list%20is,other%20to%20form%20a%20circle.&text=Here%2C%20the%20address%20of%20the,address%20of%20the%20first%20node.
• https://www.programiz.com/cpp-programming/library-function/ctime/time
• https://cplusplus.com/reference/istream/istream/ignore/
• https://www.tutorialspoint.com/rand-and-srand-in-c-cplusplus

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// "Node" is the struct with two elements: "originalAvenger", and a pointer to "succeeding".
struct Node {
  string originalAvenger;
  Node* succeeding;
};

// The player() function asks the player what their name is, and for their favorite Avengers character.
void player (string name, string avengersCharacter) {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your favorite Avengers character: ";
    cin.ignore();
    getline(cin, avengersCharacter);
}

// The place() function inserts a contemporary Node with the given Avenger's name to the linked list's end pointed to by the top.
void place (Node*& top, string originalAvenger) {
  Node* secondNode = new Node;
  secondNode->originalAvenger = originalAvenger;
  secondNode->succeeding = nullptr;
  if (top == nullptr) {
    top = secondNode;
  } else {
    Node* present = top;
    while (present->succeeding != nullptr) {
      present = present->succeeding;
    }
    present->succeeding = secondNode;
  }
}

// The exhibit() function outputs all the Avengers' names in the linked list pointed to by the top. If the top equals nullptr, then the list is empty.
void exhibit (Node* top) {
  if (top == nullptr) {
    cout << "Empty list!" << endl;
  } else {
    Node * present = top;
    do {
      cout << present->originalAvenger;
      if (present->succeeding != nullptr) {
        cout << ", ";
      }
      present = present->succeeding;
    } while (present != nullptr);
    cout << endl;
  }
}

// The spin() function randomly chooses the winner by counting how many Avengers there are in the linked list, generating a random number, and then observing the linked list until the winner is found.
void spin (Node* top) {
  int include = 0;
  Node* present = top;
  double money;
  string avengerGuess;
  do {
    present = present->succeeding;
    include++;
  } while (present != nullptr);
  srand (time(nullptr));
  int integer = rand() % include;
  present = top;
  for (int i = 0; i < integer; i++) {
    present = present->succeeding;
  }
  cout << "Betting For: $";
  cin >> money;
  cout << "Enter your Avenger guess: ";
  cin.ignore();
  getline(cin, avengerGuess);
  cout << endl;
  cout << endl << "The WHEEL OF FORTUNE is spinning right now!" << endl;
  cout << "Winning Avenger: " << present->originalAvenger << endl;
  if (avengerGuess == "Captain America" || avengerGuess == "Steve Rogers" || avengerGuess == "Chris Evans") {
    if ("Captain America" == present->originalAvenger) {
      cout << "You win $" << money << "!";
    } else {
      cout << "You lose $" << money << "!";
    }
  } else if (avengerGuess == "Iron Man" || avengerGuess == "Tony Stark" || avengerGuess == "Robert Downey Jr.") {
    if ("Iron Man" == present->originalAvenger) {
      cout << "You win $" << money << "!";
    } else {
      cout << "You lose $" << money << "!";
    }
  } else if (avengerGuess == "Thor" || avengerGuess == "God of Thunder" || avengerGuess == "Chris Hemsworth") {
    if ("Thor" == present->originalAvenger) {
      cout << "You win $" << money << "!";
    } else {
      cout << "You lose $" << money << "!";
    }
  } else if (avengerGuess == "Black Widow" || avengerGuess == "Natasha Romanoff" || avengerGuess == "Scarlett Johansson") {
    if ("Black Widow" == present->originalAvenger) {
      cout << "You win $" << money << "!";
    } else {
      cout << "You lose $" << money << "!";
    }
  } else if (avengerGuess == "Hulk" || avengerGuess == "The Hulk" || avengerGuess == "Bruce Banner" || avengerGuess == "Mark Ruffalo") {
    if ("Hulk" == present->originalAvenger) {
      cout << "You win $" << money << "!";
    } else {
      cout << "You lose $" << money << "!";
    }
  } else if (avengerGuess == "Hawkeye" || avengerGuess == "Clint Barton" || avengerGuess == "Jeremy Renner") {
    if ("Hawkeye" == present->originalAvenger) {
      cout << "You win $" << money << "!";
    } else {
      cout << "You lose $" << money << "!";
    }
  }
}

// The main() function builds an empty list with six of the original Avengers' names, using the place() function for help. The exhibit() function helps with showing the list. The player() function welcomes the player to the WHEEL OF FORTUNE game. The spin() function helps with choosing the winner randomly before returning 0 to end the game.
int main () {
  Node* top = nullptr;
  string name;
  string avengersCharacter;
  cout << "Welcome to the game of WHEEL OF FORTUNE! Today, you will guess one out of the six randomly selected Avengers to possibly win some money." << endl;
  cout << endl << "Here are the six original Avengers: ";
  place(top, "Captain America");
  place(top, "Iron Man");
  place(top, "Thor");
  place(top, "Black Widow");
  place(top, "Hulk");
  place(top, "Hawkeye");
  exhibit(top);
  cout << endl;
  player(name, avengersCharacter);
  cout << endl;
  spin(top);
  return 0;
}
