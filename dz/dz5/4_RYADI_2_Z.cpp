// 52 определяет определитель квадратной матрицы второго порядка
#include <iostream>
using namespace std;
double opredelitel(double a[2][2])
{
    return a[0][0]*a[1][1]-a[0][1]*a[1][0];
}
 
int main()
{
    double matrix[2][2];
    cout<<"Enter a second order matrix.\nAfter entering line items press <Enter> "<<endl;
    for(int i = 0; i < 2; i++) {   
        for(int j = 0; j < 2; j++) {
            cin >> matrix[i][j];
        }
    }
   
    cout<<"Determinant of a matrix\n";
    for(int i = 0; i < 2; i++) {   
        for(int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
            if (j == 1) {
                cout << endl;
            }
        }
    }   
    //cout << endl;
    cout << "Equal " << opredelitel(matrix) << endl;
    return 0;
}