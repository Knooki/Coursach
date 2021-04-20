//#include "Header.h"
//#include "sha1.h"
//#include <iostream>
//#include <conio.h>
//#include <cstdlib>
//#include <string>
//#include <fstream>
//
//using namespace std;
//int i, counter = 0, subject_counter = 0;
//string* login, * password;
//int* priority;
//
//#define file_st "students.txt"
//#define file_sub "subjects.txt"
//#define file_pass_log "passwords_logins.txt"
//
//struct subject {
//	int code;
//	string name;
//	string t_full_name;
//	int hour_amount;
//	int semester;
//};
//
//struct accounting {
//	int st_code;
//	int sub_code;
//	int completion_data[8];
//	int mark;
//};
//
//struct student {
//	int code;
//	string full_name;
//	int birth_data[8];
//	string specialty;
//	char group[6];
//	accounting* scores;
//};
//
//struct student* arr_student;
//
//int entering() {
//	string _login, _password;
//	int sw;
//	while (1) {
//		counter = counting_users();
//		login = new string[counter];
//		password = new string[counter];
//		priority = new int[counter];
//		load_log_pas();
//		cout << "�������� �����." << endl;
//		cout << "1)����.\n2)�����������\n3)�����" << endl;
//		while (!(cin >> sw) || cin.peek() != '\n') {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "������. �� ������ ������ ������ �����." << endl;
//		}
//		switch (sw) {
//		case 1:
//			if (counter != 0)
//				do {
//					cout << "������� �����." << endl;
//					rewind(stdin);
//					getline(cin, _login);
//					cout << "������� ������." << endl;
//					rewind(stdin);
//					getline(cin, _password);
//					_login = sha1(_login);
//					_password = sha1(_password);
//					for (int i = 0; i < counter; i++)
//						if (*(login + i) == _login && *(password + i) == _password && *(priority + i) >= 0)
//						{
//							cout << "�� ������� �����." << endl;
//							return (*(priority + i));
//						}
//						else
//							cout << "�� ����� ������������ ����� ��� ������." << endl;
//				} while (is_operation());
//			else cout << "� ������� ���� ��� ��� ������� �������. �����������������." << endl;
//			break;
//		case 2:
//			cout << "������� ����� ����� � ������." << endl;
//			do {
//				rewind(stdin);
//				getline(cin, _login);
//				i = 0;
//				while (i < counter)
//				{
//					if (*(login + i) == _login) {
//						cout << "����� ��� ������������ ��� ������." << endl;
//						break;
//					}
//					i++;
//				}
//			} while (i != counter);
//			rewind(stdin);
//			getline(cin, _password);
//			if (add_log_pas(_login, _password, 1))
//				cout << "����������� ������ �������." << endl;
//			break;
//		case 3: return(-1);
//		default: cout << "�� ����� �������� �����." << endl; break;
//		}
//	}
//}
//
//void user() {
//	switch (menu_user()) {
//	case 1:
//
//		break;
//	case 2:
//
//		break;
//	}
//}
//
//int menu_user() {
//	int sw;
//	cout << "�������� �����:" << endl;
//	cout << "1)�������������� � �������." << endl;
//	cout << "2)�������� ���������� � ���� �������." << endl;
//	cout << "3)����� ������������ ������." << endl;
//	cout << "4)���������� ������." << endl;
//	while (!(cin >> sw) || cin.peek() != '\n') {
//		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		cout << "������. �� ������ ������ ������ �����." << endl;
//	}
//	return (sw);
//}
//
//void admin() {
//}
//
//void load_log_pas() {
//	ifstream fin;
//	int amount = 0;
//	fin.open(file_pass_log, ios_base::in);
//	if (!fin.is_open())
//	{
//		cout << "������ � �������� �����." << endl;
//	}
//	else {
//		i = 0;
//		while (getline(fin, *(login + i))) {
//			getline(fin, *(password + i));
//			fin >> *(priority + i);
//			i++;
//		}
//	}
//}
//
//bool add_log_pas(string log, string pas, int prior) {
//	ofstream fout;
//	fout.open(file_pass_log, ios_base::app | ios_base::out);
//	if (!fout.is_open())
//	{
//		cout << "������ � �������� �����." << endl;
//		return false;
//	}
//	else
//	{
//		log = sha1(log);
//		pas = sha1(pas);
//		fout << log << endl;
//		fout << pas << endl;
//		fout << prior << endl;
//		return true;
//	}
//}
//
//int counting_users() {
//	ifstream fin;
//	string log, pas;
//	int i = 0, buffer;
//	fin.open(file_pass_log, ios_base::in);
//	if (!fin.is_open())
//	{
//		cout << "������ � �������� �����." << endl;
//		return(0);
//	}
//	else {
//		while (getline(fin, log)) {
//			getline(fin, pas);
//			fin >> buffer;
//			i++;
//		}
//		return(i);
//	}
//}
//
////string cryptography(string* str) {
////	char key[3] = { 'K', 'C', 'Q' };
////	string* output = str;
////
////	for (int j = 0; j < str[0].size(); j++)
////		output[0][j] = str[0][j] ^ key[j % (sizeof(key) / sizeof(char))];
////	return *output;
////}
//
//void load_from_file()
//{
//	ifstream fin;
//	fin.open(file_pass_log);
//	if (!fin.is_open())
//	{
//		cout << "Error in opening file.\n";
//	}
//	else {
//		i = 0;
//		while (getline(fin, arr_p_l[i].login))
//		{
//			fin.ignore(numeric_limits<streamsize>::max(), '\n');
//			getline(fin, arr_p_l[i].password);
//			fin.ignore(numeric_limits<streamsize>::max(), '\n');
//			i++;
//		}
//	}
//	fin.close();
//}
//
//void save_in_file()
//{
//	remove(*file_students);
//	ofstream fout;
//	fout.open(file_students);
//	if (!fout.is_open())
//	{
//		cout << "������ �������� �����.\n";
//	}
//	else {
//		fout << counter << endl;
//		for (i = 0; i < counter; i++)
//		{
//		}
//	}
//	fout.close();
//}
//
//bool is_operation() {
//	cout << "������� ����� ������� ��� �����������." << endl;
//	cout << "����� ����� ������� Esc." << endl;
//	return(_getch() != 27);
//}