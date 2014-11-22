%% Skrypt prezentujący rozwiązywanie równań z ode45
% Cel jest taki aby równanie rozwiązać z ode a nie w Simulinku

%% Modelowane równania
% $$ \dot V = rV - abVP $$ 
%
% $$ \dot P = -sP +abVP $$ 

f=@(r,a,s,b,V,P) [r*V-a*V*P; -s*P+a*b*V*P];

%% Tymczasowe parametry
% Inicjacje r,a,s,b oraz czasu tspan i x0
r=2.1;a=0.2;s=0.2;b=0.4;
f2 = @(t,x) f(r,a,s,b,x(1),x(2));
tspan = linspace(0,10,100);
x0=[20;5];
f2(1,x0)
%% Rozwiązanie równania
[T,Y]=ode45(f2,tspan,x0);
plot(T,Y);