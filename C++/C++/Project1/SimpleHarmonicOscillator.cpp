//
//  main.cpp
//  Simple Harmonic Oscillation
//
//  Created by Surbhi Gupta on 6/20/18.
//  Copyright © 2018 Surbhi Gupta. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, x1, xstar, v = 0, v1, vstar, h = .0001, pi = 3.14159265359, time = pi, xInitial = 1, k = 1;
	x = xInitial;

	for (double i = 0; i<time; i += h)
	{
		xstar = x + (v*h);
		vstar = v + (-(pow(k, 2)*x)*h);
		x1 = x + (0.5)*(v + vstar)*h;
		v1 = v + (0.5)*(-(pow(k, 2)*x) - (pow(k, 2)*xstar))*h;
		x = x1;
		v = v1;
	}
	cout << "The position is: " << x << "\n\tThe actual position is: " << xInitial * cos(k*time);
	cout << "\nThe velocity is: " << v << "\n\tThe actual velocity is: " << -k * sin(k*time)*xInitial << endl;
	system("PAUSE");
	return 0;
}
