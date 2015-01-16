//Program testuj¹cy squeeze test
//autor - Ignacy Solecki
#include<iostream>
#include"squeeze_test.h"
#include"RandL.h"
#include"blum_blum.h"
#include"Fibonacci.h"

using namespace std;

int main()
{
	cout<<"Program testujacy \"squeeze_test\"\n";
	char stop;
	do{
		cout<<"Ile liczb losowac ma test? ";
		int ile;
		cin>>ile;
		cout<<"Podaj seed, 0 oznacza czas: ";
		double seed;
		cin>>seed;
		RandL r(seed);
		Generator *gener = &r;
		squeeze_test moj_test(ile);
		Test * test=&moj_test;
		test->testuj(gener);
		cout<<"Wynik testu: "<<test->wynik()<<endl
			<<"Interpretacja(error): "<<test->interpretacja()<<"%"<<endl;
		cin.get(stop);
	}while(stop=='\n');
	
	return 0;
}
