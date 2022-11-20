// Задача «Геометрические фигуры».
#include <iostream>
#include <cstdio>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
double S_rectangle(float a, float b) {
    float S;
    S = a*b;
    return S;
}
double S_triangle(float a, float h) {
    float S;
    S = 0.5*a*h;
    return S;
}
double S_circle(float R) {
    float S;
    S = M_PI*R;
    return S;
}
double CN (float x) { //CN - CorrectNumber
    if (x > 0) {
        return 1;
    }
    else return 0;
}
int main() {
    float S, a, b, h, R;
    char answ = ' ';
    cout << "Choose which shape you would like to use (triangle - t, circle - c, rectangle - r ): "; cin >> answ; cout << endl;
    cout << "Enter the values: " << endl;
    if (answ == 't') {
            cout << "a: "; cin >> a;
            cout << "h: "; cin >> h;
            if (CN(a) && CN(h)) {
                cout << "Area of a triangle: " << S_triangle(a, h) << endl;
            }
            else cout << "Invalid input. " << endl;
    }
    if (answ == 'c') {
            cout << "R: "; cin >> R;
            if (CN(R)) {
                cout << "Area of a circle: " << S_circle(R) << endl;
            }
            else cout << "Invalid input. " << endl;
    }
    if (answ == 'r') {
            cout << "a: "; cin >> a;
            cout << "b: "; cin >> b;
            if (CN(a) && CN(b)) {
                cout << "Area of a rectangle: " << S_rectangle(a, b) << endl;
            }
            else cout << "Invalid input. " << endl;
    }
    answ = ' ';
    system("pause");    
    return 0;
}


    // if (S < 0 && a < 0 && b < 0) {
    //     cout << "Area of a rectangle: " << S_rectangle(a, b) << endl;
    // }
    // else if (S < 0 && a < 0 && h < 0) {
    //     cout << "Area of a triangle: " << S_triangle(a, h) << endl;
    // }
    // else if (S < 0 && R < 0) {
    //     cout << "Area of a circle: " << fixed << setprecision(5) << S_circle(R) << endl;
    // }
    // else cout << "Invalid input. Try again. " <<  endl;