#include "Sort.h"
using namespace std;
int main()
{
    int option;
    int n, min, max;
    cout << "Introdu numarul de elemente: ";
    cin >> n;

    cout << "Introdu marginile elementelor din vector vector[i] apartine [min, max): ";
    cin >> min >> max;

    Sort sorter(n, min, max);

    cout << "Vectorul nesortat:\n";
    sorter.Print();

    bool ok = true;
    while (ok) {
        cout << "Selecteaza algoritmul de sortare pe care doresti sa il folosesti\n"
            << "1. Insertion Sort\n"
            << "2. Quick Sort\n"
            << "3. Bubble Sort\n";
        cin >> option;

        bool ascendent;
        cout << "Alege ordinea de sortare(0 pentru descrescator, 1 pentru crescator): ";
        cin >> ascendent;
        switch (option)
            {
            case 1:
                sorter.InsertSort(ascendent);
                ok = false;
                break;
            case 2:
                sorter.QuickSort(ascendent);
                ok = false;
                break;
            case 3:
                sorter.BubbleSort(ascendent);
                ok = false;
                break;
            default:
                std::cout << "Optiune invalida. Mai incearca:\n";
        }
    }
    

    cout << "Vectorul sortat:\n";
    sorter.Print();
    cout << "Numarul de elemente al vectorului: " << sorter.GetElementsCount() << endl;

    cout << "\n\nExemple de utilizare a constructorilor: \n\n";
    cout << "Constructorul 1: \n";
    cout << "Introdu numarul de elemente: ";
    cin >> n;
    cout << "Introdu minimul si maximul: ";
    cin >> min >> max;

    Sort s2(n, min, max);
    cout << "Elementele vectorului folosind construcotrul random: \n";
    s2.Print();

    cout << "\nConstructorul 2: \n";
    cout << "Introdu numarul de elemente: ";
    cin >> n;
    int* array{ new int[n] };
    cout << "Introdu elementele vectorului(" << n << "): \n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    Sort s3(n, array);
    s3.QuickSort(true);
    cout << "Elementele vectorului 2 sortate crescator: ";
    s3.Print();

    cout << "\nConstructorul 3\n";
    cout << "Intodu numarul de elemente care vor fi copiate din vectorul 2: ";
    cin >> n;
    Sort s4(n, array);
    cout << "Elementele vectorului 3 sortate descrescator: ";
    s4.BubbleSort();
    s4.Print();
    
    cout << "\nConstructorul 4: \n";
    cout << "Introdu un sir de elemente ale vectorului(nu folosi spatii, ci desparte elementele doar prin virgula): \n";
    char sir[1000];
    cin >> sir;
     
    Sort s5((char*)sir);
    cout << "Elementele vectorului 4: ";
    s5.Print();
 

    return 0;
}