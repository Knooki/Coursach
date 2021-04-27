#include "main.h"

bool is_repeat_operation() {
	cout << "Чтобы продолжить нажмите любую клавишу." << endl;
	cout << "Чтобы вернуться нажмите esc." << endl;
	return(_getch() != 27);
}
//int entering() {
//	int sw;
//	while (1) {
//		counter = counting_users();
//		login = new string[counter];
//		password = new string[counter];
//		priority = new int[counter];
//		load_log_pas();
//		cout << "Выберите опцию." << endl;
//		cout << "1)Вход.\n2)Регистрация\n3)Выход" << endl;
//		while (!(cin >> sw) || cin.peek() != '\n') {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "Ошибка. Вы можете ввести только цифры." << endl;
//		}
//		switch (sw) {
//		case 1:
//			if (counter != 0)
//				do {
//					for (int i = 0; i < counter; i++)
//						if (*(login + i) == _login && *(password + i) == _password && *(priority + i) >= 0)
//						{
//							cout << "Вы успешно вошли." << endl;
//							return (*(priority + i));
//						}
//						else
//							cout << "Вы ввели неправильный логин или пароль." << endl;
//				} while (is_operation());
//			else cout << "В системе пока еще нет учетных записей. Зарегистрируйтесь." << endl;
//			break;
//		case 2:
//			cout << "Введите новый логин и пароль." << endl;
//			do {
//				rewind(stdin);
//				getline(cin, _login);
//				i = 0;
//				while (i < counter)
//				{
//					if (*(login + i) == _login) {
//						cout << "Такое имя пользователя уже занято." << endl;
//						break;
//					}
//					i++;
//				}
//			} while (i != counter);
//			rewind(stdin);
//			getline(cin, _password);
//			if (add_log_pas(_login, _password, 1))
//				cout << "Регистрация прошла успешно." << endl;
//			break;
//		case 3: return(-1);
//		default: cout << "Вы ввели неверную опцию." << endl; break;
//		}
//	}
//}
