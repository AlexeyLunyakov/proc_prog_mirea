#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n, seat;
    int coupe_seats[9];
    cout << "Enter N: "; cin >> n;
    if (n < 0) {
        cout << "\nInvalid input. \n" << endl;
        return 0;
    }
    for (int i = 0; i < 9; i++){
        coupe_seats[i] = 0;
    }
    cout << "Enter numbers of free seat: ";

    for (int i = 0; i < n; i++){
        cin >> seat;
        if (seat <= 36 && seat > 0){
            //если номер места находится в верхней секции схемы, то находим номер купе по формуле [(seat - 1) / 4]
            coupe_seats[(seat - 1)/4] += 1;
        }
        else if (seat >= 37 && seat <= 54){
            //для нижней секции схемы находим номер купе по формуле [8 - (seat - 37) / 2]
            coupe_seats[8 - (seat - 37)/2]++;
        }
        else {
            cout << "\nInvalid input. \n" << endl;
            return 0;
        }
    }

    int count, max_ = 0;
    for (int i = 0; i < 9; i++){
        if (coupe_seats[i] == 6){
            count++;
            max_ = max(max_, count);
        }
        else{
            count = 0;
        }
    }
    cout << "\n" << max_ << endl;
    return 0;
}
