#include <iostream>
#include <cmath>

int main(void)
{

        int  N;
        std::cin>>N;
        for (unsigned int i=41000;  N>0;  ++i)
        {
            bool  isPrime  =  true ;
            for (unsigned int  j=2;  j<(i/2);  ++j)
            {
                if (i%j== 0)
                {
                    isPrime  =  false ;
                    break ;
                }
            }
            if (isPrime)
            {
                if((i % 4 )==3)
                {
                    --N;
                    std::cout  <<  i  <<  "\n";
                }
            }
        }
        std::cout  <<  sizeof(int)  <<  "\n";
        std::cout  <<  sizeof(long)  <<  "\n";
        std::cout  <<  sizeof(long long)  <<  "\n";
    return 0;

}
