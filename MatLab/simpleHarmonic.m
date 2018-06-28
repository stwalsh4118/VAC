k=1
x = 1;
vx = 0;
t = 0;
tend = 10*pi;
h = .001;

x_values = [x];
time = [t];
while(t<tend)
    
ax = (-(k^2))*x;
x = x+((1/2)*((vx)+(vx+(h*(ax)))))*h;
ax1 = (-(k^2))*x;
vx = vx+((1/2)*(ax+ax1))*h;

x_values = [x_values;x];
t = t+h;
time = [time;t];
end

plot(time,x_values);
