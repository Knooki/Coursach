#pragma once
#include "main.h"
#include "Classes.h"

int user::menu_user() {
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Просмотр данных с вашего потока в виде табличной формы." << endl;
	cout << "2)Вывести на экран 3 предмета по которым больше всего отрицательных оценок." << endl;
	cout << "3)Поиск данных по вашему потоку." << endl;
	cout << "4)Показ данных с вашего потока в отсортированном виде(файлы не меняются)." << endl;
	cout << "5)Смена пароля." << endl;
	cout << "6)Выход в меню первого уровня." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("Ошибка. Вы можете ввести только цифры.");
	}
	return (sw);
}

void user::operation() {
	while (1) {
		system("cls");
		cout << "Меню простого пользователя." << endl;
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
		{
			search_info(*group);
		}
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
			error_message("Вы ввели несуществующую опцию.");
			break;
		}
		system("pause");
	}
}