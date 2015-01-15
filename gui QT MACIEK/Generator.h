// Klasa Generator - bazowa dla 3 generatorów liczb pseudolosowych
// autor - Łukasz Radzio

#ifndef GENERATOR_ABS
#define GENERATOR_ABS

#include<vector>
#include<algorithm>
//kożystajcie z stl, chyba że macie poważne powody przeciwko
#include<ctime>
//Seed ma mieć możliwość przyjmowania double'a oraz czasu
#include<chrono>
// do ustawiana seed zamias tbiblioteki ctime

class Generator
{
public:
	virtual ~Generator(){};
	virtual int losujLiczbe()=0;
	virtual std::vector<int> losujTablice(int n)=0;
    virtual double losujLiczbe_double()=0;
    virtual std::vector<double> losujTablice_double(int n)=0;
	virtual void setSeed(long long newSeed)=0;
};

#endif //GENERATOR_ABS
