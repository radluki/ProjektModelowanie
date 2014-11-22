function y=losuj_parametr(E,delta)
%% LOSUJ_PARAMETR(E,delta) 
% zwraca wartość z przedziału [E-delta,E+delta], gdy E-delta>0
% inaczej losuje z [0,E+delta]
if E>delta
    y=E + 2*(rand(1)-0.5)*delta;
else
    y=rand(1)*(E+delta);
end