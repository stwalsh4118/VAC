#include <iostream>
#include <string>
using namespace std;

bool anagramFind(string a, string b) {
	bool result = true;
	char c[100];
	char d[100];
	strcpy_s(c, a.c_str());
	strcpy_s(d, b.c_str());
	string C = "";
	string D = "";
	char temp;
	for (int i = 0; i<a.length() - 1; i++){
		for (int j = i + 1; j<a.length(); j++){
			if (c[i] > c[j]){
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
	for (int i = 0; i<b.length() - 1; i++) {
		for (int j = i + 1; j<b.length(); j++) {
			if (d[i] > d[j]) {
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
	C = c;
	D = d;
	if (C != D)
		result = false;
	return result;
}

int main() {
	string a;
	string b;
	cout << "What 2 words do you want to check if theyre anagrams? " << endl;
	cin >> a;
	cout << endl;
	cin >> b;
	if (a.length() == b.length())
		if (anagramFind(a, b))
			cout << "The words entered are anagrams.";
		else
			cout << " the words are not anagrams.";
	else
		cout << "The words entered are not anagrams.";
	cin >> a;
	
	return 0;
}