// Задача ««Умножение матриц».
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int main(){
    //иницализируем матрицы a и b

    float a[3][4] = { // матрица A
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0},
    };
    
    float b[4][2] = { // матрица B
        {1.20, 0.5},
        {2.8, 0.4},
        {5, 1},
        {2, 1.5},
    };
    //нулевая матрица "С" 2 на 3
    float c[3][2] = {0};

    //перемножаем матрицы
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                c[i][j] += ( a[i][k] * b[k][j] );
            }
        }
    }
    //итоговая матрица
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
        cout << endl;
    }
    //итог
    cout << "The second earned the most: " << max( max( (c[0][0] - c[0][1]), (c[1][0] - c[1][1]) ), (c[2][0] - c[2][1]) ) << endl;

    cout << "The first earned the least: " << min(min( (c[0][0] - c[0][1]), (c[1][0] - c[1][1]) ), (c[2][0] - c[2][1]) ) << endl;

    cout << "The first earned the maximum commission: " << max(max( c[0][1], c[1][1] ), c[2][1] )  << endl;

    cout << "Minimum commission earned by the third: " << min(min( c[0][1], c[1][1] ), c[2][1] )  << endl;

    cout << "The total amount of money received for the goods sold: " << ( c[0][0] - c[0][1] ) + ( c[1][0] - c[1][1] ) + ( c[2][0] - c[2][1] )  << endl;

    cout << "Total commissions earned: " << c[0][1] + c[1][1] + c[2][1]  << endl;

    cout << "Total amount of money passed through sellers: " << c[0][0] + c[1][0] + c[2][0]  << endl;
    return 0;
}