// Задача «Конус». V = 1/3*pi*h(R^2+R*r+r^2) S = pi*(R^2+(R+r)*l+r^2) при отрицательных числах выводить ошибку
#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
int main()
{

    float l, h, R, r, Vu, Su, Vp, Sp;
    cout << "h: "; cin >> h;
    cout << "R: "; cin >> R;
    cout << "r: "; cin >> r;
    if (r == 0) {
        cout << "You have entered data for a full cone. Continue? (y/n): ";
        string cont;
        cin >> cont;
        if (cont == "y") {
            cout << "l: "; cin >> l;
            Vp = M_PI * R * R * h;
            Sp = M_PI * (R*R + R*l);
            cout << "The truncated Cone volume:" << Vp << endl;
            cout << "Full surface of the cone: " << Sp << endl;
        }
        else if (cont == "n") {
            cout << "r: "; cin >> r;
            cout << "l: "; cin >> l;
            Vu =  (M_PI * h * (R*R + R*r + r*r)) / 3;
            Su = M_PI * (R*R + (R+r)*l + r*r);
            cout << "Cone volume:" << Vu << endl;
            cout << "Full surface of the truncated cone: " << Su << endl;
        }
    }
    else {  
        Vu =  (M_PI * h * (R*R + R*r + r*r)) / 3;
        Su = M_PI * (R*R + (R+r)*l + r*r);
        cout << "Cone volume:" << Vu << endl;
        cout << "Full surface of the truncated cone: " << Su << endl;
    }
    system("pause");
    return 0;
}
