// writing to and reading from files


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// return type = void, name = writeFile(input, path)
void  writeFile(string input, string path = "save.txt") {
    ofstream file(path);
    file << input;
    file.close();
}



void writeFile(vector<string>& vec, string path = "vector.txt") {
    ofstream file(path);
    for(int i = 0; i < vec.size(); i++) {
        file << vec[i] << endl;
    }
    file.close();
}

void readFile(string path = "save.txt") {
    string line;
    ifstream file(path);
    if(file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "File not found.\n";
    }
    file.close();
}


void readFile(vector<string>& vec, string path = "vector.txt") {
    vec.clear();
    string line;
    ifstream file(path);
    if(file.is_open()) {
        while(getline(file, line)) {
            vec.push_back(line);
        }
    }
    file.close();
}

int main() {
    cout << "Let's do some file operations!\n";

    //ofstream file("save.txt");
    // file.open

   // file << "Here is some text.\n";
    //file << "Here is another line of text.";
    //file.close();


    writeFile("Here is some text.\nHere is another line of text.");

    

   // string line;
   // ifstream readFile("save.txt");
   // if(readFile.is_open()) {
  //      while(getline(readFile, line)) {
   //         cout << line << endl;
  // //     }
   // }

   readFile();
   
   
   
   
   vector<string> names = {"Harry", "Daisha", "Sonic"};

   readFile(names, "names.txt");
   for(int i = 0; i < names.size(); i++) {
    cout << names[i] << endl;
   }

   writeFile(names, "names.txt");
   



    return 0;
}