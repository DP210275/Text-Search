/*
David Pittman
CSCI 330
Vector Text Search
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<string> strings;

    string keyword;
    string fileName;
    string currentLine;
    string findLine;

    ifstream inFile;

    size_t index;

    bool found = false;

    //Asking for and opening text file
    cout << "Filename: ";
    cin >> fileName;
    cout << endl;

    inFile.open(fileName);

    //Placing all the lines of the text files into the vector
    while (getline(inFile, currentLine)) {
        strings.push_back(currentLine);
    }
    
    //Infinite loop of the asking/finding process
    while (cin) {
        cout << "Text to find: ";
        cin >> keyword;

        //for loop to cycle though the vector and access individual strings
        for (auto position {strings.begin()};
             position != strings.end();
             position++) {
            found = false;
            findLine = *position;
            index = findLine.find(keyword);
            
            //Analysis of single string
            if (index != string::npos) {
                cout << keyword << " first found on line "
                     << position - strings.begin() + 1 << endl;
                position = strings.end() - 1 ;
                found = true;
                cout << endl;
            }
        }
        //If keyword is not found, display message
        if(!found) {
            cout << "Couldn't find: " << keyword << endl << endl;         
        }
    }
    //Good practice, not entirely needed
    inFile.close();
    return 0;
}