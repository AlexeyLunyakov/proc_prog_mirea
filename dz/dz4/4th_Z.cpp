// Задача ««Былая слава».
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    for(int i = 0 ; i < 8 ; i++) {
        if(i < 7) {
            if(i % 2 == 0){
                for(int j = 0; j < 6; j++) {
                        cout << " * ";
                }
                cout.width(10);
            cout<< setw(54) << setfill('-')  ;
            }
            else {
                cout << " ";
                for(int j = 0; j < 6; j++) {
                    cout << " * ";
                }
            }
            cout << '\n';
        }
    }
    for(int i = 0; i < 18; i++) {
        if(i % 2 == 0)  cout << setw(72) << setfill(' ') << '\n';
        else            cout << setw(72) << setfill('-') << '\n';
    }
    system("pause");    
    return 0;
}