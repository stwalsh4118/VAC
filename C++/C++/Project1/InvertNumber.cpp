#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int num;
	int remainder = 100000;
	int digits = 0;
	int invert = 0;

	cout << "Input a number: ";
	cin >> num;
	cout << endl;
	int tempNum = num;

	if ((num % 10 == 0))
		num++;
	while (remainder!=0) {
		remainder = num % 10;
		cout << remainder << endl;
		if (remainder != 0) {
			digits++;
		}
		cout << "digits" << digits << endl;
		num /= 10;
	}

	for (int i = digits-1; i>=0;i--) {
		cout << "temp num" << tempNum << endl;
		cout << "add to invert " << (tempNum%10)*(int)pow(10,i) << endl;
		invert = invert + (tempNum%10)*(int)pow(10,i);
		cout << "Invert" << invert << endl;
		tempNum /= 10;
	}
	cout << invert;
	cin >> digits;
	return 0;
}