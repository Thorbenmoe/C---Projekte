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
// Aufgabe 1
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

    counter = 0;  // Reset am Ende der Aufgabe
}

// -------------------------------------------------------------
// Beispiel-Funktion: gerade / ungerade
// -------------------------------------------------------------
std::uint32_t super_duper_example(std::uint32_t eingabe)
{
    return eingabe % 2;
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
    default:
        return -1;
    }

    return 0;
}
