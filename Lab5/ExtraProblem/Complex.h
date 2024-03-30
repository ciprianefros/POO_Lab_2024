#pragma once

#include <ostream>

class Complex {
private:
    double real_data;
    double imag_data;

public:
    Complex();
    Complex(double real, double imag);

    bool is_real() const;

    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    Complex& operator()(double real, double imag);

    Complex& operator++();
    Complex operator++(int val);
    Complex& operator--();
    Complex operator--(int val);
};

Complex operator+(double number, const Complex& comp);
Complex operator+(const Complex& comp1, const Complex& comp2);
Complex operator+(const Complex& comp, double number);

Complex operator-(double number, const Complex& comp);
Complex operator-(const Complex& comp1, const Complex& comp2);
Complex operator-(const Complex& comp, double number);

Complex operator*(double number, const Complex& comp);
Complex operator*(const Complex& comp1, const Complex& comp2);
Complex operator*(const Complex& comp, double number);

Complex operator-(const Complex& obj);

bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

std::ostream& operator<<(std::ostream& out, const Complex& complex);



