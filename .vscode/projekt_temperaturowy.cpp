
#include <iostream>
#include <stdlib.h>
using namespace std;

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

void menu(){
cout << "Wybierz opcje: " << endl;
cout << "1 - przelicz Fahr -> Celsius" << endl;
cout << "2 - przelicz Fahr -> Kelwin" << endl;
cout << "3 - przelicz Celsius -> Fahr" << endl;
cout << "4 - przelicz Celsius -> Kelwin" << endl;
cout << "5 - przelicz Kelwin -> Celsius" << endl;
cout << "6 - przelicz Kelwin -> Fahr" << endl;
cout << "7 - zakoncz dzialanie programu" << endl;
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
    if (wybor < 1 || wybor > 7)
        return 0;
    if (wybor == 7)
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
            wynik = FtoC(temp);
        cout << "Przeliczenie " << temp << " stopni Fahrenheita na stopnie Kelwina = " << FtoK(temp) << endl;
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
        }
        cout << "Nacisnij ENTER zeby kontynuowac" << endl;
        cin.ignore();
        cin.get();
        break; 
        }
        default:
        return 0;
    }
}

}
