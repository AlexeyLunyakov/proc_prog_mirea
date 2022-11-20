#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int m; 
    cout << "Enter value: "; cin >> m;
    //количество спиннеров с 4 лопастями (если число делится на 3 бех остатка, то спинеров с четырьмя лопастями не будет)
    int n4 = m % 3;
    //количество спиннеров с 3 лопастями из оставшихся лопастей
    int n3 = (m - 4 * n4) / 3;
    //если n3 получается отрицательным, значит, нельзя сделать ни один спиннер
    if (n3 >= 0) {
        cout << "Number of spinners with three blades " << n3 << endl;
        cout << "Number of spinners with four blades " << n4 << endl;
    }
    else {
        cout << 0 << "\n" << 0 << endl;
    }
    return 0;
}

