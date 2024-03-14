#include "Math.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Introdu 2 numere: ";
	int a, b, c;
	Math m;

	cin >> a >> b;

	cout << "Suma numerelor este: " << m.Add(a, b) << endl;
	cout << "Produsul numerelor este: " << m.Mul(a, b) << endl;

	cout << endl << "Introdu 3 numere: ";

	cin >> a >> b >> c;

	cout << "Suma numerelor este: " << m.Add(a, b, c) << endl;
	cout << "Produsul numerelor este: " << m.Mul(a, b, c) << endl;
	

	cout << endl << "Introdu 2 numere in dubla precizie: ";
	double x, y, z;

	cin >> x >> y;

	cout << "Suma numerelor(trunchiata) este: " << m.Add(x, y) << endl;
	cout << "Produsul numerelor este: " << m.Mul(x, y) << endl;

	cout << endl <<"Introdu 3 numere in dubla precizie: ";

	cin >> x >> y >> z;

	cout << "Suma numerelor(trunchiata) este: " << m.Add(x, y, z) << endl;
	cout << "Produsul numerelor este: " << m.Mul(x, y, z) << endl;

	const char* str = "Hello";
	const char* str2 = " World!";

	cout << m.Add(str, str2) << endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	cout << "Elementele array-ului sunt: ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Suma numerelor din array este: " << m.Add(arrSize, arr[0], arr[1], arr[2], arr[3], arr[4]);

	


}