// Bradley Dyer coding 1 Spring 2026
// using VS Codium and it's integrated terminal
// to learn about variables and logic

// compile in the Developer Command Prompt with
// 'cl Ehsc main.cpp'

#include <iostream>
using namespace std;

int main() {
    // '\n' or 'backslash n' makes a new line.
    cout << "\n\n\nAll about variables and logic!\n\n\n";

    //declaring a variable means it exists!
    // defining a variable means giving it a value.
    int playerAge = -1;             // intergers are whole numbers
    string playerName = "Naomi";    // strings aer for words/letters
    float playerHeight = 1.8f;      // height in meters
    bool playAgain = true;          // booleans aere true or false

    // an if statement is a branch in unreal engine.
    if(playerAge == -1) {
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge < 13) {
            cout << "I'm sorry, this game is too grown up for you.\n";
        }
        else {
            cout << "wow! That's old!\n";
        }
    } // end of (playerAge)

    // Can you test to see if the player name is "naomi" and if it is,
    // ask the player what their name is, and assign their response
    // to playerName.

    if(playerName == "Naomi") {
        cout << "Is your name Naomi?\n(yes/no)";
        string input;
        cin >> input;

        if(input == "yes") {
            cout << "Well, that's Convenient!\n";
        }
        else {
            cout , "What is your name?\n";
            cin >> playerName;
        }

        cout << "Hello " << playerName << ".\n";
    } // end of if(true)

    // if their nameand age matches the programmer of this program
    // unlock god mode.

    bool godMode = false;

    if(playerAge == 37 && playerName == "Brad") {
        cout << "God Mode is active\n";
        godMode = true;
    }

    if(playAgain) {
        cout << "Let's play a game!\n";
    }

    // next class we'll build a "guess the number" game.
    return 0;
} // end of main()