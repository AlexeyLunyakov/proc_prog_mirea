#include <iostream> // доработать - сделал
#include <cstdio>
#include <deque>
#include <math.h>
using namespace std;
long long factorial(int i)
{
    if (i==0) return 1;
    else return i*factorial(i-1);
}
double Catalan(int n){
    double Number, a, b; 
    a = factorial(2*n);
    b = (factorial(n+1)*factorial(n));
    Number = a / b;
    return Number;
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
        int b = Catalan(i);
        arr.push_back(b);
        //cout << Catalan(i) << endl;
    }
    cout << "Catalan numbers from " << start << " to " << end << endl;
    for (int numb = start; numb <= end; numb++ ) {
        for ( int i = 0; i < end; i++ ) {
            if (numb == arr[i]) {
                cout << numb << endl;
            }
        }
    }
}
