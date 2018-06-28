syms f(x);
h = .000001
tn = 0
f(x) = sin(tn)+(h*(cos(x)))-sin(x);
f1 = diff(f,x);

accuracy = 100;
startingPoint = 20;
xn = startingPoint;
xnplus1 = 0;
table = ["index","value"];

for i = 1:accuracy
    xnplus1 = eval(xn-(f(xn)/f1(xn)));
    table = [table;[i,xnplus1]];
        if(abs(xnplus1-xn)<(10^-10))
            break;
        end
    xn = xnplus1;

end

disp(xn);
table