#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return (*this);
}

Complex& Complex::operator++()
{
    ++real_data;
    ++imag_data;
    return (*this);
}

Complex Complex::operator++(int val)
{
    Complex temp(real_data, imag_data);
    ++(*this);
    return temp;
}

Complex& Complex::operator--()
{
    --real_data;
    --imag_data;
    return(*this);
}

Complex Complex::operator--(int val)
{
    Complex temp(real_data, imag_data);
    ++(*this);
    return temp;
}

Complex operator+(double number, const Complex& comp)
{
    Complex result(comp.real() + number, comp.imag());
    return result;
}

Complex operator+(const Complex& comp1, const Complex& comp2)
{
    Complex result(comp1.real() + comp2.real(), comp1.imag() + comp2.imag());
    return result;
}

Complex operator+(const Complex& comp, double number)
{
    Complex result(comp.real() + number, comp.imag());
    return result;
}

Complex operator-(double number, const Complex& comp)
{
    Complex result(comp.real() - number, comp.imag());
    return result;
}

Complex operator-(const Complex& comp1, const Complex& comp2)
{
    Complex result(comp1.real() - comp2.real(), comp1.imag() - comp2.imag());
    return result;
}

Complex operator-(const Complex& comp, double number)
{
    Complex result(comp.real() - number, comp.imag());
    return result;
}

Complex operator*(double number, const Complex& comp)
{
    double real = number * comp.real();
    double imag = number * comp.imag();
    Complex result(real, imag);
    return result;
}

Complex operator*(const Complex& comp1, const Complex& comp2)
{
    double real = comp1.real() * comp2.real() - comp1.imag() * comp2.imag();
    double imag = comp1.real() * comp2.imag() + comp1.imag() * comp2.real();
    Complex result(real, imag);
    return result;
}

Complex operator*(const Complex& comp, double number)
{
    double real = number * comp.real();
    double imag = number * comp.imag();
    Complex result(real, imag);
    return result;
}

Complex operator-(const Complex& obj)
{
    Complex result(-obj.real(), -obj.imag());
    return result;
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag() == r.imag()) {
        return true;
    }
    return false;
}

bool operator!=(const Complex& l, const Complex& r)
{
    if (l.real() != r.real() || l.imag() != r.imag()) {
        return true;
    }
    else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.real() == 0 && complex.imag() != 0) {
        out << complex.imag() << "i";
    }
    else if (complex.imag() == 0 && complex.real() != 0) {
        out << complex.real();
    }
    else if (complex.real() != 0 && complex.imag() != 0 && complex.imag() > 0) {
        out << complex.real() << " + " << complex.imag() << "i";
    }
    else if (complex.real() != 0 && complex.imag() != 0 && complex.imag() < 0) {
        out << complex.real() << " - " << abs(complex.imag()) << "i";
    }
    else {
        out << "0";
    }

    
    return out;
}
