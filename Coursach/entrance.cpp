#include "main.h"
#include "entrance.h"

int log_pas::entr_menu() {
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

int log_pas::entrance() {
	switch (entr_menu()) {
	case 1:
		int counter = load_from_file();
		if (counter == 0) {
			cout << "Нет учетных записей." << endl;
			return(-1);
		}
		else {
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
						*pas = _password[i];
						return(_type[i]);
					}
				cout << "Вы ввели неверный логин или пароль." << endl;
			} while (is_repeat_operation());
		}
		break;
	case 2:
		int counter = load_from_file();
		if (counter == 0) {
			cout << "Нет учетных записей." << endl;
			return(-1);
		}
		else {
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
						system("pause");
						break;
					}
					i++;
				}
				if (i == counter) break;
			}
			cout << "Введите пароль." << endl;
			rewind(stdin);
			getline(cin, password);
			password = sha1(password);
			if (load_in_file(login, password, 1))
			{
				*log = login;
				*pas = password;
				cout << "Вы успешно зарегестрировались." << endl;
				counter++;
				system("pause");
				return (0);
			}
			else cout << "Ошибка регистрации." << endl;
			system("pause");
		}
		break;
	case 3:
		return(-1);
	default: cout << "Вы ввели неизвестную опцию." << endl;
	}
}

int log_pas::load_from_file() {
	ifstream fin(file_log_pas, ios_base::in);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла." << endl;
		return(0);
	}
	else {
		int i = 0;
		string buffer = "";
		int buf;
		while (getline(fin, buffer, ',')) {
			log_pas::_login.push_back(buffer);
			getline(fin, buffer, ',');
			log_pas::_password.push_back(buffer);
			fin >> buf;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			log_pas::_type.push_back(buf);
			i++;
		}
		return (i);
		fin.close();
	}
}

bool log_pas::load_in_file(string login, string password, int type) {
	ofstream fout;
	fout.open(file_log_pas, ios_base::app);
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

void log_pas::change_pas() {
	string pas;
	cout << "Введите нынешний пароль." << endl;
	cin >> pas;
	pas = sha1(pas);
	if (pas == this->password)
	{
		cout << "Введите новый пароль." << endl;
		cin >> this->password;
		int counter = load_from_file();
		int i = 0;
		while (i < counter)
		{
			if (this->login == _login[i])
			{
				fstream fout;
				fout.open(file, ios_base::out);
				if (!fout.is_open())
				{
					cout << "Ошибка открытия файла." << endl;
				}
				else {
					this->password = sha1(this->password);
					_password[i] = this->password;
					for (register int i = 0; i < counter; i++) {
						if (i == counter - 1)
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
					remove(file_log_pas);
					char old_name[] = file, new_name[] = file_log_pas;
					fout.close();
					if (rename(old_name, new_name) == 0) {
						cout << "Вы успешно изменили пароль." << endl;
						system("pause");
						break;
					}
					else cout << "Ошибка в переименовании файлов." << endl;
				}
			}
			i++;
		}
		if (i == counter) cout << "Произошла ошибка в изменении пароля." << endl;
	}
	else {
		cout << "Вы ввели неверный пароль." << endl;
		if (is_repeat_operation()) return;
	}
}