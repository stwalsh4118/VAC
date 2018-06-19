#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

double func(double x) {
	return  cos(x)-x;
}

double deriv(double x) {
	return -sin(x)-1;
}

int main() {
	int accuracy = 0;
	double startingPoint = 0;
	double tolerance = .00000001;
	//cout << "Input accuracy to which you want to calculate: ";
	//cin >> accuracy;
	//cout << endl << "Input your starting point: ";
	//cin >> startingPoint;
	long double xnplus1 = 0;
	long double xn = startingPoint;
	int arr[100000][2];
	int maxIndex = 100000;
	cout << "Calculating the root for " << maxIndex << " starting points." << endl;
	int startClock = clock();
	int lastClock = 0;
	for (int i = 1;i <= maxIndex;i++) {
		int j = 0;
		xn = i;
		xnplus1 = 0;
		if (i % 1000 == 1)
			int startClock = clock();
		while (true) {
			j++;
			//for (int i = 0;i < accuracy;i++) {
			xnplus1 = (xn - (func(xn) / deriv(xn)));
			//cout << xnplus1 << " ,index: " << j << endl;
			//cout << "Tolerance: " << abs((xnplus1 - xn)) << endl;

			if ((abs((xnplus1 - xn)) < tolerance) || isnan(xnplus1)) {
				xn = xnplus1;
				if (isnan(xnplus1)) {
					//cout << "Starting Point: " << i << " Went undefined on the index: " << j << endl;
					arr[i][0] = j;
					arr[i][1] = 1;
				}
				else {
					//cout << "Starting Point: " << i << " Elements to find root: " << j << " Root found at: " << xn << endl;
					arr[i][0] = j;
					arr[i][1] = 0;
				}
				
				break;
			}
			xn = xnplus1;
		}
		
		if (i % 1000 == 0) {
			int endClock = clock();
			
			cout << "Loading... " << i << " indexes completed. Time to calculate " << (endClock-startClock)-lastClock << " miliseconds." << endl;
			lastClock = endClock - startClock;
		}
	}
	int exit = 1;
	while (exit != 0) {
		int start;
		int end;
		int userInput;
		int max = 0;
		int maxI = 0;

		cout << "Do you want to find: Where its goes undefined(1), Max number of calculations(2), a range of indices(3), or exit(0)." << endl;
		cin >> userInput;
		switch (userInput) {
		case 1:
			for (int i = 0;i < maxIndex;i++) {
				if (arr[i][1] == 1) {
					cout << "Starting Point: " << i << " Went undefined on the index: " << arr[i][0] << endl;
				}
			}
			break;
		case 2:
			
			for (int i = 0;i < maxIndex;i++) {
				if (arr[i][0] > max) {
					max = arr[i][0];
					maxI = i;
				}
			}
			cout << "Max number of calculations is at Starting Point: " << maxI << " with " << arr[maxI][0] << " calculations" << endl;
			break;
		case 3:
			cout << "Which indexes do you want to look at,from start to end(max allowed 8999). Number available: " << maxIndex << endl;
			cin >> start;
			cin >> end;
			for (int i = start;i <= end;i++) {
				if (arr[i][1] == 1) {
					cout << "Starting Point: " << i << " Went undefined on the index: " << arr[i][0] << endl;
				}
				else {
					cout << "Starting Point: " << i << " Elements to find root: " << arr[i][0] << endl;
				}
			}
			break;
		}
	}
	cin >> xn;
	return 0;
}