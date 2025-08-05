#include <iostream>
#include <string>

int main()
{
    //string deklarieren
    std::string guesTheWord;
    char letter;
    char correct = 0;
    char trial = 7;
    bool winning= false;

    std::cout << "Geben sie ein Wort ein dass erratet werden soll" << std::endl;
    std::cin >> guesTheWord;
    std::cout << "Erraten sie das Wort, geben sie einen Buchstaben ein: " << std::endl;



     do

    {


        //Game over Abfrage
        if (trial == 0)
        {
            std::cout << "Game Over." << std::endl;
            break;
        }


        std::cin >> letter;


        //Spielzug
        if ((int)letter == (int)guesTheWord[correct])
        {
            std::cout << "Die Eingabe" << letter << " ist korrekt!" << std::endl;
            correct++;
            //Spiel Gewonnen
            if (correct == guesTheWord.length())
            {
                std::cout << "Spiel Gewonnen." << std::endl;
                winning=true;
                return 0;
            }
            continue;
        }

        else
        {
            trial--;
            std::cout << "Die Eingabe" << letter << " ist falsch." << std::endl;
            std::cout << "Verbleibende Versuche: " << (int)trial << "." << std::endl;
            continue;
        }

    }while(winning==false);

    return 0;
}
