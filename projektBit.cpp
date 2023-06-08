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

    BitmapaExt b(5, 5);
    b(2, 2) = b(2, 1) = b(2, 3) = b(1, 2) = b(3, 2) = true;
    std::cout << "\n" << b;

    Erozja e;
    e.przeksztalc(b);
    std::cout << "\n" << b;
}
