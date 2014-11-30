//Fibonacci.h Generator Fibonacciego liczb pseudolosowych - Marcin

#ifndef Fibon
#define Fibon

#include <vector>
#include <chrono>
#include <algorithm>
#include "Generator.h"
#include <climits>

class Fibonacci : public Generator //dziedziczy interfejs
{
private:
	long actual; //ktora liczbe bedzie teraz losowal
	long i; //pierwsze opoznienie
	long j; //drugie opoznienie
	std::vector<unsigned long long> seed; //wektor wartosci poczatkowych (musi ich byc tyle ile wieksze opoznienie)
	unsigned long long maxnumber; //maksymalna wylosowana liczba
public:
	Fibonacci();
	Fibonacci(unsigned long long max, long a = 1279, long b = 418); //pierwszy argument to maksymalna wartosc, a dwa pozostale to opoznienia
	~Fibonacci() {}
	int losujLiczbe();
	std::vector<int> losujTablice(int);
	void setSeed(long, long); //tu jest dobry setSeed
	void setSeed(long long newSeed); //ten z klasy bazowej nie ma sensu dla generatora Fibonacciego
};
#endif