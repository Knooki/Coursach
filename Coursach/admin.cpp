#pragma once
#include "main.h"
#include "Classes.h"

int admin::menu_admin() {
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)���������� ������." << endl;
	cout << "2)�������������� ������." << endl;
	cout << "3)�������� ������." << endl;
	cout << "4)�������� ������ � ��������� �����." << endl;
	cout << "5)����� ������." << endl;
	cout << "6)���������� ��������������." << endl;
	cout << "7)��������� ������." << endl;
	cout << "8)����� � ���� 1-�� ������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
	}
	return(sw);
}

void admin::operation() {
	cout << "�� ������� ����� ��� ������� ������." << endl;
	switch (menu_admin()) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
	{
		entrance ad(login);
		ad.change_pas(login);
	}
	break;
	case 8:
		return;
	default: cout << "�� ����� �������������� �����." << endl;
	}
}

void admin::add_data() {
}

void admin::change_data() {
}

void admin::delete_data() {
}

void admin::user_manage() {
}