#include "Math.h"

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return  a + b ;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    int val = 0;
    va_list ap;
    int i;

    va_start(ap, count);
    for (i = 0; i < count; i++) {
        val += va_arg(ap, int);
    }
    va_end(ap);

    return val;
}

char* Math::Add(const char* a, const char* b)
{
    if (a == nullptr || b == nullptr)
    {
        return nullptr;
    }

    size_t length1 = strlen(a);
    size_t length2 = strlen(b);

    char* rezultat = (char*)malloc(length1 + length2 + 1);
    if (rezultat == nullptr) {
        return nullptr;
    }

    strcpy_s(rezultat, sizeof(a), a);
    strcat_s(rezultat, length1+length2+1, b);

    return rezultat;

}
