#include "main.h"
#include "entrance.h"

int log_pas::entr_menu() {
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
	int counter = load_from_file();
	switch (entr_menu()) {
	case 1:
		if (counter != 0) {
			do {
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
		else
			cout << "В базе еще нет учетных записей." << endl;
		break;
	case 2:
		while (1) {
			cout << "Введите логин." << endl;
			rewind(stdin);
			getline(cin, login);
			login = sha1(login);
			int i = 0;
			while (i < counter) {
				if (login == _login[i])
				{
					cout << "Этот логин уже занят." << endl;
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
			return (0);
		}
		else cout << "Ошибка регистрации." << endl;
		break;
	case 3:
		return(-1);
	default: cout << "Вы ввели неизвестную опцию." << endl;
	}
	return(-1);
}

int log_pas::load_from_file() {
	ifstream fin("file_log_pas.txt", ios_base::in);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла." << endl;
		return(0);
	}
	else {
		int i = 0;
		string buffer = "";
		int buf;
		while (getline(fin, buffer)) {
			log_pas::_login.push_back(buffer);
			getline(fin, buffer);
			log_pas::_password.push_back(buffer);
			fin >> buf;
			log_pas::_type.push_back(buf);
			i++;
		}
		return (i);
		fin.close();
	}
}

bool log_pas::load_in_file(string login, string password, int type) {
	ofstream fout;
	fout.open("file_log_pas.txt", ios_base::app);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла." << endl;
		return false;
	}
	else {
		fout << login << endl;
		fout << password << endl;
		fout << type << endl;
		fout.close();
		return true;
	}
}

void log_pas::change_pas() {
	int counter = load_from_file();
	for (register int i = 0; i < counter; i++)
		if (login == _login[i])
			if (new_pas(i + 1)) cout << "Пароль успешно изменен." << endl;
			else cout << "Произошла ошибка в изменении пароля." << endl;
}

bool log_pas::new_pas(int place) {
	ofstream fout;
	fout.open("file_log_pas.txt", ios_base::out);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
		return false;
	}
	else {
		for (int i = 1; i < place; i++) {
		}
		this->password = sha1(this->password);
		if (fout << this->password)
		{
			fout.close();
			return true;
		}
	}
}