// Задание «Уравнение». bx + c = 0 
// 
// переделал
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    float b, c, x;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
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
    system("pause");
    return 0;    
}
