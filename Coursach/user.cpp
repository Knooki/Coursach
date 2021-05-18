#pragma once
#include "main.h"
#include "Classes.h"

int user::menu_user() {
	wcout << L"Выберите опцию:" << endl;
	wcout << L"1)Просмотр данных с вашего потока в виде табличной формы." << endl;
	wcout << L"2)Вывести на экран 3 предмета по которым больше всего отрицательных оценок." << endl;
	wcout << L"3)Поиск данных по вашему потоку." << endl;
	wcout << L"4)Показ данных с вашего потока в отсортированном виде(файлы не меняются)." << endl;
	wcout << L"5)Смена пароля." << endl;
	wcout << L"6)Выход в меню первого уровня." << endl;
	return (input_check());
}

void user::operation() {
	while (1) {
		system("cls");
		wcout << L"Меню простого пользователя." << endl;
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
			error_message(L"Вы ввели несуществующую опцию.");
			break;
		}
		system("pause");
	}
}