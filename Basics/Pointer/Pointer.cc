#include <iostream>
#include <cstdint>
#include <windows.h>
#include <array>


//& Memory Adress
//*p Wert der Memory Adress
int init()
{   

    int num =5;
    int* p= &num;
    std::cout <<"Test " << p<< "\n";
    return 0;
}