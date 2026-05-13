// Bradley Dyer
//  class inheritance adn header files if possible

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// can we build a vector of slimes
// can we get the slimes to fight each other
// can we build boss slimes?

vector<string>slimeNames = {"Tombow", "Cheryl", "Escobar", "Inigo", "Franz"};

class baseSlime {
    public:
        string name;
        int health;
        int damage;

        // default constructor
        baseSlime() {
            name = slimeNames[rand() % slimeNames.size()] + " Slime";
            health = rand() % 5 + 5;
            damage = rand() % 6 + 3; // "% '#' is range between 0 -'#'
                                     // range 3-8
        }

        void hello() {
            cout << "My name is " << name << ".\nI have " << health;
            cout << " health and " << damage << " damage.\n";
        }

        bool attack(baseSlime& opponent) {
            opponent.health -= damage;
            cout << name << " attacks " << opponent.name << "!\n";

            if(opponent.health <= 0) {
                return true;
            }
            else {
                return false;
            }
        }

        // step 1: Who attacks 1st?
        // step 2: fighter A attacks fighter B
        // step 3: (if fighter B is still alive) fighter B attacks Fighter A
};

int main() {
    srand(time(0));
    cout << "Let's make some slimes fight!\n";

    baseSlime ricky;
    ricky.name = "Richard Slime";
    ricky.health = 10;
    ricky.damage = 4;

    baseSlime beth;
    beth.name = "Elizabeth Slime";
    beth.health = 10;
    beth.damage = 4;

    ricky.hello();
    beth.hello();

    cout << "Creating our glob of slimes....\n";
    vector<baseSlime> glob(6);

    for(int i = 0; i < glob.size(); i++) {
        glob[i].hello();
        cout << "\n\n";
    }

    cout << "Let's have Ricky and Beth fight.\n";

    baseSlime temp, temp2;
    baseSlime& fighterA = temp;
    baseSlime& fighterB = temp2;

    if (rand() % 2 == 0) {
        cout << "Ricky goes first!\n";
        fighterA = ricky;
        fighterB = beth;
    }
    else {
        cout << "Beth goes first!\n";
        fighterA = beth;
        fighterB = ricky;
    }

    // the Thunderdome
    while(fighterA.health > 0 && fighterB.health > 0) {
        // cout << fighterA.name << " punches " << fighterB.name << "!\n";
        // A attacks B
        // fighterB.health -= fighterA.damage;
        if(fighterA.attack(fighterB)) {
            cout << fighterB.name << " has been defeated!\n";
        }
        else {
            fighterB.attack(fighterA);
        }
        
        // is B still alive?
        if(fighterB.health > 0) {
            cout << fighterB.name << " punches " << fighterA.name << "!\n";
            // B attacks A
            // fighterA.health -= fighterB.damage;
            
            // is A dead?
            if(fighterA.health <= 0) {
                cout << fighterA.name << " has been defeated!\n";
            }
        }
        else {
            cout << fighterB.name << " has been defeated!\n";
        }
    }

    return 0;
}