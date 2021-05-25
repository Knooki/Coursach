#pragma once
#include "main.h"
#include "Classes.h"

int entrance::entr_menu() {
	system("cls");
	wcout << L"Выберите опцию." << endl;
	wcout << L"1)Вход.\n2)Регистрация\n3)Выход из программы." << endl;
	return (input_check());
}

int entrance::entering() {
	int counter = load_from_file();
	if (counter == 0) {
		error_message(L"Ошибка.Нет учетных записей.");
		return (-1);
	}
	else {
		counter = load_from_file();
		wstring login = L"", password = L"", group;
		int type;
		wint_t p;
		switch (entr_menu()) {
		case 1:
		{
			int amount = 0;
			do {
				system("cls");
				login = L"";
				password = L"";
				wcout << L"Введите логин." << endl;
				do {
					rewind(stdin);
					p = _getwch();

					if (p == 13) break;
					if (p == L'\b' && !login.empty())
					{
						wcout << L'\b';
						wcout << L' ';
						wcout << L'\b';
						login.pop_back();
						continue;
					}
					if (p != L'\b')
						wcout << L'*';
					login.push_back(p);
				} while (1);
				wcout << L'\n';
				wcout << L"Введите пароль." << endl;
				do {
					p = _getwch();

					if (p == 13) break;
					if (p == L'\b' && !password.empty())
					{
						wcout << L'\b';
						wcout << L' ';
						wcout << L'\b';
						password.pop_back();
						continue;
					}
					if (p != L'\b')
						wcout << L'*';
					password.push_back(p);
				} while (1);
				wcout << L'\n';
				string string_login = sha1(string(login.begin(), login.end()));
				string string_password = sha1(string(password.begin(), password.end()));
				login = wstring(string_login.begin(), string_login.end());
				password = wstring(string_password.begin(), string_password.end());
				for (register int i = 0; i < counter; i++)
					if (login == _login[i] && password == _password[i])
					{
						*log = _login[i];
						*gr = _group[i];
						return(_type[i]);
					}
				error_message(L"Вы ввели неверный логин или пароль.");
				amount++;
				if (amount == 3)
				{
					amount = 0;
					for (register int i = 30; i > 0; i--) {
						Sleep(1000);
						system("cls");
						wcout << L"Программа приостановлена из-за превышения попыток ввода." << endl;
						wcout << L"До возобновления программы осталось: " << i << L" с" << endl;
					}
					system("cls");
				}
			} while (is_repeat_operation());
			break; }
		case 2:
		{
			while (1) {
				system("cls");
				login = L"";
				password = L"";
				wcout << L"Введите логин." << endl;
				do {
					p = _getwch();

					if (p == 13) break;
					if (p == L'\b' && !login.empty())
					{
						wcout << L'\b';
						wcout << L' ';
						wcout << L'\b';
						login.pop_back();
						continue;
					}
					if (p != L'\b')
						wcout << L'*';
					login.push_back(p);
				} while (1);
				wcout << L'\n';
				string string_login = sha1(string(login.begin(), login.end()));
				login = wstring(string_login.begin(), string_login.end());
				int i = 0;
				while (i < counter) {
					if (login == _login[i])
					{
						error_message(L"Этот логин уже занят.");
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
			wcout << L"Введите пароль." << endl;
			do {
				p = _getwch();

				if (p == 13) break;
				if (p == L'\b' && !password.empty())
				{
					wcout << L'\b';
					wcout << L' ';
					wcout << L'\b';
					password.pop_back();
					continue;
				}
				if (p != L'\b')
					wcout << L'*';
				password.push_back(p);
			} while (1);
			wcout << L'\n';
			string string_password = sha1(string(password.begin(), password.end()));
			password = wstring(string_password.begin(), string_password.end());
			vector<student> stud;
			stud = student::load_from_file();
			while (1) {
				wcout << L"Введите ваше полное имя." << endl;
				wstring full_name;
				rewind(stdin);
				getline(wcin, full_name, L'\n');
				if (full_name.size() > 40)
				{
					error_message(L"Имя студента не должно превышать 40 символов.");
					continue;
				}
				for (register int i = 0; i < full_name.size(); i++)
					if (!is_russian_alpha(full_name[i])) {
						error_message(L"Пожaлуйста, используйте только русские буквы.");
						full_name = L"error";
						break;
					}
				if (full_name == L"error")
					continue;
				for (register int i = 0; i < stud.size(); i++)
					if (full_name == stud[i].get_full_name()) {
						group = stud[i].get_group();
						break;
					}
				break;
			}
			if (group == L"")
			{
				wcout << L"В системе нет студента с введенном именем. Введите новый данные о студенте" << endl;
				student::add_stud();
				group = stud.back().get_group();
			}
			if (save_to_file(login, password, 0, group))
			{
				*log = login;
				*gr = group;
				complete_message(L"Вы успешно зарегестрировались.");
				counter++;
				if (is_repeat_operation())
					return (0);
				else return (-1);
			}
			error_message(L"Ошибка регистрации.");
			system("pause");
		}
		break;
		case 3:
			return(-1);
		default: error_message(L"Вы ввели неизвестную опцию.");
			system("pause");
			break;
		}
	}
	return(2);
}

int entrance::load_from_file() {
	wifstream fin(file_authentication, ios_base::in);
	fin.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fin.is_open()) {
		error_message(L"Ошибка открытия файла.");
		return(0);
	}
	else {
		int i = 0;
		wstring buffer = L"";
		int buf;
		while (getline(fin, buffer, L',')) {
			_login.push_back(buffer);
			getline(fin, buffer, L',');
			_password.push_back(buffer);
			fin >> buf;
			_type.push_back(buf);
			fin.ignore(1);
			getline(fin, buffer, L'\n');
			_group.push_back(buffer);
			i++;
		}
		return (i);
		fin.close();
	}
}

void entrance::change_data_in_file() {
	wfstream fout(file, ios_base::out);
	fout.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fout.is_open())
		error_message(L"Ошибка открытия файла.");
	else {
		for (register int i = 0; i < _login.size(); i++) {
			fout << _login[i] << L',';
			fout << _password[i] << L',';
			fout << _type[i] << L',';
			fout << _group[i] << endl;
		}
		remove(file_authentication);
		char old_name[] = file, new_name[] = file_authentication;
		fout.close();
		if (rename(old_name, new_name) != 0)
			error_message(L"Ошибка в переименовании файлов.");
		else
			complete_message(L"Аккаунты пользователей с удаленной группой удалены.");
	}
}

bool entrance::save_to_file(wstring login, wstring password, int type, wstring group) {
	wfstream fout(file_authentication, ios_base::app);
	fout.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fout.is_open()) {
		error_message(L"Ошибка открытия файла.");
		return false;
	}
	else {
		fout << login << L',';
		fout << password << L',';
		fout << type << L',';
		fout << group << endl;
		fout.close();
		return true;
	}
}

