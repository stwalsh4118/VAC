#include <iostream>
using namespace std;

int main() {
	int *pointA, a;
	a = 25;
	cout << "The & operator returns the address where a variable is held" << endl;
	cout << "The value of a is: " << a << endl;
	cout << "The address of a is: " << &a << endl;

	cout << "Pointing to the memory of a with pointA: (pointA = a)" << endl;
	pointA = &a;
	cout << "Now pointA's value is the memory of variable a, pointA = " << pointA << endl;
	cout << "If we use the * operator we can see the value of the address that pointA is holding, pointA* = " << *pointA << endl;
	a = 5;
	cout << "Lets change the value of a to see what happens, a = " << a << endl ;
	cout << "If we change the value of a the address that pointA points at will not change, pointA = " << pointA << endl;
	cout << "But that address now holds the new value of a, pointA = " << *pointA << endl;
	*pointA = 2;
	cout << "If we set *pointA to a value it will change the value at the address that pointA is pointing at" << endl;
	cout << "The value of the address that pointA is pointing at(which is also the variable a) is now, *pointA = " <<  *pointA << endl;
	cout << "After changing the value at the address that *pointA is pointing at by setting it to a new value we have changed the variable a, a = "<< a << endl;
	system("PAUSE");
	return 0;
}