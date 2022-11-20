#include <iostream> // 1 искл - исправил
#include <cstdio>
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
int main () {
    int start = 0, end = 0;
    cout << "Enter values: "; cin >> start >> end;
    if (start > end) {
        int a = end;
        end = start;
        start = a;
    }
    cout << "Sophie Germain's numbers from " << start << " to " << end << endl;
    if (start == 1) {
        start += 1;
    }
    for (int numb = start; numb <= end; numb++ ) {
        if (isPrime(numb) && isPrime(2*numb + 1)) {
            cout << numb << ' ' << 2*numb + 1 << endl;
        } 
    }
}
