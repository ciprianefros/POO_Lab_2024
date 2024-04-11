#include <iostream>
float operator"" _Kelvin(unsigned long long kel){
    return 1.0 * kel - 273.15;
}

float operator"" _Fahrenheit(unsigned long long fah) {
    return (1.0 * fah -32) / 1.8;
}



int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << (int)(a + 273.15) << " grade Kelvin sunt egale cu: " << a << " grade Celsius\n";
    std::cout << (int)(1.8 * b + 32) << " grade Fahrenheit sunt egale cu: " << b << " grade Celsius\n";

    return 0;
}