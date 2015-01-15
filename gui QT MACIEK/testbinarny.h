#ifndef TESTBINARNY_H
#define TESTBINARNY_H

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
bool spr_tablice_jedynek(int *tab);
bool testujblum_blum(int t);
//int ilosc_zer(const vector<long> &w);
int ilosc_zer(unsigned int *w,int *tab_liczb);



#endif // TESTBINARNY_H
