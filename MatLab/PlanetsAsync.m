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

mercury_x = SMD;mercury_y = 0;mercury_vx = 0;mercury_vy = 38700; mercury_year = 7603200; mercury_h = 86400*days;
venus_x = SVD;venus_y = 0;venus_vx = 0;venus_vy = 34790; venus_year = 22032000; venus_h = 86400*days;
earth_x = SED;earth_y = 0;earth_vx = 0;earth_vy = 29300; earth_year = 31557600; earth_h = 86400*days;
    moon_x = EMD;moon_y = 0;moon_vx = 0;moon_vy = 970; moon_year = earth_year; moon_h = earth_h;
mars_x = SMARSD;mars_y = 0;mars_vx = 0;mars_vy = 21970; mars_year = 59356800; mars_h = 86400*days;
jupiter_x = SJD;jupiter_y = 0;jupiter_vx = 0;jupiter_vy = 12440; jupiter_year = 371520000; jupiter_h = 86400*days; 
saturn_x = SSD;saturn_y = 0;saturn_vx = 0;saturn_vy = 9090; saturn_year = 915148800; saturn_h = 86400*days;

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

bodies = cell(6,6); 
bodies{1,1} = mercury_x_values; bodies{1,2} = mercury_y_values; bodies{1,3} = mercury_vx; bodies{1,4} = mercury_vy; bodies{1,5} = mercury_year; bodies{1,6} = mercury_h;
bodies{2,1} = venus_x_values; bodies{2,2} = venus_y_values; bodies{2,3} = venus_vx; bodies{2,4} = venus_vy; bodies{2,5} = venus_year; bodies{2,6} = venus_h;
bodies{3,1} = earth_x_values; bodies{3,2} = earth_y_values; bodies{3,3} = earth_vx; bodies{3,4} = earth_vy; bodies{3,5} = earth_year; bodies{3,6} = earth_h;
bodies{4,1} = mars_x_values; bodies{4,2} = mars_y_values; bodies{4,3} = mars_vx; bodies{4,4} = mars_vy; bodies{4,5} = mars_year; bodies{4,6} = mars_h;
bodies{5,1} = jupiter_x_values; bodies{5,2} = jupiter_y_values; bodies{5,3} = jupiter_vx; bodies{5,4} = jupiter_vy; bodies{5,5} = jupiter_year; bodies{5,6} = jupiter_h;
bodies{6,1} = saturn_x_values; bodies{6,2} = saturn_y_values; bodies{6,3} = saturn_vx; bodies{6,4} = saturn_vy; bodies{6,5} = saturn_year; bodies{6,6} = saturn_h;

n = 6;

for i = 1:n
    t = 0;
    body_x = bodies{i,1}(1); body_y = bodies{i,2}(1); body_vx = bodies{i,3}; body_vy = bodies{i,4}; body_h = bodies{i,6};
    while(t<bodies{i,5})
    body_gx = ((-G*MS*body_x)/(sqrt(body_x^2+body_y^2))^3);
    if(i == 3)
    disp(body_gx);
    end
    body_gy = ((-G*MS*body_y)/(sqrt(body_x^2+body_y^2))^3);
    body_x = body_x+((1/2)*((body_vx)+(body_vx+(body_h*(body_gx)))))*body_h;
    body_y = body_y+((1/2)*((body_vy)+(body_vy+(body_h*(body_gy)))))*body_h;
    body_gx1 = ((-G*MS*body_x)/(sqrt(body_x^2+body_y^2))^3);
    body_gy1 = ((-G*MS*body_y)/(sqrt(body_x^2+body_y^2))^3);
    body_vx = body_vx+((1/2)*(body_gx+body_gx1))*body_h;
    if(i == 3)
    %disp(body_vx);
    end
    body_vy = body_vy+((1/2)*(body_gy+body_gy1))*body_h;
    
    if(mod(t,86400)==0)
        bodies{i,1} = [bodies{i,1},body_x];
        bodies{i,2} = [bodies{i,2},body_y];
    end
    t = t+body_h;
    end
end

mercury_x_values = bodies{1,1}; mercury_y_values = bodies{1,2};
venus_x_values = bodies{2,1}; venus_y_values = bodies{2,2};
earth_x_values = bodies{3,1}; earth_y_values = bodies{3,2};
mars_x_values = bodies{4,1}; mars_y_values = bodies{4,2};
jupiter_x_values = bodies{5,1}; jupiter_y_values = bodies{5,2};
saturn_x_values = bodies{6,1}; saturn_y_values = bodies{6,2};



%Line plot
figure
hold on
numEarthYears = 100;
merc = 1; venu = 1; eart = 1; mar = 1; jupi = 1; satu = 1;
clf
xlim([2*-10^12,2*10^12])
ylim([2*-10^12, 2*10^12])
j = 1;
for i = 1:numEarthYears*numel(earth_x_values);
    hold on
    
    mercury = plot(mercury_x_values(1:j:merc),mercury_y_values(1:j:merc),'Color',[0.7,0.7,0.7]);
    if(merc==numel(mercury_x_values))
        delete(mercury)
        merc = 1;
        mercury = plot(mercury_x_values(1:j:merc),mercury_y_values(1:j:merc),'Color',[0.7,0.7,0.7]);
    else
        merc = merc+1;
    end
    
    venus = plot(venus_x_values(1:j:venu),venus_y_values(1:j:venu),'Color',[0.7,0.4,0]);
    if(venu==numel(venus_x_values))
        delete(venus);
        venu = 1;
        venus = plot(venus_x_values(1:j:venu),venus_y_values(1:j:venu),'Color',[0.7,0.4,0]);
    else
        venu = venu+1;
    end
    

    earth = plot(earth_x_values(1:j:eart),earth_y_values(1:j:eart),'Color',"blue");
    if(eart==numel(earth_x_values))
        eart = 1;
        delete(earth);
        earth = plot(earth_x_values(1:j:eart),earth_y_values(1:j:eart),'Color',"blue");
    else
        eart = eart+1;
    end
        %moon = plot(moon_x_values(1:i)+earth_x_values(1:i),moon_y_values(1:i)+earth_y_values(1:i), 'Color', [0.2,0.3,0.4]);
    
    mars = plot(mars_x_values(1:j:mar),mars_y_values(1:j:mar), 'Color',"red");
    if(mar==numel(mars_x_values))
        mar = 1;
        delete(mars);
        mars = plot(mars_x_values(1:j:mar),mars_y_values(1:j:mar), 'Color',"red");
    else
        mar = mar+1;
    end
    
    jupiter = plot(jupiter_x_values(1:j:jupi),jupiter_y_values(1:j:jupi), 'Color',[0.9,0.8,0.5]);
    if(jupi==numel(jupiter_x_values))
        jupi = 1;
        delete(jupiter);
        jupiter = plot(jupiter_x_values(1:j:jupi),jupiter_y_values(1:j:jupi), 'Color',[0.9,0.8,0.5]);
    else
        jupi = jupi+1;
    end
    
    saturn = plot(saturn_x_values(1:j:satu),saturn_y_values(1:j:satu), 'Color',[0.8,0.8,0.4]);
    if(satu==numel(saturn_x_values))
        satu = 1;
        delete(saturn);
        saturn = plot(saturn_x_values(1:j:satu),saturn_y_values(1:j:satu), 'Color',[0.8,0.8,0.4]);
    else
        satu = satu+1;
    end
    
    xlim([2*-10^12,2*10^12])
    ylim([2*-10^12, 2*10^12])
    pause(.0001)
    clf
end