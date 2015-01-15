//Plik testowy Klasy RandL
//autor - Łukasz Radzio

#include"Generator.h"
#include"RandL.h"
#include<iostream>

using namespace std;

int main()
{
char stop;
	do{
		RandL generRandL;
		Generator *gen=&generRandL;
		gen->setSeed(time(0));
		cout<<"Jedna: "<<gen->losujLiczbe()<<endl;
		vector<double> wek=gen->losujTablice(5);
		cout<<"Tablica:"<<endl;
		for(int i=0; i<wek.size(); i++)
			cout<<wek[i]<<endl;
		cout<<endl;
	cin.get(stop);
	}while(stop=='\n');
	
	return 0;
}
