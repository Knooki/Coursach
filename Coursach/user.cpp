#include "main.h"
#include "user.h"

int user::menu_user() {
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)�������� ���� ������ � ���� ��������� �����." << endl;
	cout << "2)������� �� ����� 3 �������� �� ������� � ��� ������ ����� ������������� ������." << endl;
	cout << "3)����� ������." << endl;
	cout << "4)����� � ���� ������� ������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
	}
	return (sw);
}

void user::show_information() {
}