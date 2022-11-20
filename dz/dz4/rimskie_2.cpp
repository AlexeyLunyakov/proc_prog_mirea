#include <string>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;

int main() 
{ 
    //setlocale(LC_ALL, "Rus"); 
    string roman_number; 
    int result = 0; 
    map <char, int> converter; 
    converter['I'] = 1; 
    converter['V'] = 5; 
    converter['X'] = 10; 
    converter['L'] = 50; 
    converter['C'] = 100; 
    converter['D'] = 500; 
    converter['M'] = 1000; 
    cout << "Enter Rome-numb "; 
    cin >> roman_number; 
 
    for (int i = 0; i < roman_number.length(); i++) 
        if (i == 0) {result += converter[roman_number[i]]; }
        else if (converter[roman_number[i]] <= converter[roman_number[i - 1]]) { result += converter[roman_number[i]]; }
        else {result += converter[roman_number[i]] - 2 * converter[roman_number[i - 1]]; }
 
    int number = result; 
    string ToRomanBase;
    ToRomanBase = to_string(number); 
 
    int default_numbers[] = { 1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1 }; 
    string defaults_values[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" }; 
 
    string result1 = ""; 
 
    //13 - длина массивов 
    for (int i = 0; i < 13; i++) 
    { 
        while (number >= default_numbers[i]) 
        { 
            result1 += defaults_values[i]; 
            number -= default_numbers[i]; 
        } 
    } 
 
    cout << result1; 
    cout << "\nTo 10-deck  " << result; 
}