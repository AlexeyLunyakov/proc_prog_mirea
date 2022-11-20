#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
bool Automorphism(int x) {
    int sq_x = x*x;
    int d_x = x;
    string str_x = to_string(x);
    string str_sq_x = to_string(sq_x);
    if (str_sq_x.find(str_x) != std::string::npos) {
        int k = 0;
        while (d_x > 0){
            if (sq_x % 10 == d_x % 10) {
                k += 1;
            }
            else {
                return false;
            }
            sq_x /= 10;
            d_x /= 10;
            k -= 1;
        }
        if (k == 0) {
            return true;
        }
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
    cout << "Automorphic numbers from " << start << " to " << end << endl;
    for (int i = start; i <= end; i++ ) {
        if (Automorphism(i)) {
            cout << i*i << ' ' << i << endl;
        }
    }
    return 0;
}