bool entrance::change_pas(wstring* login) {
	int counter = load_from_file();
	int i = 0;
	while (i < counter) {
		if (*login == _login[i]) {
			wstring pas;
			wint_t p;
			wcout << L"Введите нынешний пароль." << endl;
			do {
				rewind(stdin);
				p = _getwch();
				if (p == 13) break;
				if (p == L'\b' && !pas.empty())
				{
					wcout << L'\b';
					wcout << L' ';
					wcout << L'\b';
					pas.pop_back();
					continue;
				}
				if (p != L'\b')
					wcout << L'*';
				pas.push_back(p);
			} while (1);
			wcout << L'\n';
			string string_password = sha1(string(pas.begin(), pas.end()));
			pas = wstring(string_password.begin(), string_password.end());
			if (pas == _password[i])
			{
				wcout << L"Введите новый пароль." << endl;
				do {
					rewind(stdin);
					p = _getwch();

					if (p == 13) break;
					if (p == L'\b' && !_password[i].empty())
					{
						wcout << L'\b';
						wcout << L' ';
						wcout << L'\b';
						_password[i].pop_back();
						continue;
					}
					if (p != L'\b')
						wcout << L'*';
					_password[i].push_back(p);
				} while (1);
				wcout << L'\n';
				wfstream fout;
				fout.open(file, ios_base::out);
				if (!fout.is_open())
				{
					error_message(L"Ошибка открытия файла.");
				}
				else {
					string string_password = sha1(string(_password[i].begin(), _password[i].end()));
					_password[i] = wstring(string_password.begin(), string_password.end());
					for (register int j = 0; j < counter; j++) {
						fout << _login[i] << L',';
						fout << _password[i] << L',';
						fout << _type[i] << endl;
					}
					remove(file_authentication);
					char old_name[] = file, new_name[] = file_authentication;
					fout.close();
					if (rename(old_name, new_name) == 0) {
						complete_message(L"Вы успешно изменили пароль.");
						system("pause");
						return true;
					}
					else error_message(L"Ошибка в переименовании файлов.");
				}
			}
			else {
				error_message(L"Вы ввели неверный пароль.");
				system("pause");
				return false;
			}
			break;
		}
		i++;
	}
	if (i == counter) {
		error_message(L"Произошла ошибка в изменении пароля.");
		return false;
	}
}

void entrance::delete_users_with_group(wstring group) {
	int amount = load_from_file();
	for (register int j = 0; j < amount; j++)
		if (_group[j] == group)
		{
			_login.erase(_login.begin() + j);
			_password.erase(_login.begin() + j);
			_type.erase(_type.begin() + j);
			_group.erase(_group.begin() + j);
		}
	change_data_in_file();
}