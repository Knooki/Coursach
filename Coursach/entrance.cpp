#pragma once
#include "main.h"
#include "Classes.h"

int entrance::entr_menu() {
	system("cls");
	int sw;
	cout << "Выберите опцию." << endl;
	cout << "1)Вход.\n2)Регистрация\n3)Выход из программы." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	return (sw);
}

int entrance::entering() {
	int counter = load_from_file();
	if (counter == 0) {
		cout << "Нет учетных записей." << endl;
		return(-1);
	}
	else {
		counter = load_from_file();
		string login, password;
		switch (entr_menu()) {
		case 1:
			do {
				system("cls");
				cout << "Введите логин." << endl;
				rewind(stdin);
				getline(cin, login);
				cout << "Введите пароль." << endl;
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
				cout << "Вы ввели неверный логин или пароль." << endl;
			} while (is_repeat_operation());
			break;
		case 2:
			while (1) {
				system("cls");
				cout << "Введите логин." << endl;
				rewind(stdin);
				getline(cin, login);
				login = sha1(login);
				int i = 0;
				while (i < counter) {
					if (login == _login[i])
					{
						cout << "Этот логин уже занят." << endl;
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
			cout << "Введите пароль." << endl;
			rewind(stdin);
			getline(cin, password);
			password = sha1(password);
			if (save_to_file(login, password, 0))
			{
				*log = login;
				cout << "Вы успешно зарегестрировались." << endl;
				counter++;
				if (is_repeat_operation())
					return (0);
				else return (-1);
			}
			else cout << "Ошибка регистрации." << endl;
			system("pause");
			break;
		case 3:
			return(-1);
		default: cout << "Вы ввели неизвестную опцию." << endl;
		}
	}
}

int entrance::load_from_file() {
	ifstream fin(file_authentication, ios_base::in);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла." << endl;
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
		cout << "Ошибка открытия файла." << endl;
		return false;
	}
	else {
		fout << endl;
		fout << login << ',';
		fout << password << ',';
		fout << type;
		fout.close();
		return true;
	}
}

void entrance::change_pas(string* login) {
	int counter = load_from_file();
	int i = 0;
	while (i < counter) {
		if (*login == _login[i]) {
			string pas;
			cout << "Введите нынешний пароль." << endl;
			cin >> pas;
			pas = sha1(pas);
			if (pas == _password[i])
			{
				cout << "Введите новый пароль." << endl;
				cin >> _password[i];
				fstream fout;
				fout.open(file, ios_base::out);
				if (!fout.is_open())
				{
					cout << "Ошибка открытия файла." << endl;
				}
				else {
					_password[i] = sha1(_password[i]);
					for (register int j = 0; j < counter; j++) {
						if (j == counter - 1)
						{
							fout << _login[i] << ',';
							fout << _password[i] << ',';
							fout << _type[i];
						}
						else {
							fout << _login[i] << ',';
							fout << _password[i] << ',';
							fout << _type[i] << endl;
						}
					}
					remove(file_authentication);
					char old_name[] = file, new_name[] = file_authentication;
					fout.close();
					if (rename(old_name, new_name) == 0) {
						cout << "Вы успешно изменили пароль." << endl;
						system("pause");
						break;
					}
					else cout << "Ошибка в переименовании файлов." << endl;
				}
			}
			else {
				cout << "Вы ввели неверный пароль." << endl;
				if (is_repeat_operation()) return;
			}
		}
		else i++;
	}
	if (i == counter) cout << "Произошла ошибка в изменении пароля." << endl;
}