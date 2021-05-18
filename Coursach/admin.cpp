#pragma once
#include "main.h"
#include "Classes.h"

// There aren't search and user_manage

int admin::menu_admin() {
	int sw;
	wcout << L"�������� �����:" << endl;
	wcout << L"1)���������� ������." << endl;
	wcout << L"2)�������������� ������." << endl;
	wcout << L"3)�������� ������." << endl;
	wcout << L"4)������������� ������." << endl;
	wcout << L"5)�������� ������ � ��������� �����." << endl;
	wcout << L"6)����� ������." << endl;
	wcout << L"7)����� ������ � ��������������� ����(����� �� ��������)." << endl;
	wcout << L"8)������� ������������� �� ������������ ������." << endl;
	wcout << L"9)��������� ������." << endl;
	wcout << L"10)����� � ���� 1-�� ������." << endl;
	while (!(wcin >> sw) || wcin.peek() != L'\n') {
		wcin.clear();
		wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
		error_message(L"������. �� ������ ������ ������ �����.");
	}
	return(sw);
}

void admin::operation() {
	do {
		system("cls");
		wcout << L"���� ������." << endl;
		switch (menu_admin()) {
		case 1:
			add_data();
			break;
		case 2:
			change_data();
			break;
		case 3:
			delete_data();
			break;
		case 4:
			sort_data();
			break;
		case 5:
			show_info(L"admin");
			break;
		case 6:
			search_info(L"admin");
			break;
		case 7:
			show_sorted_info(L"admin");
			break;
		case 8:
			break;
		case 9:
		{
			entrance ad;
			if (!ad.change_pas(login))
				return;
		}
		break;
		case 10:
			return;
		default: error_message(L"�� ����� �������������� �����.");
		}
	} while (1);
}

void admin::sort_data() {
	while (1) {
		system("cls");
		wcout << L"�������� �����:" << endl;
		wcout << L"1)���������� ������ � ���������." << endl;
		wcout << L"2)���������� ������ � ���������." << endl;
		wcout << L"3)���������� �� ������������ ���������." << endl;
		wcout << L"4)�����." << endl;
		switch (input_check()) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud(L"sort");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj(L"sort");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info(L"sort");
		}
		break;
		case 4: return;
		default:
			error_message(L"�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::add_data() {
	while (1) {
		system("cls");
		wcout << L"�������� �����." << endl;
		wcout << L"1)�������� ������ ��������." << endl;
		wcout << L"2)�������� ����� �������." << endl;
		wcout << L"3)�������� ����� ���� � �����." << endl;
		wcout << L"4)����� � ���� ������." << endl;
		switch (input_check()) {
		case 1:
		{
			student st;
			st.add_stud();
		}
		break;
		case 2:
		{
			subject sub;
			sub.add_subj();
		}
		break;
		case 3:
		{
			accounting acc;
			acc.add_info();
		}
		break;
		case 4:
			return;
		default: error_message(L"�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::change_data() {
	while (1) {
		system("cls");
		wcout << L"�������� �����." << endl;
		wcout << L"1)�������� ������ � ���������." << endl;
		wcout << L"2)�������� ������ � ���������." << endl;
		wcout << L"3)�������� ������ �� ����� �����." << endl;
		wcout << L"4)����� � ���� ������." << endl;
		switch (input_check()) {
		case 1:
		{
			student st;
			st.change_stud();
		}
		break;
		case 2:
		{
			subject sub;
			sub.change_subj();
		}
		break;
		case 3:
		{
			accounting acc;
			acc.change_info();
		}
		break;
		case 4:
			return;
		default: error_message(L"�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::delete_data() {
	while (1) {
		system("cls");
		wcout << L"�������� �����." << endl;
		wcout << L"1)������� ������ � ���������." << endl;
		wcout << L"2)������� ������ � ���������." << endl;
		wcout << L"3)������� ������ �� ����� �����." << endl;
		wcout << L"4)����� � ���� ������" << endl;
		switch (input_check()) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud(L"delete");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj(L"delete");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info(L"delete");
		}
		break;
		case 4:
			return;
		default: error_message(L"�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::user_manage() {
	wstring string_buffer;
	rewind(stdin);
	wcout << "������� ������" << endl;
	while (1) {
		int flag = 1;
		getline(wcin, string_buffer, L'\n');
		if (string_buffer.size() != 6)
		{
			error_message(L"������ ������ ���� 6-��������� ������.");
			continue;
		}
		for (register int i = 0; i < string_buffer.size(); i++) {
			if (!isdigit(string_buffer[i]))
			{
				error_message(L"� ������ ����� ���� ������ �����.");
				flag = -1;
				break;
			}
		}
		if (flag == -1)
			continue;
		entrance delete_users;
		delete_users.delete_users_with_group(string_buffer);
		break;
	}
}