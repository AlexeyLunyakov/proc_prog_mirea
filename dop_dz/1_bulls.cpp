#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <vector>
#include <ctime>
using namespace std;
int conceived[4], introduced[4], extra[4] = {-1}, dop, dop2;
string input_num;
void human_num(int input_num) {
    int del = 10;
    for(int i = 3; i > -1; i--) { 
        introduced[i] = input_num % 10;
        input_num /= 10;
    }
}
int testing_comp(int dop, int extra[4]) {
    for (int i = 0; i < 4; i++) {
        if (dop == extra[i])
            return 0;
    }
    return 1;
}
void comp_num() {
    srand(time(NULL));
    conceived[0] = rand() % 9 + 1;
    for (int x = 0; x <= 3; x++) {
        dop = rand() % 10;
        while (testing_comp(dop, extra) == 0) {
            dop = rand() % 10;
        }
        conceived[x] = dop;
        extra[x] = dop; 
    }
}
int bulls() {
    int bull = 0;
    for (int x = 0; x < 4; x++)
        if (conceived[x] == introduced[x])
            bull++;
    return bull;
}
int cows() {
    int cow = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (conceived[i] == introduced[j] && i != j)
                cow++;
    return cow;
}
void Analysis() {
    comp_num();
    int k = 0, count = 0;
    bool flag = 0;
    for (int x = 0; x < 4; x++) {
        cout << conceived[x];
        count += 1;
    } cout << endl;
    cout << "Ваш номер | Быки  | Коровы\n" << "----------------------\n";
    while (bulls() != 4) {
        cout << "Ваше число: \n";
        cin >> input_num;
        if (input_num.size() != 4) {
            cout << "Прочитайте правила !!! А потом сыграйте снова. \n";
            break;
        }
        for (int i = 0; i < input_num.size(); i++ ) {
            for (int j = i + 1; j < input_num.size(); j++) {
                if (int(input_num[i]) == int(input_num[j])) {
                    flag = 1;
                }
                else if (isalpha(input_num[i])) flag = 1;
            }
        }
        if (flag == 1) {
            cout << "Прочитайте правила !!! А потом сыграйте снова. \n";
            break;
        }
        int b = atoi(input_num.c_str());
        //cout << b;
        human_num(b);
        k += 1;
        cout << endl;
        if (k % 2 == 0) cout << "Ваш номер | Быки  | Коровы\n" << "----------------------\n";
        cout << "\t  |   " << bulls() << "   |   " << cows() << "\n"; // ' ' << count <<
        if (bulls() == 4) {
            cout << "Число угадано! \n";
            break;    
        }
    }
}
int main() {
    char flag = 'Y';
    cout << "Если фигура совпадает, но стоит в другом месте, это Корова; если он стоит на нужном месте, это Бык.\n\n Вводить можно только строку из четырех положительных чисел меньших десяти\n\n";
    while (flag == 'Y' || flag == 'y') {
        Analysis();
        cout << "Сыграть ещё раз? (Y/N)\n"; cin >> flag;
        // if (flag == 'n' || flag == 'N')  break;
    }
}