#include <iostream>
#include <string>
using namespace std;

int main() {
	string alpha = "ABCDEDCBA";
	string spaces = "      ";
	string asterisk = "*********";
	int spacenum = 4;

	for (int i = 0; i < 5;i++) {
		cout << spaces.substr(0, spacenum) << alpha.substr(0, i + 1) << alpha.substr(9-i,9) << endl;
		spacenum--;
	}

	spacenum = 4;
	for (int i = 0; i < 9;i+=2) {
		cout << spaces.substr(0, spacenum) << asterisk.substr(0, i + 1)<< endl;
		spacenum--;
	}

	spacenum = 0;
	for (int i = 7; i > 0;i -= 2) {
		cout << spaces.substr(0, spacenum+1) << asterisk.substr(0, i) << endl;
		spacenum++;
	}

	int j;
	cin >> j;

	return 0;
}

