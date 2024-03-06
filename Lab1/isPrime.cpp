#include <iostream>
using namespace std;

bool estePrim(int n)
{
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr ) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cout << "Scrie un numar:";
    cin >> n;
    if (estePrim(n))
        cout << n << " Numarul este prim !";
    else 
        cout << n << " Numarul nu este prim !";
    return 0;
}
