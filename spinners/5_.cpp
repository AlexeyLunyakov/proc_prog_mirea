#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
    int N, K, free_left, free_right;
    int left_border = 0, right_border = 0, sum = 0, max = 0;
    cout << "Enter number of seats (N): "; cin >> N;
    cout << "Enter number of students (K): "; cin >> K;
    int* Seats = new int[N + 2];

    Seats[0] = -1; 
    Seats[N + 1] = -1;
    for (int i = 1; i <= N; i++) {
        Seats[i] = 0;
    }

    while (K > 0) {
        for (int i = 0; i <= N + 1; i++) {
            if (Seats[i] == 0)
                sum = sum + 1;
            else {
                if (sum > max) {
                    left_border = i - sum - 1;
                    right_border = i;
                    max = sum;
                }
                sum = 0;
            }
        }
        sum = 0;

        Seats[(left_border + right_border) / 2] = 1;
        max = 0;
        if (K == 1) {
                Seats[(left_border + right_border) / 2] = 2;
        }
        K = K - 1;
    }
    free_left = (left_border + right_border) / 2 - left_border - 1;
    free_right = right_border - 1 - (left_border + right_border) / 2;
    //cout << left_border << ' ' << right_border << endl;
    cout << "\nThe resulting series: ";
    for (int i = 0; i <= N + 1; i++) {
        cout << Seats[i] << " ";
    }
    cout << "\nLeft: " << free_left << "\nRight: " << free_right << endl;
}