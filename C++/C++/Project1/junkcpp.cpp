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