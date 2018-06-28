#include <iostream>
#include<vector>
using namespace std;

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}

	else if (n == 1) {
		return 1;
	}

	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}

int main() {
	vector<int> fibb;
	for (int i = 0;i < 21;i++) {
		fibb.push_back(fibonacci(i));
	}
	for (int i = 0;i < 21;i++) {
		cout << fibb[i] << " ";
	}
	system("PAUSE");
	return 0;
}