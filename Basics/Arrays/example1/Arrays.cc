#include <iostream>
#include <cstdint>
#include <windows.h>

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

int init()
{
    clearConsole();
    constexpr auto len = std::uint32_t{3U};
    float vector1[len]{};
    float vector2[len]{};

    //-------------------------------------------------------------
    // Eingabe der Vektorelemente1
    //-------------------------------------------------------------
    for (std::uint32_t i = 0; i < len; ++i)
    {
        std::cout << "Geben Sie die " << i << ". Zahl für Vector1 ein: ";
        std::cin >> vector1[i];
    }

    //-------------------------------------------------------------
    // Eingabe der Vektorelemente2
    //-------------------------------------------------------------
    for (std::uint32_t j = 0; j < len; ++j)
    {
        std::cout << "Geben Sie die " << j << ". Zahl für Vector2 ein: ";
        std::cin >> vector2[j];
    }

    //-------------------------------------------------------------
    // Ausgabe der Vektorelemente1
    //-------------------------------------------------------------
    std::cout << "Vector1" << std::endl;
    for (std::uint32_t k = 0; k < len; ++k)
    {

        std::cout << vector1[k] << std::endl;
    }

    //-------------------------------------------------------------
    // Ausgabe der Vektorelemente2
    //-------------------------------------------------------------
    std::cout << "Vector2" << std::endl;
    for (std::uint32_t l = 0; l < len; ++l)
    {

        std::cout << vector2[l] << std::endl;
    }

    // -------------------------------------------------------------
    // addieren der Vektorelemente
    // -------------------------------------------------------------
    for (std::uint32_t m = 0; m < len; ++m)
    {
        vector1[m] = vector1[m] + vector2[m];
        std::cout << "Summe der Vektorelemente an Position " << m << ": " << vector1[m] << std::endl;
    }

    

    return 0;
}
