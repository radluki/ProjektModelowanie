//RandL - nakładka na funkcję rand() z biblioteki standardowej
#ifndef RANDL
#define RANDL

#include"Generator.h"
#include<cstdlib>

class RandL:public Generator
{
public:
	double losujLiczbe()
	{
		return double(std::rand())/RAND_MAX;
	}
	std::vector<double> losujTablice(int n);
	void setSeed(double newSeed)
	{
		std::srand(newSeed);
	}
	~RandL(){};
};




#endif //RANDL
