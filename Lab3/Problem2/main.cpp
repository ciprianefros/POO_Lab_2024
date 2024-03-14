#include "Canvas.h"

int main()
{
    Canvas canvas(30, 30);
    canvas.DrawCircle(15, 10, 3, '*');
    canvas.FillCircle(15, 5, 2, '3');
    canvas.DrawRect(5, 2, 15, 8, '+');
    canvas.FillRect(1, 1, 18, 9, '-');
    canvas.DrawLine(3, 2, 17, 8, '|');
    canvas.Print();
    canvas.Clear();
    canvas.DrawRect(1, 1, 29, 19, '&');
    canvas.SetPoint(12, 12, 'h');
    canvas.SetPoint(13, 13, 'e');
    canvas.SetPoint(14, 14, 'l');
    canvas.SetPoint(15, 15, 'l');
    canvas.SetPoint(16, 16, '0');
    canvas.Print();
    return 0;
}