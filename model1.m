function [fun,names,default_values] = model1()
% Mniejwięcej tak można zrobić funkcje z bazy danych
fun = @(param) [param(3)-param(2);param(1)*param(2)];

default_values=[1 2 3]