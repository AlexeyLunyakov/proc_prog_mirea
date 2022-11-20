#include <iostream>
#include <string>
using namespace std;
void zodiac (int month, int day) {
        switch (month) {
            case 1:
                    if (day < 20)
                        cout << "Козерог"<<endl;
                    else cout << "Водолей"<<endl;
                    break;
            case 2:
                    if (day < 19)
                        cout << "Водолей"<<endl;
                    else if (day < 30 && day > 18) cout << "Рыбы"<<endl;
                    else cout << "Неправильной ввод данных \n";
                    break;
            case 3:
                    if (day < 20)
                        cout << "Рыбы"<<endl;
                    else cout << "Овен"<<endl;
                    break;
            case 4:
                    if (day < 20)
                        cout << "Овен"<<endl;
                    else if (day < 31 && day > 21)cout << "Телец"<<endl;
                    else cout << "Неправильной ввод данных \n";
                    break; 
            case 5:
                    if (day < 21)
                        cout << "Телец"<<endl;
                    else cout << "Близнецы"<<endl;
                    break;
            case 6:
                    if (day < 21)
                        cout << "Близнецы"<<endl;
                    else if (day < 31 && day > 20) cout << "Рак"<<endl;
                    else cout << "Неправильной ввод данных \n";
                    break;
            case 7: 
                    if (day < 22)
                        cout << "Рак"<<endl;
                    else cout << "Лев"<<endl;
                    break;
            case 8: 
                    if (day < 23)
                        cout << "Лев"<<endl;
                    else cout << "Дева"<<endl;
                    break;
            case 9:
                    if (day < 23)
                        cout << "Дева"<<endl;
                    else if (day < 31 && day > 22) cout << "Весы"<<endl;
                    else cout << "Неправильной ввод данных \n";
                    break;
            case 10:
                    if (day < 23)
                        cout << "Весы"<<endl;
                    else cout << "Скорпион"<<endl;
                    break;
            case 11:
                    if (day < 22)
                        cout << "Скорпион"<<endl;
                    else if (day < 31 && day > 21) cout << "Стрелец"<<endl;
                    else cout << "Неправильной ввод данных \n";
                    break;
            case 12: 
                    if (day < 21)
                        cout << "Стрелец"<<endl;
                    else cout << "Козерог"<<endl;
        }
}
int main() {
    int month, day;
    int t_month, t_day;
    cout << "Enter the month: ";  cin >> month;
    cout << "Enter the day: ";  cin >> day;
    if (month < 1 || month > 12 || day > 32 || day < 1) {
        while (month < 1 || month > 12) {
            cout << "Fail. Try again. Enter the month: "; cin >> month;
        }
        t_month = month;
        while (day < 1 || day > 31) {
            cout << "Fail. Try again. Enter the day: "; cin >> day;
        }
        t_day = day;

    }
    else {
        t_month = month;
        t_day = day;
    }
    // cout << t_day << ' ' <<  t_month << endl;
    zodiac(t_month, t_day);
}