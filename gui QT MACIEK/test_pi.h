//test pi
//autor - Łukasz Radzio
#ifndef TEST_PI
#define TEST_PI
#include "Test.h"

class test_pi:public Test
{
public:
	test_pi(int ile_losowac=10000):ile(ile_losowac){};//ile punktow ma losowac test
	void testuj(Generator *gener);
	double wynik();
	double interpretacja();
	~test_pi(){};
private:
	double przyblizenie_pi;
	double error;
	int ile;
};


#endif //TEST_PI
