//test pi
//autor - Łukasz Radzio
#include"test_pi.h"
#include<vector>
#include<math.h>
#include<conio.h>

using namespace std;

#define M_PI 3.14159265358979323846
void test_pi::testuj(Generator *gener)
{
	int ile_w_kole=0;
 //   vector<double> wek=gener->losujTablice_double(2*ile);
    vector<double> wek=gener->losujTablice_double(2*ile);
	for(int i=0; i<ile; i++)
	{
		if((wek[2*i]-0.5)*(wek[2*i]-0.5)+(wek[2*i+1]-0.5)*(wek[2*i+1]-0.5)<0.25)
			ile_w_kole++;
	}
    przyblizenie_pi=(double)4*(ile_w_kole)/ile;

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
