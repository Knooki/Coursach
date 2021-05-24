#include "main.h"
#include "Classes.h"

int input_check() {
	int sw;
	while (!(wcin >> sw) || wcin.peek() != L'\n') {
		wcin.clear();
		wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
		error_message(L"�� ������ ������ ������ �����");
	}
	return sw;
}

void show_info(wstring type) {
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

void show_sorted_info(wstring type) {
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
	system("pause");
}

int switch_sort() {
	system("cls");
	wcout << L"�������� �����:" << endl;
	wcout << L"1)� ���������� �������//�� ������������." << endl;
	wcout << L"2)�� � ���������� �������//�� ��������." << endl;
	wcout << L"3)�����." << endl;
	return input_check();
}

void search_info(wstring group) {
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
	system("pause");
}

void error_message(wstring message) {
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	wcout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void complete_message(wstring message) {
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	wcout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

bool check_date(wstring str, wstring type) {
	if (str.size() != 10) {
		error_message(L"���� ����� ���� ������ 10 ��������.");
		return false;
	}
	if (str[2] != L'.' || str[5] != L'.')
	{
		error_message(L"�������� ������ ����.");
		return false;
	}
	for (register int i = 0; i < 10; i++)
		if (!isdigit(str[i]) && str[i] != L'.')
		{
			error_message(L"� ���� ����� ���� ������ ����� � �����.");
			return false;
		}
	wstring date, month, year;
	date = str.substr(0, 2);
	month = str.substr(3, 2);
	year = str.substr(6, 4);
	int da, mo, ye;
	da = stoi(date);
	mo = stoi(month);
	ye = stoi(year);
	int flag = 0;
	time_t now = time(0);
	struct tm local;
	localtime_s(&local, &now);
	while (1) {
		if (ye < 1950) {
			error_message(L"��� �� ����� ���� ������ ������ ��� 1950");
			flag++;
			break;
		}
		if (type == L"stud")
			if (ye > local.tm_year + 1900 - 15)
			{
				error_message(L"������� �� ����� ���� ��������� �����.");
				flag++;
				break;
			}
		if (mo > 12 || mo == 0) {
			error_message(L"�������� ���������� �������.");
			flag++;
			break;
		}
		if (da > 31 || da == 0) {
			error_message(L"�������� ���������� ����.");
			flag++;
			break;
		}
		if (ye > local.tm_year + 1900)
		{
			error_message(L"��� ���� ��� �� ���������.");
			flag++;
			break;
		}
		if (ye == local.tm_year + 1900)
			if (mo > local.tm_mon + 1)
			{
				error_message(L"��� ���� ��� �� ���������.");
				flag++;
				break;
			}
		if (ye == local.tm_year + 1900)
			if (mo == local.tm_mon + 1)
				if (da > local.tm_mday)
				{
					error_message(L"��� ���� ��� �� ���������.");
					flag++;
					break;
				}
		if (ye % 4 == 0)
			if (mo == 2)
				if (da > 29 || da == 0)
				{
					error_message(L"� ���������� ��� � ������� �������� 29 �����.");
					flag++;
					break;
				}
		if (ye % 4 != 0)
			if (mo == 2)
				if (da > 28 || da == 0)
				{
					error_message(L"� �� ���������� ��� � ������� �������� 28 �����.");
					flag++;
					break;
				}
		if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
			if (da > 30) {
				error_message(L"�������� ���������� ����. � ���� ������ �������� 30 ����.");
				flag++;
				break;
			}
		break;
	}
	if (flag == 0) return true;
	else return false;
}

bool check_date(wstring str, int number_of_semester, int course_of_stud) {
	if (check_date(str, L"sub")) {
		wstring month, year;
		month = str.substr(3, 2);
		year = str.substr(6, 4);
		int mo, ye;
		mo = stoi(month);
		ye = stoi(year);
		time_t now = time(0);
		struct tm local;
		localtime_s(&local, &now);
		int possible_year;
		int current_semester = 0;
		if (local.tm_mon + 1 > 8)
			current_semester = 1;//������ ���
		else if (local.tm_mon + 1 < 7)
			current_semester = 0;//������ ���
		else
			current_semester = -1; //��������
		possible_year = (local.tm_year + 1900) - course_of_stud + ceil((float)number_of_semester / 2) + current_semester;
		if (ye != possible_year)
		{
			error_message(L"��������� ������� ������� �����, �� ��� ������� ������� ������� �������� � ��������� ���� ����.");
			return (false);
		}
		if (number_of_semester % 2 == 1)
		{
			if (mo != 1)
			{
				error_message(L"������ � �������� ��������� �������� � ������(01).");
				return false;
			}
		}
		else
			if (mo != 6)
			{
				error_message(L"������ � ������ ��������� �������� � ����(06).");
				return false;
			}
		return true;
	}
	else return false;
}

bool is_russian_alpha(wchar_t c) {
	return (c >= L'�' && c <= L'�' || c == L' ' || c == L'�' || c == L'�');
}

bool is_repeat_operation() {
	wcout << L"����� ���������� � ���� 2-�� ������ ������� ����� �������." << endl;
	wcout << L"����� ��������� � ���� ������� ������ ������� esc." << endl;
	return(_getch() != 27);
}