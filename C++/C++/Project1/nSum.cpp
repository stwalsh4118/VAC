#include <iostream>
using namespace std;

int main() {
	int n;
	int sum = 0;

	cout << "How many n natural numbers do you want to sum?" << endl;
	cin >> n;

	for (int i = 1; i < n + 1;i++) {
		sum += i;
	}
	cout << "The some of the first " << n << " natural numbers is: " << sum;
	cin >> n;

	return 0;
}