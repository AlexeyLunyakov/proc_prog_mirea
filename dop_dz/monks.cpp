#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

float isInt() {
	string str; cin >> str;
	int i = 0;
	int score = 0;
	for (i; i < str.size(); i++) {
		if (isdigit(str[i])) score++;
		else if (str[i] == '-' && i == 0) score++;
	}
	if (i == score) return atof(str.c_str());
	else {
		cout << "Invalid input \n";
		exit(0);
	}
}
int main() {
	int arr1[610] = {0};
	int* teach = new int[600];
	for (int i = 0; i < 600; i++) teach[i] = 0;
	// for (int i = 0; i < 600; i++) arr1[i] = 0;
	arr1[0] = -1;
	cout << "Построчно введите таблицу Монахов (не более 600 монахов). Если меньше, введите отрицательное число для окончания ввода\n";

	int score = 0;

	int j = 0;
	while (true) {

		bool flag = 0;
		int teacher = isInt();
		if (teacher == 0 || teacher >= 600) {
			cout << "Данные введены неверно";
			exit(0);
		}
		if (teacher < 0) break;

		for (int i = 0; i < 3; i++) {
			int student = 0;
			student = isInt();
			if (student < 0) {
				flag = 1;
				break;
			}
			teach[teacher]++;
			if (student > 600 || (teacher >= student && student != 0) || teach[teacher-1] > 3 || (arr1[student-1] != 0 && student != 0)) {
				cout << "Данные неверны";
				exit(0);
			}

			arr1[student-1] = teacher;
			score++;
			if (score >= 600) break;
		}
		if (flag == 1) break;


	}
	delete[] teach;

	cout << "Введите необходимую последовательность, конец ввода обозначьте -1: \n";
	vector<int>ivector = vector<int>();
	int b = 1;
	while (b >= 0) {
		cin >> b; ivector.push_back(b);
	}

	vector<int> teachs = vector<int>();	  // содержит последовательность с первой введенной цифрой 1
	vector<int> noTeach = vector<int>(); //содержит последовательность с первой введенной цифрой 2
	int a = 0;

	while (ivector[a] != -1) {
		if (ivector[a] == 1) {
			teachs.push_back(ivector[a + 1]);
			a += 2;
		}
		if (ivector[a] == 2) {
			noTeach.push_back(ivector[a + 1]);
			noTeach.push_back(ivector[a + 2]);
			a += 3;
		}
	}


	int noTeachNumber = noTeach.size();
	int teachsNumber = teachs.size();

	//for (int i = 0; i < teachs.size(); i++) cout << teachs[i] << ' ';
	//cout << endl;
	//for (int i = 0; i < noTeach.size(); i++) cout << noTeach[i] << ' ';
	//cout << endl;
	//cout << "teachs: " << teachsNumber << endl;
	//cout << "No teachs: " << noTeachNumber << endl;
	for (int i = 0; i < teachsNumber; i++) {
		//cout << "Teachs: " << teachs[0] << endl;
		int numMonk = teachs[i];
		//cout << "Num monk: " << numMonk << endl;

		if (arr1[numMonk - 1] != 0) {
			vector <int> vect;
			while (numMonk != -1) {
				numMonk = arr1[numMonk - 1];
				if (numMonk == 0) {
					cout << teachs[i] << " - не монах" << endl;
					exit(0);
				}
				if (numMonk == -1) break;
				vect.push_back(numMonk);
			}
			cout << teachs[i] << " - монах, его учителя ";
			for (int i = 0; i < vect.size(); i++) cout << vect[i] << " "; cout << endl;
		}
		else cout << teachs[i] << " - не монах" << endl;
	}

	for (int i = 0; i < noTeachNumber; i += 2) {
		vector <int> vect1;
		vector <int> vect2;
		bool flag1 = 0, flag2 = 0;
		int numMonk1 = noTeach[i], numMonk2 = noTeach[i + 1];
		int save1 = numMonk1, save2 = numMonk2;
		while (numMonk1 != -1) {
			numMonk1 = arr1[numMonk1 - 1];
			if (numMonk1 == 0) {
				flag1 = 1;
				break;
			}
			if (numMonk1 == -1) break;
			vect1.push_back(numMonk1);
		}

		while (numMonk2 != -1) {
			numMonk2 = arr1[numMonk2 - 1];
			if (numMonk2 == 0) {
				flag2 = 1;
				break;
			}
			if (numMonk2 == -1) break;
			vect2.push_back(numMonk2);
		}

		if (flag1 && flag2) cout << noTeach[i] << " и " << noTeach[i + 1] << " оба не монахи" << endl;
		else if (flag1) cout << noTeach[i] << " - не монах";
		else if (flag2) cout << noTeach[i + 1] << " - не монах";
		if (flag1 || flag2) exit(0);

		for (int i = 0; i < vect1.size(); i++) {
			for (int j = 0; j < vect2.size(); j++) {
				if (vect1[i] == vect2[j]) {
					cout << noTeach[i] << " и " << noTeach[i + 1] << " оба монахи, их общий учитель " << vect1[i];
					exit(0);
				}
			}
		}

	}
		
	return 0;
}
