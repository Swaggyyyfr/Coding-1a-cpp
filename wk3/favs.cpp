// Bradley Dyer
// create a list of favs

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<string> videoGames;

    while(true) {
     
        int chapter = 0;
        cout << "Welcome to the 'Favorite Game Franchises' list.\n"; 
        cout << "What program would you like to run?\n"; 
        cout << "Type 'show' to see the list.\n"; 
        cout << "Type 'add' to add to the list.\n"; 
        cout << "Type 'remove' to remove from the list.\n"; 
        cout << "Type 'edit' to edit the list.\n";
        cout << "Type 'quit' to quit.\n";  

        string input;
        getline(cin, input);

        if(input == "quit") {
            cout << "Thanks for playing.\n";
            break;
        }
        
        
        
        else if(input == "show") {
           
            for(vector<string>::iterator iter = videoGames.begin(); iter != videoGames.end(); iter++) {
                    cout << *iter << endl;
                }
                                        
            cout << "Here are the titles in the favs list.\n";
            cout << "There are " << videoGames.size() << " titles currently.\n";

            for(int i = 0; i < videoGames.size(); i++) {
                cout << i + 1 << ". " << videoGames[i] << "\n";
            }
        }
        else if(input == "add") {
           

                cout << "Which games would you like to add?\n";

                getline(cin, input);

                videoGames.push_back(input);

                
             
               
        }
        else if(input == "remove") {
            cout << "What game would you like to remove?\n";

             sort(videoGames.begin(), videoGames.end());

            for(int i = 0; i < videoGames.size(); i++) {
                cout << videoGames[i] << endl;
            }

            cout << "what name should we remove from favs?\n";
            getline(cin, input);

            auto iter = find(videoGames.begin(), videoGames.end(), input);

            if(iter != videoGames.end()) {
                cout << "found it!\n";
                videoGames.erase(iter); 
            }
            else{
                cout << "I could not find that name in favs.\n";
            }
        }
        else if(input == "edit") {
            cout << "What game would you like to edit?\n";

          sort(videoGames.begin(), videoGames.end());

            for(int i = 0; i < videoGames.size(); i++) {
                cout << videoGames[i] << endl;
            }

            cout << "What edit should we do to the game?\n";
            getline(cin, input);

            auto iter = find(videoGames.begin(), videoGames.end(), input);

            if(iter != videoGames.end()) {
                cout << "Found it!\n";
                cout << "What edit would you like to do?\n";
            }
            
        }
            
        
        else {
            cout << "I don't recognize that input.\n";
        }
    }
}