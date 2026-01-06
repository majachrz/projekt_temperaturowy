
#include <iostream>
#include <stdlib.h>
#include "headerFile.h"
using namespace std;


double HISTORY[100] = {0};
char HISTORY_TYPE[100] = {0};
int dataCounter = 0;

//konwersja temperatur

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

//pobieranie danych do zwrocenia w main

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

//sprawdzenie czy temperatura miesci sie w skali

bool check(float temp, char stopnie){
    if (stopnie == 'K' && temp < 0) {
        return false;}
    if (stopnie == 'C' && temp < -273.15f)
    {return false;}
    if (stopnie == 'F' && temp < -459.67f){
        return false;
    }
    return true;
}

//zapisanie w historii

bool zapiszHistorie(float stara, char typ1, float nowa, char typ2){
    if(dataCounter >= 50){ //sprawdzenie czy jest miejsce
        cout << "Brak miejsca w historii" << endl;
        return false;
    }
int i = dataCounter * 2;
    HISTORY[i] = stara;
    HISTORY_TYPE[i] = typ1;
    HISTORY[i + 1] = nowa;
    HISTORY_TYPE[i + 1] = typ2;
    dataCounter ++;
    return true;
}

//wyswietlnie historii 

void pokazHistorie(){
    cout << "Historia przeliczen:" << endl;
    if(dataCounter == 0){
        cout << "Brak zapisanych przeliczen" << endl;
        return;
    }

    for(int i = 0; i < dataCounter; i ++){
        int indeks = i * 2; //pozycja wpisu w tablicy
        cout << i + 1 << ". " << HISTORY[indeks] << HISTORY_TYPE[indeks] << " = " << HISTORY[indeks+1] << HISTORY_TYPE[indeks+1] << endl;
    }
    cout << "Koniec historii przeliczen" << endl;
}

//wyswietlanie wyfiltrowanej historii

void pokazHistoriaFiltr(char typ){
    bool found = false;
    for (int i = 0; i < dataCounter; i++){
        int indeks = i *2;
        if (HISTORY_TYPE[indeks] == typ) {
            cout << i + 1 << ". " << HISTORY[indeks] << HISTORY_TYPE[indeks] << " = " << HISTORY[indeks + 1] << HISTORY_TYPE[indeks+1] << endl;
            found = true;
        }
    }
    if (!found)
    cout << "Brak danych dla tej skali" << endl;
}

//usuwanie z historii

void usunZHISTORII(){
    if (dataCounter ==0){
        cout << "Historia jest pusta" << endl;
        return;
    }
    pokazHistorie();
    int n;
    cout << "Podaj ktory wpis usunac" << endl;
    cin >> n;
    if (n < 1 || n > dataCounter){
        cout << "Nieprawidlowy numer" << endl;
        return;
    }
    int start = (n-1) * 2;
    for (int i = start +2; i < dataCounter * 2; i++){ //przesuniecie pierwszego elementu nastepnego wpisu
        HISTORY[i -2] = HISTORY[i]; //przesuniecie w lewo o 2 miejsca
        HISTORY_TYPE[i - 2] = HISTORY_TYPE[i];
    }
    dataCounter--;
    cout << "Wpis zostal usuniety" << endl;
    }

//menu historii

void menuHistorii(){
    cout << "1 - Tylko Celsius -> inne\n";
    cout << "2 - Tylko Fahr -> inne\n";
    cout << "3 - Tylko Kelwin -> inne\n";
    cout << "4 - Cala historia\n";
    cout << "Wybor: ";
    int x;
    cin >> x;
    switch (x){
        case 1: pokazHistoriaFiltr('C');
        break;
        case 2: pokazHistoriaFiltr('F');
        break;
        case 3: pokazHistoriaFiltr('K');
        break;
        case 4: pokazHistorie();
        break;
        default:
        cout << "Bledny wybor\n"; 
    }
}

//menu glowne

void menu(){
cout << "Wybierz opcje: " << endl;
cout << "1 - Przelicz Fahr -> Celsius" << endl;
cout << "2 - Przelicz Fahr -> Kelwin" << endl;
cout << "3 - Przelicz Celsius -> Fahr" << endl;
cout << "4 - Przelicz Celsius -> Kelwin" << endl;
cout << "5 - Przelicz Kelwin -> Celsius" << endl;
cout << "6 - Przelicz Kelwin -> Fahr" << endl;
cout << "7 - Pokaz historie" << endl;
cout << "8 - Usun wpis z historii" << endl;
cout << "-1 - Zakoncz dzialanie programu" << endl;
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

    if (wybor == -1){
        break;
    }

    switch(wybor){
        case 1:{
        temp = pobierzF();
        if (check(temp, 'F')){
            wynik = FtoC(temp);
        cout << "Przeliczenie " << temp << " stopni Fahrenhaita na stopnie Celsjusza = " << FtoC(temp) << endl;
        if (!zapiszHistorie(temp, 'F', wynik, 'C')){
            cout << "Historia jest pelna\n";
        }
        }
        break;
        }
        case 2:{
        temp = pobierzF();
        if (check(temp, 'F')){
            wynik = FtoK(temp);
        cout << "Przeliczenie " << temp << " stopni Fahrenheita na stopnie Kelwina = " << FtoK(temp) << endl;
        if (!zapiszHistorie(temp, 'F', wynik, 'K')){
            cout << "Historia jest pelna\n";
        }
    }
        break;
        }
        case 3:{
        temp = pobierzC();
        if (check(temp, 'C')){
            wynik = CtoF(temp);
        cout << "Przeliczenie " << temp << " stopni Celsjusza na stopnie Fahrenheita = " << CtoF(temp) << endl;
        if (!zapiszHistorie(temp, 'C', wynik, 'F')){
            cout << "Historia jest pelna\n";
        }
        }
        break;
        }
        case 4:{
        temp = pobierzC();
        if (check(temp, 'C')){
            wynik = CtoK(temp);
        cout << "Przeliczenie " << temp << " stopni Celsjusza na stopnie Kelwina = " << CtoK(temp) << endl;
        if (!zapiszHistorie(temp, 'C', wynik, 'K')){
            cout << "Historia jest pelna\n";
        }
        }
        break;
        }
        case 5:{
        temp = pobierzK();
        if (check(temp, 'K')){
            wynik = KtoC(temp);
        cout << "Przeliczenie " << temp << " stopni Kelwina na stopnie Celsjusza = " << KtoC(temp) << endl;
        if (!zapiszHistorie(temp, 'K', wynik, 'C')){
            cout << "Historia jest pelna\n";
        }
        }
        break;
        }
        case 6: {
        temp = pobierzK();
        if (check(temp, 'K')){
            cout << "Nie ma takiej temperatury" << endl;
            wynik = KtoF(temp);
        cout << "Przeliczenie " << temp << " stopni Kelwina na stopnie Fahrenheita = " << KtoF(temp) << endl;
        if (!zapiszHistorie(temp, 'K', wynik, 'F')){
            cout << "Historia jest pelna\n";
        }
        }
        break; 
        }
        case 7:
            menuHistorii();
            break;
        case 8: {
        usunZHISTORII();
        break;
    }
        default:
        cout << "Nieznana opcja\n";
    }
}
return 0;
}
