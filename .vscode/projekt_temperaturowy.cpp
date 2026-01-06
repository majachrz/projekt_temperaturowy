
#include <iostream>
#include <stdlib.h>
#include "headerFile.h"
#include <ctime>
using namespace std;

//konwersja tekstu na double

bool convertToDouble(const char*str, double* outValue){
    char* end;
    double val = strtod(str, &end);
    if (end == str || *end != '\0'){
        return false;
    }
    *outValue = val;
    return true;
}

//czyszczenie ekranu

void czyscEkran(){
    system("cls");
}

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
    char buf[50];
    double F;
    while (true){
    cout << "Podaj temperature w stopniach Fahrenheita" << endl;
    cin >> buf;
    if (!convertToDouble(buf, &F)){
        cout << "Niepoprawny format liczby. Wpisz ponownie" << endl;
        continue;
    }
    if (!check((float)F, 'F')){
        cout << "Niepoprawna temperatura dla Fahrenheita" << endl;
        continue;
    }
    return (float)F;
}
}

float pobierzC(){
    char buf[50];
    double C;
    while (true){
    cout << "Podaj temperature w stopniach Celsjusza" << endl;
    cin >> buf;
    if (!convertToDouble(buf, &C)){
        cout << "Niepoprawny format liczby. Wpisz ponownie" << endl;
        continue;
    }
    if (!check((float)C, 'C')){
        cout << "Niepoprawna temperatura dla Celsjusza" << endl;
        continue;
    }
    return (float)C;
}
}

float pobierzK(){
    char buf[50];
    double K;
    while (true){
    cout << "Podaj temperature w stopniach Kelwina" << endl;
    cin >> buf;
    if (!convertToDouble(buf, &K)){
        cout << "Niepoprawny format liczby. Wpisz ponownie" << endl;
        continue;
    }
    if (!check((float)K, 'K')){
        cout << "Niepoprawna temperatura dla Kelwina" << endl;
        continue;
    }
    return (float)K;
}
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

//modyfikacja historii

void modyfikujWpis(){
    if (dataCounter == 0){
        cout << "Historia jest pusta" << endl;
        return;
    }
    pokazHistorie();
    int n;
    cout << "Podaj numer wpisu do modyfikacji: " << endl;
    cin >> n;
        if (n < 1 || n > dataCounter){
        cout << "Nieprawidlowy numer" << endl;
        return;
    }
    int indeks = (n-1) *2;

    char buf[50];
    double nowaTemp;
    char nowyTyp;

    while (true){
    cout << "Podaj nowa temperature: " << endl;
    cin >> buf;
    if(!convertToDouble(buf, &nowaTemp)){
        cout << "Niepoprawny format liczby!\n";
        continue;
    }
    break;
}
    while(true){
    cout << "Podaj nowy typ C/F/K" << endl;
    cin >> nowyTyp;
    nowyTyp = toupper(nowyTyp); //zmiana malej litery na duza
    if (nowyTyp != 'C' && nowyTyp != 'F' && nowyTyp != 'K'){
        cout << "Niepoprawny typ. Wprowadz C/F/K\n";
        continue;
    }
    if (!check ((float)nowaTemp, nowyTyp)){
        cout << "Niepoprawna temperatura dla tego typu";
        continue;
    }
    break;
}

    HISTORY[indeks] = nowaTemp;
    HISTORY_TYPE[indeks] = nowyTyp;
    
    char docelowyTyp = HISTORY_TYPE[indeks +1];
    float przeliczonaTemp;

    if (nowyTyp == 'C' && docelowyTyp == 'F'){
        przeliczonaTemp = CtoF(nowaTemp);
    }
    else if (nowyTyp == 'C' && docelowyTyp == 'K'){
        przeliczonaTemp =CtoK(nowaTemp);
    }
        else if (nowyTyp == 'F' && docelowyTyp == 'C'){
        przeliczonaTemp =FtoC(nowaTemp);
    }
        else if (nowyTyp == 'F' && docelowyTyp == 'K'){
        przeliczonaTemp =FtoK(nowaTemp);
    }
        else if (nowyTyp == 'K' && docelowyTyp == 'C'){
        przeliczonaTemp =KtoC(nowaTemp);
    }
        else if (nowyTyp == 'K' && docelowyTyp == 'F'){
        przeliczonaTemp =KtoF(nowaTemp);
    }
    HISTORY[indeks + 1] = przeliczonaTemp;
    cout << "Wpis zaktualizowany" << endl;
}

//losowanie historii

void losujHistorie(){
    srand(time(0));
    int n;
    cout << "Podaj ile losowych wpisow dodac: " << endl;
    cin >> n;
    if (dataCounter * 2 + n * 2 > 100){
        int dostepne = (100 - dataCounter * 2)/2;
        cout << "Mozna dodac tylko " << dostepne << "wpisow. Czy kontunowac? (1 - tak, 2 - nie)" << endl;
        int wybor;
        cin >> wybor;
        if (wybor == 0){
            return;
        }
        n = dostepne;
    }
    for (int i = 0; i < n; i ++){
        char losowyTyp;
        int randTyp = rand() % 3;
        if (randTyp == 0){
            losowyTyp = 'C';
        }
        else if (randTyp == 1){
            losowyTyp = 'F';
        }
        else {
            losowyTyp = 'K';
        }

        int minTemp;
        if (losowyTyp == 'C'){
            minTemp = -273;
        }
        else if (losowyTyp == 'F'){
            minTemp = -459;
        }
        else {
            minTemp = 0;
        }

        int tempInt = minTemp+ rand() % 1001; //losowanie z 1000
        double temp = (double)tempInt; //konwersja na double
        char docelowyTyp;
        do{
            int randDoc = rand() % 3;
            if(randDoc == 0){
                docelowyTyp = 'C';
            }
            else if (randDoc == 1){
                docelowyTyp = 'F';
            }
            else{
                docelowyTyp = 'K';
            }
        }
            while (docelowyTyp == losowyTyp); 

            double wynik;
            if (losowyTyp == 'C' && docelowyTyp == 'F'){
                wynik = CtoF((float)temp);
            }
            else if (losowyTyp == 'C' && docelowyTyp == 'K'){
                wynik = CtoK((float)temp);
            }
            else if (losowyTyp == 'F' && docelowyTyp == 'C'){
                wynik = FtoC((float)temp);
            }
                        else if (losowyTyp == 'F' && docelowyTyp == 'K'){
                wynik = FtoK((float)temp);
            }
                        else if (losowyTyp == 'K' && docelowyTyp == 'C'){
                wynik = KtoC((float)temp);
            }
                        else if (losowyTyp == 'K' && docelowyTyp == 'F'){
                wynik = KtoF((float)temp);
            }
            else{
                wynik = float(temp);
            }
            if (!zapiszHistorie((float)temp, losowyTyp, (float)wynik, docelowyTyp)){
                cout << "Historia jest pelna " << endl;
                break;
            }
    }
    cout << "Dodano " << n << " losowych wpisow do historii" << endl;
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
cout << "9 - Modyfikuj wpis z historii" << endl;
cout << "10 - Wprowadz losowe wpisy do historii" << endl;
cout << "-1 - Zakoncz dzialanie programu" << endl;
cout << "Wybor: \n";
}

int main(){

int wybor;
float temp;
float wynik;
 

while (1){
    czyscEkran();
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
        case 9:{
            modyfikujWpis();
            break;
        }
        case 10:{
            losujHistorie();
        }
        default:
        cout << "Nieznana opcja\n";
    }
    cout << "Nacisnij dowolny klawisz zeby przejsc dalej" << endl;
    system("pause");
}
return 0;
}
