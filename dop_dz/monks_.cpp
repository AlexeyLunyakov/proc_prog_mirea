#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	char ch;
	string s, tmp;
	int monks[601] = { 0 }, b[4], i = 0, j, t, r;
	vector <int> v;

	/* Считаем исходные данные о монахах из заранее приготовленного файла monks.dat */
	ifstream fin(".\monks.dat");
	if (!fin.is_open()) {
		cout << "* Ошибка открытия файла monks.dat! *" << endl;
		return(1);
	}
	while (getline(fin, s))	{
		s += " ";
		j = 0;
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')	{

				b[j] = stoi(tmp);
				tmp.clear();
				j++;
			}
			else tmp += s[i];
		}
		for (i = 1; i < 4; i++) // заполняем данные о монахах в массив monks так, что элемент monk[i] содержит учителя монаха под номером i
		{
			monks[b[i]] = b[0];
		}
	}
	fin.close();

	/* Считываем вариант задания из файла task.dat и решаем задачи */
	fin.open(".\task.dat");
	if (!fin.is_open())	{
		cout << "* Ошибка открытия файла monks.dat! *" << endl;
		return(1);
	}
	while (getline(fin, s))	{
		s += " ";
		j = 0;
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{

				b[j] = stoi(tmp);
				tmp.clear();
				j++;
			}
			else tmp += s[i];
		}
		if (b[0] == 1) // если код строки = 1, то определяем монах это или нет и всех его учителей до Святого Павла
		{
			if (monks[b[1]] == 0) // нет учителя (должен быть один), значит не монах
			{
				cout << b[1] << " - not a monk" << endl;
			}
			else	{
				cout << b[1] << " - a monk, his teachers are ";
				t = monks[b[1]]; // первый учитель в цепочке
				cout << t;
				while (t > 1) // идем по цепочке учителей вверх до Святого Павла
				{
					t = monks[t];
					cout << ", " << t;
				}
				cout << endl;
			}
		}
		if (b[0] == 2) // если код строки = 2, то определяем монахи это или нет и их общего ближайшего учителя 
		{
			if (monks[b[1]] == 0) // у первого монаха нет учителя (должен быть один), значит не монах и общего учителя нет
			{
				cout << b[1] << " - not a monk" << endl;
			}
			else if (monks[b[2]] == 0) // у второго монаха нет учителя (должен быть один), значит не монах и общего учителя нет
			{
				cout << b[2] << " - not a monk" << endl;
			}
			else // оба монахи
			{
				r = 0; // общий учитель пока не найден
				cout << b[1] << " and " << b[2] << " are both monks, and their nearest common teacher is ";
				t = monks[b[1]]; // первый учитель в цепочке первого монаха
				v.push_back(t); // добавляем в массив первого учителя
				while (t > 1) // идем по цепочке учителей первого монаха вверх до Святого Павла
				{
					t = monks[t];
					v.push_back(t); // добавляем в массив следующего учителя
				}
				t = monks[b[2]]; // первый учитель в цепочке второго монаха
				for (i = 0; i < v.size(); i++)	{
					if (v[i] == t)
					{
						r = t;
						break;
					}
				}
				if (!r)	{
					while (t > 1) // идем по цепочке учителей первого монаха вверх до Святого Павла
					{
						t = monks[t];
						for (i = 0; i < v.size(); i++)	{
							if (v[i] == t)	{
								r = t;
								break;
							}
						}
						if (r) break;
					}
				}
				cout << r << endl;
			}
		}
	}
	fin.close();
}