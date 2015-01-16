#include"RandL.h"

std::vector<int> RandL::losujTablice(int n)
{
	std::vector<int> wek(n);
	for(int i=0; i<wek.size(); i++)
        wek[i]=losujLiczbe();
	return wek;
}

std::vector<double> RandL::losujTablice_double(int n)
{
	std::vector<double> wek(n);
	for(int i=0; i<wek.size(); i++)
        wek[i]=losujLiczbe_double();
	return wek;
}
