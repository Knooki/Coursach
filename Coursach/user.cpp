#pragma once
#include "main.h"
#include "Classes.h"

int user::menu_user() {
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)�������� ������ � ������ ������ � ���� ��������� �����." << endl;
	cout << "2)������� �� ����� 3 �������� �� ������� ������ ����� ������������� ������." << endl;
	cout << "3)����� ������ �� ������ ������." << endl;
	cout << "4)����� ������ � ������ ������ � ��������������� ����(����� �� ��������)." << endl;
	cout << "5)����� ������." << endl;
	cout << "6)����� � ���� ������� ������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("������. �� ������ ������ ������ �����.");
	}
	return (sw);
}

void user::operation() {
	while (1) {
		system("cls");
		cout << "���� �������� ������������." << endl;
		switch (menu_user()) {
		case 1:
			show_info(*group);
			break;
		case 2:
		{
			accounting acc;
			acc.show_info_about_three();
		}
		break;
		case 3:
		{
			search_info(*group);
		}
		break;
		case 4:
			show_sorted_info(*group);
			break;
		case 5:
		{
			entrance us;
			if (!us.change_pas(login))
				return;
		}
		break;
		case 6:
			return;
		default:
			error_message("�� ����� �������������� �����.");
			break;
		}
		system("pause");
	}
}