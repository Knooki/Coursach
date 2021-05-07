#pragma once
#include "main.h"
#include "Classes.h"

// There aren't search and user_manage

int admin::menu_admin() {
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)���������� ������." << endl;
	cout << "2)�������������� ������." << endl;
	cout << "3)�������� ������." << endl;
	cout << "4)������������� ������." << endl;
	cout << "5)�������� ������ � ��������� �����." << endl;
	cout << "6)����� ������." << endl;
	cout << "7)����� ������ � ��������������� ����(����� �� ��������)." << endl;
	cout << "8)������� ������������� �� ������������ ������." << endl;
	cout << "9)��������� ������." << endl;
	cout << "10)����� � ���� 1-�� ������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("������. �� ������ ������ ������ �����.");
	}
	return(sw);
}

void admin::operation() {
	do {
		system("cls");
		cout << "���� ������." << endl;
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
			show_info("admin");
			break;
		case 6:
			search_info("admin");
			break;
		case 7:
			show_sorted_info("admin");
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
		default: error_message("�� ����� �������������� �����.");
		}
	} while (1);
}

void admin::sort_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "�������� �����:" << endl;
		cout << "1)���������� ������ � ���������." << endl;
		cout << "2)���������� ������ � ���������." << endl;
		cout << "3)���������� �� ������������ ���������." << endl;
		cout << "4)�����." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("�� ������ ������ ������ �����");
		}
		switch (sw) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud("sort");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj("sort");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info("sort");
		}
		break;
		case 4: return;
		default:
			error_message("�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::add_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "�������� �����." << endl;
		cout << "1)�������� ������ ��������." << endl;
		cout << "2)�������� ����� �������." << endl;
		cout << "3)�������� ����� ���� � �����." << endl;
		cout << "4)����� � ���� ������." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("������. �� ������ ������ ������ �����.");
		}
		switch (sw) {
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
		default: error_message("�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::change_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "�������� �����." << endl;
		cout << "1)�������� ������ � ���������." << endl;
		cout << "2)�������� ������ � ���������." << endl;
		cout << "3)�������� ������ �� ����� �����." << endl;
		cout << "4)����� � ���� ������." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("������. �� ������ ������ ������ �����.");
		}
		switch (sw) {
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
		default: error_message("�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::delete_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "�������� �����." << endl;
		cout << "1)������� ������ � ���������." << endl;
		cout << "2)������� ������ � ���������." << endl;
		cout << "3)������� ������ �� ����� �����." << endl;
		cout << "4)����� � ���� ������" << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("������. �� ������ ������ ������ �����.");
		}
		switch (sw) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud("delete");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj("delete");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info("delete");
		}
		break;
		case 4:
			return;
		default: error_message("�� ����� ����������� �����.");
			break;
		}
	}
}

void admin::user_manage() {
	string string_buffer;
	rewind(stdin);
	cout << "������� ������" << endl;
	while (1) {
		int flag = 1;
		getline(cin, string_buffer, '\n');
		if (string_buffer.size() != 6)
		{
			error_message("������ ������ ���� 6-��������� ������.");
			continue;
		}
		for (register int i = 0; i < string_buffer.size(); i++) {
			if (!isdigit(string_buffer[i]))
			{
				error_message("� ������ ����� ���� ������ �����.");
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