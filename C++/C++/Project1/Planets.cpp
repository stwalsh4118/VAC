#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

const double G = 6.672*pow(10, -11);
const double Ms = 1.989*pow(10, 30);
const double SED = 149600000000;

double ax(double x, double y) {
	cout << "ax: " << (-G * Ms*x) / (pow(((x*x) + (y*y)), 3 / 2)) << endl;
	double r = sqrt(pow(x, 2) + pow(y, 2));
	return (-G * Ms*x) / pow(r, 3);
}

double ay(double x, double y) {
	double r = sqrt(pow(x, 2) + pow(y, 2));
	return (-G * Ms*y) / pow(r, 3);
}

double axs(double XP1, double YP1) {
	return (-G * Ms*XP1) / (pow(((XP1*XP1) + (YP1*YP1)), 3 / 2));
}

double ays(double XP1, double YP1) {
	return (-G * Ms*YP1) / (pow(((XP1*XP1) + (YP1*YP1)), 3 / 2));
}

double vxp1(double vx, double h, double AX, double AXS) {
	return vx + ((1 / 2)*(AX + AXS))*h;
}

double vxs(double vx, double h, double AX) {
	cout << "VX: " << vx + (AX*h) << endl;
	return vx + (AX*h);
}

double vyp1(double vy, double h, double AY, double AYS) {
	return vy + ((1 / 2)*(AY + AYS))*h;
}

double vys(double vy, double h, double AY) {
	cout << "VY: " << vy << "+" << (AY*h) << endl;
	return vy + (AY*h);
}

double xp1(double x, double VX, double h, double VXS) {
	return x + ((1 / 2)*(VX + VXS))*h;
}

double xs(double x, double vx, double h) {
	return x + (vx*h);
}

double yp1(double y, double VY, double h, double VYS) {
	return y + ((1 / 2)*(VY + VYS))*h;
}

double ys(double y, double vy, double h) {
	return y + (vy*h);
}

void planets(double X, double Y, double VX, double VY, double H, double END) {
	double t = 0, x = X, y = Y, vx = VX, vy = VY, h = H, end = END, xplus1 = 0, yplus1 = 0, vxplus1 = 0, vyplus1 = 0;

	cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
	while (t < end) {
		if ((int)t % 86400 == 0) {
			cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
		};
		//xplus1 = xp1(x, vx, h, vxs(vx, h, ax(x, y)));
		xplus1 = xs(x, vx, h);
		vxplus1 = vxs(vx, h, ax(x, y));
		//cout << "New vx" << endl;

		//cout << "New x" << endl;
		//vxplus1 = vxp1(vx, x, y, h, ax(x, y), axs(xp1(x, vx, h, vxs(vx, h, ax(x, y))), yp1(y, vy, h, vys(vy, h, ay(x, y)))));

		//yplus1 = yp1(y, vy, h, vys(vy, h, ay(x, y)));
		//cout << "New vy" << endl;
		vyplus1 = vys(vy, h, ay(x, y));
		yplus1 = ys(y, vy, h);
		//cout << "New y" << endl;

		//vyplus1 = vyp1(vy, x, y, h, ay(x, y), ays(xp1(x, vx, h, vxs(vx, h, ax(x, y))), yp1(y, vy, h, vys(vy, h, ay(x, y)))));
		t += h;
		x = xplus1;
		y = yplus1;
		vx = vxplus1;
		vy = vyplus1;
		cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
	};
	cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
}




int main() {
	double h, x, y, vx, vy, end;
	cout << "Enter your h(delta t)" << endl;
	cin >> h;
	cout << "How many seconds" << endl;
	//cin >> end;
	end = 31557600;
	cout << "Enter initial x" << endl;
	//cin >> x;
	x = SED;
	cout << "Enter your initial y" << endl;
	//cin >> y;
	y = 0;
	cout << "Enter your initial x velocity" << endl;
	//cin >> vx;
	vx = 0;
	cout << "Enter your initial y velocity" << endl;
	//cin >> vy;
	vy = 20000;
	//planets(x, y, vx, vy, h, end);
	double t = 0, xplus1 = 0, yplus1 = 0, vxplus1 = 0, vyplus1 = 0;
	cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
	while (t < end) {
		if ((int)t % 86400 == 0) {
			cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
		};
		//xplus1 = xp1(x, vx, h, vxs(vx, h, ax(x, y)));
		vx = vxs(vx, h, ax(x, y));
		vy = vys(vy, h, ay(x, y));
		x = xs(x, vx, h);
		y = ys(y, vy, h);
		//cout << "New vx" << endl;

		//cout << "New x" << endl;
		//vxplus1 = vxp1(vx, x, y, h, ax(x, y), axs(xp1(x, vx, h, vxs(vx, h, ax(x, y))), yp1(y, vy, h, vys(vy, h, ay(x, y)))));

		//yplus1 = yp1(y, vy, h, vys(vy, h, ay(x, y)));
		//cout << "New vy" << endl;


		//cout << "New y" << endl;

		//vyplus1 = vyp1(vy, x, y, h, ay(x, y), ays(xp1(x, vx, h, vxs(vx, h, ax(x, y))), yp1(y, vy, h, vys(vy, h, ay(x, y)))));
		t += h;

		cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;
	};
	cout << "(X,Y) at t: ( " << x << " , " << y << " ) at " << t << " X Velocity: " << vx << " Y Velocity: " << vy << endl;

	cin >> h;
	return 0;
}