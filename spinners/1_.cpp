#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int a, b, c, n = 0;
    cout << "Enter values: "; cin >> a >> b >> c;
    if (a <= c) {
        // a + b*n <= c;  n <= (c - a) / b
        n = (c - a) / b;
        cout << n << endl;
    }
    else cout << "Invalid input. ";
    return 0;
}

// 20 + 10 * 3 <= 55 --> a + b*n <= c