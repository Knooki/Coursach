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
	cout << "8)���������� ��������������." << endl;
	cout << "9)��������� ������." << endl;
	cout << "10)����� � ���� 1-�� ������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
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
			show_info();
			break;
		case 6:
			break;
		case 7:
			show_sorted_info();
			break;
		case 8:
			break;
		case 9:
		{
			entrance ad(login);
			ad.change_pas(login);
		}
		break;
		case 10:
			return;
		default: cout << "�� ����� �������������� �����." << endl;
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
			cout << "�� ������ ������ ������ �����" << endl;
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
			cout << "�� ����� ����������� �����." << endl;
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
			cout << "������. �� ������ ������ ������ �����." << endl;
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
		default: cout << "�� ����� ����������� �����." << endl;
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
			cout << "������. �� ������ ������ ������ �����." << endl;
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
		default: cout << "�� ����� ����������� �����." << endl;
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
			cout << "������. �� ������ ������ ������ �����." << endl;
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
		default: cout << "�� ����� ����������� �����." << endl;
			break;
		}
	}
}

void admin::user_manage() {
}