#include "main.h"
#include "Classes.h"

void show_info() {
	int sw;
	system("cls");
	cout << "�������� �����:" << endl;
	cout << "1)�������� ������ � ���������." << endl;
	cout << "2)�������� ������ � ���������." << endl;
	cout << "3)�������� ������ �� ������������ ���������." << endl;
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
		st.show_info_stud("non_sorted");
	}
	break;
	case 2:
	{
		subject sub;
		sub.show_info_subj("non_sorted");
	}
	break;
	case 3:
	{
		accounting acc;
		acc.show_info("non_sorted");
	}
	break;
	case 4: return;
	default:
		error_message("�� ����� ����������� �����.");
		system("pause");
		break;
	}
}

void show_sorted_info() {
	int sw;
	system("cls");
	cout << "�������� �����:" << endl;
	cout << "1)���������� � �������� ������ � ���������." << endl;
	cout << "2)���������� � �������� ������ � ���������." << endl;
	cout << "3)���������� � �������� �� ������������ ���������." << endl;
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
		st.show_info_stud("sorted");
	}
	break;
	case 2:
	{
		subject sub;
		sub.show_info_subj("sorted");
	}
	break;
	case 3:
	{
		accounting acc;
		acc.show_info("sorted");
	}
	break;
	case 4: return;
	default:
		error_message("�� ����� ����������� �����.");
		system("pause");
		break;
	}
}

int switch_sort() {
	int sw;
	system("cls");
	cout << "�������� �����:" << endl;
	cout << "1)� ���������� �������//�� ������������." << endl;
	cout << "2)�� � ���������� �������//�� ��������." << endl;
	cout << "3)�����." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("�� ������ ������ ������ �����.");
	}
	return sw;
}

void error_message(string message) {
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	cout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void complete_message(string message) {
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	cout << message << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

bool check_date(string str, string type) {
	if (str.size() != 10) {
		error_message("���� ����� ���� ������ 10 ��������.");
		return false;
	}
	if (str[2] != '.' || str[5] != '.')
	{
		error_message("�������� ������ ����.");
		return false;
	}
	for (register int i = 0; i < 10; i++)
		if (!isdigit(str[i]) && str[i] != '.')
		{
			error_message("� ���� ����� ���� ������ ����� � �����.");
			return false;
		}
	string date, month, year;
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
			error_message("��� �� ����� ���� ������ ������ ��� 1950");
			flag++;
			break;
		}
		if (type == "stud")
			if (ye > local.tm_year + 1900 - 15)
			{
				error_message("������� �� ����� ���� ��������� �����.");
				flag++;
				break;
			}
		if (mo > 12 || mo == 0) {
			error_message("�������� ���������� �������.");
			flag++;
			break;
		}
		if (da > 31 || da == 0) {
			error_message("�������� ���������� ����.");
			flag++;
			break;
		}
		if (ye > local.tm_year + 1900)
		{
			error_message("��� ���� ��� �� ���������.");
			flag++;
			break;
		}
		if (ye == local.tm_year + 1900)
			if (mo > local.tm_mon + 1)
			{
				error_message("��� ���� ��� �� ���������.");
				flag++;
				break;
			}
		if (ye == local.tm_year + 1900)
			if (mo == local.tm_mon + 1)
				if (da > local.tm_mday)
				{
					error_message("��� ���� ��� �� ���������.");
					flag++;
					break;
				}
		if (ye % 4 == 0)
			if (mo == 2)
				if (da > 29 || da == 0)
				{
					error_message("� ���������� ��� � ������� �������� 29 �����.");
					flag++;
					break;
				}
		if (ye % 4 != 0)
			if (mo == 2)
				if (da > 28 || da == 0)
				{
					error_message("� �� ���������� ��� � ������� �������� 28 �����.");
					flag++;
					break;
				}
		if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
			if (da > 30) {
				error_message("�������� ���������� ����. � ���� ������ �������� 30 ����.");
				flag++;
				break;
			}
		break;
	}
	if (flag == 0) return true;
	else return false;
}

bool check_date(string str, int number_of_semester, int course_of_stud) {
	if (check_date(str, "sub")) {
		string month, year;
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
			error_message("��������� ������� ������� �����, �� ��� ������� ������� ������� �������� � ��������� ���� ����.");
			return (false);
		}
		if (number_of_semester % 2 == 1)
		{
			if (mo != 1)
			{
				error_message("������ � �������� ��������� �������� � ������(01).");
				return false;
			}
		}
		else
			if (mo != 6)
			{
				error_message("������ � ������ ��������� �������� � ����(06).");
				return false;
			}
		return true;
	}
	else return false;
}

bool is_russian_alpha(char c) {
	return (c >= '�' && c <= '�' || c == ' ' || c == '�' || c == '�');
}

bool is_repeat_operation() {
	cout << "����� ���������� ������� ����� �������." << endl;
	cout << "����� ��������� � ���� ������ ���� ������� esc." << endl;
	return(_getch() != 27);
}