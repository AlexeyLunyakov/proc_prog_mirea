// Задача ««Знак числа».
#include <iostream>
#include <cstdio>
using namespace std;
int Sign(int n){
        if (n > 0) return 1;
        else if (n < 0) return -1;
        else if (n == 0) return 0;
}

int main() {
    float x;
    cout << "Enter your number: "; cin >> x;
    cout << "Your number sign: " << Sign(x) << endl;
    system("pause");    
    return 0;
}