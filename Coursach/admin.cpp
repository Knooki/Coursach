#pragma once
#include "main.h"
#include "Classes.h"

// There aren't search and user_manage

int admin::menu_admin() {
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Добавление записи." << endl;
	cout << "2)Редактирование записи." << endl;
	cout << "3)Удаление записи." << endl;
	cout << "4)Отсортировать данные." << endl;
	cout << "5)Просмотр данных в табличной форме." << endl;
	cout << "6)Поиск данных." << endl;
	cout << "7)Показ данных в отсортированном виде(файлы не меняются)." << endl;
	cout << "8)Управление пользователями." << endl;
	cout << "9)Изменение пароля." << endl;
	cout << "10)Выход в меню 1-го уровня." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	return(sw);
}

void admin::operation() {
	do {
		system("cls");
		cout << "Меню админа." << endl;
		switch (menu_admin()) {
		case 1:
			add_data();
			break;
		case 2:
			change_data();
			break;
		case 3:
			delete_data();
			break;
		case 4:
			sort_data();
			break;
		case 5:
			show_info();
			break;
		case 6:
			break;
		case 7:
			show_sorted_info();
			break;
		case 8:
			break;
		case 9:
		{
			entrance ad(login);
			ad.change_pas(login);
		}
		break;
		case 10:
			return;
		default: cout << "Вы ввели несуществующую опцию." << endl;
		}
	} while (1);
}

void admin::sort_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "Выбериет опцию:" << endl;
		cout << "1)Сортировка данных о студентах." << endl;
		cout << "2)Сортировка данных о предметах." << endl;
		cout << "3)Сортировка об успеваемости студентов." << endl;
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
			st.delete_stud_or_sort_stud("sort");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj("sort");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info("sort");
		}
		break;
		case 4: return;
		default:
			cout << "Вы ввели неизвестную опцию." << endl;
			break;
		}
	}
}

void admin::add_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "Выберите опцию." << endl;
		cout << "1)Дабавить нового студента." << endl;
		cout << "2)Добавить новый предмет." << endl;
		cout << "3)Добавить новый учет о сдаче." << endl;
		cout << "4)Выход в меню админа." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка. Вы можете ввести только цифры." << endl;
		}
		switch (sw) {
		case 1:
		{
			student st;
			st.add_stud();
		}
		break;
		case 2:
		{
			subject sub;
			sub.add_subj();
		}
		break;
		case 3:
		{
			accounting acc;
			acc.add_info();
		}
		break;
		case 4:
			return;
		default: cout << "Вы ввели неизвестную опцию." << endl;
			break;
		}
	}
}

void admin::change_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "Выберите опцию." << endl;
		cout << "1)Поменять данные о студентах." << endl;
		cout << "2)Поменять данные о предметах." << endl;
		cout << "3)Поменять данные об учете сдачи." << endl;
		cout << "4)Выход в меню админа." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка. Вы можете ввести только цифры." << endl;
		}
		switch (sw) {
		case 1:
		{
			student st;
			st.change_stud();
		}
		break;
		case 2:
		{
			subject sub;
			sub.change_subj();
		}
		break;
		case 3:
		{
			accounting acc;
			acc.change_info();
		}
		break;
		case 4:
			return;
		default: cout << "Вы ввели неизвестную опцию." << endl;
			break;
		}
	}
}

void admin::delete_data() {
	int sw;
	while (1) {
		system("cls");
		cout << "Выберите опцию." << endl;
		cout << "1)Удалить данные о студентах." << endl;
		cout << "2)Удалить данные о предметах." << endl;
		cout << "3)Удалить данные об учете сдачи." << endl;
		cout << "4)Выход в меню админа" << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка. Вы можете ввести только цифры." << endl;
		}
		switch (sw) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud("delete");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj("delete");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info("delete");
		}
		break;
		case 4:
			return;
		default: cout << "Вы ввели неизвестную опцию." << endl;
			break;
		}
	}
}

void admin::user_manage() {
}