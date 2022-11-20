#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int isPrime(int n){
    int d = 2;
    while (d * d <= n){
        if (n % d == 0)
            return 0;
        d += 1;
    }
    return 1;
}
int main()
{
    int start, end, N;
    cout << "Enter the last element of the search scope: "; cin >> N;
    for (int i = 1; i < (N + 1); i++) {
        if (isPrime(i)) {
            cout << i << "  ";
        }
    }
    system("pause");
    return 0;
}