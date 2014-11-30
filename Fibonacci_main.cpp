//Fibonacci_main.cpp Prosty test generatora Fibonacciego - Marcin

#include "Fibonacci.h"
#include <iostream>

int main()
{
	unsigned long long suma = 0;
	int temp;
	unsigned int operacje = 1000000; //ilosc testowanych liczb
	Fibonacci generator; //mozna okreslic tu wartosc maksymalna jako argument
	for (unsigned int i = 0; i < operacje; i++) //obliczamy srednia liczb
	{
		temp = generator.losujLiczbe();
		suma += temp;
	}
	int average = suma / operacje;
	std::cout << "Srednia wylosowanych liczb wynosi " << average << ".\n";
	std::cout << "Powinna wynosic: " << INT_MAX / 2 << ".\n";
	return 0;
}