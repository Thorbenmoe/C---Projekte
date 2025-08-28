#include <iostream>
#include <cstdint>
#include <windows.h>
#include <array>

// -------------------------------------------------------------
// Hilfsfunktion: Konsole leeren
// -------------------------------------------------------------

//--------------------------------------------------------------
// globals
//--------------------------------------------------------------
constexpr static auto num_rows = std::uint32_t{3};
constexpr static auto num_cols = std::uint32_t{2};

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

//--------------------------------------------------------------
// Arrays summieren
//--------------------------------------------------------------
int arraysum(int matrix1[num_rows][num_cols], int matrix_col_sum[num_cols])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix_col_sum[j] += matrix1[i][j];
        }
    }
    return 0;
}

//--------------------------------------------------------------
// Arrays printen
//--------------------------------------------------------------
int printArray(int matrix_col_sum[])
{
    for (int k = 0; k < num_cols; k++)
    {
        std::cout << matrix_col_sum[k] << "\n";
    }
}

//--------------------------------------------------------------
//double Array funktion
//--------------------------------------------------------------
double dbl_array_sum(double dbl_array[], const std::size_t length)
{
    for (int i = 0; i < length; i++)
    {
       
        
            dbl_array[i]=dbl_array[i]+i;
            dbl_array[i]=dbl_array[i]+dbl_array[i-1];
            std::cout << dbl_array[i] << "\n";
        
        
    }
    
    return 0;

}

int init()
{
    clearConsole();


    // 2d Array (Matrix)
    // 3 Zeilen 2 Spalten

    int matrix1[num_rows][num_cols] = {1, 2, 3, 4, 5, 6};
    double dbl_array[99];
    int matrix_col_sum[num_cols] = {};

    arraysum(matrix1, matrix_col_sum);
    dbl_array_sum(dbl_array,99);
    printArray(matrix_col_sum);

    return 0;
}
