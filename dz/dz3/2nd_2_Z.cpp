#include <iostream> 
#include <cmath> 
#include <iomanip> 
#include <stdlib.h> 
using namespace std; 
int main(){ 
    setlocale(0, ""); 
    float s, p, n, r, m, k, answ, prom; 
    cout << "Loan - S: "; cin >> s;
    cout << "Years - n: "; cin >> n;
    cout << "Payout - m: "; cin >> m;
    p = -100; 
    prom = m; 
    if ((s > 0) && (n > 0) && (s > m) && (m > 0)){ 
        for (p = -100; p <= 100; p += 0.01){ 
            r = p / 100; 
            if (r == 0){ 
                k = s/12; 
            } 
            else { 
                k = (s * r * pow( (1 + r) , n )) / (12 * (pow( (1 + r) , n ) - 1 )); 
            } 
            if (abs(m - k) < prom){ 
                answ = round(r*100)/100 * 100; 
                prom = abs(m - k); 
            } 
    } 
    cout << fixed << setprecision(2)  << "Prosent_b: " << answ << "%" << endl; 
    } 
    else 
    cout << "Invalid input. \n"; 
}