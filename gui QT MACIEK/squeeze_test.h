//squeeze test
//autor - Ignacy Solecki
#ifndef SQUEEZE_TEST
#define SQUEEZE_TEST
#include"Test.h"

class squeeze_test:public Test
{
public:
	squeeze_test(int ile_losowac=20000):ile(ile_losowac){};
	void testuj(Generator *gener);
	double wynik();
	double interpretacja();
	~squeeze_test(){};
private:
	double srednia_l_iteracji;
	double error; //Blad wzgledny w procentach
	int ile;
};


#endif //SQUEEZE_TEST
