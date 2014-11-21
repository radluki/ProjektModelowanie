#ifndef RANDOMGEN_H
#define RANDOMGEN_H
#define <random>
#definr "Generator.h"

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
    return (double)(generator()/generator.max());
}
template <class G>
std::vector<double> RandomGen<G>::losujTablice(int n)
{
    vector<double> vec(n)
    for(int i=0; i<vec.size(); i++) vec[i]=generator();
    return vec;
}
template <class G>
void RandomGen<G>::setSeed(double newSeed)
{
    generator.seed(newSeed);
}
#endif // RANLUX24
