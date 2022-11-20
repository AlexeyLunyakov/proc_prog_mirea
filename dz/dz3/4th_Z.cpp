// Задача Фильтр
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream file("./new_file1.txt");
    ifstream file2("./new_file1.txt");
    string str, answ;
    char probel[] = " ";
    int i;
    bool flag;
    if (file) {
        string line_from_file, summary_line = "";
        for(getline(file, str); !file.eof(); getline(file, str)){ 
            getline(file2, line_from_file);
            flag = false;
            for (int i = 0; i < line_from_file.size(); i++) {
                if(line_from_file[i] < 58 && line_from_file[i] > 47) {
                    summary_line += line_from_file[i];
                }
            }
            if (summary_line.size() == 2) {
                cout << summary_line[0] << " " << summary_line[1] << endl;
            }
            else if (summary_line.size() == 4) {
                cout << summary_line[0] << summary_line[1] << " " << summary_line[2] << summary_line[3] << endl;
            }
            else { cout << summary_line << endl;}
            line_from_file = ""; summary_line = "";
        }
    }
    else {
        cout << "Create the file first? (y/n) " ; cin >> answ;
        if (answ == "y") {
            cout << "Your empty file has been successfully generated.. "<< endl;
            ofstream outfile ("new_file.txt");
        }
        else if (answ == "n") {
            cout << "ok" << endl;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
