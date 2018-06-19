syms f(x)
f(x) = cos(x)-x
f1 = diff(f,x)

accuracy = 400;
startingPoint = 10;
xn = startingPoint;
xnplus1 = 0;


for i = 1:accuracy
    xnplus1 = eval(xn-(f(xn)/f1(xn)));
    xn = xnplus1;
end

disp(xn);