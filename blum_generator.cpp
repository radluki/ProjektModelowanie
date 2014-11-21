#include "blum_blum.h"

Blum_Generator::Blum_Generator():prime_number_1(167),prime_number_2(179),base_modulo(prime_number_1*prime_number_2),min(0),max(10000)
{
    long seed = std::chrono::system_clock::now().time_since_epoch().count();
    current_random_number=seed;
}

double Blum_Generator::to_draw_number()
{
    long next_random_number;
    next_random_number=((current_random_number*current_random_number)%base_modulo);
    current_random_number=next_random_number;
    return (double)current_random_number/(base_modulo-1);
}
double Blum_Generator::operator()()
{
    return to_draw_number();
}
double Blum_Generator::losujLiczbe()
{
    return to_draw_number();
}
std::vector<double> Blum_Generator::losujTablice(int n)
{
    std::vector<double> vek(n);
	for(int i=0; i<vek.size(); i++)
		vek[i]=to_draw_number();
	return vek;
}
void Blum_Generator::setSeed(double newSeed)
{
    current_random_number=newSeed;
}
