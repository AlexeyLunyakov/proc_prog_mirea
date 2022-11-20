// Зачтено
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream (file);
    file.open("./new_file_2.txt");
    string str1 = "a", str2;
    char buff[50];
    if (!file) {
        ofstream outfile ("new_file_2.txt");
        while (str1 != " ") {
                cout << "Enter string "; 
                getline(cin, str1);
                str2 += str1;
                outfile << str2 << endl;
                //outfile << "\n" << endl;
                str2 = "";
        }
        cout << "Your file has been successfully generated.. "<< endl;
    } else {
        for(file >> str1; !file.eof(); file >> str1){
            cout << str1 << "\n";
        }
    }
    
    system("pause");
    return 0;
}