#ifndef TESTY_H
#define TESTY_H

#include "Fibonacci.h"
#include <iostream>
#include "blum_blum.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

void zapiszdopliku(unsigned int *w,string nazwa);
void odczytpliku(unsigned int *w,string nazwa,int *tab);
void zamien_na_4bity( unsigned int *ww,unsigned int *aa);
void spr_tablice_jedynek(int *tab);
void testujblum_blum();
//int ilosc_zer(const vector<long> &w);
int ilosc_zer(unsigned int *w,int *tab_liczb);
	
int tab_liczb[16];
string bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
ofstream PLIK;
ifstream PLIK1;
int tablicajedynek[7];

void zamien_na_4bity(unsigned int *wzor,unsigned int *nowa){
	
	
	struct liczba
	{
		unsigned int  a    : 4;
		unsigned int  b    : 4;
		unsigned int  c	   : 4;
		unsigned int  d    : 4; 
		unsigned int  e    : 4;
			
	};
	union
	{
		unsigned int cala;
		liczba l;
	};
	int j=0;

	for(int i=0;i<1000;i++)
	{
		j=5;
		unsigned int zmienna=wzor[i];
	 cala=zmienna;

		nowa[i*j]=l.a;
		nowa[i*j+1]=l.b;
		nowa[i*j+2]=l.c;
		nowa[i*j+3]=l.d;
		nowa[i*j+4]=l.e;
		
	}
	
}

int ilosc_zer(unsigned int *w,int *tab_liczb)
{
	int ilosc=0;
	int pom;
	for (int i=0;i<5000;i++)
	{
		if(w[i]==8||w[i]==2||w[i]==1||w[i]==4)
		ilosc+=3;
		else if (w[i]==14||w[i]==13||w[i]==11||w[i]==7)
		ilosc++;
		else if(w[i]==0)
		ilosc+=4;
		else if (w[i]==15)
		ilosc=ilosc;
		else
		ilosc+=2;
		pom=w[i];
		tab_liczb[pom]=tab_liczb[pom]+1;
	}
	return ilosc;
}

void zapiszdopliku(unsigned int *w,string nazwa){
	
		
		PLIK.open(nazwa.c_str(),ios::out);
		if(PLIK.is_open())
		{
			int liczba;
			for(int i=0;i<5000;i++)
			{
				liczba=w[i];
				PLIK<<bin[liczba];
			}	
		}
	PLIK.close();		
}

void odczytpliku(unsigned int *w,string nazwa,int *tab)
{
	PLIK1.open(nazwa.c_str(),ios::in);
	if(PLIK1.is_open())
	{
		
		char liczba;
		int ile=0;
		for(int i=0;i<20000;i++)
	{
		PLIK1.get(liczba);
		if(liczba=='1')
		ile++;
		else
		{
			if(ile>=1&&ile<6)
			tab[ile]=tab[ile]+1;
			else if (ile>=6&&ile<26)
			tab[6]+=1;
			if(ile>=26)
			tab[0]=-1;
			ile=0;
		}
		
	}
	}
	PLIK1.close();
}
void spr_tablice_jedynek(int *tab)
{
	int t=0;
	if(tab[0]==-1)
	{
		cout<<"\n\tblad 26 lub wiecej jedynek w ciagu\n";
		t--;	
	}
	else if((tab[1]<2343)||(tab[1]>2657))
	{
		cout<<"tab[1] "<<tab[1]<<"\n";
		t--;
	}

	else if((tab[2]<1135)||(tab[2]>1365))
	{
		cout<<"tab[2] "<<tab[2]<<"\n";
		t--;
	}
	else if((tab[3]<542)||(tab[3]>708))
	{
		cout<<"tab[3] "<<tab[3]<<"\n";
		t--;
	}
	else if((tab[4]<251)||(tab[4]>373))
	{
		cout<<"tab[4] "<<tab[4]<<"\n";
		t--;
	}
	else if((tab[5]<111)||(tab[5]>201))
	{
		cout<<"tab[5] "<<tab[5]<<"\n";
		t--;
	}
	else if((tab[6]<111)||(tab[6]>201))
	{
		cout<<"tab[6] "<<tab[6]<<"\n";
		t--;
			}
			
	if(t==0)
	cout<<"\n\tgenerator dobry\n\n";
	else if(t<0)
	cout<<"\n\tgenerator zly\n\n";
}
void testujblum_blum()
{
	
	unsigned long long suma = 0;
	int temp;
	unsigned int a[1000];
	unsigned int nowa[5000];
	unsigned int operacje = 1000; //ilosc testowanych liczb
//	Fibonacci generator(1048575); //mozna okreslic tu wartosc maksymalna jako argument
	Blum_Generator generator;

	
	for (unsigned int i = 0; i < operacje; i++) //obliczamy srednia liczb
	{
		a[i] = generator.losujLiczbe();
		suma += a[i];
	}
//	int average = suma / operacje;
//	std::cout << "Srednia wylosowanych liczb wynosi " << average << ".\n";
//	std::cout << "Powinna wynosic: " << 1048576 / 2 << ".\n";

	zamien_na_4bity(a,nowa);

//	for(int i=0;i<50;i++)
//	{
//		cout<<nowa[i]<<"\t"<<a[i]<<"\n";	}
//	
	cout<<"ilosc zer =\t"<<ilosc_zer(nowa,tab_liczb)<<"\n";
	double x=0;
	for(int i=0;i<16;i++)
	{
	//	cout<<tab_liczb[i]<<"\n";
		x=x+tab_liczb[i]*tab_liczb[i];
	}
	x=16*x/5000-5000;	
	if((2.16<x<46.17)&&(9725<ilosc_zer(nowa,tab_liczb)<10275))
{
	cout<<"zapisywanie do pliku\n";
	string nazwa;
		cout<<"podaj nazwe pliku\n";
		cin>>nazwa;
	zapiszdopliku(nowa,nazwa);
	
	odczytpliku(nowa,nazwa,tablicajedynek);
	//cout<<"tablica z podciagami jedynek\n";
	//for(int i=1;i<7;i++)
	//{
	//	cout<<tablicajedynek[i]<<"\n";
	//}
	spr_tablice_jedynek(tablicajedynek);
}
	else cout<<"\n\tgenerator zly\n\n";
}

#endif
