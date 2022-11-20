// 15
#include <iostream>
#include <string>
#include <cmath>
#include <deque>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("./file_for_5_2.txt");
    ifstream file2("./file_for_5_2.txt");
    string str, answ, enter_line;
    string number; int ons, rns;
    char probel[] = " ";
    int i;
    bool flag;
    if (file) {
        string line_from_file;
        cout << "\nEnter new number system: \n"; cin >> rns; cout <<'\n';
        for(getline(file, str); !file.eof(); getline(file, str)){ 
            getline(file2, line_from_file);
            if (line_from_file == " ") { break; }
            number = line_from_file;
            ons = 10;
            int ns_10_num = 0;
            for (int i = 0; i < number.size(); i++) {
                if (int(number[i]) >= 48 && int(number[i]) <= 57) {
                    if (int(number[i]) - 48 >= ons) { 
                        cout << "Invalid input. " << endl;
                        return -1;                
                    }
                    ns_10_num += (int(number[i]) - 48) * pow(ons, number.size() - i - 1);
                }
                else{
                    cout << "Invalid input. " << endl;
                    return -1;
                }
            }
            cout << ns_10_num << " ---> ";
            // в необходимую
            deque<int> arr;

            while (ns_10_num > 0) {
                arr.push_front(ns_10_num % rns);
                ns_10_num = ns_10_num / rns;

            }

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == 10) {
                    cout << "A";
                }
                else if (arr[i] == 11) {
                    cout << "B";
                }
                else if (arr[i] == 12) {
                    cout << "C";
                }
                else if (arr[i] == 13) {
                    cout << "D";
                }
                else if (arr[i] == 14) {
                    cout << "E";
                }
                else if (arr[i] == 15) {
                    cout << "F";
                }
                else cout << arr[i];
            }
            line_from_file = "";
            cout << "\n\n";
        }
    }
    return 0;
}


                // if (int(number[i]) >= 65 && int(number[i]) <= 90) { 
                //     if (10 + int(number[i]) - 65 >= ons) { // проверека на несовместимость для букв
                //         cout << "Invalid input. " << endl;
                //         return -1;
                //     }
                //     ns_10_num += (10 + int(number[i]) - 65);
                // } 
                //else 