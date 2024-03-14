#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : latime(width), inaltime(height)
{
    canvas = new char* [height];
    for (int i = 0; i < height; ++i)
    {
        canvas[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            canvas[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; ++i)
    {
        for (int j = y - ray; j <= y + ray; ++j)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
            {
                if (i >= 0 && i < latime && j >= 0 && j < inaltime)
                    canvas[j][i] = ch;
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; ++i)
    {
        for (int j = y - ray; j <= y + ray; ++j)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
            {
                if (i >= 0 && i < latime && j >= 0 && j < inaltime)
                    canvas[j][i] = ch;
            }
        }
    }

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i <= right; ++i)
    {
        for (int j = top; j <= bottom; ++j)
        {
            if ((i == left || i == right) || (j == top || j == bottom))
            {
                if (i >= 0 && i < latime && j >= 0 && j < inaltime)
                    canvas[j][i] = ch;
            }
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i <= right; ++i)
    {
        for (int j = top; j <= bottom; ++j)
        {
            if (i >= 0 && i < latime && j >= 0 && j < inaltime)
                canvas[j][i] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < latime && y >= 0 && y < inaltime)
        canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int error = dx - dy;

    while (true)
    {
        if (x1 >= 0 && x1 < latime && y1 >= 0 && y1 < inaltime)
            canvas[y1][x1] = ch;

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * error;
        if (e2 > -dy)
        {
            error -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            error += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < inaltime; ++i)
    {
        for (int j = 0; j < latime; ++j)
        {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < inaltime; ++i)
    {
        for (int j = 0; j < latime; ++j)
        {
            canvas[i][j] = ' ';
        }
    }
}
