#ifndef HEADERFILE_H
#define HEADERFILE_H


float FtoC(float);
float FtoK(float);
float CtoF(float);
float CtoK(float);
float KtoC(float);
float KtoF(float);
float pobierzF();
float pobierzC();
float pobierzK();
float check (float temp, char stopnie);
void menu();

void zapiszHistorie(float stara, char typ1, float nowa, char typ2);
void pokazHistorie();



#endif
