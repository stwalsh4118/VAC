#include <iostream>
#include <cstdlib>
using namespace std;

const int mrow = 3;
const int mcol = 4;
char B[3] = { 'A','B','C' };

void printMatrix(double A[][mcol]);
void gaussJordan(double A[][mcol]);
void pivotMatrix(double A[][mcol],int pivot);

int main() {
	double A[3][4] = { {0,2,4,2},
					   {4,5,6,1},
					   {7,8,10,1} };
	
	printMatrix(A);
	gaussJordan(A);
	for (int c = 0;c < mcol - 1;c++) {
		cout << B[c] << " ";
	}
	system("PAUSE");
	return 0;
}

void printMatrix(double A[][mcol]) {
	int row = mrow;
	int col = mcol;
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void gaussJordan(double A[][mcol]) {
	const int rows = mrow;
	const int cols = mcol;

	int pivot = 0;

	while (pivot < rows) {
		double div, mult;

		for (int r = 0;r < rows;r++) {
			if (A[pivot][pivot] == 0) {
				pivotMatrix(A,pivot);
			}
			div = A[pivot][pivot];
			mult = A[r][pivot] / div;

			for (int c = 0;c < cols;c++) {
				if (r == pivot) {
					A[r][c] /= div;
					A[r][c] += 0.0;
					printMatrix(A);
				}
				else {
					A[r][c] -= A[pivot][c] * mult;
					A[r][c] += 0.0;
					printMatrix(A);
				}
			}
		}
		pivot++;
		printMatrix(A);
	}
}

void pivotMatrix(double A[][mcol], int pivot) {
	int row = mrow;
	int col = mcol;
	int max = A[pivot][pivot];
	int temp;
	for (int c = 0;c < mcol - 1;c++) {
		if (A[pivot][c] > max) {
			max = c;
		}
	}
	for (int r = 0;r < mrow;r++) {
		temp = A[r][pivot];
		A[r][pivot] = A[r][max];
		A[r][max] = temp;
	}
	char tempC;
	tempC = B[pivot];
	B[pivot] = B[max];
	B[max] = tempC;
	

}