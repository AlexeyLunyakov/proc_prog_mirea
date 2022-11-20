// Задача «Системы счисления».
#include <iostream>
#include <string>
#include <cmath>
#include <deque>
using namespace std;

int main(){
    //исходная -> 10-ая -> необходимая 
    string number; int ons, rns;

    cout << "Enter the base of the original number system (ns) > "; cin >> ons; // ввод основания исходной сс
    cout << "Enter the number in the original ns > "; cin >> number; // ввод числа в исходной сс
    cout << "Enter the base of the required ns > "; cin >> rns; // ввод основания необходимой сс

    // в 10-ую
    int ns_10_num = 0;

    for (int i = 0; i < number.size(); i++) {
        if (int(number[i]) >= 65 && int(number[i]) <= 90) { // если буквы 
            if (10 + int(number[i]) - 65 >= ons) { // проверека на несовместимость систем для букв
                cout << "Invalid input. " << endl;
                return -1;
            }
            ns_10_num += (10 + int(number[i]) - 65) * pow(ons, number.size() - i - 1);
        } 
        else if (int(number[i]) >= 48 && int(number[i]) <= 57) { // если цифры
            if (int(number[i]) - 48 >= ons) { 
                cout << "Invalid input. " << endl;
                return -1;                
            }
            ns_10_num += (int(number[i]) - 48) * pow(ons, number.size() - i - 1);
        }
        else{
            cout << "Invalid input. " << endl;
            return -1;
        }
    }
    // в необходимую
    deque<int> arr; // double-ended queue - структура, в которой можно добавлять элементы в начало и конец
    
    while (ns_10_num > 0) {
        arr.push_front(ns_10_num % rns);
        ns_10_num = ns_10_num / rns;

    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 10) {
            cout << "A";
        }
        else if (arr[i] == 11) {
            cout << "B";
        }
        else if (arr[i] == 12) {
            cout << "C";
        }
        else if (arr[i] == 13) {
            cout << "D";
        }
        else if (arr[i] == 14) {
            cout << "E";
        }
        else if (arr[i] == 15) {
            cout << "F";
        }
        else cout << arr[i];
    }
    cout << endl;
    return 0;
}