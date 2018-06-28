#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

double func1(double alpha, double t) {
	double output = 0;
	output = alpha * cos(alpha*t);
	return output;
}

double exact(double alpha, double t) {
	return sin(alpha*t);
}

double func(double tnplus1,double tn, double alpha, double h) {
	return  sin(alpha*tn) + (h*(cos(alpha*tnplus1))) - sin(alpha*(tnplus1));
}
double deriv(double tnplus1, double alpha, double h) {
	return -alpha * (h*sin(alpha*tnplus1) + cos(alpha*tnplus1));
}

double NR( double alpha, double h, double tn,double tolerance) {
	double xnplus1 = 0, xn = 0;
	while (true) {
		xnplus1 = (xn - (func(xn, tn, alpha, h) / deriv(xn, alpha, h)));
		if ((abs((xnplus1 - xn)) < tolerance) || isnan(xnplus1)) {
			xn = xnplus1;
			break;
		}
		xn = xnplus1;
	}

	return xn;
}

double impli(double alpha, double tStart, double tEnd, double h,double tolerance) {
	double output = 0, step = tStart, utnplus1 = 0, finalDeltat = 0, utn = tStart;
	int i = 0;
	while ((step + h) <= tEnd) {
		//cout << "Output: " << output << endl;
		utnplus1 = utn + (h*func1(alpha,(step + h)));
		//cout << "tn: " << utn << endl;
		//cout << "tnplus1: " << utnplus1 << endl;
		utn = utnplus1;
		step += h;
		i++;
		if (i % 1000000 == 0) {
			cout << i << " terms completed" << endl;
		}
	}
	finalDeltat = tEnd - step;
	output = utn;
	//output += (utn*finalDeltat);	
	return output;
	return output;
}

double expli(double alpha, double tStart, double tEnd, double h) {
	double output = 0, step = tStart, utnplus1 = 0, finalDeltat = 0, utn = tStart;
	int i = 0;
	while ((step+h) <= tEnd) {

		utnplus1 = utn + (h*func1(alpha,step));

		utn = utnplus1;
		step += h;
	}
	finalDeltat = tEnd - step;
	output = utn;
	return output;
};

double expliAdaptive(double alpha, double tStart, double tEnd, double h) {
	double output = 0, step = tStart, utnplus1 = 0, finalDeltat = 0, utn = tStart, deltaD, utnplus1L, utnplus1half, phi, epsilon = .0000001;
	int i = 0;
	while ((step + h) <= tEnd) {

		utnplus1L = utn + (h*func1(alpha, step));
		deltaD = epsilon*(abs(utn) + (h*abs(func1(alpha, step))));
		utnplus1half = utn + ((h*.5)*func1(alpha, step));
		utnplus1half = utnplus1half + ((h*.5)*func1(alpha, step+(h*.5)));
		utnplus1 = utnplus1half;
		phi = deltaD / (abs(utnplus1half - utnplus1L));
		cout << (abs(utnplus1half - utnplus1L)) << endl;
		//cout << "Phi: " << phi << endl;
		if (phi < 1) {
			h = h * (pow(phi, .25));
			cout <<"Decreasing h:" << h << endl;
		}
		else if (phi > 1) {
			h = h * (pow(phi, .2));
			cout << " Increasing h: " << h << endl;
		}
		utn = utnplus1;
		step += h;
	}
	finalDeltat = tEnd - step;
	output = utn;
	return output;
};

int main() {
	double h, alpha, tStart, tEnd;
	cout << "Enter your h(delta t)" << endl;
	cin >> h;
	cout << "Enter your tStart" << endl;
	cin >> tStart;
	//cout << "Enter your tEnd" << endl;
	//cin >> tEnd;
	cout << "tEnd is pi/2" << endl;
	tEnd = M_PI/2;
	cout << "Enter your alpha" << endl;
	cin >> alpha;
	cout << "Approximated integral of function alpha*cos(alpha*t) using explicit method: " << expli(alpha, tStart, tEnd, h) << endl;
	cout << "Exact integral of function alpha*cos(alpha*t): " << exact(alpha, tEnd) << endl;
	cout << "Approximated integral of function alpha*cos(alpha*t) using implicit method: " << impli(alpha, tStart, tEnd, h, .0000000001) << endl;
	cout << "Exact integral of function alpha*cos(alpha*t): " << exact(alpha, tEnd) << endl;
	cout << "Approximated integral of function alpha*cos(alpha*t) using adaptive explicit method: " << expliAdaptive(alpha, tStart, tEnd, h) << endl;
	cout << "Exact integral of function alpha*cos(alpha*t): " << exact(alpha, tEnd) << endl;
	cin >> h;
	return 0;
}