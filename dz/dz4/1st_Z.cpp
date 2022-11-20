// Задача «Файл».
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int main () {
    ofstream file("file.txt");
    string str1;
    int n;
    cout << "Enter the estimated number of items in the file: "; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++ ){
        int zn;
        cin >> zn;
        arr[i] = zn;
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        file << arr[i] << " ";
    }
    cout << endl;
    file.close();
    int summa = 0, chislo;
    string main_str = "", dop_str = "", sum_str = "";
    char probel = ' ';
    ifstream o_file("file.txt");
    getline(o_file, main_str);
    for (int i = 0; i < main_str.size(); i++ ){
        if (main_str[i] != probel) {
            dop_str += main_str[i];
        }
        else {
            chislo = stoi(dop_str);
            summa += chislo;
            chislo = 0;
            dop_str = "";
        }
    }
    cout << summa << endl;
    system("pause"); 
    return 0;
}


    // cout << "Elements of your file: " << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i]<< " ";
    // }