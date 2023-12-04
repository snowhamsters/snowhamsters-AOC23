#include <iostream>
#include <fstream>
#include <array>
#include <regex>

using namespace std;

// Finds the minimum amount of cubes from a given game and color
int MinimumCubes(string s, string color, int previousCubes, int pos) {
    // Number of cubes
    int cubes = previousCubes;

    // Check for color in string
    string number = "";
    pos = s.find(color,pos);
    if (pos!=string::npos) {
        number += s[pos-3];
        number += s[pos-2];
        // If there is a new maximum cubes
        if (stoi(number) > cubes) {
            cubes = stoi(number);
        }
        // Uses recursion to check all instances of a color and keep max cubes
        cubes = MinimumCubes(s, color, cubes, pos+1);
    }
    return cubes;
}

int main() {
    // Variables
    int redCubes;
    int greenCubes;
    int blueCubes;
    int sum = 0;

    // File input
	ifstream file("input.txt");
	string s;
	while (getline(file, s)) {
        redCubes = MinimumCubes(s, "red", 0, 0);
        greenCubes = MinimumCubes(s, "green", 0, 0);
        blueCubes = MinimumCubes(s, "blue", 0, 0);

        sum += (redCubes * greenCubes * blueCubes);
        cout<<(redCubes * greenCubes * blueCubes)<<": "<<s<<endl;
	}

	cout<<endl<<"Sum of the power of these sets: "<<sum<<endl;

    return 0;
}
