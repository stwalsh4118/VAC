%% 1)
a = 10;
b = (2.5)*10^23;
c = 2+3*i;
d = exp(1)^(j*2*(pi/3));

%% 4)
x = 1/(1+exp(-(a-15)/6));
y = (sqrt(a)+(b^(1/21)))^pi;
z = (log(real((c+d)*(c-d))*sin(a*pi/3)))/(c*conj(c));

%% 8)
figure;
hold on;
t = linspace(0,2*pi,1000);
plot(t,sin(t));
plot(t,cos(t), '--r');
xlabel('Time(s)');
ylabel('Function Value');
title('Sin and Cos Functions');
legend('Sin','Cos');