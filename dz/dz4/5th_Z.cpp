// sin(x) graphic
#include <iostream>
#include <cstdio>
#include <cmath>
#include <Windows.h>
#include <stdlib.h>
int main()
{
    float x;
    HWND hWnd = GetConsoleWindow(); // созадем дескриптор окна Консоли window handle

    HDC hDC = GetDC(hWnd); // задаем Device context handle для рисования

    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // создаем сплошное перо, шириной 2, белого цвета RGB палитры
    SelectObject(hDC, Pen); // выбираем созданное перо

    // рисуем координатную плоскость

    MoveToEx(hDC, 0, 85, NULL);  // MoveToEx(дескриптор, координата x новой позиции, координата y новой позиции, старая текущая позиция)
    LineTo(hDC, 200, 85); // LineTo(дескриптор, начальная позиция, конечная позиция, старая текущая позиция)
    MoveToEx(hDC, 100, 0, NULL); 
    LineTo(hDC, 100, 170);

    // закончили рисовать кп

    // рисуем график с центром в точке с координатами (100, 85)
    for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - центр; 1000.f = 1000.float
    {
        MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL); // умножение на 10 и -10 позволяет задать размер
        LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85); // графика относительно кп
    }
    ReleaseDC(hWnd, hDC); // ReleaseDC освобождает контекст устройства для использования другими приложениями
    std::cin.ignore();
    return 0;
}
