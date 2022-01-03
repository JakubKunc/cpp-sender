#define NOMINMAX
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN
#define B_RED FOREGROUND_RED | FOREGROUND_INTENSITY
#define B_GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define B_BLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY

#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <Windows.h>
#include "spam.h"

using namespace std;

int main() {
    
    // Prom�nn�
    string ans;
    UINT codepage = 1250;
    string sLocale;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Z�kladn� nastaven�
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    SetConsoleTextAttribute(hConsole, B_RED);
    
    cout << "Editovat adv. nastaven�? (ano/ne): ";
    cin >> ans;

    if (ans == "ano") {

    Q1:
        cout << "\nProdleva mezi repeticemi (ms): ";
        cin >> delay;
        
            if (!cin) {
            
                flushCin("Neplatn� prodleva. Zadejte jinou.");
                goto Q1;

            }
    Q2:
        cout << "\nCodepage: ";
        cin >> codepage;

            if (!cin) {

                flushCin("Neplatn� codepage. Zadejte jin�.");
                goto Q2;

            }
    Q3:
        cout << "\nLocale: ";
        cin >> sLocale;

            if (!cin || sLocale.length() < 4 || sLocale.length() > 10) {

                flushCin("Neplatn� locale. Zadejte jin�.");
                goto Q3;

            }
            
            SetConsoleTextAttribute(hConsole, B_GREEN);
            cout << "\nNastaveno.\n";
    }
    else { // Cokoliv jin�ho ne� "ano" se bere jako ne
        
        delay = 30;
        codepage = 1250;
        sLocale = "cs_CZ";

        SetConsoleTextAttribute(hConsole, B_GREEN);
        cout << "\nProdleva nastavena na z�kladn� (" << delay << "ms).\n";
        cout << "Locale nastaven na z�kladn� (" << sLocale << ").\n";
        cout << "Codepage nastaven na z�kladn� (" << codepage << ").\n";

    }

    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);
    
    SetConsoleTextAttribute(hConsole, WHITE);
    cout << "\n(c) Petr ��cha 2022. Podporuje diakritiku.\n";
    cout << "Pou�it�m programu souhlas�te se samostatnost� M�kovic.\n";
    cout << "Co chcete spamovat? -> ";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // jinak nebude kv�li cin-u fungovat getline
    getline(wcin, wts);

    SetConsoleTextAttribute(hConsole, B_GREEN);
    cout << "\nHotovo. Dr�te F12 pro spam.\n"; 
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }
        
    }
    SetConsoleTextAttribute(hConsole, WHITE);
    return 0;
}
