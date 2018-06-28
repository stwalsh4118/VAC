clc
clear
close all
G = 6.672*(10^-11);
MS = 1.989*(10^30);
ME = 5.972*(10^24);
SMD = 69816900000;
SVD = 108200000000;
SED = 152100000000;
    EMD = 405500000;
SMARSD = 249230000000;
SJD = 816600000000;
SSD = 1514500000000;

years = 1;
days = .005;
h = 86400*days; endt = 31557600*years;

mercury_x = SMD;mercury_y = 0;mercury_vx = 0;mercury_vy = 38700; mercury_year = 7603200; mercury_h = (mercury_year*days)/365.25;
venus_x = SVD;venus_y = 0;venus_vx = 0;venus_vy = 34790; venus_year = 22032000; venus_h = (venus_year*days)/365.25;
earth_x = SED;earth_y = 0;earth_vx = 0;earth_vy = 29300; earth_year = 31557600; earth_h = 86400*days;
    moon_x = EMD;moon_y = 0;moon_vx = 0;moon_vy = 970; moon_year = earth_year; moon_h = earth_h;
mars_x = SMARSD;mars_y = 0;mars_vx = 0;mars_vy = 21970; mars_year = 59356800; mars_h = (mars_year*days)/365.25;
jupiter_x = SJD;jupiter_y = 0;jupiter_vx = 0;jupiter_vy = 12440; jupiter_year = 371520000; jupiter_h = (jupiter_year*days)/365.25; 
saturn_x = SSD;saturn_y = 0;saturn_vx = 0;saturn_vy = 9090; saturn_year = 915148800; saturn_h = (saturn_year*days)/365.25;

t = 0;

venus_x_values = [venus_x];
venus_y_values = [venus_y];
mercury_x_values = [mercury_x];
mercury_y_values = [mercury_y];
earth_x_values = [earth_x];
earth_y_values = [earth_y];
    moon_x_values = [moon_x];
    moon_y_values = [moon_y];
mars_x_values = [mars_x];
mars_y_values = [mars_y];
jupiter_x_values = [jupiter_x];
jupiter_y_values = [jupiter_y];
saturn_x_values = [saturn_x];
saturn_y_values = [saturn_y];


