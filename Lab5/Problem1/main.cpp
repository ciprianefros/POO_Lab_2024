#include <iostream>
#include "Number.h"

int main()
{
        Number n1("10110010", 2);
        Number n2("734", 8);
        Number n3("FF", 16);

        printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
        for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
        {
            printf("n1[%d]=%c\n", tr, n1[tr]);
            
        }
        n1.Print();
        n2.Print();

        n3.Print();
        n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
        n1.Print();
        n1.SwitchBase(2);
        n1.Print();

        if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

        Number n4 = 12345; // n4 will be in base 10
        n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
        n4 += n1;
        n4.Print();

        n4 = "13579"; // n4 mentains its base (10) and will be 13579
        n4.Print();
        --n4; // the first digit from n4 will be remove ==> n4 becomes 3579
        n4.Print();
        n4--; // the last digit from n4 will be remove ==> n4 becomes 357
        n4.Print();

        Number n5("10", 2);
        Number n6("111", 2);

        Number n7 = n5 * n6;
        n7.Print();
        n7.GetBase();

        std::cout << "Numerele pe care vom efectua operatiile sunt:" << std::endl;
        Number num1("11", 2);
        std::cout << "Primul numar:" << std::endl;
        num1.Print();
        Number num2("AE", 16);
        std::cout << "Al doilea numar:" << std::endl;
        num2.Print();
        Number num3(154);
        std::cout << "Al treilea numar:" << std::endl;
        num3.Print();

        num1++;
        --num2;
        num3++;
        Number suma = num1 + num2;
        Number diferenta = num2 - num3;
        Number produsul = num1 * num3;
        Number catul = num3 / n7;

        std::cout << std::endl;
        std::cout << "Cateva exemple proprii de utilizare a Clasei Number:" << std::endl;
        std::cout << "Suma: ";
        suma.Print();
        std::cout << "Diferenta: ";
        diferenta.Print();
        std::cout << "Produsul: ";
        produsul.Print();
        std::cout << "Catul: ";
        catul.Print();

     
        if (num1 <= num2)
            std::cout << "num1 este mai mic sau egal decat num2" << std::endl;
        else
            std::cout << "num2 este mai mare decat num1" << std::endl;

        
        num1 += num3;
        num2 -= num3;
        num3 += num1;

        std::cout << "num1 modificat: ";
        num1.Print();
        std::cout << "num2 modificat: ";
        num2.Print();
        std::cout << "num3 modificat: ";
        num3.Print();



        return 0;
}
    
