#pragma once
#include "main.h"
#include "Classes.h"

int user::menu_user() {
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Просмотр всех данных в виде табличной формы." << endl;
	cout << "2)Вывести на экран 3 предмета по которым у вас больше всего отрицательных оценок." << endl;
	cout << "3)Поиск данных." << endl;
	cout << "4)Смена пароля." << endl;
	cout << "5)Выход в меню первого уровня." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	return (sw);
}

void user::operation() {
	cout << "Вы успешно вошли под правами простого пользователя." << endl;
	switch (menu_user()) {
	case 1:
	{
		admin us;
		us.show_info();
	}
	break;
	case 2:
	{
		admin us;
		us.three_subjects();
	}
	break;
	case 3:
	{
		admin us;
		us.search();
	}
	break;
	case 4:
	{
		entrance us;
		us.change_pas(login, password);
	}
	break;
	case 5:
		return;
	}
}