#ifndef BLUM_H
#define BLUM_H
#include "Generator.h"
#include <chrono>
class Blum_Generator: public Generator
{
private:
    unsigned int prime_number_1;// 4 100 000 027    //prime_number_1 mod 4=3
    unsigned int prime_number_2;// 4 100 000 083    //prime_number_2 mod 4=3
    const unsigned long long base_modulo; //base_modulo=prime_number_1*prime_number_2
    double to_draw_number();
    long long current_random_number;
public:
    Blum_Generator();
    ~Blum_Generator(){};
    double operator()();
    virtual int losujLiczbe();
    virtual void setSeed(long long newSeed);
    virtual std::vector<int> losujTablice(int n);
};



#endif // BLUM_H
