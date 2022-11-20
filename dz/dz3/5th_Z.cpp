// Задача
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int Num; 
    cout << "Enter the number of characters to sort: "; cin >> Num;
    char symbols[Num];
    char new_symbols[Num];

    for (int i = 0; i < Num; i++){
        cin >> symbols[i];
        if (int(symbols[i]) >= 97 && int(symbols[i]) <= 122) { new_symbols[i] = char(int(symbols[i]) - 32); }
        else { new_symbols[i] = symbols[i]; }
    }

    for (int i = 0; i < Num; i++) {
        for (int j = 0; j < Num - 1; j++) {
            if ( int(new_symbols[j]) > int(new_symbols[j + 1]) ) {
                swap( new_symbols[j], new_symbols[j + 1] );
                swap( symbols[j], symbols[j + 1] );
            }
        }
    }

    cout << "Final order of entered characters: ";
    for (int i = 0; i < Num; i++ ){
        cout << symbols[i] << " ";
    }
    cout << "\r\n";
    system("pause");
    return 0;
}





    // int N;  
    // cout << "Enter the number of characters to sort: "; cin >> N;
    // char symbols[N];
    // char new_symbols[N];
    // char new_Symbols[N];
    // for (int i = 0; i < N; i++) {
    //     cin >> symbols[i];
    //     if (int(symbols[i]) >= 97 && int(symbols[i]) <= 122) {
    //         new_symbols[int(symbols[i]) - 96] = symbols[i];
    //     }
    //     else if (int(symbols[i]) >= 65 && int(symbols[i]) <= 90) {
    //         new_Symbols[int(symbols[i]) - 64] = symbols[i];
    //     } 
    // }
    // for (int i = 0; i < N; i++){
    //     cout << "Your shit " << endl;
    //     cout << new_symbols[i] << endl;
    //     cout << new_Symbols[i] << endl;
    // }