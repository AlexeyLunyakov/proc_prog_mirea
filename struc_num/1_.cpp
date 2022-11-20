#include <iostream> // тройки по разу - исправил
#include <cstdio>
using namespace std;
bool Pythagoras(int x, int y, int z) {
    if (x*x + y*y == z*z) {
        return true;
    }
    return false;
}
int main () {
    int start = 0, end = 0;
    cout << "Enter values: "; cin >> start >> end;
    if (start > end) {
        int a = end;
        end = start;
        start = a;
    }
    cout << "Pythagorean triplets ranging from " << start << " to " << end << endl;
    for (int i = start; i <= end; i++ ) {
        for (int k = i + 1; k <= end; k++ ) {
            for (int n = k + 1; n <= end; n++ ) {
                if (Pythagoras(i, k, n)) {
                    {cout << i << ' ' << k << ' ' << n << endl;}
                }
            }
        }
    }
    return 0;
}