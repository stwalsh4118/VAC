clc
clear
close all
G = 6.672*(10^-11);
MS = 1.989*(10^30);
MM = 3.285*(10^23);
MV = 4.867*(10^24);
ME = 5.972*(10^24);
SMD = 69816900000;
SVD = 108200000000;
SED = 152100000000;

years = 1;
days = 1;
h = 86400*days; endt = 31557600*years;

sun_x = 0; sun_y = 0; sun_z = 0; sun_vx = 0; sun_vy = 0; sun_vz = 50000; sun_year = 31557600; sun_h = 86400*days; sun_OM = [MS,MM,MV,ME];
mercury_x = SMD; mercury_y = 0; mercury_z = 0; mercury_vx = 0; mercury_vy = 38700; mercury_vz = 1000; mercury_year = 31557600; mercury_h = 86400*days; mercury_OM = [MS,MM,MV,ME];
venus_x = SVD; venus_y = 0; venus_z = 0; venus_vx = 0; venus_vy = 34790; venus_vz = 1000; venus_year = 31557600; venus_h = 86400*days; venus_OM = [MS,MM,MV,ME];
earth_x = SED; earth_y = 0; earth_z = 0; earth_vx = 0; earth_vy = 29300; earth_vz = 1000; earth_year = 31557600; earth_h = 86400*days; earth_OM = [MS,MM,MV,ME];

t = 0;

sun_x_values = [sun_x];
sun_y_values = [sun_y];
sun_z_values = [sun_z];

venus_x_values = [venus_x];
venus_y_values = [venus_y];
venus_z_values = [venus_z];

mercury_x_values = [mercury_x];
mercury_y_values = [mercury_y];
mercury_z_values = [mercury_z];

earth_x_values = [earth_x];
earth_y_values = [earth_y];
earth_z_values = [earth_z];
   

bodies = cell(3,9); 
bodies{1,1} = sun_x_values; bodies{1,2} = sun_y_values; bodies{1,3} = sun_z_values; bodies{1,4} = sun_vx; bodies{1,5} = sun_vy; bodies{1,6} = sun_vz; bodies{1,7} = sun_year; bodies{1,8} = sun_h; bodies{1,9} = sun_OM;
bodies{2,1} = mercury_x_values; bodies{2,2} = mercury_y_values; bodies{2,3} = mercury_z_values; bodies{2,4} = mercury_vx; bodies{2,5} = mercury_vy; bodies{2,6} = mercury_vz; bodies{2,7} = mercury_year; bodies{2,8} = mercury_h; bodies{2,9} = mercury_OM;
bodies{3,1} = venus_x_values; bodies{3,2} = venus_y_values; bodies{3,3} = venus_z_values; bodies{3,4} = venus_vx; bodies{3,5} = venus_vy; bodies{3,6} = venus_vz; bodies{3,7} = venus_year; bodies{3,8} = venus_h; bodies{3,9} = venus_OM;
bodies{4,1} = earth_x_values; bodies{4,2} = earth_y_values; bodies{4,3} = earth_z_values; bodies{4,4} = earth_vx; bodies{4,5} = earth_vy; bodies{4,6} = earth_vz; bodies{4,7} = earth_year; bodies{4,8} = earth_h; bodies{4,9} = earth_OM;

BX = zeros(365*years,4); BY = zeros(365*years,4); BZ = zeros(365*years,4); BVX = zeros(365*years,4); BVY = zeros(365*years,4); BVZ = zeros(365*years,4);
BX(1,:) = [sun_x,mercury_x,venus_x,earth_x]; BVX(1,:) = [sun_vx,mercury_vx,venus_vx,earth_vx]; BGX = zeros(365*years,4); BGX1 = zeros(365*years,4);
BY(1,:) = [sun_y,mercury_y,venus_y,earth_y]; BVY(1,:) = [sun_vy,mercury_vy,venus_vy,earth_vy]; BGY = zeros(365*years,4); BGY1 = zeros(365*years,4);
BZ(1,:) = [sun_z,mercury_z,venus_z,earth_z]; BVZ(1,:) = [sun_vz,mercury_vz,venus_vz,earth_vz]; BGZ = zeros(365*years,4); BGZ1 = zeros(365*years,4);
n = 4;


