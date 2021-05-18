#pragma once
#include "main.h"
#include "Classes.h"

int user::menu_user() {
	wcout << L"�������� �����:" << endl;
	wcout << L"1)�������� ������ � ������ ������ � ���� ��������� �����." << endl;
	wcout << L"2)������� �� ����� 3 �������� �� ������� ������ ����� ������������� ������." << endl;
	wcout << L"3)����� ������ �� ������ ������." << endl;
	wcout << L"4)����� ������ � ������ ������ � ��������������� ����(����� �� ��������)." << endl;
	wcout << L"5)����� ������." << endl;
	wcout << L"6)����� � ���� ������� ������." << endl;
	return (input_check());
}

void user::operation() {
	while (1) {
		system("cls");
		wcout << L"���� �������� ������������." << endl;
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
			error_message(L"�� ����� �������������� �����.");
			break;
		}
		system("pause");
	}
}