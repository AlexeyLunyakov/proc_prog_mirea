#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n, nmin = 10000000, nmax = 0, d;
    cout << "Enter the number of variables in the array: "; cin >> n; //cout << endl;
    int N[n] = {0};
    string input_line;
    for (int i = 0; i < n; i++) {   
        cin >> input_line;
        if (stoi(input_line)) {
            N[i] = (stoi(input_line));
        }
        input_line = " ";
    } 
    //int N[10] = {30, 55, 21, 21, 82, 46, 79, 63, 94, 108};  // Тестовый массив

    for (int i = 0; i < n; i++) {
        if (N[i] < nmin) nmin = N[i];
        if (N[i] > nmax) nmax = N[i];
    }
    int value[nmax + 1] = {0};
    int final[n] =  {0};
    for (int i = 0; i < n; i++ ) value[N[i]] += 1; 
    cout << endl;
    for (int i = 1; i < nmax + 1; i++) {
        if (value[i] > 0) {
            for (int x = 0; x < value[i]; x++) {
                for (int k = 0; k < n; k++) {
                    if (final[k] == 0) {
                        final[k] = i;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (final[i] != 0)  cout << final[i] << ' '; // 
    }
    cout << endl;
}

    //for (int i = 0; i < n; i++ )  cout << N[i] << ' '; 
    //cout << endl;
    //for (int i = 0; i < n; i++ )  cout << N[i] << ' '; 
    //for (int i = 1; i < nmax + 1; i++ ) cout << value[i] << ' '; 
    //cout << nmin << ' ' << nmax << endl << endl; 
            //cout << i << ' ' << value[i];
