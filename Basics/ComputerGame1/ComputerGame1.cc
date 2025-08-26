#include <cstdint>
#include <ctime>
#include <iostream>
#include <windows.h>
#include "ComputerGame1.h"


//-----------------------------------------------------
// status
//-----------------------------------------------------
std::uint32_t gameStatus;
bool playerJump = false;




//-----------------------------------------------------
// Hilfsfunktion: Konsole leeren
//-----------------------------------------------------
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

//-----------------------------------------------------
// Funktion: Gegner bewegen
//-----------------------------------------------------
std::uint32_t moveEnemy(std::uint32_t moveFields)
{

    if (playerPosition > enemyPosition)
    {
        enemyPosition = enemyPosition + moveFields;
        return enemyPosition;
    }
    if (enemyPosition > 0)
    {
        enemyPosition = enemyPosition - moveFields;
        return enemyPosition;
    }
}

//-----------------------------------------------------
// Funktion: Spielfeld zeichnen und Spielstatus prüfen
//-----------------------------------------------------
void drawField()
{

    for (std::uint32_t i = 0; i <= FIELD_SIZE; i++)
    {
        if (i == playerPosition)
        {

            std::cout << "|"; // Spieler
        }
        else if (i == enemyPosition)
        {

            std::cout << "X"; // Gegner
        }
        else
        {

            std::cout << "_ "; // Feld
        }
    }
}

//-----------------------------------------------------
// Eingabe: Spielerbewegung
//-----------------------------------------------------
char getPlayerInput()
{
    char input;
    bool playerTurn = true;
    std::cin >> input;
    input = std::tolower(input); // Eingabe in Kleinbuchstaben umwandeln

    if (input == MOVE_RIGHT && playerTurn)
    {
        playerPosition++;
        moveEnemy(1);
        playerTurn = false;
    }
    else if (input == MOVE_LEFT && playerPosition > 0 && playerTurn)
    {
        playerPosition--;
        moveEnemy(1);
        playerTurn = false;
    }
    else if (input == JUMP && playerTurn)
    {
        playerJump = true;
        playerPosition += 2; // Spieler springt 2 Felder vorwärts
        moveEnemy(4);
        playerTurn = false;
    }

    else
    {
        std::cout << "Ungültige Eingabe!\n";
    }
    return input, playerTurn;
}

//-----------------------------------------------------
// ende überprüfen
//-----------------------------------------------------
std::uint32_t checkEnd(std::uint32_t playersPosition, std::uint32_t enemysPosition, bool playerJumps)
{
    if (playersPosition == enemysPosition && playerJumps == false)
    {

        return 0;
    }
    if (playerPosition >= FIELD_SIZE)
    {

        return 1;
    }
    return 2; // Spiel läuft weiter
}

//-----------------------------------------------------
// Hauptfunktion
//-----------------------------------------------------
int init()
{
    bool playerTurn = true;
    while (true)
    {

        // Spielfeld anzeigen
        clearConsole();
        drawField();

        // Ende prüfen
        gameStatus = checkEnd(playerPosition, enemyPosition, playerJump);
        if (gameStatus == 0)
        {
            std::cout << "Game Over! Du hast verloren.\n";
            break;
        }
        else if (gameStatus == 1)
        {
            std::cout << "Herzlichen Glückwunsch! Du hast gewonnen!\n";
            break;
        }

        // Eingabe abfragen
        playerJump = false;
        char input = getPlayerInput();
    }

    return 0;
}
