#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include <random>
#include "Generator.h"
//obslugiwane klasy
//std::default_random_engine
//std::random_device
//std::ranlux24
//std::ranlux48
//std::ranlux24_base
//std::ranlux24_base
//std::minstd_rand0
//std::minstd_rand
//std::linear_congruential_engine<class UIntType, UIntType a, UIntType c, UIntType m> generator liniowy itp
//std::mt19937_64
//std::mt19937
//std::knuth_b
//std::mersenne_twister_engine <class UIntType, size_t w, size_t n, size_t m, size_t r,
                            //  UIntType a, size_t u, UIntType d, size_t s,
                            //  UIntType b, size_t t, UIntType c, size_t l, UIntType f>

template <class G>
class RandomGen: public Generator
{
private:
    G generator;
public:

    RandomGen(){};
    ~RandomGen(){};
    virtual int losujLiczbe();
	virtual std::vector<int> losujTablice(int n);
	virtual void setSeed(long long newSeed);
};
template <class G>
int RandomGen<G>::losujLiczbe()
{
    unsigned int i=generator();
    return (int)(i%16777216);
}
template <class G>
std::vector<int> RandomGen<G>::losujTablice(int n)
{
    std::vector<int> vec(n);
    for(int i=0; i<vec.size(); i++) vec[i]=losujLiczbe();
    return vec;
}
template <class G>
void RandomGen<G>::setSeed(long long newSeed)
{
    generator.seed(newSeed);
}
template <>   //klasa random_device nie ma seeda
void RandomGen<std::random_device>::setSeed(long long newSeed){}
#endif // RANLUX24
