#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "input int a"<< endl;
	cin >> a;
	cout << "input int b" << endl;
	cin >> b;
	int *ptrA, *ptrB;
	ptrA = &a;
	ptrB = &b;
	cout << "ptrA: " << *ptrA<< endl;
	cout << "prtB: " << *ptrB;

	cin >> a;
	return 0;
}