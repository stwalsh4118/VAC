#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int array[10];
	double userInput;

	cout << "how many elements (no more than 10)?" << endl;
	cin >> userInput;

	for (int i = 0; i < userInput;i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> array[i];
		cout << endl;
	}
	cout << "Elements with even indices: " << ceil(userInput / 2);
	cin >> userInput;
	return 0;
}