﻿#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <exception>
#include"Bitmapa.h"
#include"BitmapaExt.h"
#include"LibExcp.h"
#include"Przeksztalcenia.h"


int main()
{
    setlocale(LC_CTYPE, "Polish");

    try {
        BitmapaExt a(7, 7);
        a(1, 3) = a(2, 2) = a(2, 3) = a(2, 4) = a(3, 1) = a(3, 2) = a(3, 3) = a(3, 4) = a(3, 5) = a(4, 2) = a(4, 3) = a(4, 4) = a(5, 3) = true;
        std::cout << "\n" << a;

        Usrednienie u;
        Inwersja i;

        ZlozeniePrzeksztalcen z;
        z.dodajPrzeksztalcenie(&u);
        z.dodajPrzeksztalcenie(&i);

        z.przeksztalc(a);

        std::cout << "\n" << a;
    }
    catch (std::exception& e) {
        std::cerr<<e.what();
    }

}
