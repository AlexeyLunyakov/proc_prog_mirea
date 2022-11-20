// 24 
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool SymbCorr (const char &x) {
    char Consonant[21] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z' }; 
    for (int i = 0; i < 21; ++i) {
        if (toupper(x) == Consonant[i]) {
            return true;
        }
    }
    return false;
}

bool vowels (const char &x) {
    char Vowels[6] {'A', 'E', 'I', 'O', 'U', 'Y'};
    for (int i = 0; i < 6; i++) {
        if (toupper(x) == Vowels[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream file("./file1.txt");
    ifstream file2("./file1.txt");
    string str, answ, enter_line;
    char probel[] = " ";
    char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
    int consonant[21] = {0};
    int i;
    bool flag;
    if (file) {
        string line_from_file, sum_line = "";
        bool flag = false;
        int symb_rep[26] = {0};
        for(getline(file, str); !file.eof(); getline(file, str)){ 
            getline(file2, line_from_file);
            if (line_from_file == " ") {
                break;
            }
            //cout << line_from_file;
            for (int i = 0; i < line_from_file.size(); i++) {
                int numb;
                numb = int(toupper(line_from_file[i])) - 65;
                for (int x = 0; x < 26; x++ ) {
                    if (x == numb) {
                        if (SymbCorr(line_from_file[i])) {
                            symb_rep[x] += 1;
                        }
                        else {
                            symb_rep[x] += -1;
                        }
                    }
                }
                numb = -1;
            }
            line_from_file = ""; sum_line = "";
        }
        cout << endl;
        int min = 10000;
        for (int i = 0; i < 26; i++) {
            if (( ( symb_rep[i]) < min ) && (symb_rep[i] > 0)) {
                min = symb_rep[i];
            }
        }
        // for (int i = 0; i < 26; i++) {
        //     cout << alphabet[i] << ' ';
        // }
        // cout << endl;
        for (int i = 0; i < 26; i++) {
            if (symb_rep[i] == min) {
                cout << alphabet[i] << ' ' << symb_rep[i] << endl;
            }
            //cout << symb_rep[i] << ' ';
        }
    }
    cout << endl;
    return 0;    
}











            //cout << sum_line << endl;
            // if (sum_line.find(enter_line) != std::string::npos) {
            //     //cout << "\nFind! String - " << enter_line << "\n";
            //     flag = true;
            //     break;
            // }


// ifstream file("./file.txt");
//     ifstream file2("./file.txt");
//     string str, answ;
//     char probel[] = " ";
//     int i;
//     bool flag;
//     if (file) {
//         string line_from_file, sum_line = "";
//         for(getline(file, str); !file.eof(); getline(file, str)){ 
//             getline(file2, line_from_file);
//             if (line_from_file == " ") {
//                 break;
//             }
//             flag = false;
//             for (int i = 0; i < line_from_file.size(); i++) {
//                     sum_line += line_from_file[i];
//             }
//             cout << sum_line << endl;
//             line_from_file = ""; sum_line = "";
//         }
//     }
//     cout << endl;
//     return 0;