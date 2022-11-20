// Задача «Разветвление». Помнить про область определения
// очно (классичекая +  усложненная)                        переделать
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