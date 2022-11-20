// Задание «Арифметика».
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    float first, second;
    float summa, raznost, proizv, chastnoe;
    cout << "first: "; cin >> first;
    cout << "second: "; cin >> second;
    while (second == 0) {
        cout << "The second number is 0, please try again " << endl;  // просим вводить числа, 
        cin >> first >> second;                                      // пока второе не перестанет быть нулем.
    }
    summa = first + second;
    proizv = first*second;
    if (first > second) {
        raznost = first - second;}
    else {
        raznost = second - first;}
    if (second != 0)   {                          
        chastnoe = first/second;}         
    cout << "summa: " << summa << endl;
    cout << "raznost: " << raznost << endl;
    cout << "proizvedenie: " << proizv << endl;
    cout << "chastnoe: " << chastnoe << endl;
    system("pause");
    return 0;
}