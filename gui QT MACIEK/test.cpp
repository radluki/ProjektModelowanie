#include "RandomGen.h"
#include "blum_blum.h"
#include <iostream>
#include <algorithm>
#include <iterator>

int main(void)
{
    Generator *g[3];
    g[0]=new RandomGen<std::ranlux24> ;
    g[1]=new Blum_Generator;
    g[2]=new RandomGen<std::random_device>;
    std::cout<<g[0]->losujLiczbe()<<std::endl;
    g[0]->setSeed(1000000);
    std::cout<<g[1]->losujLiczbe()<<std::endl;
    std::vector<double> a=g[0]->losujTablice(5);
    for(int i=0;i<5;i++)
    {
        std::cout<<a[i]<<std::endl;
    }
	std::cout<<"\nTest random_device:\n";
	std::cout<<g[2]->losujLiczbe()<<std::endl;
	std::vector<double> b=g[2]->losujTablice(30);
	std::ostream_iterator<double> out_iter(std::cout,"ł;\n");
	std::copy(b.begin(),b.end(),out_iter);		
	return 0;

}
