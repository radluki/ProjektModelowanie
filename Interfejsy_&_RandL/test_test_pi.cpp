//Program testujący "test pi"
//autor - Łukasz Radzio

#include<iostream>
#include"test_pi.h"
#include"RandL.h"

using namespace std;

int main()
{
	cout<<"Program testujący \"test_pi\"\n";
	char stop;
	do{
		cout<<"Ile liczb losować ma test? ";
		int ile;
		cin>>ile;
		cout<<"Podaj seed, 0 oznacza czas: ";
		double seed;
		cin>>seed;
		RandL r(seed);
		Generator *gener = &r;
		test_pi moj_test(ile);
		Test * test=&moj_test;
		test->testuj(gener);
		cout<<"Wynik testu: "<<test->wynik()<<endl
			<<"Interpretacja(error): "<<test->interpretacja()<<endl;
		cin.get(stop);
	}while(stop=='\n');
	
	return 0;
}
