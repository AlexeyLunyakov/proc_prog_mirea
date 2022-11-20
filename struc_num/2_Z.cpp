#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int main () {
    int start = 0, end = 0;
    cout << "Enter values: "; cin >> start >> end;
    if (start > end) {
        int a = end;
        end = start;
        start = a;
    }
    cout << "Perfect numbers from " << start << " to " << end << endl;
    for (int numb = start; numb <= end; numb++ ) {
        int sum_divider = 0;
        deque<int> dividers;
        if (numb < 1000) {
            for (int i = 1; i < numb; i++) {
                if (numb % i == 0) {
                    sum_divider += i;
                    dividers.push_back(i);
                }
            }
        }
        else {
            sum_divider += 1;
            for (int i = 2; i*i <= numb; i++) {
                if (numb % i == 0) {
                    sum_divider += i;
                    if ((numb / i) != numb) {
                        sum_divider += (numb / i);
                    }
                    dividers.push_back(i);
                }
            }
        }

        if (sum_divider == numb) { 
            cout << numb << ' ';
        }
        
    }
    return 0;
}




// понятный вывод
            //cout << "\n" << numb << endl;
            // cout << "( ";
            // for (int n = 0; n < dividers.size(); n++) {
            //     cout << dividers[n] << ' ';
            // }
            // cout << ")\n";