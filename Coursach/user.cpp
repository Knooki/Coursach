#pragma once
#include "main.h"
#include "Classes.h"

//there aren't search

int user::menu_user() {
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Просмотр данных в виде табличной формы." << endl;
	cout << "2)Вывести на экран 3 предмета по которым больше всего отрицательных оценок." << endl;
	cout << "3)Поиск данных." << endl;
	cout << "4)Показ данных в отсортированном виде(файлы не меняются)." << endl;
	cout << "5)Смена пароля." << endl;
	cout << "6)Выход в меню первого уровня." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	return (sw);
}

void user::operation() {
	while (1) {
		system("cls");
		cout << "Меню простого пользователя." << endl;
		switch (menu_user()) {
		case 1:
			show_info();
			break;
		case 2:
		{
			accounting acc;
			acc.show_info_about_three();
		}
		break;
		case 3:
		{
		}
		break;
		case 4:
			show_sorted_info();
			break;
		case 5:
		{
			entrance us(login);
			if (!us.change_pas(login))
				return;
		}
		break;
		case 6:
			return;
		}
	}
}