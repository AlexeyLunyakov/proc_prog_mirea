#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int N, M;
    cout << "Enter N: "; cin >> N;
    cout << "Enter M: ";cin >> M;
    // Пусть координаты первой клетки найденного прямоугольника имеет координаты x1, y1, а крайняя клетка — координаты x2, y2. 
    // Т.о. нужно найти пары чисел x1, x2 и y1, y2 которые будут принадлежать промежутку (1, N) и (1, M) соответственно
    int x_axis = 0 , y_axis = 0;
    for (int x1 = 0; x1 < N; x1++) {
        for (int x2 = x1; x2 < N; x2++) {
            x_axis += 1;
        }
    }
    for (int y1 = 0; y1 < M; y1++) {
        for (int y2 = y1; y2 < M; y2++) {
            y_axis += 1;
        }
    }
    int result = (x_axis*y_axis);
    cout << "Result " << result << endl;
    return 0;
}
