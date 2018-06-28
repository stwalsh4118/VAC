h = linspace(0,10^-15,100000);
alpha = 1;
x = pi/4;
eH = abs(((-h)/2)*(-alpha^2)*(cos(alpha*x)))/(-alpha*sin(alpha*x));
eH2 = abs(((-h)/6)*(alpha^3)*(sin(alpha*x)))/(-alpha*sin(alpha*x));
plot(log(eH),log(1./h),'blue');
hold on
plot(log(eH2),log(1./h),'red');
xlabel("log(1/h)");
ylabel("log(e(h))");
title("alpha: 100");
legend("first order","second order");