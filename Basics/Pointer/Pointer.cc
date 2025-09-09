#include <iostream>
#include <cstdint>

void f(int v)
{   //intv !=a   beides sind eigenstädnige variabeln auf einen eigenstädnigen speicher und es wird lediglich eine ,,Kopie" erstellt
    std::cout <<&v << std::endl;
}

int main()
{
   
    int a= 2;
    std::cout << &a << std::endl;
    f(a); 

    return 0;
}