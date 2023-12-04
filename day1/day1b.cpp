#include <iostream>
#include <fstream>

using namespace std;

// Function to replace part of a word with a digit
string replaceWord(string s, string word, string digit) {
  if ( s.find(word) != string::npos ) {
    s.replace(s.find(word)+1, 1, digit);
    s = replaceWord(s, word, digit);
  }
  return s;
}

int main() {
  // Variables
  string firstDigit;
  string lastDigit;
  int sum = 0;

  // File input
	ifstream file("input.txt");
	string s;
	while ( getline(file, s) ) {
    // Replace words of numbers with digits
    s = replaceWord( s, "one",   "1" );
    s = replaceWord( s, "two",   "2" );
    s = replaceWord( s, "three", "3" );
    s = replaceWord( s, "four",  "4" );
    s = replaceWord( s, "five",  "5" );
    s = replaceWord( s, "six",   "6" );
    s = replaceWord( s, "seven", "7" );
    s = replaceWord( s, "eight", "8" );
    s = replaceWord( s, "nine",  "9" );

    // Convert string to only digits
    string temp;
    for ( int i = 0; i < s.length(); i++ ) {
      if ( isdigit(s[i]) ) {
        temp += s[i];
      }
    }
    s = temp;

    // Get first and last digit
    firstDigit = s[0];
    lastDigit = s[s.length()-1];

    // Adding together + formatting
    cout << sum << " + ";
    cout << firstDigit << lastDigit << ": ";
    sum += stoi(firstDigit + lastDigit);
    cout << sum << endl;
  }

  cout << endl << "Sum of calibration values: " << sum << endl;

	return 0;
}
