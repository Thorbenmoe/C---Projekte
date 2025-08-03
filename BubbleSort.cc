#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::uint32_t i, j, k, temp;
    std::uint32_t arr[100];
    std::srand(std::time(nullptr)); // einmalig initialisieren

    // Zufallszahlen generieren
    for (i = 0; i < 100; i++) {
        arr[i] = std::rand() % 1000 + 1;
    }

    // Bubble Sort
    for (j = 0; j < 99; j++) {
        for (k = 1; k < 100 - j; k++) {
            if (arr[k] < arr[k - 1]) {
                temp = arr[k];
                arr[k] = arr[k - 1];
                arr[k - 1] = temp;
            }
        }
    }

    // Sortierte Zahlen ausgeben
    for (i = 0; i < 100; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
