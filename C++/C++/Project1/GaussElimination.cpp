#include<iostream>
#include<iomanip>
using namespace std;
const int n = 3;
const int mrow = 3;
const int mcol = 4;
void printMatrix(float A[][mcol]) {
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

void pivotMatrix(float A[][4]) {
	for (int i = 0;i<n;i++)                    //Pivotisation
		for (int k = i + 1;k<n;k++)
			if (abs(A[i][i])<abs(A[k][i]))
				for (int j = 0;j <= n;j++)
				{
					float temp = A[i][j];
					A[i][j] = A[k][j];
					A[k][j] = temp;
				}
}

int main()
{
	int i, j, k;
	float x[n]; 
	float A[3][4] = { {0,2,4,2},
					 {4,5,6,1},
					 {7,9,10,1} };

	pivotMatrix(A);
	cout << "\nPost Pivoting Matrix:\n";
	printMatrix(A);
	for (i = 0;i<n - 1;i++)           
		for (k = i + 1;k<n;k++)
		{
			double t = A[k][i] / A[i][i];
			for (j = 0;j <= n;j++)
				A[k][j] = A[k][j] - t * A[i][j];    
		}

	cout << "\n\nPost Gauss Elimination:\n";
	printMatrix(A);
	//backsub
	for (i = n - 1;i >= 0;i--) {                       
		x[i] = A[i][n];               
		for (j = i + 1;j<n;j++)
			if (j != i)           
				x[i] = x[i] - A[i][j] * x[j];
		x[i] = x[i] / A[i][i];          
	}
	cout << "\nX:\n";
	for (i = 0;i<n;i++)
		cout << x[i] << endl;             
	system("PAUSE");
	return 0;
}
