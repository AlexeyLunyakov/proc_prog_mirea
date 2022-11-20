// 16
#include <iostream>
#include <string>
#include <cmath>
#include <deque>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("./file_for_5.txt");
    ifstream file2("./file_for_5.txt");
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
            ons = 16;
            // в 10-ую
            int ns_10_num = 0;
            for (int i = 0; i < number.size(); i++) {
                if (int(number[i]) >= 65 && int(number[i]) <= 90) { 
                    if (10 + int(number[i]) - 65 >= ons) { // проверека на несовместимость для букв
                        cout << "Invalid input. " << endl;
                        return -1;
                    }
                    ns_10_num += (10 + int(number[i]) - 65) * pow(ons, number.size() - i - 1);
                } 
                else if (int(number[i]) >= 48 && int(number[i]) <= 57) {
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








// Сортировка - позже
    // ifstream file("./phone_book.txt");
    // if (!file) {
    //     string last_name = "a", phone_num, str_for_file_1, str_for_file_2;
    //     // char buff[50];
    //     ofstream file ("phone_book.txt");
    //     while (last_name != " ") {
    //         cout << "(To finish, enter ' ' at the beginning of the line and press <Enter>)\n"; 
    //         cout << endl;
    //         cout << "Enter your friend's last name and press <Enter>.\n";
    //         getline(cin, last_name); 
            
    //         if (last_name == " ") {
    //             break;
    //         }
    //         else {
    //             cout << "Enter his(her) phone numberand press <Enter>.\n";
    //             getline(cin, phone_num);
    //             str_for_file_1 += last_name;
    //             file << str_for_file_1 << " - ";
    //             str_for_file_1 = "";
    //             str_for_file_2 += phone_num;
    //             file << str_for_file_2 << "\n";
    //             str_for_file_2 = "";
    //         }
    //     }
    //     file.close();
    //     cout << "Your file has been successfully generated.. "<< endl;
    // }
    // else {
    //     ifstream file("./phone_book.txt");
    //     ifstream file2("./phone_book.txt");
    //     string str;
    //     string line_from_file, all_line, cin_line, l_n_line, cout_line;
    //     cout << "Enter your friend's last name and press <Enter>\n"; 
    //     cin >> cin_line;
    //     cout << endl;
    //     for(getline(file, str); !file.eof(); getline(file, str)){ 
    //             getline(file2, line_from_file);
    //             for (int i = 0; i < line_from_file.size(); i++) {
    //                 all_line += line_from_file[i];
    //                 if (isalpha(line_from_file[i])) {
    //                     l_n_line += line_from_file[i];
    //                 }
    //             }

    //             if (l_n_line == cin_line) {
    //                 cout_line += all_line;
    //                 cout_line += "\n";
    //             }
    //             line_from_file = ""; all_line = ""; l_n_line = "";
    //         }
    //     cout << cout_line << endl;
    // }
    // cout << endl;
    // return 0;