while(t<endt)
    
    mercury_gx = ((-G*MS*mercury_x)/(sqrt(mercury_x^2+mercury_y^2))^3);
    mercury_gy = ((-G*MS*mercury_y)/(sqrt(mercury_x^2+mercury_y^2))^3);
    mercury_x = mercury_x+((1/2)*((mercury_vx)+(mercury_vx+(mercury_h*(mercury_gx)))))*mercury_h;
    mercury_y = mercury_y+((1/2)*((mercury_vy)+(mercury_vy+(mercury_h*(mercury_gy)))))*mercury_h;
    mercury_gx1 = ((-G*MS*mercury_x)/(sqrt(mercury_x^2+mercury_y^2))^3);
    mercury_gy1 = ((-G*MS*mercury_y)/(sqrt(mercury_x^2+mercury_y^2))^3);
    mercury_vx = mercury_vx+((1/2)*(mercury_gx+mercury_gx1))*mercury_h;
    mercury_vy = mercury_vy+((1/2)*(mercury_gy+mercury_gy1))*mercury_h;
    
    venus_gx = ((-G*MS*venus_x)/(sqrt(venus_x^2+venus_y^2))^3);
    venus_gy = ((-G*MS*venus_y)/(sqrt(venus_x^2+venus_y^2))^3);
    venus_x = venus_x+((1/2)*((venus_vx)+(venus_vx+(venus_h*(venus_gx)))))*venus_h;
    venus_y = venus_y+((1/2)*((venus_vy)+(venus_vy+(venus_h*(venus_gy)))))*venus_h;
    venus_gx1 = ((-G*MS*venus_x)/(sqrt(venus_x^2+venus_y^2))^3);
    venus_gy1 = ((-G*MS*venus_y)/(sqrt(venus_x^2+venus_y^2))^3);
    venus_vx = venus_vx+((1/2)*(venus_gx+venus_gx1))*venus_h;
    venus_vy = venus_vy+((1/2)*(venus_gy+venus_gy1))*venus_h;
    
    %venus_r = sqrt(venus_x^2+venus_y^2);
   % venus_vx = venus_vx+(-G*MS*venus_x*h)/(venus_r^3);
   % venus_vy = venus_vy+(-G*MS*venus_y*h)/(venus_r^3);
   % venus_x = venus_x+venus_vx*h;
   % venus_y = venus_y+venus_vy*h;z
    
    earth_gx = ((-G*MS*earth_x)/(sqrt(earth_x^2+earth_y^2))^3);
    earth_gy = ((-G*MS*earth_y)/(sqrt(earth_x^2+earth_y^2))^3);
    earth_x = earth_x+((1/2)*((earth_vx)+(earth_vx+(earth_h*(earth_gx)))))*earth_h;
    earth_y = earth_y+((1/2)*((earth_vy)+(earth_vy+(earth_h*(earth_gy)))))*earth_h;
    earth_gx1 = ((-G*MS*earth_x)/(sqrt(earth_x^2+earth_y^2))^3);
    earth_gy1 = ((-G*MS*earth_y)/(sqrt(earth_x^2+earth_y^2))^3);
    earth_vx = earth_vx+((1/2)*(earth_gx+earth_gx1))*earth_h;
    earth_vy = earth_vy+((1/2)*(earth_gy+earth_gy1))*earth_h;
    
        moon_gx = ((-G*ME*moon_x)/(sqrt(moon_x^2+moon_y^2))^3);
        moon_gy = ((-G*ME*moon_y)/(sqrt(moon_x^2+moon_y^2))^3);
        moon_x = moon_x+((1/2)*((moon_vx)+(moon_vx+(moon_h*(moon_gx)))))*moon_h;
        moon_y = moon_y+((1/2)*((moon_vy)+(moon_vy+(moon_h*(moon_gy)))))*moon_h;
        moon_gx1 = ((-G*ME*moon_x)/(sqrt(moon_x^2+moon_y^2))^3);
        moon_gy1 = ((-G*ME*moon_y)/(sqrt(moon_x^2+moon_y^2))^3);
        moon_vx = moon_vx+((1/2)*(moon_gx+moon_gx1))*moon_h;
        moon_vy = moon_vy+((1/2)*(moon_gy+moon_gy1))*moon_h;
        
    mars_gx = ((-G*MS*mars_x)/(sqrt(mars_x^2+mars_y^2))^3);
    mars_gy = ((-G*MS*mars_y)/(sqrt(mars_x^2+mars_y^2))^3);
    mars_x = mars_x+((1/2)*((mars_vx)+(mars_vx+(mars_h*(mars_gx)))))*mars_h;
    mars_y = mars_y+((1/2)*((mars_vy)+(mars_vy+(mars_h*(mars_gy)))))*mars_h;
    mars_gx1 = ((-G*MS*mars_x)/(sqrt(mars_x^2+mars_y^2))^3);
    mars_gy1 = ((-G*MS*mars_y)/(sqrt(mars_x^2+mars_y^2))^3);
    mars_vx = mars_vx+((1/2)*(mars_gx+mars_gx1))*mars_h;
    mars_vy = mars_vy+((1/2)*(mars_gy+mars_gy1))*mars_h;
    
    jupiter_gx = ((-G*MS*jupiter_x)/(sqrt(jupiter_x^2+jupiter_y^2))^3);
    jupiter_gy = ((-G*MS*jupiter_y)/(sqrt(jupiter_x^2+jupiter_y^2))^3);
    jupiter_x = jupiter_x+((1/2)*((jupiter_vx)+(jupiter_vx+(jupiter_h*(jupiter_gx)))))*jupiter_h;
    jupiter_y = jupiter_y+((1/2)*((jupiter_vy)+(jupiter_vy+(jupiter_h*(jupiter_gy)))))*jupiter_h;
    jupiter_gx1 = ((-G*MS*jupiter_x)/(sqrt(jupiter_x^2+jupiter_y^2))^3);
    jupiter_gy1 = ((-G*MS*jupiter_y)/(sqrt(jupiter_x^2+jupiter_y^2))^3);
    jupiter_vx = jupiter_vx+((1/2)*(jupiter_gx+jupiter_gx1))*jupiter_h;
    jupiter_vy = jupiter_vy+((1/2)*(jupiter_gy+jupiter_gy1))*jupiter_h;
    
    saturn_gx = ((-G*MS*saturn_x)/(sqrt(saturn_x^2+saturn_y^2))^3);
    saturn_gy = ((-G*MS*saturn_y)/(sqrt(saturn_x^2+saturn_y^2))^3);
    saturn_x = saturn_x+((1/2)*((saturn_vx)+(saturn_vx+(saturn_h*(saturn_gx)))))*saturn_h;
    saturn_y = saturn_y+((1/2)*((saturn_vy)+(saturn_vy+(saturn_h*(saturn_gy)))))*saturn_h;
    saturn_gx1 = ((-G*MS*saturn_x)/(sqrt(saturn_x^2+saturn_y^2))^3);
    saturn_gy1 = ((-G*MS*saturn_y)/(sqrt(saturn_x^2+saturn_y^2))^3);
    saturn_vx = saturn_vx+((1/2)*(saturn_gx+saturn_gx1))*saturn_h;
    saturn_vy = saturn_vy+((1/2)*(saturn_gy+saturn_gy1))*saturn_h;
    
    %moon with sun gravity 
    %mr = sqrt((mx+ex)^2+(my+ey)^2);
    %mvx = mvx+(((-G*ME*mx)/(mr^3))+((-G*MS*(mx+ex))/(mr^3)));
    %mvy = mvy+(((-G*ME*my)/(mr^3))+((-G*MS*(my+ey))/(mr^3)));
    %mx = mx+mvx*h;
    %my = my+mvy*h;
    
    t = t+h;
    if(mod(t,86400*1)==0)
    mercury_x_values = [mercury_x_values;mercury_x];
    mercury_y_values = [mercury_y_values;mercury_y];
    venus_x_values = [venus_x_values;venus_x];
    venus_y_values = [venus_y_values;venus_y];
    earth_x_values = [earth_x_values;earth_x];
    earth_y_values = [earth_y_values;earth_y];
        moon_x_values = [moon_x_values;moon_x];
        moon_y_values = [moon_y_values;moon_y];
    mars_x_values = [mars_x_values;mars_x];
    mars_y_values = [mars_y_values;mars_y];
    jupiter_x_values = [jupiter_x_values;jupiter_x];
    jupiter_y_values = [jupiter_y_values;jupiter_y];
    saturn_x_values = [saturn_x_values;saturn_x];
    saturn_y_values = [saturn_y_values;saturn_y];
    end
