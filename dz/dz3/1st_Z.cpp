// Зачтено
#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
int main()
{
    double m, S, n, p, p1, r;
    cout << "Loan - S: "; cin >> S;
    cout << "Years - n: "; cin >> n;
    cout << "Prosent - p: "; cin >> p;
    if (n > 0 && S > 0) {
            if (p == 0) {
                m = (S) / (12*n);
                cout << m << endl;
            }
            else {
                r = p / 100;
                m = ( S*r*pow((1 + r), n)) / ( 12 * (pow((1 + r), n) - 1) );
                cout << "Payout: " << m << endl;
            }
    }
    else {
        cout << "Invalid input. Try again " << endl;
    }
    system("pause");
    return 0;
}
