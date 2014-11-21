#include "blum_blum.h"

Blum_Generator::Blum_Generator():prime_number_1(167),prime_number_2(179),base_modulo(prime_number_1*prime_number_2),min(0),max(10000)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    current_random_number=seed;
}

long Blum_Generator::to_draw_number()
{
    long next_random_number;
    next_random_number=((current_random_number*current_random_number)%base_modulo);
    current_random_number=next_random_number;
    return current_random_number%max+min; /*????????? czy to nie popsuje algorytmu*/
    return current_random_number;
}
long operator()()
{
    return to_draw_number()
}
