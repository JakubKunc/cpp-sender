#define NOMINMAX

#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main() {
    
    string ans;
    UINT codepage;

    setlocale(LC_ALL, "cs_CZ");
    system("Color 0E"); // �lut� - mus� se nastavit parametry
    
    cout << "Chcete zm�nit pokro�il� nastaven�? (ano/ne): ";
    cin >> ans;

    if (ans == "ano") {

        cout << "\nProdleva mezi repeticemi (ms): "; // 30ms je rozumn� ale m��e tak� zp�sobit probl�my p�i del��m spamu
        cin >> delay;
        cout << "Prodleva nastavena na " << delay << "ms.\n\n";

        cout << "Codepage: "; // Pokud u�ivatel chce z n�jak�ho d�vodu n�meck�, francouzsk� znaky atd.
        cin >> codepage;

    }
    else { // Cokoliv jin�ho ne� "ano" se bere jako ne
        delay = 30;
        cout << "\nProdleva nastavena na 30ms.\n";
        codepage = 1250;
    }
    
    SetConsoleCP(codepage);
    cout << "Codepage nastaven na " << codepage << ".\n\n";

    cout << "(c) Petr ��cha 2022. M�lo by podporovat �esk� znaky.\n";
    cout << "Pou�it�m programu souhlas�te se samostatnost� M�kovic.\n";
    cout << "Co chcete spamovat? -> ";
    
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // jinak bude kv�li p�edchoz�mu cin-u p�esko�en getline
    getline(wcin, wts);

    system("Color 0A"); // Zelen� - program je p�ipraven

    cout << "\nP�ipraveno. Dr�te F12 pro spam.\n"; 
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }
        
    }
    return 0;
}