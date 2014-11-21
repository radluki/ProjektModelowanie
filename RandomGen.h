#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include <random>
#include "Generator.h"

template <class G>
class RandomGen: public Generator
{
private:
    G generator;
public:

    RandomGen(){};
    ~RandomGen(){};
    virtual double losujLiczbe();
	virtual std::vector<double> losujTablice(int n);
	virtual void setSeed(double newSeed);
};
template <class G>
double RandomGen<G>::losujLiczbe()
{
    double i=generator(),p=generator.max();
    return (i/p);
}
template <class G>
std::vector<double> RandomGen<G>::losujTablice(int n)
{
    std::vector<double> vec(n);
    for(int i=0; i<vec.size(); i++) vec[i]=(double)losujLiczbe();
    return vec;
}
template <class G>
void RandomGen<G>::setSeed(double newSeed)
{
    generator.seed(newSeed);
}
template <>   //klasa random_device nie ma seeda
void RandomGen<std::random_device>::setSeed(double newSeed){}
#endif // RANLUX24
