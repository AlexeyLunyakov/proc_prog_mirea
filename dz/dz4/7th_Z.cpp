// Задача ««Генератор псевдослучайных чисел».
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
using namespace std; 
int main(){  
    int m, i, c;
    string answ;
    cout << "Enter which numbers - large or small - you want to get (L/S)\n";  cin >> answ;
    if (answ == "L") {
        m = 25173;
        i = 13849;
        c = 65537;
    }
    else if (answ == "S") {
        m = 37;
        i = 3;
        c = 64;
    }
    int s0;
    srand(time(0));
    s0 = rand(); 
    cout << "s0 = " << s0 << endl; 
    int sn = (m * s0 + i) % c; 
    cout << "s1 = " << sn << endl; 
    //cout << i << " " << m * s0 << " " << (m * s0 + i) % c << endl; 
    int n = 1; 
    while (n < 10){ 
        sn = (m * sn + i) % c; 
        n++; cout << "s" << n << " = " << sn << endl; 
    } 
    return 0; 
}