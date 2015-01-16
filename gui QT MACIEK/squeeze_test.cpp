//squeeze test
//autor - Ignacy Solecki
#include"squeeze_test.h"
#include<vector>
#include<cmath>

using namespace std;

void squeeze_test::testuj(Generator *gener)
{
    long long n=0;
    double k=0,j=pow(2,31);
	for(int i=1; i<=ile; i++)
	{
		j=pow(2,31);
		n=0;
		while(j>1)
		    {
		    j=j*(gener->losujLiczbe_double());
		    n++;
		    }
		k+=n; //Wyliczanie œredniej liczby potrzebnych iteracji
	}
	srednia_l_iteracji=k/ile;
	error=(22.48756-srednia_l_iteracji)*100/22.48756;
	if(error<0)
		error*=-1;
}

double squeeze_test::wynik()
{
	return srednia_l_iteracji;
}

double squeeze_test::interpretacja()
{
	return error;
}
