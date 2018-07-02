#include <iostream>
#include <math.h>
using namespace std;

double roundOff(double input, int n) {
	double output = 0;
	output = roundf(input * pow(10,n)) / pow(10, n);
	return output;
}

double roundUp(double input, int n) {
	double output = 0;
	output = ceilf(input * pow(10, n)) / pow(10, n);
	return output;
}

double roundDown(double input, int n) {
	double output = 0;
	output = floorf(input * pow(10, n)) / pow(10, n);
	return output;
}

int main() {
	double input;
	cout << "Input the number you want to round" << endl;
	cin >> input;
	cout << "The rounded number is: " << roundOff(input) << endl;
	cout << "The rounded up number is: " << roundUp(input) << endl;
	cout << "The rounded down number is: " << roundDown(input) << endl;
	cin >> input;
	return 0;
}