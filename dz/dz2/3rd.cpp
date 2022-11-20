// Задача «Разветвление».
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