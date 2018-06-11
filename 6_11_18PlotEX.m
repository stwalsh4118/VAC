t = linspace(0,1,1000);
y_values = cos(2*pi*t);
plot(t,y_values);
xlabel('x');
ylabel('y');
dat1 = randn(10000,1);
hist(dat1,50);