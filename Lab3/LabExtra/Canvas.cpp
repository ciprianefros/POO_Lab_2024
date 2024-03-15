#include "Canvas.h"
#include <iostream>
#include <stdlib.h>
#include <stdarg.h>

Canvas::Canvas(int lines, int columns) : linii(lines), coloane(columns)
{
    canvas = new char* [lines];
    for (int i = 0; i < lines; ++i)
    {
        canvas[i] = new char[columns];
        for (int j = 0; j < columns; ++j)
        {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::set_pixel(int x, int y, char value)
{
    if (x >= 0 && x < linii && y >= 0 && y < coloane)
        canvas[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
    va_list ap;
    int i;
    int x;
    int y;
    char ch;

    va_start(ap, count);
    for (i = 0; i < count; i++) {
        x = va_arg(ap, int);
        y = va_arg(ap, int);
        ch = va_arg(ap, char);

        set_pixel(x, y, ch);
    }
    va_end(ap);

}

void Canvas::clear()
{
    for (int i = 0; i < linii; ++i)
    {
        for (int j = 0; j < coloane; ++j)
        {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::print() const
{
    for (int i = 0; i < linii; ++i)
    {
        for (int j = 0; j < coloane; ++j)
        {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}
