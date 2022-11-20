#include <iostream>
#include <cstdio>
using namespace std;
int Fibonacci(int x) {
    if (x == 1 || x == 2) 
        return 1;
    if (x >= 3) {
        return Fibonacci(x - 1) + Fibonacci(x - 2);
    }
}
int main () {
    int start = 0;
    cout << "Enter value: "; cin >> start;
    cout << start << "-th Fibonacci number: ";
    cout << Fibonacci(start) <<  endl;
    return 0;
}