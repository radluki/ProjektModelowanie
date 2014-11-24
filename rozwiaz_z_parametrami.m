function [T,Y]=rozwiaz_z_parametrami(r,a,s,b,tspan,x0)
%% ROZWIAZ_Z_PARAMETRAMI(r,a,s,b,tspan,x0) - rozwiązuje równanie Lotki-Volterry

%% Modelowane równania
% $$ \dot V = rV - aVP $$ 
%
% $$ \dot P = -sP +abVP $$ 
%
% V - ofiara, P - drapieżnik
f=@(r,a,s,b,V,P) [r*V-a*V*P; -s*P+a*b*V*P];

%% Rozwiązanie

f2 = @(t,x) f(r,a,s,b,x(1),x(2));
options=odeset('maxstep',.01); %ustawiam opcje maksymalnego kroku
[T,Y]=ode45(f2,tspan,x0,options); %przekazuje opcje maksymalnego skoku do solvera
end