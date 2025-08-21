#include <iostream>
#include <cstdint>
#include <windows.h>

// globale Variablen
static std::uint32_t counter = 0;

// -------------------------------------------------------------
// Hilfsfunktion: Konsole leeren
// -------------------------------------------------------------
void clearConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
        return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;

    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);
}

// -------------------------------------------------------------
// Aufgabe 1 gerade oder ungerade
// -------------------------------------------------------------
int aufgabeEins()
{
    do
    {
        clearConsole();
        std::cout << "Aufgabe 1" << std::endl;
        std::cout << "Zähler: " << counter << std::endl;
        std::cout << "Super Duper Eingabe:";

        std::uint32_t eingabe;
        if (!(std::cin >> eingabe))
        {
            std::cout << "Ungültige Eingabe." << std::endl;
            return -1;
        }

        // Ausführung der Funktion und Ausgabe des Ergebnisses
        std::uint32_t super_duper_example(std::uint32_t eingabe);

        if (super_duper_example(eingabe) == 0)
        {
            std::cout << "Zähler: " << counter << std::endl;
            std::cout << "Die Eingabe ist gerade." << std::endl;
            counter++;
        }
        else
        {
            std::cout << "Die Eingabe ist ungerade." << std::endl;
        }

    } while (counter < 10);

    counter = 0; // Reset am Ende der Aufgabe
}

// -------------------------------------------------------------
// Aufgabe 2 beliebig gerade ausgeben
// -------------------------------------------------------------
int mod_cross_sum(int I, int J)
{
    clearConsole();
    if (I < 0 || J < 0)
    {
        std::cout << "Ungültige Eingabe. I und J müssen positiv sein." << std::endl;
        return -1;
    }
    std::cout << "Aufgabe 2" << std::endl;
    std::cout << "I: " << I << ", J: " << J << std::endl;
    for (int i = 0; i <= I; i++)
    {
        std::uint32_t super_duper_example(int i);
        if (i % 2 == 0)
        {
            std::cout << "i:" << i << std::endl;
        }
    }
    for (int j = 0; j <= J; j++)
    {
        std::uint32_t super_duper_example(int j);
        if (j % 2 == 0)
        {
            std::cout << "j:" << j << std::endl;
        }
    }
    return 0;
}
int aufgabeZwei()
{
    int eingabeI, eingabeJ;
    std::cout << "Geben Sie zwei Zahlen ein (I und J):" << std::endl;
    std::cin >> eingabeI >> eingabeJ;
    return mod_cross_sum(eingabeI, eingabeJ);
};


// -------------------------------------------------------------
// Aufgabe 3 Rekursive Funktion Fakultät
// -------------------------------------------------------------
std::uint32_t rekursiv_function(std::uint32_t rekursiv_n)
{
    if (rekursiv_n == 0)
    {
        return 1; // Basisfall
    }
    else
    {
        return rekursiv_n * rekursiv_function(rekursiv_n - 1); // Rekursiver Fall
    }
}


// -------------------------------------------------------------
// Beispiel-Funktion: gerade / ungerade
// -------------------------------------------------------------
std::uint32_t super_duper_example(std::uint32_t eingabe)
{
    return eingabe % 2;
}
std::uint32_t aufgabeDrei()
{
    std::uint32_t n;
    std::cout << "Geben Sie eine Zahl n ein:" << std::endl;
    std::cin >> n;
    if (n < 0)
    {
        std::cout << "Ungültige Eingabe. n muss positiv sein." << std::endl;
        return -1;
    }
    return rekursiv_function(n);
}

// -------------------------------------------------------------
// Hauptfunktion init
// -------------------------------------------------------------
int init()
{
    clearConsole();
    std::cout << "Welche Aufgabe ausführen?" << std::endl;
    std::int32_t welcheAufgabe;
    if (std::cin >> welcheAufgabe)
    {
        std::cout << "Ungültige Aufgabe." << std::endl;
    }
    switch (welcheAufgabe)
    {
    case 1:
        return aufgabeEins();
    case 2:
        return aufgabeZwei();
    case 3:
        return aufgabeDrei();
    default:
        return -1;
    }
    return 0;
}
