#include <iostream>
#include <fstream>
#include <cstring>
#include <array>

using namespace std;

// X and Y size of 2d array from input
const int INPUT_X = 140;
const int INPUT_Y = 141;

// Function to search, return, and delete numbers near a symbol
float SearchNearbyNumbers(char c[INPUT_Y][INPUT_X], int y, int x, int engineNumber) {
    string digits = "";
    int startingX = x;
    int startingY = y;

    // Check all 8 directions
    if (isdigit(c[y][x+1])) { x = x+1; }
    else if (isdigit(c[y+1][x])) { y = y+1; }
    else if (isdigit(c[y][x-1])) { x = x-1; }
    else if (isdigit(c[y-1][x])) { y = y-1; }
    else if (isdigit(c[y+1][x+1])) { y = y+1; x = x+1; }
    else if (isdigit(c[y+1][x-1])) { y = y+1; x = x-1; }
    else if (isdigit(c[y-1][x+1])) { y = y-1; x = x+1; }
    else if (isdigit(c[y-1][x-1])) { y = y-1; x = x-1; }
    else {
        return engineNumber;
    }

    // If a digit is found, start at the leftmost digit and convert to a number
    while (isdigit(c[y][x]) && x >= 0) {
        x = x-1;
    }
    x = x+1;
    while (isdigit(c[y][x]) && x <= INPUT_X) {
        digits += c[y][x];
        c[y][x] = '.'; // replace so it can't be found again
        x = x+1;
    }

    // Update engineNumber because of recursion
    engineNumber += stoi(digits);

    // Recursive to find and replace all digits near a specific symbol
    SearchNearbyNumbers(c, startingY, startingX, engineNumber);
}

int main() {
    char charArray[INPUT_Y][INPUT_X];
    int lineNumber = 0;

    // File input to 2d char array
	ifstream file("input.txt");
	string s;
	while (getline(file, s)) {
        lineNumber++;
        strcpy(charArray[lineNumber], s.c_str());
	}

    int sumOfEngine = 0;

    for (int i=0; i<INPUT_Y; i++) {
        for (int j=0; j<INPUT_X; j++) {
            if (ispunct(charArray[i][j]) && charArray[i][j] != '.') {
                // Symbol detected!
                sumOfEngine += SearchNearbyNumbers(charArray, i, j, 0);
                cout<<sumOfEngine<<" = ";
            }
        }
    }

    // Print array
    for (int i=0; i<INPUT_Y; i++) {
        for (int j=0; j<INPUT_X; j++) {
            cout<<charArray[i][j];
        }
        cout<<endl;
    }

    cout<<endl<<"Sum of part numbers in the engine: "<<sumOfEngine<<endl;

    return 0;
}
