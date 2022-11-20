// Задание «Еще уравнение». ax2 + bx + c = 0. 
// 
// переделал
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c, x, x1, x2, discr;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
            cout << "The equation has infinitely many solutions. " << endl;            
            }
            else {
                cout << "No solutions. " << endl;
            }
        }
        else {
            if (c == 0) {
                cout << "The equation has infinitely many solutions. " << endl; 
            }
            else {
                x = (-c)/b;
                cout << "Solution: " << x << endl;
            }
        }
    }
    else {
        discr = b*b - 4*a*c;
        if (discr == 0) {
            x = (-b) / (2*a);
            cout << "Solution: " << x << endl;
        }
        else if (discr > 0) {
            x1 = ((-b) + sqrt(discr)) / (2*a);
            x2 = ((-b) - sqrt(discr)) / (2*a);
            cout << "Solutions: " << "x1: " << x1;  cout << ", x2: " << x2 << endl;
        }
        else {
            cout << "No solutions. "<< endl;
        } 
    }
    system("pause");
    return 0;
}
