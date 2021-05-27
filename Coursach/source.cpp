#include "main.h"
#include "Classes.h"

int input_check() {
	int sw;
	while (!(wcin >> sw) || wcin.peek() != L'\n') {
		wcin.clear();
		wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
		error_message(L"Вы можете ввести только цифры");
	}
	return sw;
}

int switch_sort() {
	system("cls");
	wcout << L"Выбериет опцию:" << endl;
	wcout << L"1)В алфавитном порядке//по возврастанию." << endl;
	wcout << L"2)Не в алфавитном порядке//по убыванию." << endl;
	wcout << L"3)Выход." << endl;
	return input_check();
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
		error_message(L"Дата дожна быть длиной 10 символов.");
		return false;
	}
	if (str[2] != L'.' || str[5] != L'.')
	{
		error_message(L"Неверный формат даты.");
		return false;
	}
	for (register int i = 0; i < 10; i++)
		if (!isdigit(str[i]) && str[i] != L'.')
		{
			error_message(L"В дате могут быть только цифры и точки.");
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
			error_message(L"Год не может быть введен раньше чем 1950");
			flag++;
			break;
		}
		if (type == L"stud")
			if (ye > local.tm_year + 1900 - 15)
			{
				error_message(L"Студент не может быть настолько молод.");
				flag++;
				break;
			}
		if (mo > 12 || mo == 0) {
			error_message(L"Неверное количество месяцев.");
			flag++;
			break;
		}
		if (da > 31 || da == 0) {
			error_message(L"Неверное количество дней.");
			flag++;
			break;
		}
		if (ye > local.tm_year + 1900)
		{
			error_message(L"Эта дата еще не наступила.");
			flag++;
			break;
		}
		if (ye == local.tm_year + 1900)
			if (mo > local.tm_mon + 1)
			{
				error_message(L"Эта дата еще не наступила.");
				flag++;
				break;
			}
		if (ye == local.tm_year + 1900)
			if (mo == local.tm_mon + 1)
				if (da > local.tm_mday)
				{
					error_message(L"Эта дата еще не наступила.");
					flag++;
					break;
				}
		if (ye % 4 == 0)
			if (mo == 2)
				if (da > 29 || da == 0)
				{
					error_message(L"В високосный год в феврале максимум 29 чисел.");
					flag++;
					break;
				}
		if (ye % 4 != 0)
			if (mo == 2)
				if (da > 28 || da == 0)
				{
					error_message(L"В не високосный год в феврале максимум 28 чисел.");
					flag++;
					break;
				}
		if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
			if (da > 30) {
				error_message(L"Неверное количество дней. В этом месяце максимум 30 дней.");
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
			current_semester = 1;//первый сем
		else if (local.tm_mon + 1 < 7)
			current_semester = 0;//второй сем
		else
			current_semester = -1; //каникулы
		possible_year = (local.tm_year + 1900) - course_of_stud + ceil((float)number_of_semester / 2) + current_semester;
		if (ye != possible_year)
		{
			error_message(L"Введенный студент данного курса, не мог сдавать предмет данного семестра в введенном вами году.");
			return (false);
		}
		if (number_of_semester % 2 == 1)
		{
			if (mo != 1)
			{
				error_message(L"Сессия в нечетных семестрах проходит в январе(01).");
				return false;
			}
		}
		else
			if (mo != 6)
			{
				error_message(L"Сессия в четных семестрах проходит в июне(06).");
				return false;
			}
		return true;
	}
	else return false;
}

bool is_russian_alpha(wchar_t c) {
	return (c >= L'А' && c <= L'я' || c == L' ' || c == L'Ё' || c == L'ё');
}

bool is_repeat_operation() {
	wcout << L"Чтобы продолжить в меню 2-го уровнянажмите любую клавишу." << endl;
	wcout << L"Чтобы вернуться в меню первого уровня нажмите esc." << endl;
	return(_getch() != 27);
}