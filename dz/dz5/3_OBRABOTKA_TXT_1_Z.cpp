// 16 Поиск определенного сочетания слов в текстовом файле.
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream file("./file.txt");
    ifstream file2("./file.txt");
    string str, answ, enter_line;
    char probel[] = " ";
    int i;
    bool flag;
    if (file) {
        string line_from_file, sum_line = "";
        bool flag = false;
        cout << "Enter your line: \n";
        getline(cin, enter_line);
        //cout << enter_line << endl;
        for(getline(file, str); !file.eof(); getline(file, str)){ 
            getline(file2, line_from_file);
            if (line_from_file == " ") {
                break;
            }
            for (int i = 0; i < line_from_file.size(); i++) {
                    sum_line += line_from_file[i];
            }
            //cout << sum_line << endl;
            if (sum_line.find(enter_line) != std::string::npos) {
                //cout << "\nFind! String - " << enter_line << "\n";
                flag = true;
                break;
            }
            line_from_file = ""; sum_line = "";
        }
        if (flag == true) cout << "\nFind! String - " << enter_line << "\n";
        else cout << "Unexpected error. No such string \n";
    }
    cout << endl;
    return 0;
}

// sum_line.find(enter_line) != std::string::npos
// string str1 = "a", str2;
//     char buff[50];
//     ofstream file ("file.txt");
//     while (str1 != " ") {
//             cout << "Enter your string and press <Enter>.\nTo finish, enter '' at the beginning of the line and press <Enter>\n"; 
//             getline(cin, str1);
//             if (str1 == " ") {
//                 break;
//             }
//             else {
//                 str2 += str1;
//                 file << str2 << "\n";
//                 str2 = "";
//             }

//     }
//     file.close();
//     cout << "Your file has been successfully generated.. "<< endl;