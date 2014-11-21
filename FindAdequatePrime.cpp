#include <iostream>

int main(void)
{

        int  N;
        std::cin>>N;
        for (int i=2;  N>0;  ++i)
        {
            bool  isPrime  =  true ;
            for (int  j=2;  j<i;  ++j)
            {
                if (i%j== 0)
                {
                    isPrime  =  false ;
                    break ;
                }
            }
            if (isPrime)
            {
                --N;
                if((i % 4 )==3)
                {
                    std::cout  <<  i  <<  "\n";
                }
            }
        }
    return 0;
}
