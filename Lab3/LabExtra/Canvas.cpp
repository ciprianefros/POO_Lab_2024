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
    if (x >= 0 && x < coloane && y >= 0 && y < linii)
        canvas[y][x] = value;
}

void Canvas::set_pixels(int count, ...)
{
    va_list ap;
    int i;

    va_start(ap, count);
    for (i = 0; i < count; i++) {
        int x = va_arg(ap, int);
        int y = va_arg(ap, int);
        char ch = va_arg(ap, char);

        if (x >= 0 && x < coloane && y >= 0 && y < linii)
            canvas[y][x] = ch;
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
