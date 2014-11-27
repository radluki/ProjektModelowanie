#include "blum_blum.h"

Blum_Generator::Blum_Generator():prime_number_1(4 100 000 027),prime_number_2(4 100 000 083),base_modulo(prime_number_1*prime_number_2)
{
    unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    current_random_number=seed;
}

int Blum_Generator::to_draw_number()
{
    long long next_random_number;
    next_random_number=((current_random_number*current_random_number)%base_modulo);
    current_random_number=next_random_number;
    return (int)(current_random_number%16777216);
}
double Blum_Generator::operator()()
{
    return to_draw_number();
}
int Blum_Generator::losujLiczbe()
{
    return to_draw_number();
}
std::vector<int> Blum_Generator::losujTablice(int n)
{
    std::vector<int> vek(n);
	for(int i=0; i<vek.size(); i++)
		vek[i]=to_draw_number();
	return vek;
}
void Blum_Generator::setSeed(long long newSeed)
{
    current_random_number=newSeed;
}
