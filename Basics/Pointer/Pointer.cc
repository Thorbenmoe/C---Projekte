#include <iostream>
#include <cstdint>

//& Memory Adress
//*p Wert der Memory Adress
int init()
{

    auto *p = new std::int32_t{4};

    if (p != nullptr)
    {
        std::cout << p << "\n";
        std::cout << *p << "\n";
    }
    else
    {
        delete p;
        p = nullptr;
    }

    return 0;
}