end

n = numel(earth_x_values);
%Line plot
figure
hold on
numPlots = 100;
for j = 1:numPlots
    clf
    xlim([2*-10^12,2*10^12])
    ylim([2*-10^12, 2*10^12])
    for i=1:n
    mercury = line(mercury_x_values(1:i),mercury_y_values(1:i),'Color',[0.7,0.7,0.7]);
    venus = line(venus_x_values(1:i),venus_y_values(1:i),'Color',[0.7,0.4,0]);
    earth = line(earth_x_values(1:i),earth_y_values(1:i),'Color',"blue");
        moon = line(moon_x_values(1:i)+earth_x_values(1:i),moon_y_values(1:i)+earth_y_values(1:i), 'Color', [0.2,0.3,0.4]);
    mars = line(mars_x_values(1:i),mars_y_values(1:i), 'Color',"red");
    jupiter = line(jupiter_x_values(1:i),jupiter_y_values(1:i), 'Color',[0.9,0.8,0.5]);
    saturn = line(saturn_x_values(1:i),saturn_y_values(1:i), 'Color',[0.8,0.8,0.4]);
    pause(.001)
    end
end


% figure()
% xlim([-10^12,10^12])
% ylim([-10^12 10^12])
% hold on
% %Scatter Plot
% for i = 1:n
% scatter(mercury_x_values(1:i),mercury_y_values(1:i),[],[0.7,0.7,0.7]);
% scatter(venus_x_values(1:i),venus_y_values(1:i),[],[0.7,0.4,0]);
% scatter(earth_x_values(1:i),earth_y_values(1:i),"blue");
%     scatter(moon_x_values(1:i)+earth_x_values(1:i),moon_y_values(1:i)+earth_y_values(1:i), [], [0.2,0.3,0.4]);
% scatter(mars_x_values(1:i),mars_y_values(1:i), "red");
% scatter(jupiter_x_values(1:i),jupiter_y_values(1:i),[],[0.9,0.8,0.5]);
% pause(.001)
% end 