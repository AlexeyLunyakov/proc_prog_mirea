// 16
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std; 
int main()
{
    int n;
    double y, mn, eps;
    cout << "Enter eps: "; cin >> eps;
    mn = 1/(pow(3, 0));
    n = 0;
    y = 0; 
    cout << mn << endl;
    while(mn >= eps) {
        mn = 1/(pow(3, n));
        n += 1; 
        cout << mn << endl;
        double flag1, flag2;
        flag1 = pow(3, n - 1);
        flag2 = cos(flag1);
        y += mn*pow(flag2, 3);
    }
    cout << (y) << endl;
}





    // int n, summa = 0, kolvo = 0, count;
    // float srednee;
    // cout << " * * * Student growth analysis * * * \n";
    // vector< int > arr; 
    // string height;    
    // cout << "Enter height (cm) and press <Enter>.\n(Enter 0 to complete and press <Enter>)\n";
    // while (height != "0") {
    //     cin >> height;
    //     if (height != "0") {
    //         int chislo = 0;
    //         arr.push_back(atoi(height.c_str()));
    //         chislo  = atoi(height.c_str()); 
    //         summa += chislo;
    //         kolvo += 1; 
    //     }
    // } 
    // srednee  = (summa / kolvo);
    // cout << "Medium height: " << srednee << "\n"; 
    // for (int i = 0;  i < arr.size(); i ++ ) {
    //     if (arr[i] > srednee) {
    //         count += 1;
    //     }
    // }
    // cout << count << " people have a height above average" << endl;
    // // for(auto el: arr)
    // // cout << el << " ";