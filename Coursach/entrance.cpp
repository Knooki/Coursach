#pragma once
#include "main.h"
#include "Classes.h"

int entrance::entr_menu() {
	system("cls");
	int sw;
	cout << "�������� �����." << endl;
	cout << "1)����.\n2)�����������\n3)����� �� ���������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("������. �� ������ ������ ������ �����.");
	}
	return (sw);
}

int entrance::entering() {
	int counter = load_from_file();
	if (counter == 0) {
		error_message("������.��� ������� �������.");
		return(-1);
	}
	else {
		counter = load_from_file();
		string login, password;
		switch (entr_menu()) {
		case 1:
		{
			int amount = 1;
			do {
				if (amount % 4 == 0)
				{
					int c = clock() + 30000;
					while (clock() < c)
					{
						system("cls");
						int _c = clock();
						cout << "��������� �������������� ��-�� ���������� ������� �����." << endl;
						cout << "�� ������������� ��������� ��������: " << (c - _c) / 1000 << " �" << endl;
					}
				}
				system("cls");
				cout << "������� �����." << endl;
				rewind(stdin);
				getline(cin, login);
				cout << "������� ������." << endl;
				rewind(stdin);
				getline(cin, password);
				login = sha1(login);
				password = sha1(password);
				for (register int i = 0; i < counter; i++)
					if (login == _login[i] && password == _password[i])
					{
						*log = _login[i];
						return(_type[i]);
					}
				error_message("�� ����� �������� ����� ��� ������.");
				amount++;
			} while (is_repeat_operation());
			break; }
		case 2:
			while (1) {
				system("cls");
				cout << "������� �����." << endl;
				rewind(stdin);
				getline(cin, login);
				login = sha1(login);
				int i = 0;
				while (i < counter) {
					if (login == _login[i])
					{
						error_message("���� ����� ��� �����.");
						if (is_repeat_operation())
							break;
						else {
							i = counter + 1;
							break;
						}
					}
					i++;
				}
				if (i > counter) return (2);
				if (i == counter) break;
			}
			cout << "������� ������." << endl;
			rewind(stdin);
			getline(cin, password);
			password = sha1(password);
			if (save_to_file(login, password, 0))
			{
				*log = login;
				complete_message("�� ������� ������������������.");
				counter++;
				if (is_repeat_operation())
					return (0);
				else return (-1);
			}
			else
				error_message("������ �����������.");
			system("pause");
			break;
		case 3:
			return(-1);
		default: error_message("�� ����� ����������� �����.");
		}
	}
}

int entrance::load_from_file() {
	ifstream fin(file_authentication, ios_base::in);
	if (!fin.is_open()) {
		error_message("������ �������� �����.");
		return(0);
	}
	else {
		int i = 0;
		string buffer = "";
		int buf;
		while (getline(fin, buffer, ',')) {
			_login.push_back(buffer);
			getline(fin, buffer, ',');
			_password.push_back(buffer);
			fin >> buf;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			_type.push_back(buf);
			i++;
		}
		return (i);
		fin.close();
	}
}

bool entrance::save_to_file(string login, string password, int type) {
	ofstream fout;
	fout.open(file_authentication, ios_base::app);
	if (!fout.is_open()) {
		error_message("������ �������� �����.");
		return false;
	}
	else {
		fout << login << ',';
		fout << password << ',';
		fout << type;
		fout.close();
		return true;
	}
}

bool entrance::change_pas(string* login) {
	int counter = load_from_file();
	int i = 0;
	while (i < counter) {
		if (*login == _login[i]) {
			string pas;
			cout << "������� �������� ������." << endl;
			cin >> pas;
			pas = sha1(pas);
			if (pas == _password[i])
			{
				cout << "������� ����� ������." << endl;
				cin >> _password[i];
				fstream fout;
				fout.open(file, ios_base::out);
				if (!fout.is_open())
				{
					error_message("������ �������� �����.");
				}
				else {
					_password[i] = sha1(_password[i]);
					for (register int j = 0; j < counter; j++) {
						fout << _login[i] << ',';
						fout << _password[i] << ',';
						fout << _type[i] << endl;
					}
					remove(file_authentication);
					char old_name[] = file, new_name[] = file_authentication;
					fout.close();
					if (rename(old_name, new_name) == 0) {
						complete_message("�� ������� �������� ������.");
						system("pause");
						return true;
					}
					else error_message("������ � �������������� ������.");
				}
			}
			else {
				error_message("�� ����� �������� ������.");
				system("pause");
				return false;
			}
			break;
		}
		i++;
	}
	if (i == counter) {
		error_message("��������� ������ � ��������� ������.");
		return false;
	}
}