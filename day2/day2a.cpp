#include <iostream>
#include <fstream>
#include <array>
#include <regex>

using namespace std;

const int RED_CUBES = 12;
const int GREEN_CUBES = 13;
const int BLUE_CUBES = 14;

// Checks if a given game is possible with a specific color
bool IsGamePossible(string s, string color, int pos) {
    // Sets number of cubes based on color
    int cubes;
    if (color == "red") { cubes = RED_CUBES; }
    else if (color == "green") { cubes = GREEN_CUBES; }
    else if (color == "blue") { cubes = BLUE_CUBES; }
    else { cubes = -1; cout<<"ERROR"; }

    // Check for color in string
    string number = "";
    pos = s.find(color,pos);
    if (pos!=string::npos) {
        number += s[pos-3];
        number += s[pos-2];
        // Uses recursion in if statement to check all instances of a color
        if ((stoi(number) > cubes) || !IsGamePossible(s, color, pos+1)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Variables
    int lineNumber = 0;
    int sumOfIDs = 0;

    // File input
	ifstream file("input.txt");
	string s;
	while (getline(file, s)) {
        lineNumber++;
        // Check if Game is Possible
        if (IsGamePossible (s, "red", 0) &&
            IsGamePossible (s, "green", 0) &&
            IsGamePossible (s, "blue", 0)) {
            // If true, then add it's game ID
            cout<<"Y: ";
            sumOfIDs += lineNumber;
        }

        cout<<s<<endl;
	}

	cout<<endl<<"Sum of Game IDs: "<<sumOfIDs<<endl;

    return 0;
}
