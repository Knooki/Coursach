#pragma once
#include "main.h"
#include "Classes.h"

int admin::menu_admin() {
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Добавление записи." << endl;
	cout << "2)Редактирование записи." << endl;
	cout << "3)Удаление записи." << endl;
	cout << "4)Просмотр данных в табличной форме." << endl;
	cout << "5)Поиск данных." << endl;
	cout << "6)Управление пользователями." << endl;
	cout << "7)Изменение пароля." << endl;
	cout << "8)Выход в меню 1-го уровня." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	return(sw);
}
void admin::operation() {
	cout << "Вы успешно вошли под правами админа." << endl;
	switch (menu_admin()) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
	{
		entrance ad;
		ad.change_pas(login, password);
	}
	break;
	case 8:
		return;
	default: cout << "Вы ввели несуществующую опцию." << endl;
	}
}
void admin::add_data() {
}
void admin::change_data() {
}
void admin::delete_data() {
}
void admin::user_manage() {
}
void admin::show_info() {
}
void admin::search() {
}
void admin::three_subjects() {
}
