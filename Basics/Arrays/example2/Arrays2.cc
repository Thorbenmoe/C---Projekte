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
    constexpr std::uint32_t len = 4;
    std::uint32_t array1[len] = {12, 32, 203, 14};
    std::uint32_t reverseArray[len];
    
    for(std::uint32_t i =0; i < len; i++)
    {
        reverseArray[i]=array1[len-i-1];
        std::cout << reverseArray[i] << std::endl;
    }

    return 0;
}
