clc
clear
close all
G = 6.672*(10^-11);
MS = 1.989*(10^30);
ME = 5.972*(10^24);
SED = 152100000000;

years = 1;
days = .005;
h = 86400*days; endt = 31557600*years;

sun_x = -SED; sun_y = 0; sun_z = 0; sun_vx = 0; sun_vy = 0; sun_vz = 1000; sun_year = 31557600; sun_h = 86400*days; sun_OM = [ME];
earth_x = SED; earth_y = 0; earth_z = 0; earth_vx = 0; earth_vy = 29300; earth_vz = 0; earth_year = 31557600; earth_h = 86400*days; earth_OM = [MS];

t = 0;

sun_x_values = [sun_x];
sun_y_values = [sun_y];
sun_z_values = [sun_z];

earth_x_values = [earth_x];
earth_y_values = [earth_y];
earth_z_values = [earth_z];
   

bodies = cell(2,9); 
bodies{1,1} = sun_x_values; bodies{1,2} = sun_y_values; bodies{1,3} = sun_z_values; bodies{1,4} = sun_vx; bodies{1,5} = sun_vy; bodies{1,6} = sun_vz; bodies{1,7} = sun_year; bodies{1,8} = sun_h; bodies{1,9} = sun_OM;
bodies{2,1} = earth_x_values; bodies{2,2} = earth_y_values; bodies{2,3} = earth_z_values; bodies{2,4} = earth_vx; bodies{2,5} = earth_vy; bodies{2,6} = earth_vz; bodies{2,7} = earth_year; bodies{2,8} = earth_h; bodies{2,9} = earth_OM;

BX = [sun_x,earth_x]; BVX = [sun_vx,earth_vx]; BGX = [0,0];
BY = [sun_y,earth_y]; BVY = [sun_vy,earth_vy]; BGY = [0,0];
BZ = [sun_z,earth_z]; BVZ = [sun_vz,earth_vz]; BGZ = [0,0];

n = 2;


for t = 1:365
        for g = 1:n
            body_x = bodies{g,1}(t); body_y = bodies{g,2}(t); body_z = bodies{g,3}; body_vx = bodies{g,4}; body_vy = bodies{g,5}; body_vz = bodies{g,6}; body_h = bodies{g,8}; body_OM = bodies{g,9};
            BGX(t,g) = ((-G*body_OM*BX(t,g))/(sqrt(BX(t,g)^2+BY(t,g)^2+BZ(t,g)^2))^3);
            BGY(t,g) = ((-G*OM*BY(t,g))/(sqrt(BX(t,g)^2+BY(t,g)^2+BZ(t,g)^2))^3);
            BGZ(t,g) = ((-G*OM*BZ(t,g))/(sqrt(BX(t,g)^2+BY(t,g)^2+BZ(t,g)^2))^3);
        end
        
        for p = 1:n
            body_x = bodies{p,1}(t); body_y = bodies{p,2}(t); body_z = bodies{p,3}; body_vx = bodies{p,4}; body_vy = bodies{p,5}; body_vz = bodies{p,6}; body_h = bodies{p,8};
            BX(t,p) = BX(t,p)+((1/2)*((body_vx)+(body_vx+(body_h*(body_gx)))))*body_h;
            BY(t,p) = body_y+((1/2)*((body_vy)+(body_vy+(body_h*(body_gy)))))*body_h;
            BZ(t,p) = body_z+((1/2)*((body_vz)+(body_vz+(body_h*(body_gz)))))*body_h;
        end
    body_gx1 = ((-G*MS*body_x)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
    body_gy1 = ((-G*MS*body_y)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
    body_gz1 = ((-G*MS*body_z)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
    body_vx = body_vx+((1/2)*(body_gx+body_gx1))*body_h;
    body_vy = body_vy+((1/2)*(body_gy+body_gy1))*body_h;
    body_vz = body_vz+((1/2)*(body_gz+body_gz1))*body_h;
    
    if(mod(t,86400)==0)
        bodies{i,1} = [bodies{i,1},body_x];
        bodies{i,2} = [bodies{i,2},body_y];
        bodies{i,3} = [bodies{i,3},body_z];
    end
end

sun_x_values = bodies{1,1}; sun_y_values = bodies{1,2}; sun_z_values = bodies{1,3};
earth_x_values = bodies{2,1}; earth_y_values = bodies{2,2}; earth_z_values = bodies{2,3};


%Line plot
figure
hold on
numEarthYears = 100;
sol = 367 ;merc = 1; venu = 1; eart = 1; mar = 1; jupi = 1; satu = 1; 
clf
xlim([2*-10^12,2*10^12])
ylim([2*-10^12, 2*10^12])
j = 1;

plot3(sun_x_values(1:j:sol),sun_y_values(1:j:sol),sun_z_values(1:j:sol),'Color',"yellow");
hold on
plot3(earth_x_values(1:j:numel(earth_x_values)),earth_y_values(1:j:numel(earth_y_values)),earth_z_values(1:numel(earth_z_values)),'Color',"blue");

% for i = 1:numEarthYears*numel(earth_x_values);
%     hold on
%     
%     sun = plot3(sun_x_values(1:j:sol),sun_y_values(1:j:sol),sun_z_values(1:j:sol),'Color',"blue");
%     if(sol==numel(sun_x_values))
%         sol = 1;
%         delete(sun);
%         sun = plot3(sun_x_values(1:j:sol),sun_y_values(1:j:sol),sun_z_values(1:j:sol),'Color',"blue");
%     else
%         sol = sol+1;
%     end
%    
%     earth = plot3(earth_x_values(1:j:eart),earth_y_values(1:j:eart),earth_z_values(1:j:eart),'Color',"blue");
%     if(eart==numel(earth_x_values))
%         eart = 1;
%         delete(earth);
%         earth = plot3(earth_x_values(1:j:eart),earth_y_values(1:j:eart),earth_z_values(1:j:eart),'Color',"blue");
%     else
%         eart = eart+1;
%     end
%         %moon = plot(moon_x_values(1:i)+earth_x_values(1:i),moon_y_values(1:i)+earth_y_values(1:i), 'Color', [0.2,0.3,0.4]);
%    
%     xlim([2*-10^12,2*10^12])
%     ylim([2*-10^12, 2*10^12])
%     pause(.0001)
%     clf
% end