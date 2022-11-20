#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
using namespace std;

void Tower(int N, int first, int second, int third) {
    if (N == 0) return;
    if (N == 1) cout << first << " --> " << third << endl;
    else {
        Tower(N - 1, first, third, second); //{перенос N-1 дисков на промежуточный стержень}
        Tower(1, first, second, third); //{перенос 1 диска на конечный стержень}
        Tower(N - 1, second, first, third); //{перенос N-1 дисков с промежуточного на конечный стержень}
    }
    
}
int permutations(int n) {
    if (n == 1) return 1;
    else return permutations(n-1) * 2 + 1;
}
int main() {
    int count = 1;
    int n; cout << "Number of rings:  "; cin >> n;
    if (n > 0 && n < 20) {
        cout << "Number of permutations: " << permutations(n) << endl;
        cout << "Sequence of permutations \n"; Tower(n, 1, 2, 3);
    }
    else cout << "Invalid input. \n";
}