// Зачтено
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int NOD(int A, int B )
{
    if( A == 0 ) return B;
    return NOD( B % A, A );
}
 
int main(){
    int A, B;
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;
    cout << "NOD ( " << A << ", " << B << " ) = " << NOD(A, B) << endl;
    system("pause");
}