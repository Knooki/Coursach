#pragma once
#include "main.h"
#include "Classes.h"

int user::menu_user() {
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)�������� ���� ������ � ���� ��������� �����." << endl;
	cout << "2)������� �� ����� 3 �������� �� ������� � ��� ������ ����� ������������� ������." << endl;
	cout << "3)����� ������." << endl;
	cout << "4)����� ������." << endl;
	cout << "5)����� � ���� ������� ������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
	}
	return (sw);
}

void user::operation() {
	cout << "�� ������� ����� ��� ������� �������� ������������." << endl;
	switch (menu_user()) {
	case 1:
	{
	}
	break;
	case 2:
	{
	}
	break;
	case 3:
	{
	}
	break;
	case 4:
	{
		entrance us(login);
		us.change_pas(login);
	}
	break;
	case 5:
		return;
	}
}