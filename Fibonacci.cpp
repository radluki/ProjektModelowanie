//Fibonacci.cpp Definicje motod klasy Fibonacci - Marcin

#include "Fibonacci.h"

Fibonacci::Fibonacci() : i(1279), j(418), maxnumber(INT_MAX), actual(0)
{
	std::vector<unsigned long long> temp(std::max(i, j));
	for (int k = 0; k < std::max(i, j); k++)
		temp[k] = std::chrono::system_clock::now().time_since_epoch().count() % (maxnumber + 1); //ustawiam seed na podstawie zegara
	seed = temp;
}

Fibonacci::Fibonacci(unsigned long long max, long a, long b) : i(a), j(b), maxnumber(max), actual(0)
{
	std::vector<unsigned long long> temp(std::max(i, j));
	for (int k = 0; k < std::max(i, j); k++)
		temp[k] = std::chrono::system_clock::now().time_since_epoch().count() % (maxnumber + 1);
	seed = temp;
}

int Fibonacci::losujLiczbe()
{
	seed[actual] = (seed[actual] + seed[(actual + std::abs(i - j)) % (std::max(i, j))]) % (maxnumber + 1);
	return seed[actual];
	actual = (actual + 1) % (std::max(i, j));
}

std::vector<int> Fibonacci::losujTablice(int n)
{
	std::vector<int> wynik(n);
	for (int k = 0; k < n; k++)
		wynik[k] = losujLiczbe();
	return wynik;
}

void Fibonacci::setSeed(long a, long b)
{
	i = a;
	j = b;
	actual = 0;
	for (int k = 0; k < std::max(i, j); k++)
		seed[k] = std::chrono::system_clock::now().time_since_epoch().count() % (maxnumber + 1);
	return;
}

void Fibonacci::setSeed(long long newSeed)
{
	return; //Ta funkcja nie ma sensu dla generatora Fibonacciego. Za to dodalem funkcje setSeed, która ma sens.
}