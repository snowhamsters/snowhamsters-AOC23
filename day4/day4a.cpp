#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    int winningNumbers;
    int totalPoints = 0;

	ifstream file("input.txt");
	string s;
	while (getline(file, s)) {
        winningNumbers = 0;

        s.erase(0,10);
        s += " ";
        cout<<s;

        for (int j=0; j<30; j+=3) {
            if (s.find(s.substr(j, 3),30) != string::npos) { winningNumbers++; }
        }
        if (winningNumbers > 0) {
            totalPoints += pow(2,winningNumbers-1);
        }

        cout<<"#: "<<winningNumbers<<" totalPoints: "<<totalPoints<<" "<<endl;
	}

	cout<<endl<<"Total points: "<<totalPoints<<endl;

    return 0;
}
