//RandL - nakładka na funkcję rand() z biblioteki standardowej
#ifndef RANDL
#define RANDL

#include"Generator.h"
#include<cstdlib>
#include<ctime>

class RandL:public Generator
{
public:
	RandL(double x=0)
	{
		if(x==0)setSeed(time(0));
		else setSeed(x);
	}
	int losujLiczbe()
	{
	   return std::rand();
	}
	std::vector<int> losujTablice(int n);
    double losujLiczbe_double()
	{
		return double(std::rand())/RAND_MAX;
	}
    std::vector<double> losujTablice_double(int n);
	void setSeed(long long newSeed)
	{
		std::srand(newSeed);
	}
	~RandL(){};
};




#endif //RANDL
