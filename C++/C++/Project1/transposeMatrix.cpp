#include <iostream>
using namespace std;

void Transpose(int m[][4]) {
	int temp[4][4];
	//transpose m by transfering into temp array
	for (int r = 0;r < 4;r++) {
		for (int c = 0; c < 4;c++) {
			temp[c][r] = m[r][c];
		}
	}
	//copy transposed temp array back to m
	for (int r = 0;r < 4;r++) {
		for (int c = 0; c < 4;c++) {
			m[r][c] = temp[r][c];
		}
	}
}

int main() {
	int m[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	Transpose(m);
	// print out array
	for (int r = 0;r < 4;r++) {
		for (int c = 0; c < 4;c++) {
			cout << m[r][c] << " ";
		}
		cout << endl;
	}
	int j = 0;
	cin >> j;
	return 0;
}