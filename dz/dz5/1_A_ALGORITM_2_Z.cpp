// Зачтено
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int NOD(int A, int B) {
    while (A != 0 && B != 0) {
        if (A > B) A %= B; 
        else B %= A; }
    return A + B;
}
int main () {
    int A, B;
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;
    cout << "NOD ( " << A << ", " << B << " ) = " << NOD(A, B) << endl;
    system("pause");
}