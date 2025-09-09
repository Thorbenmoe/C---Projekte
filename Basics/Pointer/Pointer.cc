#include <iostream>
#include <cstdint>
#include "Pointer.h"

void f1(int v)
{ // intv !=a   beides sind eigenstädnige variabeln auf einen eigenstädnigen speicher und es wird lediglich eine ,,Kopie" erstellt
    std::cout << &v << std::endl;
}

//nicht verwenden
void f2(int *v)
{ // intv !=a   beides sind eigenstädnige variabeln auf einen eigenstädnigen speicher und es wird lediglich eine ,,Kopie" erstellt
    std::cout << *v << std::endl;
}

//verwenden
void f3(int &v)
{ // reference , keine Kopoie  f3(a) ist dasselbe wie das int &v was übergeben wird
    std::cout << &v << std::endl;
     std::cout << v << std::endl;
}

int init()
{

    int a = 2;
    std::cout << &a << std::endl;
    f1(a);
    f2(&a);
    f3(a);
    return 0;
}
