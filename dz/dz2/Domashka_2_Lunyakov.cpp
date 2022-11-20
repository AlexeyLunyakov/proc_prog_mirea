// 1
// Задача «Конус»
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
// 2
// Задача «Разветвление».
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
int main()
{
    float w, a, x, safe_x;
    cout << "a: "; cin >> a;
    cout << "x: "; cin >> x;
    if (x != 0) {
        if (x < 0) {
            safe_x = x;
            x = -x;
        }
        if (x < 1) {
            w = a * log(x);
            cout << "Solution: " << w << endl;
        }
        else {
            if ( (a - x*x)  < 0 ) {
                cout << "No solutions. " << endl;
            }
            else {
                w = sqrt(a - x*x);
                cout << "Solution: " << w << endl;
            }
        }
    }
    else {
        cout << "No solutions. " << endl;
    }
    system("pause");
    return 0;
}
// 3 
// Задача «Функция».
#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
int main()
{
    float z, b, x, y;
    cout << "b: "; cin >> b;
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;
    if ( ((b - y) <= 0) || ((b - x) < 0) ) {
        cout << "No solutions for Z.  " << endl;
    }
    else {
        z = ( log(b - y) )  *  ( sqrt(b - x) );
        cout << "Solution: " << z << endl;
    }
    system("pause");
    return 0;
}
// 4
// Задача «Порядок».
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
int main()
{
    int N0, N;
    cout << "N: "; cin >> N;
    if (N > 0) {
        N0 = N;
        for (N; N < N0 + 10;  N ++) {
            cout << N << endl;
        }
    }
    else {
        while (N < 0) {
            cout << "Invalid input. " << endl;
            cout << "N: "; cin >> N;
        }
        N0 = N;
        for (N; N < N0 + 10;  N ++) {
            cout << N << endl;
        }
    }
    system("pause");
    return 0;
}
// 5
// Задача «Табуляция».
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    float y;
    float x, xk;
    const char nl1[] = " ";    
    const char nl2[] = "  ";
    const char nl3[] = "   ";
    const char nl4[] = "    ";
    x = -4;
    xk = 4;
/*     for (x; x <= xk; x += 0.5) { // простое решение
        if ((x - 1) == 0) {
            cout << "No solution " << endl; 
        }
        else {
            y = (x*x - 2*x + 2) / (x - 1);
            cout << "Solution: " << y << endl;
        }

    } */
    cout << "------------------" << endl;
    while (x <= xk) {
        if ((x - 1) == 0) {
            cout << "|   0   |   NO   |" << endl; 
            cout << "------------------" << endl;            
        }
        else {
            y = (x*x - 2*x + 2) / (x - 1);
            if (x == int(x) && x < 0) {
                cout << "| " << round(x*10)/10 << nl3 << " |  " << round(y*10)/10 << "  |" << endl;
                cout << "------------------" << endl;            
            }
            else if (x == int(x) && x > 0) {
                if (y == int(y)) {
                    cout << "|  " << round(x*10)/10 << nl4 << "|  " << round(y*10)/10 << "     |" << endl;
                    cout << "------------------" << endl;            
                }
                else {
                    cout << "|  " << round(x*10)/10 << nl4 << "|  " << round(y*10)/10 << "   |" << endl;
                    cout << "------------------" << endl;            
                }
            }
            else if (x != int(x) && x < 0)  {
                cout << "| " << round(x*10)/10 << nl1 << " |  " << round(y*10)/10 << "  |" << endl;
                cout << "------------------" << endl;            
            }
            else if (x != int(x) && x > 0)  {
                cout << "|  " << round(x*10)/10 << nl2 << "|  " << round(y*10)/10 << "   |" << endl;
                cout << "------------------" << endl;            
            }
            //cout << "|" << round(x*10)/10 << "|" << round(y*10)/10 << "|" << endl; //prob*" " <<
        }
        x += 0.5;
    }
    system("pause");
    return 0;
}