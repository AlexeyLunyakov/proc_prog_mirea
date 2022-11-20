#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main()
{ 
    int n, nmin = 10000000, nmax = 0, d;

    // тестовый массив
    int N[10] = {30, 55, 21, 17, 82, 46, 79, 63, 94, 108}; 
    n = 10;
    cout << "Table 3" << endl;
    for (int i = 0; i < n; i++) {
        cout << N[i] << ' ';
    }
    cout << endl;
/*    
    Ручной ввод массива
    cout << "Enter the number of variables in the array: "; cin >> n; cout << endl;
    vector<int> N1;
    string input_line;
    for (int i = 0; i < n; i++) {   
        cin >> input_line;
        if (stoi(input_line)) {
            N1.push_back(stoi(input_line));
        }
        input_line = " ";
    } 
*/
    // первая обработка массива: нахождение масимума и минимума
    for (int i = 0; i < n; i++) {
        if (N[i] < nmin) nmin = N[i];
        if (N[i] > nmax) nmax = N[i];
    }
    // нахождение Дельты
    d = ((nmax - nmin) / n);

    cout << "\nnmax " << nmax << "\nnmin " << nmin << "\nd " << d;
    cout << "\n\n";

    // 'Разбрасывание камней' 
    vector<double> indx_arr (n); 
    vector<double> indxs_arr (n);
    for (int x = 0; x < n; x++) { // проиндексируем каждый элемент
        if (N[x] != nmax){
        indx_arr[x] = round((( N[x] - nmin) / d) + 1);
        }
        else
        indx_arr[x] = n;
    }
    
    // cout << "Table 4" << endl; // сравним результат
    // for (auto const &element: indx_arr)
    //     cout << element << ' ';
    // cout << "\n\n";

    int max_indxs = 0; // найдем максимальный индекс 
    for (int x = 0; x < n; x++) { // для дальшейшего создания 
        for (int i = 1; i < n + 1; i++) { // двумерного массива
            if ((indx_arr[x]) == i) {
                indxs_arr[i-1] += 1;
                if (indxs_arr[i-1] > max_indxs) {
                    max_indxs = indxs_arr[i-1];
                }
            }
        }
    }

    // cout << "Table 5" << endl;
    // for (auto const &element: indxs_arr)
    //     cout << element << ' ';
    // cout << "\n\n";
    // создаем двумерный вектор
    vector< vector<double> > N_new (max_indxs, vector<double> (n)); 
    for (int i = 0; i < max_indxs; i++)     
        for (int j = 0; j < n; j++) {
            N_new[i][j] = 0; // Заполнение вектора нулями
        }
    for (int x = 0; x < n; x++) { //заполняем его 
        int a = N[x];               // с учетом полученных индексов
        double indx_a;

        if (a != nmax) {
            indx_a = round((( N[x] - nmin) / d) + 1); }
        else indx_a = n;

        int j = 0;
        if ((N_new[j][indx_a - 1]) == 0)
            N_new[j][indx_a - 1] = a;
        else
            N_new[j+1][indx_a - 1] = a;
    } 
    // cout << "Table 6" << endl;
    // for (int i = 0; i < max_indxs; i++) 
    // {
    //     for (int j = 0; j < n; j++) 
    //         cout << N_new[i][j] << ' '; 
    //     cout << endl;
    // }
    // cout << "\n\n";
    
// 
    // "Сбор камней"
    vector<int> Sort_N;
    for (int i = 1; i < n + 1; i ++) {
        if (indxs_arr[i-1] == 0) {
            continue;
        }
        else if (indxs_arr[i-1] == 1)
            Sort_N.push_back(N_new[0][i - 1]);
        else if (indxs_arr[i - 1] == 2) {
            int j = 0;
            if (N_new[j][i - 1] <  N_new[j+1][i - 1]){    
                Sort_N.push_back(N_new[j][i - 1]);
                Sort_N.push_back(N_new[j + 1][i - 1]);
            }
            else {
                Sort_N.push_back(N_new[j + 1][i - 1]);
                Sort_N.push_back(N_new[j][i - 1]);
            }
        }
    }
    cout << "Table 7" << endl; // выводим отсортированный массив
    for (auto const &element: Sort_N)
        cout << element << ' ';
    cout << "\n\n";
  
    return 0;
}

//    double indx_arr[n];
//    double indxs_arr[n];
    // for (auto const &element: N1)
    //     cout << element << ' ';
    // cout << endl;