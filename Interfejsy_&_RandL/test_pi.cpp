//test pi
//autor - Łukasz Radzio
#include"test_pi.h"
#include<vector>
#include<cmath>

using namespace std;


void test_pi::testuj(Generator *gener)
{
	int ile_w_kole=0;
	vector<double> wek=gener->losujTablice(2*ile);
	for(int i=0; i<ile; i++)
	{
		if((wek[2*i]-0.5)*(wek[2*i]-0.5)+(wek[2*i+1]-0.5)*(wek[2*i+1]-0.5)<0.25)
			ile_w_kole++;
	}
	przyblizenie_pi=4*double(ile_w_kole)/ile;
	error=M_PI-przyblizenie_pi;
	if(error<0)
		error*=-1;
}
double test_pi::wynik()
{
	return przyblizenie_pi;
}

//Ciało tej funkcji ulegnie zmianie
//Jest zależne od innych generatorów
double test_pi::interpretacja()
{
	return error;
}
