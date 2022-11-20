#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
// #include <Windows.h>
using namespace std;

int main() {
    int i, j, c = 0, n, i0, i1, di, j0, j1, dj, t;
    int present[21][21] = { 0 }, future[21][21] = { 0 };
    char ch;
    unsigned rand_value = 26;
    ofstream fout("./work.dat"); 
    for (i = 1; i <= 21; i++) {
        for (j = 1; j <= 21; j++) {
            srand(time(0) + i + j + c);
            c = 65 + rand() % 25; // пишем случайный символ (A-Z)
            fout << char(c) << '\t';
        }
        if (i < 21) fout << endl;
    }
    fout.close();

    ifstream fin("./work.dat");
    fout.open("./work.out");
    if (fin.is_open()) {
        i = 0;
        j = 0;
        while ((ch = fin.get()) != EOF) {
            if (ch != '\n' && ch != '\t') {
                if (ch == 'X') present[i][j] = 1; // если это микроб, то элемент массива = 1
                else present[i][j] = 0; // если не микроб, то элемент массива = 0
                fout << present[i][j] << '\t'; 
                if (j == 20) {
                    i++;
                    j = 0;
                    if (i < 21) fout << endl;
                }
                else j++;
            }
        }
    }
    else {
        cout << "\n Нет файла work.dat! \n" << endl;
        return(1);
    }
    fin.close();
    fout.close();

    cout << "Введите количество поколений: ";
    cin >> c;
    cout << endl;

    for (int k = 2; k <= c; k++) { // повторение жизненного цикла микробов поколение за поколением начиная со 2-го (1-е уже есть)
        fout.open("./work.out");
        t = 0; // количество мертвых микробов
        for (i = 0; i < 21; i++) {
            for (j = 0; j < 21; j++) {
                n = 0; // количество соседей микроба
                switch (present[i][j]) {
                case 0:
                    future[i][j] = 1; // обновляем жизненный уровень до 1
                    break;
                case 12:
                    future[i][j] = 0; // микроб погибает
                    t++; 
                    break;
                default: // если жизненный уровень микроба от 1 до 11
                    i0 = -1; // верхний сосед микроба
                    i1 = 1; // нижний сосед микроба
                    j0 = -1; // левый  сосед микроба
                    j1 = 1; // правый сосед микроба
                    if (i == 0) i0 = 0; // проверка верхней границы колонии микробов (соседей сверху нет)
                    if (i == 20) i1 = 0; // проверка нижней границы колонии микробов (соседей снизу нет)
                    if (j == 0) j0 = 0; // проверка левой границы колонии микробов (соседей слева нет)
                    if (j == 20) j1 = 0; // проверка правой границы колонии микробов (соседей справа нет)
                    for (di = i0; di <= i1; di++) {
                        for (dj = j0; dj <= j1; dj++) {
                            if (present[i + di][j + dj] != 0 && di != 0 && dj != 0) n++; // считаем количество соседей микроба вокруг
                        }
                    }
                    if (n < 2 || n > 3) {
                        future[i][j] = 0; // микроб погибает, т.к. он задыхается или умирает от скуки
                        t++; // увеличиваем количество мертвых микробов
                    }
                    else future[i][j] = present[i][j] + 1; // если соседей 2 или 3, микроб продолжает жить и подрастает
                    break;
                }
                present[i][j] = future[i][j]; // массив «будущее» становится «настоящим»
                fout << future[i][j] << '\t'; // все последующие поколения тоже записываются в файл work.out
            }
            if (i < 21) fout << endl;
        }
        fout.close();
        if (t == 441) {
            cout << "Жалко, но колония микробов вымерла." << endl;
            break;
        }
    }
    return(0);
}