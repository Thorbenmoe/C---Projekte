#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>


//Funktion für Löschen des Terminals
//quelle: https://learn.microsoft.com/en-us/windows/console/fillconsoleoutputcharacter                                              //Notizen zur Funktion
void clearScreen()
{ //HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); Holt sich den Zugriff auf die Konsole
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO
    csbi; //CONSOLE_SCREEN_BUFFER_INFO csbi; Informationen über den Bildschirm (Größe der Konsole, Cursor Position, Textfarbe);
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {
        0,
        0}; //COORD homeCoords = {0, 0}; Wir setzen dort den Punkt (X,Y) um von dort aus die Konsole zu überarbeiten

    if (hStdOut == INVALID_HANDLE_VALUE)
        return; //Abbrechen wenn die Konsole ungültig ist (Sicherheitsabbruch)

    // Anzahl der Zellen im Buffer
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return; //GetConsoleScreenBufferInfo(hStdOut, &csbi); Fragt die Konsole ab ,,Wie groß bist du?"
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Bildschirm mit Leerzeichen füllen
    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count))
        return; //FillConsoleOutputCharacter(...) füllt alle Zellen mit Leerzeichen

    // Attribute zurücksetzen
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
        return;

    // Cursor zurück an den Anfang
    SetConsoleCursorPosition(
        hStdOut,
        homeCoords); //SetConsoleCursorPosition(hStdOut, homeCoords) setzt den Cursor dort zurück damit der Text dort starten kann
}


int main()
{


    std::uint32_t guess_Number;
    std::uint32_t secret_Number = 0;
    std::uint32_t max_number_of_attempts = 6;
    std::uint32_t current_number_of_attempts = 0;
    std::srand(std::time(nullptr)); // einmalig initialisierens
    std::uint32_t i, j, k;          //Zähler

    secret_Number = std::rand() % 25 + 1;

    while (true)
    {
        std::cout << "Leben: " << max_number_of_attempts << std::endl;
        std::cout << "Erraten sie die Zahl: zwischen 1 und 25" << std::endl;
        std::cin >> guess_Number;

        if (guess_Number == secret_Number)
        {
            std::cout << "Gewonnen!";
            clearScreen();
            return 0;
        }

        if (max_number_of_attempts == 0 || current_number_of_attempts == 6)
        {
            std::cout << "verloren!";
            std::cout<< secret_Number;
            clearScreen();
            return 0;
        }

        if (guess_Number < secret_Number)
        {
            std::cout << "Deine Zahl ist zu klein." << std::endl;
            std::cout << "Tipp: Gesuchte Zahl ist höher als "<< guess_Number << std::endl;

            max_number_of_attempts--;
        }


        if (guess_Number > secret_Number)
        {
            std::cout << "Deine Zahl ist zu klein." << std::endl;
            std::cout << "Tipp: Gesuchte Zahl ist niedriger als " << guess_Number << std::endl;

            max_number_of_attempts--;
        }


    }


    return 0;
}
