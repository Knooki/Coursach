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
	do {
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
			search_info(*group);
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
	} while (is_repeat_operation());
}

void user::show_info(wstring type) {
	system("cls");
	wcout << L"Выбериет опцию:" << endl;
	wcout << L"1)Просмотр данных о студентах." << endl;
	wcout << L"2)Просмотр данных о предметах." << endl;
	wcout << L"3)Просмотр данных об успеваемости студентов." << endl;
	wcout << L"4)Выход." << endl;
	switch (input_check()) {
	case 1:
	{
		student st;
		st.show_info_stud(type, L"non_sorted");
	}
	break;
	case 2:
	{
		subject sub;
		sub.show_info_subj(L"non_sorted");
	}
	break;
	case 3:
	{
		accounting acc;
		acc.show_info(type, L"non_sorted");
	}
	break;
	case 4: return;
	default:
		error_message(L"Вы ввели неизвестную опцию.");
		break;
	}
}

void user::show_sorted_info(wstring type) {
	system("cls");
	wcout << L"Выбериет опцию:" << endl;
	wcout << L"1)Сортировка и просмотр данных о студентах." << endl;
	wcout << L"2)Сортировка и просмотр данных о предметах." << endl;
	wcout << L"3)Сортировка и просмотр об успеваемости студентов." << endl;
	wcout << L"4)Выход." << endl;
	switch (input_check()) {
	case 1:
	{
		student st;
		st.show_info_stud(type, L"sorted");
	}
	break;
	case 2:
	{
		subject sub;
		sub.show_info_subj(L"sorted");
	}
	break;
	case 3:
	{
		accounting acc;
		acc.show_info(type, L"sorted");
	}
	break;
	case 4: return;
	default:
		error_message(L"Вы ввели неизвестную опцию.");
		break;
	}
}

void user::search_info(wstring group) {
	system("cls");
	wcout << L"Выберите опцию" << endl;
	wcout << L"1)Поиск студентов" << endl;
	wcout << L"2)Поиск предметов" << endl;
	wcout << L"3)Поиск данных учета" << endl;
	wcout << L"4)Выход" << endl;
	switch (input_check()) {
	case 1: {
		student st;
		st.search_student(group);
	}
		  break;
	case 2:
	{
		subject sub;
		sub.search_subject();
	}
	break;
	case 3:
	{
		accounting acc;
		acc.search_info(group);
	}
	break;
	default:
		error_message(L"Вы ввели неизвестную опцию");
	}
}