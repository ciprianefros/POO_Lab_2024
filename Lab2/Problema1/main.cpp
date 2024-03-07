#include "NumberList.h"
int main() {
    NumberList n;
    n.Init();

    int num;

    std::cout << "Cate numere vrei sa introduci(max 10): ";
    std::cin >> num;
    if (num > 10)
        num = 10;
    for (int i = 0; i < num; i++) {
        int numar;
        std::cout << "Introdu numarul " << i+1  << " : ";
        std::cin >> numar;
        n.Add(numar);
    }
    std::cout << "Numerele introduse sunt: " << std::endl;
    n.Print();
    std::cout << std::endl;
    n.Sort();
    std::cout << "Numerele Sortate sunt: " << std::endl;
    n.Print();
    return 0;
}