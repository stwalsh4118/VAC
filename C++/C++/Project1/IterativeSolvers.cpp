#include <iostream>
#include <math.h>
using namespace std;

const int mrow = 2;
const int mcol = 3;

double roundOff(double input, int n) {
	double output = 0;
	output = roundf(input * pow(10, n)) / pow(10, n);
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


void Jacobi(double A[][mcol], double &x, double &y, double &z) {
	double xp1, yp1, zp1;
	int it = 0;
	double err = 100;
	while (err > .0001) {
		it++;
		//cout << "Iterations: " << it << endl;
		xp1 = ((-A[0][1] * y) - (A[0][2] * z) + A[0][3]) / A[0][0];
		yp1 = ((-A[1][0] * x) - (A[1][2] * z) + A[1][3]) / A[1][1];
		zp1 = ((-A[2][0] * x) - (A[2][1] * y) + A[2][3]) / A[2][2];
		//cout << xp1 << " " << yp1 << " " << zp1 << endl;
		err = (abs((xp1 - x)) + abs((yp1 - y)) + abs((zp1 - z))) / 3;
		//cout << "Error: " << err << endl;
		x = xp1;
		y = yp1;
		z = zp1;

	}
}

void JacobiGeneral(double A[][mcol],double b[mrow]) {
	int it = 0;
	double err = 100;
	double temp[mrow];
	
	for (int i = 0;i < mrow;i++)
		temp[i] = b[i];
	while (err > .0000000000001) {
		
		err = 0;
		it++;
		for (int r = 0; r < mrow; r++) {
			double current = 0;
			for (int c = 0;c < mcol - 1;c++) {
				if (r == c) {

				}
				else {
					current -= A[r][c] * b[c];
				}
			}
			current += A[r][mcol - 1];
			current /= A[r][r];
			//roundOff(current, 2);
			temp[r] = current;
		}
		for (int i = 0;i < mrow;i++) {
			err += abs(temp[i] - b[i]);
		}
		err /= mrow;
		for (int i = 0;i < mrow;i++)
			b[i] = temp[i];
	}
	cout << "Iterations: " << it << endl;
}

void GaussSiedel(double A[][mcol], double &x, double &y, double &z) {
	double xp1 = x, yp1 = y, zp1 = z;
	int it = 0;
	double err = 100;
	while (err > .0001) {
		it++;
		//cout << "Iterations: " << it << endl;
		xp1 = ((-A[0][1] * yp1) - (A[0][2] * zp1) + A[0][3]) / A[0][0];
		yp1 = ((-A[1][0] * xp1) - (A[1][2] * zp1) + A[1][3]) / A[1][1];
		zp1 = ((-A[2][0] * xp1) - (A[2][1] * yp1) + A[2][3]) / A[2][2];
		cout << xp1 << " " << yp1 << " " << zp1 << endl;
		err = (abs((xp1 - x)) + abs((yp1 - y)) + abs((zp1 - z))) / 3;
		//cout << "Error: " << err << endl;
		x = xp1;
		y = yp1;
		z = zp1;

	}
}

void GaussSiedelGeneral(double A[][mcol], double b[mrow]) {
	int it = 0;
	double err = 100;
	double temp[mrow];

	for (int i = 0;i < mrow;i++)
		temp[i] = b[i];
	while (err > .0000000000000001) {
		err = 0;
		it++;
		for (int r = 0; r < mrow; r++) {
			double current = 0;
			for (int c = 0;c < mcol - 1;c++) {
				if (r == c) {

				}
				else {
					current -= A[r][c] * b[c];
				}
			}
			current += A[r][mcol - 1];
			current /= A[r][r];
			//roundOff(current, 2);
			b[r] = current;
		}
		for (int i = 0;i < mrow;i++) {
			err += abs(b[i] - temp[i]);
		}
		err /= mrow;
		for (int i = 0;i < mrow;i++) {
			temp[i] = b[i];
		}
	}
	cout << "Iterations: " << it << endl;
}

int main() {
	double x, y, z, xp1, yp1, zp1;
	x = 2.8, y = -2, z =6;


	double A[mrow][mcol] = { {0.1036,0.2122,0.7381},
							 {0.2081,0.4247,0.9327} };
	double b[mrow] = {0,0};
	//Jacobi(A, x,y,z);
	//cout << "Values from Jacobi: " << endl << "X: " << x << " Y: " << y << " Z: " << z << endl;
	//x = 2.8, y = -2, z = 6;
	//GaussSiedel(A, x, y, z);
	//cout << "Values from GaussSiedel" << endl << "X:" << x << " Y: " << y << " Z: " << z << endl;
	JacobiGeneral(A, b);
	cout << "Values from JacobiGeneral: " << endl;
	for (int i = 0;i < mrow;i++) {
		cout << "X" << i+1 << ": " << b[i] << endl;
	}
	double c[3] = {0,0};
	GaussSiedelGeneral(A, c);
	cout << "Values from GaussSiedelGeneral: " << endl;
	for (int i = 0;i < mrow;i++) {
		cout << "X" << i + 1 << ": " << c[i] << endl;
	}
	
	
	
	
	system("PAUSE");

	return 0;
}