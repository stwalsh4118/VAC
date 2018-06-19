#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string b = "";
	cout << "Input string to flip: " << endl;
	cin >> a;
	for (int i = a.length()-1; i >=0;i--) {
		b += a[i];
	}


	cout << "Flipped word: " << b << endl;
	cin >> a;


	return 0;
}