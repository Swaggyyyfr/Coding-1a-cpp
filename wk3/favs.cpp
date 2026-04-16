// Bradley Dyer
// create a list of favs

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    

    while(true) {
     
        int chapter = 0;
        cout << "Welcome to the 'Favorite Game Franchises' list.\n"; 
        cout << "What program would you like to run?\n"; 
        cout << "Press 1 to show list.\n"; 
        cout << "Press 2 to add to list.\n"; 
        cout << "Press 3 to remove from list.\n"; 
        cout << "Press 4 to edit the list.\n";
        cout << "Press 5 to quit.\n";  

        string input;
        getline(cin, input);

        if(input == "1") {
           vector<string> videoGames;
                                    
            cout << "Here are the titles in the favs list.\n";
            cout << "There are " << videoGames.size() << " titles currently.\n";

            for(int i = 0; i < videoGames.size(); i++) {
                cout << i + 1 << ". " << videoGames[i] << "\n";
            }
        }
        if(input == "2") {
            vector<string> videoGames;

            while(videoGames.size() < 5) {
                cout << "You can add up to 5 games.\n";
                cout << "Which games would you like to add?\n";
                string input;
                cin >> input;

                videoGames.push_back(input);
            }
        }
            ///
        
        else {
            cout << "I don't recognize that input.\n";
        }
    }
}