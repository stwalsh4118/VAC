#include <iostream>
#include <math.h>
using namespace std;

double factorial(int n) {
	double fact = 1;
	for (int i = 1; i <= n;i++) {
		fact = fact * i;
	}
	return fact;
}

int main() {
	int accuracy;
	cout << "To what accuracy do you want to calculate sin(x)." << endl;
	cin >> accuracy;
	double x;
	cout << "To what x do you want to calculate sin(x)." << endl;
	cin >> x;
	double calc = 0;

	for (int n = 1; n <=accuracy; n++) {
		calc = calc + ((pow(-1, (n - 1)))*((pow(x, ((2 * n) - 1))) / factorial((2 * n) - 1)));
	}

	cout << "Estimation of sin(" << x << ") with accuracy " << accuracy << " is: " << calc << endl;
	cout << "The exact value of sin(" << x << ") is: " << sin(x) << endl;

	cin >> x;
	return 0;
}