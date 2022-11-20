// Задача «Порядок». в обычном варианте при отрицательных  ошибка
// очно (классичекая +  усложненная)
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
