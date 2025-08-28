#include <iostream>
#include <cstdint>
#include <windows.h>
#include <array>

int init()
{   
    int num =5;
    int* p= &num;
    std::cout <<"Test " << p<< "\n";
    return 0;
}