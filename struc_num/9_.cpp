


















































// #include <iostream>
// #include <algorithm>
// using namespace std;
 
// int main() {
//     int n;
//     cin >> n;
//     const auto h = 5;
//     int arr[h]; // массив для перестановки из n чисел
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     for (int i = n - 2; i >= 0; i--) { 
//         if (arr[i] < arr[i+1]){
//             int min = i + 1; // индекс минимального элемента 
//             for (int j = i + 2; j < n; j++) {
//                 if (arr[j] > arr[i] && arr[j] < arr[min]) min = j;
//             }
//             swap(arr[i], arr[min]);
//             reverse(&arr[i + 1], &arr[n]);
//             break;
//         }
//         if (i == 0) reverse(&arr[i], &arr[n]);
//     }
//     for (int i = 0; i < n; i++) cout << arr[i] << " ";
//     return 0;
// }