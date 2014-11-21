#ifndef BLUM_H
#define BLUM_H
#include "Generator.h"
#include <chrono>
class Blum_Generator: public Generator
{
private:
    int prime_number_1;//167    //prime_number_1 mod 4=3
    int prime_number_2;//179    //prime_number_2 mod 4=3
    const unsigned long base_modulo; //base_modulo=prime_number_1*prime_number_2
    double to_draw_number();
    long current_random_number;
public:
    Blum_Generator();
    ~Blum_Generator(){};
    double operator()();
    virtual double losujLiczbe()
    virtual void setSeed(double newSeed);
    virtual std::vector<double> losujTablice(int n);
};



#endif // BLUM_H
