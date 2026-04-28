// Bradley Dyer
// Classes

#include <iostream>

#include <string>

using namespace std;

// classes are custom variable types that have their own
// variable functions

// constructors
// getters and setters (privacy)
// instances
// inheritance (not on 4/28/26)




class robot {
private:    // datat members
    string name;
    int charge;
    int boredom;

public:
    // a constructor accepts variables and sets up the robot whenit is created.
    // a constructor function needs no return type, and must be named same as class.
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    //overload the constructor
    robot() {
        name = "bot";
        charge = 10;
        boredom = 0;
        status();
    }
// member functions
    void status() {
        cout << "My name is " << name << ", my charge is " << charge << ".\n";
        cout << "I am ";
        if(boredom < 5) {
            cout << "happy";
        }
        else if(boredom <10) {
            cout << "bored";
        }
        else if(boredom < 15) {
            cout << "frustrated";
        }
        else {
            cout << "ENRAGED";
        }
        cout << ".\n";
    }

    void newDay() {
        boredom += 2;
    }

    void play() {
        boredom -= 1;
    }

    void setName(string givenName) {
        if(givenName.size() <= 5) {
            name = givenName;
        }
        else {
            cout << "error: name is too long.\n";
        }
    }
    void setCharge(int givenCharge) {
        if(givenCharge < 0) {
            charge = 0;
        }
        else if(givenCharge > 100) {
            charge = 100;
        }
        else {
            charge = givenCharge
        }
    }

    string getName() {
        return name;
    }
    int getCharge() {
        return charge;
    }
    int getBoredom() {
        return boredom;
    }
};          // don't forget the semi colon
            // class of definition




int main() {
    cout << "Let's build some classes!\n";

    // creating 2 new variables of the type 'robot'
    robot artoo("R2-D2", 45, 10);       // using the constructor
    // artoo.name = "R2-D2";
    // artoo.charge = 45;
    // artoo.boredom = 10;

    robot threepio;
    threepio.setNamename("C-3P0");          // using the setter now
    threepio.charge = 2;                    // this is a dot syntax

    cout << "Here's artoo: " << artoo.name << ".\n";

    cout << artoo.name << " notices thtat " << threepio.name;
    cout << " doesn't have uch battery left. Let's fix that.\n";

    while(threepio.charge < 15) {
        artoo.charge -= 1;
        threepio.charge += 1;
    }

    cout << "threepio's charge is now " << threepio.charge << ".\n";
    cout << "artoo's charge is now " << artoo.charge << ".\n";

    // using member functions
    artoo.status();
    threepio.status();

    string input = "";
    int turns = 0;

    while(true) {
        while(turns < 3) {
            cout << "What would you like to do?\n";
            getline(cin, input);

            if(input == "play") {
                cout << "Let's play with " << artoo.name << "!\n";
                artoo.play();
            }
            else if(input == "status") {
                artoo.status();
            }
            turns++;
        }
        turns = 0;
        cout << "Do you want to keep playing?\n";
        getline(cin, input);

        if(input == "no") {
            break;
        }
        artoo.newDay();
    }

    return 0;
}