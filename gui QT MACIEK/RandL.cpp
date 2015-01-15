#include"RandL.h"

std::vector<double> RandL::losujTablice_double(int n)
{
	std::vector<double> wek(n);
	for(int i=0; i<wek.size(); i++)
        wek[i]=losujLiczbe_double();
	return wek;
}
