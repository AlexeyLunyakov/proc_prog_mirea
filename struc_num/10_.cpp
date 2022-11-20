#include <iostream> // вывести в промежутке
#include <cstdio>
#include <deque>
using namespace std;
int Jacobsthal(int x) {
    if (x == 0) { return 0; }
    if (x == 1) { return 1; }
    if (x > 1) { return Jacobsthal(x - 1) + 2*Jacobsthal(x - 2); }
}
int main () {
    int start = 0, end = 0;
    cout << "Enter values: "; cin >> start >> end;
    if (start > end) {
        int a = end;
        end = start;
        start = a;
    }
    deque <int> arr;
    for (int i = 0; i < end; i++ ) {
        int b = Jacobsthal(i);
        arr.push_back(b);
        //cout << Jacobsthal(i) << endl;
    }
    cout << "Automorphic numbers from " << start << " to " << end << endl;
    for (int numb = start; numb <= end; numb++ ) {
        for ( int i = 0; i < end; i++ ) {
            if (numb == arr[i]) {
                cout << numb << endl;
            }
        }
    }
    return 0;
}