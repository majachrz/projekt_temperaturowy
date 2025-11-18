
#include <iostream>
#include <stdlib.h>
#include "headerFile.h"
using namespace std;


double HISTORY[100] = {0};
char HISTORY_TYPE[100] = {0};
int dataCounter = 0;

float FtoC(float F) {
   return (F - 32.0f) * 5.0f / 9.0f;
}

float FtoK(float F){
    return (F + 459.67f) * 5.0f / 9.0f;
}

float CtoF(float C){
    return C * 9.0f / 5.0f + 32.0f;
}

float CtoK(float C){
    return C + 273.15f;
}

float KtoC(float K){
    return K - 273.15f;
}

float KtoF(float K){
    return K * 9.0f / 5.0f - 459.67f;
}

float pobierzF(){
    float F;
    cout << "Podaj temperature w stopniach Fahrenheita" << endl;
    cin >> F;
    return F;
}

float pobierzC(){
    float C;
    cout << "Podaj temperature w stopniach Celsjusza" << endl;
    cin >> C;
    return C;
}

float pobierzK(){
    float K;
    cout << "Podaj temperature w stopniach Kelwina" << endl;
    cin >> K;
    return K;
}

float check(float temp, char stopnie){
    if (stopnie == 'K' && temp < 0) 
    return -999.0f;
    if (stopnie == 'C' && temp < -273.15f)
    return -999.0f;
    if (stopnie == 'F' && temp < -459.67f)
    return -999.0f;
    return temp;
}

void zapiszHistorie(float stara, char typ1, float nowa, char typ2){
    if(dataCounter + 2 > 100){
        cout << "Brak miejsca w historii" << endl;
        return;
    }

    HISTORY[dataCounter] = stara;
    HISTORY_TYPE[dataCounter] = typ1;
    HISTORY[dataCounter + 1] = nowa;
    HISTORY_TYPE[dataCounter + 1] = typ2;
    dataCounter += 2;
}

void pokazHistorie(){
    cout << "Historia przeliczen:" << endl;
    if(dataCounter == 0){
        cout << "Brak zapisanych przeliczen" << endl;
        return;
    }

    int entry = 1;
    for(int i = 0; i < dataCounter; i += 2){
        cout << "<" << entry++ << "> " << HISTORY[i] << HISTORY_TYPE[i] << " = " << HISTORY[i+1] << HISTORY_TYPE[i+1] << endl;
    }
    cout << "Koniec historii przeliczen" << endl;
}

void menu(){
cout << "Wybierz opcje: " << endl;
cout << "1 - Przelicz Fahr -> Celsius" << endl;
cout << "2 - Przelicz Fahr -> Kelwin" << endl;
cout << "3 - Przelicz Celsius -> Fahr" << endl;
cout << "4 - Przelicz Celsius -> Kelwin" << endl;
cout << "5 - Przelicz Kelwin -> Celsius" << endl;
cout << "6 - Przelicz Kelwin -> Fahr" << endl;
cout << "7 - Pokaz historie" << endl;
cout << "8 - Zakoncz dzialanie programu" << endl;
cout << "Wybor: " << endl; 
}

int main(){

int wybor;
float temp;
float wynik;
 

while (1){
    system("cls");
    menu();
    cin >> wybor;

    if (wybor < 1 || wybor > 8)
        return 0;
    if (wybor == 8)
        return 0;

    switch(wybor){
        case 1:{
        temp = pobierzF();
        if (check(temp, 'F') == -999.0f){
            cout << "Nie ma takiej temperatury" << endl;
        } 
        else {
            wynik = FtoC(temp);
        cout << "Przeliczenie " << temp << " stopni Fahrenhaita na stopnie Celsjusza = " << FtoC(temp) << endl;
        zapiszHistorie(temp, 'F', wynik, 'C');
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break;
        }
        case 2:{
        temp = pobierzF();
        if (check(temp, 'F') == -999.0f){
            cout << "Nie ma takiej temperatury" << endl;
        } 
        else {
            wynik = FtoK(temp);
        cout << "Przeliczenie " << temp << " stopni Fahrenheita na stopnie Kelwina = " << FtoK(temp) << endl;
        zapiszHistorie(temp, 'F', wynik, 'K');
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break;
        }
        case 3:{
        temp = pobierzC();
        if (check(temp, 'C') == -999.0f){
            cout << "Nie ma takiej temperatury" << endl;
        } 
        else {
            wynik = CtoF(temp);
        cout << "Przeliczenie " << temp << " stopni Celsjusza na stopnie Fahrenheita = " << CtoF(temp) << endl;
        zapiszHistorie(temp, 'C', wynik, 'F');
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break;
        }
        case 4:{
        temp = pobierzC();
        if (check(temp, 'C') == -999.0f){
            cout << "Nie ma takiej temperatury" << endl;
        } 
        else {
            wynik = CtoK(temp);
        cout << "Przeliczenie " << temp << " stopni Celsjusza na stopnie Kelwina = " << CtoK(temp) << endl;
        zapiszHistorie(temp, 'C', wynik, 'K');
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break;
        }
        case 5:{
        temp = pobierzK();
        if (check(temp, 'K') == -999.0f){
            cout << "Nie ma takiej temperatury" << endl;
        } 
        else {
            wynik = KtoC(temp);
        cout << "Przeliczenie " << temp << " stopni Kelwina na stopnie Celsjusza = " << KtoC(temp) << endl;
        zapiszHistorie(temp, 'K', wynik, 'C');
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break;
        }
        case 6: {
        temp = pobierzK();
        if (check(temp, 'K') == -999.0f){
            cout << "Nie ma takiej temperatury" << endl;
        } 
        else {
            wynik = KtoF(temp);
        cout << "Przeliczenie " << temp << " stopni Kelwina na stopnie Fahrenheita = " << KtoF(temp) << endl;
        zapiszHistorie(temp, 'K', wynik, 'F');
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break; 
        }
        case 7:
            pokazHistorie();
            break;
        default:
        return 0;
    }
}

}
