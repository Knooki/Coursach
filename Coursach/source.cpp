#include "main.h"
#include "Classes.h"

bool check_date(string str) {
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

bool is_repeat_operation() {
	cout << "Чтобы продолжить нажмите любую клавишу." << endl;
	cout << "Чтобы вернуться нажмите esc." << endl;
	return(_getch() != 27);
}