for t = 1:365*years
        for g = 1:n
            body_vx = bodies{g,4}; body_vy = bodies{g,5}; body_vz = bodies{g,6}; body_h = bodies{g,8}; body_OM = bodies{g,9};
            for OM = 1:numel(body_OM)
                if(~(OM==g))
                    body_x = (BX(t,g)-BX(t,OM));
                    body_y = (BY(t,g)-BY(t,OM));
                    body_z = (BZ(t,g)-BZ(t,OM));
                    BGX(t,g) = BGX(t,g)+((-G*body_OM(OM)*body_x)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
                    BGY(t,g) = BGY(t,g)+((-G*body_OM(OM)*body_y)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
                    BGZ(t,g) = BGZ(t,g)+((-G*body_OM(OM)*body_z)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
                end
            end
        end
        
        for p = 1:n
            body_h = bodies{p,8}; body_OM = bodies{p,9};
            BX(t+1,p) = BX(t,p)+((1/2)*((BVX(t,p))+(BVX(t,p)+(body_h*(BGX(t,p))))))*body_h;
            BY(t+1,p) = BY(t,p)+((1/2)*((BVY(t,p))+(BVY(t,p)+(body_h*(BGY(t,p))))))*body_h;
            BZ(t+1,p) = BZ(t,p)+((1/2)*((BVZ(t,p))+(BVZ(t,p)+(body_h*(BGZ(t,p))))))*body_h;
        end
        
        for g1 = 1:n
            body_vx = bodies{g1,4}; body_vy = bodies{g1,5}; body_vz = bodies{g1,6}; body_h = bodies{g1,8}; body_OM = bodies{g1,9};
            for OM = 1:numel(body_OM)
                if(~(OM==g1))
                    body_x = (BX(t+1,g1)-BX(t+1,OM));
                    body_y = (BY(t+1,g1)-BY(t+1,OM));
                    body_z = (BZ(t+1,g1)-BZ(t+1,OM));
                    BGX1(t,g1) = BGX1(t,g1)+((-G*body_OM(OM)*body_x)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
                    BGY1(t,g1) = BGY1(t,g1)+((-G*body_OM(OM)*body_y)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
                    BGZ1(t,g1) = BGZ1(t,g1)+((-G*body_OM(OM)*body_z)/(sqrt(body_x^2+body_y^2+body_z^2))^3);
                end
            end
        end
        
        for v = 1:n
            body_vx = bodies{v,4}; body_vy = bodies{v,5}; body_vz = bodies{v,6}; body_h = bodies{v,8}; body_OM = bodies{v,9};
            BVX(t+1,v) = BVX(t,v)+((1/2)*(BGX(t,v)+BGX1(t,v)))*body_h;
            BVY(t+1,v) = BVY(t,v)+((1/2)*(BGY(t,v)+BGY1(t,v)))*body_h;
            BVZ(t+1,v) = BVZ(t,v)+((1/2)*(BGZ(t,v)+BGZ1(t,v)))*body_h;
        end
end

sun_x_values = BX(:,1); sun_y_values = BY(:,1); sun_z_values = BZ(:,1);
mercury_x_values = BX(:,2); mercury_y_values = BY(:,2); mercury_z_values = BZ(:,2);
venus_x_values = BX(:,3); venus_y_values = BY(:,3); venus_z_values = BZ(:,3);
earth_x_values = BX(:,4); earth_y_values = BY(:,4); earth_z_values = BZ(:,4);


%Line plot
figure
hold on
numEarthYears = 100;
sol = 365*years ;merc = 1; venu = 1; eart = 1; mar = 1; jupi = 1; satu = 1; 
clf

j = 1;
xlabel('x');
ylabel('y');
zlabel('z');
i = 365*years;
%for i = 1:365*years
xlim([2*-10^11, 2*10^11])
ylim([2*-10^11, 2*10^11])
plot3(sun_x_values(1:j:i),sun_y_values(1:j:i),sun_z_values(1:j:i),'Color',"yellow");
hold on
plot3(mercury_x_values(1:j:i),mercury_y_values(1:j:i),mercury_z_values(1:i),'Color',[0.7,0.7,0.7])
hold on
plot3(venus_x_values(1:j:i),venus_y_values(1:j:i),venus_z_values(1:i),'Color',[0.7,0.4,0]);;
hold on
plot3(earth_x_values(1:j:i),earth_y_values(1:j:i),earth_z_values(1:i),'Color',"blue");
pause(.005)
%end

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