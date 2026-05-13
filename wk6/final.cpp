// Bradley Dyer
// Coding 1a Final Assignment

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string>tikiNames {"Mofongo", "Plantain", "Acai", "Jollof", "Enchilada", "Curry"};

class baseTiki {
    public:
        string name;
        int health;
        int damage;
        int hunger;

        baseTiki() {
            name = tikiNames[rand() % tikiNames.size()];
            health = rand() % 8 + 12;
            damage = rand() % 2 + 6;
        }

        void hello() {
            cout << "My name is " << name << ".\nI have " << health;
            cout << " health and " << damage << " damage.\n";
            cout << "My hunger level is " << hunger << ".\n";
        }

        void train() {
            health += rand() % 6;
            damage += rand() % 4;
            hunger += 1;
        }

        void feed() {
            hunger += 1;
        }

        bool atk(baseTiki& opponent) {
            opponent.health -= damage;
            cout << name << " punches " << opponent.name << "!\n";

            if(opponent.health <= 0) {
                return true;
            }
            else {
                return false;
            }
        }

        
};

int main() {
        srand(time(0));
        string input;

        baseTiki Ackee;
        Ackee.name = "Ackee";
        Ackee.health = 10;
        Ackee.damage = 2;

        baseTiki opponent;

        while(true) {
            cout << "Type what do you want to do.\n";
            cout << "Train\nStats\nBattle\nFeed\n";

            getline(cin, input);

            // feed their critter
            if(input == "feed") {
                cout << "nom nom\n";
                Ackee.feed();
            }

            // trains to increase health n damage
            else if(input == "train") {
                cout << "RAAAAAAGGHHHH I'M GETTING STRONGERRRRRR!!\n";
                Ackee.train();
            }

            //listen 
            else if(input == "stats") {
                Ackee.hello();
            }

            //battle (atk, hl, run)
            else if(input == "battle") {
                cout << "A random opponenet has appeared!!\n";
                cout << "Prepare for battle\n";

                
                vector<baseTiki> stack(6);

                for(int i = 0; i < stack.size(); i++) {
                stack[i].hello();
                cout << "\n\n";
                }

                baseTiki temp, temp2;
                baseTiki& fighterA = temp;
                baseTiki& fighterB = temp2;

                if (rand() % 2 == 0) {
                    cout << "Ackee goes first!\n";
                    fighterA = Ackee;
                    fighterB = opponent;
                }
                else {
                    cout << opponent.name << " goes first!\n";
                    fighterA = opponent;
                    fighterB = Ackee;
                }

                while(fighterA.health > 0 && fighterB.health > 0) {

                    if(fighterA.atk(fighterB)) {
                        cout << fighterB.name << " has been defeated!\n";
                    
                    }
                    else {
                        fighterB.atk(fighterA);
                    }
                }
                if(fighterB.health > 0) {
                
                    if(fighterA.health <= 0) {
                        cout << fighterA.name << " has been defeated!\n";
                    }
                }
                else {
                    cout << fighterB.name << " has been defeated!\n";
                }
        }
    }

}   