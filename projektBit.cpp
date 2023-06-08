#include <iostream>
#include <locale.h>
#include <stdio.h>
#include"Bitmapa.h"
#include"BitmapaExt.h"
#include"LibExcp.h"
#include"Przeksztalcenia.h"


int main()
{
    setlocale(LC_CTYPE, "Polish");

    BitmapaExt a(5, 5);
    a(0, 0) = a(1, 1) = a(2, 2) = a(3, 3) = a(4, 4) = true;
    std::cout << "\n" << a;

    Inwersja i;
    i.przeksztalc(a);

    std::cout << "\n" << a;
}
