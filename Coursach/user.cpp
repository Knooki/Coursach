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
	do {
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
			search_info(*group);
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
	} while (is_repeat_operation());
}

void user::show_info(wstring type) {
	system("cls");
	wcout << L"�������� �����:" << endl;
	wcout << L"1)�������� ������ � ���������." << endl;
	wcout << L"2)�������� ������ � ���������." << endl;
	wcout << L"3)�������� ������ �� ������������ ���������." << endl;
	wcout << L"4)�����." << endl;
	switch (input_check()) {
	case 1:
	{
		student st;
		st.show_info_stud(type, L"non_sorted");
	}
	break;
	case 2:
	{
		subject sub;
		sub.show_info_subj(L"non_sorted");
	}
	break;
	case 3:
	{
		accounting acc;
		acc.show_info(type, L"non_sorted");
	}
	break;
	case 4: return;
	default:
		error_message(L"�� ����� ����������� �����.");
		break;
	}
}

void user::show_sorted_info(wstring type) {
	system("cls");
	wcout << L"�������� �����:" << endl;
	wcout << L"1)���������� � �������� ������ � ���������." << endl;
	wcout << L"2)���������� � �������� ������ � ���������." << endl;
	wcout << L"3)���������� � �������� �� ������������ ���������." << endl;
	wcout << L"4)�����." << endl;
	switch (input_check()) {
	case 1:
	{
		student st;
		st.show_info_stud(type, L"sorted");
	}
	break;
	case 2:
	{
		subject sub;
		sub.show_info_subj(L"sorted");
	}
	break;
	case 3:
	{
		accounting acc;
		acc.show_info(type, L"sorted");
	}
	break;
	case 4: return;
	default:
		error_message(L"�� ����� ����������� �����.");
		break;
	}
}

void user::search_info(wstring group) {
	system("cls");
	wcout << L"�������� �����" << endl;
	wcout << L"1)����� ���������" << endl;
	wcout << L"2)����� ���������" << endl;
	wcout << L"3)����� ������ �����" << endl;
	wcout << L"4)�����" << endl;
	switch (input_check()) {
	case 1: {
		student st;
		st.search_student(group);
	}
		  break;
	case 2:
	{
		subject sub;
		sub.search_subject();
	}
	break;
	case 3:
	{
		accounting acc;
		acc.search_info(group);
	}
	break;
	default:
		error_message(L"�� ����� ����������� �����");
	}
}