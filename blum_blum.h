#ifndef BLUM_H
#define BLUM_H
#include //"kalsa bazowa
#include <chrono>
class Blum_Generator: public /* wpisz klase bazowa*/
{
private:
    int prime_number_1;//167    //prime_number_1 mod 4=3
    int prime_number_2;//179    //prime_number_2 mod 4=3
    const unsigned long base_modulo; //base_modulo=prime_number_1*prime_number_2
    unsigned long to_draw_number();
    unsigned long current_random_number;
    unsigned long min,max;
public:
    Blum_Generator();
    void set_min(long new_min){if(min<max) min=new_min};
    void set_max(long new_max){if(max>min and max>0) max=new_max};
};



#endif // BLUM_H
