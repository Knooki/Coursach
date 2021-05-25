﻿#pragma once
#include "main.h"
#include "Classes.h"

int admin::menu_admin() {
	wcout << L"Выберите опцию:" << endl;
	wcout << L"1)Добавление записи." << endl;
	wcout << L"2)Редактирование записи." << endl;
	wcout << L"3)Удаление записи." << endl;
	wcout << L"4)Отсортировать данные." << endl;
	wcout << L"5)Просмотр данных в табличной форме." << endl;
	wcout << L"6)Поиск данных." << endl;
	wcout << L"7)Показ данных в отсортированном виде(файлы не меняются)." << endl;
	wcout << L"8)Удалить пользователей из определенной группы." << endl;
	wcout << L"9)Изменение пароля." << endl;
	wcout << L"10)Выход в меню 1-го уровня." << endl;
	return(input_check());
}

void admin::operation() {
	do {
		system("cls");
		wcout << L"Меню админа." << endl;
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
			show_info(L"admin");
			break;
		case 6:
			search_info(L"admin");
			break;
		case 7:
			show_sorted_info(L"admin");
			break;
		case 8:
			break;
		case 9:
		{
			entrance ad;
			if (!ad.change_pas(login))
				return;
		}
		break;
		case 10:
			return;
		default: error_message(L"Вы ввели несуществующую опцию.");
		}
	} while (is_repeat_operation());
}

void admin::sort_data() {
	while (1) {
		system("cls");
		wcout << L"Выбериет опцию:" << endl;
		wcout << L"1)Сортировка данных о студентах." << endl;
		wcout << L"2)Сортировка данных о предметах." << endl;
		wcout << L"3)Сортировка об успеваемости студентов." << endl;
		wcout << L"4)Выход." << endl;
		switch (input_check()) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud(L"sort");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj(L"sort");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info(L"sort");
		}
		break;
		case 4: return;
		default:
			error_message(L"Вы ввели неизвестную опцию.");
			break;
		}
	}
}

void admin::add_data() {
	while (1) {
		system("cls");
		wcout << L"Выберите опцию." << endl;
		wcout << L"1)Добавить нового студента." << endl;
		wcout << L"2)Добавить новый предмет." << endl;
		wcout << L"3)Добавить новый учет о сдаче." << endl;
		wcout << L"4)Выход в меню админа." << endl;
		switch (input_check()) {
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
		default: error_message(L"Вы ввели неизвестную опцию.");
			break;
		}
	}
}

void admin::change_data() {
	while (1) {
		system("cls");
		wcout << L"Выберите опцию." << endl;
		wcout << L"1)Поменять данные о студентах." << endl;
		wcout << L"2)Поменять данные о предметах." << endl;
		wcout << L"3)Поменять данные об учете сдачи." << endl;
		wcout << L"4)Выход в меню админа." << endl;
		switch (input_check()) {
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
		default: error_message(L"Вы ввели неизвестную опцию.");
			break;
		}
	}
}

void admin::delete_data() {
	while (1) {
		system("cls");
		wcout << L"Выберите опцию." << endl;
		wcout << L"1)Удалить данные о студентах." << endl;
		wcout << L"2)Удалить данные о предметах." << endl;
		wcout << L"3)Удалить данные об учете сдачи." << endl;
		wcout << L"4)Выход в меню админа" << endl;
		switch (input_check()) {
		case 1:
		{
			student st;
			st.delete_stud_or_sort_stud(L"delete");
		}
		break;
		case 2:
		{
			subject sub;
			sub.delete_subj_or_sort_subj(L"delete");
		}
		break;
		case 3:
		{
			accounting acc;
			acc.delete_info_or_sort_info(L"delete");
		}
		break;
		case 4:
			return;
		default: error_message(L"Вы ввели неизвестную опцию.");
			break;
		}
	}
}

void admin::user_manage() {
	wstring string_buffer;
	rewind(stdin);
	wcout << "Введите группу" << endl;
	while (1) {
		int flag = 1;
		getline(wcin, string_buffer, L'\n');
		if (string_buffer.size() != 6)
		{
			error_message(L"Группа должна быть 6-тизначным числом.");
			continue;
		}
		for (register int i = 0; i < string_buffer.size(); i++) {
			if (!isdigit(string_buffer[i]))
			{
				error_message(L"В группе могут быть только цифры.");
				flag = -1;
				break;
			}
		}
		if (flag == -1)
			continue;
		entrance delete_users;
		delete_users.delete_users_with_group(string_buffer);
		break;
	}
}