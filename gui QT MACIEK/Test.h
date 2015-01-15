//Klasa Test - klasa bazowa dla 3 testów generatorów liczb pseudolosowych
//autor - Łukasz Radzio

#ifndef TEST_ABS
#define TEST_ABS

#include"Generator.h"

class Test
{
public:
	virtual void testuj(Generator *gener)=0;
	//Propozycja: niech testuj wykonuje obliczenia
	//i zmienia stan obiektu testującego
	//obiekt testujący powinien zawierać wyniki z ostatniego testu 
	//w zmiennych stanu
	//dalsze funkcje służą do publikacji i wyświetlania wyników
	virtual double wynik()=0;
	//Zwraca wynik charakterystyczny dla każdego testu
	//Opiszcie co oznacza
	virtual double interpretacja()=0;
	//Zwraca wynik w postaci którą można porównywać niezależnie od testu
	virtual ~Test(){};
};

#endif //TEST_ABS
