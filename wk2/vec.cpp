// Bradley Dyer Coding 1 Spring 2026
// Vectors, iterators, and algorithms

// use the double amperstand
// d

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout <<"Let's learn about Vectors!\n";
    // for chp 4
    vector<string> favs = {"Zelda", "Mario", "Metroid"};

    do {


        int chapter = 0;
        cout << "What program would you like to run?\n";
        cout << "Press 1 for Vectors.\n";
        cout << "Press 2 for push_back() and pop_back().\n";
        cout << "Press 3 for friends.\n";
        cout << "Press 4 for removing.\n";

        cin >> chapter;

        if(chapter == 1) {
            // collection initializer
            vector<string> names = {"Finn",
                                    "Jake",
                                    "Bubblegum",
                                    "Marceline",
                                    "Shelby"};

            cout << "Here are your names:\n";
            cout << "There are " << names.size() << " in the vector.\n";

            for(int i = 0; i < names.size(); i++) {
                cout << i + 1 << ". " << names[i] << "\n";
            }

            cout << "The first name in the vector is " << *(names.begin()) << ".\n";
            // creating our first iterator. It's a pointer to an element in a vector.
            vector<string>::iterator iter;

            iter = names.begin() + 2;

            // dereference the iter with an asterisk at the beginning
            // what's with that word "dereference"? A pointer can be thought of as a nickname
            // a "reference" to something else. When we de-reference it, we get the value
            // that is at that point.
            cout << "iter is pointing at " << *iter << ".\n";

        }   // end of Chp 1
        if(chapter == 2) {
            cout << "Let's use push_back() and pop_back().\n";

            vector<string> favMovies;

            while(favMovies.size() < 3) {
                cout << "Please add a favorite movie: ";
                string input;
                cin >> input;
                // cin.ignore (INT_MAX);       // fixes issuses with working with cin and getline()
                // getline(cin, input);

                favMovies.push_back(input);
            }

            // this time, use a for look with an iterator to move through the vector.
            for(vector<string>::iterator iter = favMovies.begin(); iter != favMovies.end(); iter++) {
                cout << *iter << endl;
            }
            

        }
        if(chapter == 3) {
            vector<string> friends;

            friends.push_back("Joey");
            friends.push_back("AJ");
            friends.push_back("Jamie");
            friends.push_back("Katie");
            friends.push_back("Anna");
            friends.push_back("Daisha");

            cout << "Here are your friends:\n";
            for(int i = 0; i < friends.size(); i++) {
                cout << friends[i] << ".\n";
            }

            cout << "Please choose a frined to go visit:\n";
            vector<string>::iterator chosenFriend = friends.begin();

            string input;
            cin >> input;

            chosenFriend = find(friends.begin(), friends.end(), input);

            if(chosenFriend != friends.end()){
                // displays the name of chosenFriend... if we found one...
                cout << "Let's talk to " << *chosenFriend << "today!\n";
            }
            else {
                cout << "I couldn't find " << input << " today!\n";
            }

            cout << "Let's give " << *chosenFriend << " a new name!\n";
            cin >> input;
            *chosenFriend = input;

            cout << "Their name is now " << *chosenFriend << ".\n";
            
            // // use an algorithm to find a friend.
            // chosenFriend = find(friends.begin(), friends.end(), "Ross")

            // // displays the name of chosenFriend... if we found one...
            // cout << "Let's talk to " << *chosenFriend << "today!\n";
        }
        else {
            cout << chapter << "Isn't one of the options.\n";
        }

        if(chapter == 4) {
            cout << "Let's remove an element from a global vector. (well, globalish)\n";

            // create a vector of strings at the top of main()
            // show favs
            sort(favs.begin(), favs.end());

            for(int i = 0; i < favs.size(); i++) {
                cout << favs[i] << endl;
            }

            // use cin to find the name to remove.
            cout << "what name should we remove from favs?\n";
            string input;
            cin >> input;

            auto iter = find(favs.begin(), favs.end(), input);

            if(iter != favs.end()) {
                cout << "found it!\n";
                favs.erase(iter); 
            }
            else{
                cout << "I could not find that name in favs.\n";
            }

            // use vec.erase(iter) to remove a name.
        }

    } while(true);

}