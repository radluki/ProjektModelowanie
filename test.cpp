#include "RandomGen.h"
#include "blum_blum.h"
#include <iostream>

int main(void)
{
    Generator *g[2];
    g[0]=new RandomGen<std::ranlux24> ;
    g[1]=new Blum_Generator;
    std::cout<<g[0]->losujLiczbe()<<std::endl;
    g[0]->setSeed(1000000);
    std::cout<<g[1]->losujLiczbe()<<std::endl;
    std::vector<double> a=g[0]->losujTablice(5);
    for(int i=0;i<5;i++)
    {
        std::cout<<a[i]<<std::endl;
    }

}
