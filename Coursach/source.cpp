#include "main.h"
#include "Classes.h"

void show_info() {
	int sw;
	cout << "Выбериет опцию:" << endl;
	cout << "1)Просмотр данных о студентах." << endl;
	cout << "2)Просмотр данных о предметах." << endl;
	cout << "3)Просмотр данных об успеваемости студентов." << endl;
	cout << "4)Выход." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы можете ввести только цифры" << endl;
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
		cout << "Вы ввели неизвестную опцию." << endl;
		break;
	}
}

void show_sorted_info() {
	int sw;
	cout << "Выбериет опцию:" << endl;
	cout << "1)Сортировка и просмотр данных о студентах." << endl;
	cout << "2)Сортировка и просмотр данных о предметах." << endl;
	cout << "3)Сортировка и просмотр об успеваемости студентов." << endl;
	cout << "4)Выход." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы можете ввести только цифры" << endl;
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
		cout << "Вы ввели неизвестную опцию." << endl;
		break;
	}
}

int switch_sort() {
	int sw;
	cout << "Выбериет опцию:" << endl;
	cout << "1)В алфавитном порядке//по возврастанию." << endl;
	cout << "2)Не в алфавитном порядке//по убыванию." << endl;
	cout << "3)Выход." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы можете ввести только цифры." << endl;
	}
	return sw;
}

bool check_date(string str, string type) {
	if (str.size() != 10) {
		cout << "Дата дожна быть длиной 10 символов." << endl;
		return false;
	}
	else {
		for (register int i = 0; i < 10; i++)
			if (!isdigit(str[i]) && str[i] != '.')
			{
				cout << "В дате могут быть только цифры и точки." << endl;
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
				cout << "Год не может быть введен раньше чем 1950" << endl;
				flag++;
				break;
			}
			if (type == "stud")
				if (ye > local.tm_year + 1900 - 15)
				{
					cout << "Студент не может быть настолько молод." << endl;
					flag++;
					break;
				}
			if (mo > 12 || mo == 0) {
				cout << "Неверное количество месяцев." << endl;
				flag++;
				break;
			}
			if (da > 31 || da == 0) {
				cout << "Неверное количество дней." << endl;
				flag++;
				break;
			}
			if (ye > local.tm_year + 1900)
			{
				cout << "Эта дата еще не наступила." << endl;
				flag++;
				break;
			}
			if (ye == local.tm_year + 1900)
				if (mo > local.tm_mon + 1)
				{
					cout << "Эта дата еще не наступила." << endl;
					flag++;
					break;
				}
			if (ye == local.tm_year + 1900)
				if (mo == local.tm_mon + 1)
					if (da > local.tm_mday)
					{
						cout << "Эта дата еще не наступила." << endl;
						flag++;
						break;
					}
			if (ye % 4 == 0)
				if (mo == 2)
					if (da > 29 || da == 0)
					{
						cout << "В високосный год в феврале максимум 29 чисел." << endl;
						flag++;
						break;
					}
			if (ye % 4 != 0)
				if (mo == 2)
					if (da > 28 || da == 0)
					{
						cout << "В не високосный год в феврале максимум 28 чисел." << endl;
						flag++;
						break;
					}
			if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
				if (da > 30) {
					cout << "Неверное количество дней. В этом месяце максимум 30 дней." << endl;
					flag++;
					break;
				}
			break;
		}
		if (flag == 0) return true;
		else return false;
	}
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
		int possible_year, possible_month;
		int current_semester = 0;
		if (local.tm_mon + 1 > 8)
			current_semester = 1;//первый сем
		else if (local.tm_mon + 1 < 7)
			current_semester = 0;//второй сем
		else
			current_semester = -1; //каникулы
		possible_year = (local.tm_year + 1900) + 1 - course_of_stud + number_of_semester / 2 + current_semester;
		if (ye != possible_year)
		{
			cout << "Введенный студент данного курса, не мог сдавать предмет данного семестра в введенном вами году." << endl;
			return (false);
		}
		if (number_of_semester % 2 == 1)
		{
			if (mo != 1)
			{
				cout << "Сессия в нечетных семестрах проходит в январе(01)." << endl;
				return false;
			}
		}
		else
			if (mo != 6)
			{
				cout << "Сессия в четных семестрах проходит в июне(06)." << endl;
				return false;
			}
		return true;
	}
	else return false;
}

bool is_russian_alpha(char c) {
	return (c >= 'А' && c <= 'я' || c == ' ' || c == 'Ё' || c == 'ё');
}

bool is_repeat_operation() {
	cout << "Чтобы продолжить нажмите любую клавишу." << endl;
	cout << "Чтобы вернуться в меню уровня ниже нажмите esc." << endl;
	return(_getch() != 27);
}