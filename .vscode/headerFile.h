#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
using namespace std;

extern double HISTORY[100];
extern char HISTORY_TYPE[100];
extern int dataCounter;

float FtoC(float F);
float FtoK(float F);
float CtoF(float C);
float CtoK(float C);
float KtoC(float K);
float KtoF(float K);
float pobierzF();
float pobierzC();
float pobierzK();


bool check (float temp, char stopnie);

bool zapiszHistorie(float stara, char typ1, float nowa, char typ2);
void pokazHistorie();
void pokazHistorieFiltr(char typ);
void usunZHistorii();
void modyfikujWpis();
void losujHistorie();

void menu();
void menuHistorii();

bool convertToDouble(const char* str, double* outValue);
void czyscEkran();

#endif
