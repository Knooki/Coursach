#include "main.h"

void show_data() {
}

void search() {
}

bool is_repeat_operation() {
	cout << "����� ���������� ������� ����� �������." << endl;
	cout << "����� ��������� ������� esc." << endl;
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