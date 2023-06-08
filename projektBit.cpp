#include <iostream>
#include <locale.h>
#include <stdio.h>


int main()
{
    setlocale(LC_CTYPE, "Polish");

    std::cout << "ąćżź";
}
