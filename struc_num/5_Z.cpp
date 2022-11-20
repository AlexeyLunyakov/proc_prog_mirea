#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
double Armstrong(int x) {
    string str_x = to_string(x);
    double c_sum = 0;
    for (int i = 0; i < str_x.size(); i++ ){
        int x_i = (int(str_x[i]) - 48);
        double f_sum = pow(x_i, str_x.size());
        c_sum += f_sum;
    }
    if (x == c_sum) {
        return 1;
    }
    else { 
        return 0;
    }
}
int main () {
    int digit;
    cout << "Enter digit: "; cin >> digit;
    cout << "All " << digit << "-digit Armstrong numbers: \n";
    double start = pow(10, (digit - 1));
    double end = pow(10, digit);
    for (int x = start ; x < end; x++){
        if (int(Armstrong(x)) == 1) {
            cout << x << endl;
        }
    }
    return 0;
}