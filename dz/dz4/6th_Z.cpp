#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool SymbCorr (const char &x) {
    char Arabic[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    for (int i = 0; i < 7; ++i) {
        if (x == Arabic[i]) {
            return true;
        }
    }
    return false;
}
int ToArabNum(const char &y){
    switch(y){
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}
bool Proverka(const char prev, const char next, int duplication) {
    if (next == prev && (prev == 'L' || prev == 'D' || prev == 'V')) { // проверка неповторяющихся
        return false;
    }
    if (duplication == 4 && (next == 'X' || next == 'C' || next == 'M' || next == 'I')) { // проверка повторяющихся
        return false;
    }
    if (((next == 'X'|| next == 'C' || next == 'L' || next == 'D') && prev == 'V') || (next == 'M' && prev == 'D') || (prev == 'L' && (next == 'D' || next == 'C'))) { // проверка несочетаемого
        return false;
    }
    if ((prev == 'V' || prev == 'I' ) && (next == 'L' || next == 'C' || next == 'D' || next == 'M')) {
        return false;
    }
    if (duplication == 2 && (prev == 'I' || prev == 'V' || prev == 'X') && (next == 'V' || next == 'X' || next == 'L' || next == 'C' || next == 'D' || next == 'M')) {
        return false;
    }
    return true;
}
//  MLDC
bool Proverka2(string str) {
    if ((str.find("IXI") != std::string::npos) || (str.find("IVI")  != std::string::npos) || (str.find("IXV")  != std::string::npos) || (str.find("VXI")  != std::string::npos) || (str.find("IVX")  != std::string::npos) || (str.find("VIV") != std::string::npos) || (str.find("VIX") != std::string::npos) || (str.find("MLD")  != std::string::npos) || (str.find("MLC")  != std::string::npos)) {
        return false;
    }
    else { return true;}
    return true;
}

int strToInt(string rims){
    int summa = 0, last_symb = 0;
    //проходимся по разрядам числа в РСС
    if (rims.size() > 1) {
        for (int i = 0; i < rims.size() - 1; i++) {
            if(SymbCorr(rims[i])) {
                if (ToArabNum(rims[i]) < ToArabNum(rims[i + 1]))
                    summa -= ToArabNum(rims[i]);
                else
                    summa += ToArabNum(rims[i]);

                last_symb = ToArabNum(rims[i + 1]);
            }
            else {
                last_symb = 0;
            }
        }
    }
    else {
        if(SymbCorr(rims[0]))
            last_symb = ToArabNum(rims[0]);
    }
    summa += last_symb;
    return summa;
}

int main(){
    string str; 
    while (str[0] != '0') {
        cout << "(To finish, enter '0' at the beginning of the line)\nEnter the Roman notation of the number: ";  cin >> str;
        if (str[0] != '0') {
            int duplication = 1;
            bool flag; 
            if (strToInt(str) != 0) {
                if (Proverka2(str)) {
                    if (str.size() > 1) {
                        for ( int i = 0; i < str.size() - 1; i++) {
                            if (str[i] == str[i+1]) duplication += 1;
                            if (Proverka(str[i], str[i+1], duplication)) {
                                flag = true;
                            }
                            else 
                                flag = false;
                        } 
                        if (flag) cout << str << " = " << strToInt(str) << endl;
                        else cout << "Invalid input. (Proverka 2) \n";
                    }
                    else {
                        cout << str << " = " << strToInt(str) << endl;
                    }
                }
                else cout << "Invalid input. (Proverka 1) \n";
            }
            else 
                cout << "Invalid input. \n";
        }
        else {
            exit(1);
        }
    }
    return 0;
}

// || str.find("IVI") || str.find("IXV") || str.find("VXI") || str.find("IVX") || str.find("IVII") || str.find("IXII") || str.find("VXII") || str.find("IVXI") || str.find("VXII") || str.find("VIV") || str.find("VIX")