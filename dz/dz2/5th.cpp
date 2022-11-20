// Задача «Табуляция». y = (x*x - 2*x + 2) / (x - 1) переделать 
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
/*     for (x; x <= xk; x += 0.5) {
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
    // while (x <= xk) {
    //     if ((x - 1) == 0) {
    //         cout << "No solution for 0 " << endl; 
    //     }
    //     else {
    //         y = (x*x - 2*x + 2) / (x - 1);
    //         cout << "Solution for " << x << ": " << y << endl;
    //     }
    //     x += 0.5;
    // }