#include "main.h"
#include "Classes.h"

void subject::save_to_file(subject new_subj) {
	wfstream fout(file_subject, ios_base::app);
	fout.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fout.is_open())
		error_message(L"Ошибка открытия файла");
	else {
		fout << new_subj.code_of_subject << L','
			<< new_subj.name << L','
			<< new_subj.teacher_name << L','
			<< new_subj.hours << L','
			<< new_subj.number_of_semester << endl;
	}
	fout.close();
}

void subject::change_data_in_file(vector<subject> array, wstring type_sort) {
	wfstream fout(file, ios_base::out);
	fout.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fout.is_open())
		error_message(L"Ошибка открытия файла.");
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].code_of_subject << L','
				<< array[i].name << L','
				<< array[i].teacher_name << L','
				<< array[i].hours << L','
				<< array[i].number_of_semester << endl;
		}
		remove(file_subject);
		char old_name[] = file, new_name[] = file_subject;
		fout.close();
		if (rename(old_name, new_name) != 0)
			error_message(L"Ошибка в переименовании файлов.");
		else if (type_sort == L"sort")
			complete_message(L"Вы успешно отсортировали данные.");
		else
			complete_message(L"Вы успешно удалили запись.");
	}
}

vector<subject> subject::load_from_file() {
	vector <subject> array;
	wifstream fin(file_subject);
	fin.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fin.is_open())
	{
		error_message(L"Нет информации о предметах.");
	}
	else {
		struct subject buffer;
		int i = 0;
		while (fin >> buffer.code_of_subject) {
			fin.ignore(1);
			getline(fin, buffer.name, L',');
			getline(fin, buffer.teacher_name, L',');
			fin >> buffer.hours;
			fin.ignore(1);
			fin >> buffer.number_of_semester;
			fin.ignore(numeric_limits<streamsize>::max(), L'\n');
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

vector<subject> subject::sort_array(vector<subject> arr) {
	system("cls");
	wcout << L"Выберите опцию:" << endl;
	wcout << L"1)Отсортировать по названию предмета." << endl;
	wcout << L"2)Отсортировать ФИО преподавателя." << endl;
	wcout << L"3)Отсортировать по количеству часов." << endl;
	wcout << L"4)Отсортировать по семестру." << endl;
	wcout << L"5)Выход." << endl;
	subject temp;
	switch (input_check()) {
	case 1:
		if (switch_sort() == 1)
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].name > arr[j + 1].name) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].name < arr[j + 1].name) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		return (arr);
	case 2:
		if (switch_sort() == 1)
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].teacher_name > arr[j + 1].teacher_name) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].teacher_name < arr[j + 1].teacher_name) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		return (arr);
	case 3:
		if (switch_sort() == 1)
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].hours > arr[j + 1].hours) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].hours < arr[j + 1].hours) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		return (arr);
	case 4:
		if (switch_sort() == 1)
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].number_of_semester > arr[j + 1].number_of_semester) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].number_of_semester < arr[j + 1].number_of_semester) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		return (arr);
	case 5:
		return (arr);
	default:
		error_message(L"Вы ввели неизвестную опцию.");
		return(arr);
		break;
	}
}

void subject::show_info_subj(wstring sort_type) {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		if (sort_type == L"sorted") array = sort_array(array);
		wcout << L"Информация о предметах." << endl;
		print(array);
	}
	else error_message(L"Нет данных о предметах.");
}

void subject::search_subject() {
	vector<subject> array;
	array = load_from_file();
	int buffer;
	wstring string_buffer;
	vector<subject> array_to_show;
	if (array.size() != 0) {
		buffer = search_menu();
		switch (buffer) {
		case 1:
			wcout << L"Введите искомый код предмета" << endl;
			while (!(wcin >> buffer) || wcin.peek() != L'\n' || buffer < 0) {
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
				if (buffer < 0) error_message(L"Код предмета не может быть отрицательным.");
				else
					error_message(L"Вы можете ввести только цифры.");
			}
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code_of_subject)
					array_to_show.push_back(array[i]);
			break;
		case 2:
			wcout << L"Введите искомое название предмета" << endl;
			while (1) {
				buffer = 1;
				rewind(stdin);
				getline(wcin, string_buffer, L'\n');
				if (string_buffer.size() > 20)
				{
					error_message(L"Название предмета не должно превышать 20 символов.");
					continue;
				}
				for (register int i = 0; i < string_buffer.size(); i++)
					if (!is_russian_alpha(string_buffer[i])) {
						error_message(L"Пожaлуйста, используйте только русские буквы.");
						buffer = -1;
						break;
					}
				if (buffer == -1)
					continue;
				for (register int i = 0; i < array.size(); i++)
					if (string_buffer == array[i].name)
						array_to_show.push_back(array[i]);
				break;
			}
			break;
		case 3:
			wcout << L"Введите искомое имя учителя." << endl;
			while (1) {
				buffer = 1;
				rewind(stdin);
				getline(wcin, string_buffer, L'\n');
				if (string_buffer.size() > 20)
				{
					error_message(L"Имя учителя не должно превышать 20 символов.");
					continue;
				}
				for (register int i = 0; i < string_buffer.size(); i++)
					if (!is_russian_alpha(string_buffer[i]) && string_buffer[i] != L'.') {
						error_message(L"Пожaлуйста, используйте только русские буквы.");
						buffer = -1;
						break;
					}
				if (buffer == -1)
					continue;
				for (register int i = 0; i < array.size(); i++)
				{
					if (string_buffer == array[i].teacher_name)
						array_to_show.push_back(array[i]);
				}
				break;
			}
			break;
		case 4:
			wcout << L"Введите искомый номер семестра." << endl;
			while (!(wcin >> buffer) || wcin.peek() != L'\n' || buffer > 8 || buffer < 1) {
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
				if (buffer > 8 || buffer < 1)
					error_message(L"Номер семестра может быть от 1 до 8");
				else
					error_message(L"Вы можете ввести только цифры");
			}
			for (register int i = 0; i < array.size(); i++)
			{
				if (buffer == array[i].get_number_of_semester())
					array_to_show.push_back(array[i]);
			}
			break;
		default: error_message(L"Вы ввели неизвестную опцию");
			break;
		}
		if (array_to_show.size() == 0) {
			error_message(L"Нет предметов с искомыми данными");
			return;
		}
		print(array_to_show);
	}
	else error_message(L"Нет данных о студентах.");
}

int subject::search_menu() {
	wcout << L"Выберите опцию." << endl;
	wcout << L"1)Поиск по коду предмета" << endl;
	wcout << L"2)Поиск по названию предмета" << endl;
	wcout << L"3)Поиск по имени учителя" << endl;
	wcout << L"4)Поиск по номеру семестра" << endl;
	return(input_check());
}

void subject::add_subj() {
	int flag = 0;
	while (flag == 0) {
		system("cls");
		vector<subject> array = load_from_file();
		subject buffer;
		wcout << L"Введите новые данные по предмету." << endl;
		wcout << L"Код предмета" << endl;
		while (1) {
			while (!(wcin >> buffer.code_of_subject) || wcin.peek() != L'\n' || buffer.code_of_subject < 0) {
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
				if (buffer.code_of_subject < 0) error_message(L"Код предмета не может быть отрицательным.");
				else
					error_message(L"Вы можете ввести только цифры.");
			}
			for (register int i = 0; i < array.size(); i++)
				if (buffer.code_of_subject == array[i].code_of_subject) {
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				error_message(L"Такой код предмета уже введен.");
				system("pause");
				continue;
			}
			break;
		}
		wcout << L"Название предмета:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(wcin, buffer.name, L'\n');
			for (register int i = 0; i < buffer.name.size(); i++)
				if (!is_russian_alpha(buffer.name[i])) {
					error_message(L"Пожaлуйста, используйте только русские буквы.");
					flag = -1;
					break;
				}
			if (flag == -1)
				continue;
			break;
		}
		wcout << L"ФИО преподавателя:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(wcin, buffer.teacher_name, L'\n');
			for (register int i = 0; i < buffer.teacher_name.size(); i++)
				if (!is_russian_alpha(buffer.teacher_name[i]) && buffer.teacher_name[i] != L'.') {
					error_message(L"Пожaлуйста, используйте только русские буквы.");
					flag = -1;
					break;
				}
			if (flag == -1)
				continue;
			break;
		}
		wcout << L"Количество часов:" << endl;
		while (!(wcin >> buffer.hours) || wcin.peek() != L'\n' || buffer.hours < 2 || buffer.hours % 2 != 0)
		{
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
			if (buffer.hours < 2 || buffer.hours % 2 != 0) error_message(L"Количество часов не может быть отрицательным или не кратным 2.");
			else
				error_message(L"Вы можете ввести только цифры.");
		}

		wcout << L"Какой по счету семестр:" << endl;
		while (!(wcin >> buffer.number_of_semester) || wcin.peek() != L'\n' || buffer.number_of_semester > 8 || buffer.number_of_semester < 1)
		{
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
			if (buffer.number_of_semester > 8 || buffer.number_of_semester < 1) error_message(L"Всего может быть только 8 семестров.");
			else error_message(L"Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.name == array[i].name)
				if (buffer.number_of_semester == array[i].number_of_semester)
				{
					error_message(L"Этот предмет уже записан. Не совпадают семестры.");
					flag = 0;
					continue;
				}
		save_to_file(buffer);
		flag = 1;
	}
}

void subject::change_subj() {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		show_info_subj(L"non_sorted");
		int buffer;
		int flag = 1;
		wcout << L"Введите код предмета, который хотите поменять." << endl;
		buffer = input_check();
		for (register int i = 0; i < array.size(); i++)
			if (buffer == array[i].code_of_subject) {
				buffer = i;
				flag = 0;
				break;
			}
		if (flag == 0) {
			subject buf;
			while (1) {
				wcout << L"Введите новые данные по предмету." << endl;
				wcout << L"Код предмета" << endl;
				while (1) {
					while (!(wcin >> buf.code_of_subject) || wcin.peek() != L'\n' || buf.code_of_subject < 0) {
						wcin.clear();
						wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
						if (buf.code_of_subject < 0) error_message(L"Код предмета не может быть отрицательным.");
						else
							error_message(L"Вы можете ввести только цифры.");
					}
					for (register int i = 0; i < array.size(); i++)
					{
						if (buf.code_of_subject == array[buffer].code_of_subject) break;
						if (buf.code_of_subject == array[i].code_of_subject) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						flag = 0;
						error_message(L"Такой код предмета уже введен.");
						continue;
					}
					break;
				}
				wcout << L"Название предмета:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(wcin, buf.name, L'\n');
					for (register int i = 0; i < buf.name.size(); i++)
						if (!is_russian_alpha(buf.name[i])) {
							error_message(L"Пожaлуйста, используйте только русские буквы.");
							flag = 1;
							break;
						}
					if (flag == 1) {
						flag = 0;
						continue;
					}
					break;
				}
				wcout << L"ФИО преподавателя:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(wcin, buf.teacher_name, L'\n');
					for (register int i = 0; i < buf.teacher_name.size(); i++)
						if (!is_russian_alpha(buf.teacher_name[i])) {
							error_message(L"Пожaлуйста, используйте только русские буквы.");
							flag = 1;
							break;
						}
					if (flag == 1) {
						flag = 0;
						continue;
					}
					break;
				}
				wcout << L"Количество часов:" << endl;
				while (!(wcin >> buf.hours) || wcin.peek() != L'\n' || buf.hours < 2 || buf.hours % 2 != 0)
				{
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buf.hours < 2 || buf.hours % 2 != 0) error_message(L"Количество часов не может быть отрицательным или не кратным 2.");
					else
						error_message(L"Вы можете ввести только цифры.");
				}
				wcout << L"Какой по счету семестр:" << endl;
				while (!(wcin >> buf.number_of_semester) || wcin.peek() != L'\n' || buf.number_of_semester > 8 || buf.number_of_semester < 1)
				{
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buf.number_of_semester > 8 || buf.number_of_semester < 1) error_message(L"Всего может быть только 8 семестров.");
					else error_message(L"Вы можете ввести только цифры.");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.name == array[i].name)
						if (buf.number_of_semester == array[i].number_of_semester)
						{
							error_message(L"Этот предмет уже записан. Не совпадает семестр.");
							flag = 0;
							break;
						}
				if (flag == 0)
					continue;
				array[buffer] = buf;
				change_data_in_file(array, L"non_sort");
				break;
			}
		}
		else error_message(L"Вы ввели неизвестный код предмета.");
	}
	else error_message(L"Нет информации по предметам.");
}

void subject::delete_subj_or_sort_subj(wstring type) {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		int flag = 0;
		if (type == L"sort") array = sort_array(array);
		else {
			show_info_subj(L"non_sorted");
			int buffer;
			wcout << L"Введите код предмета, который хотите удалить." << endl;
			buffer = input_check();
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code_of_subject) {
					array.erase(array.begin() + i);
					flag = 1;
					accounting account;
					vector<accounting> acc;
					acc = account.load_from_file();
					for (register int j = 0; j < acc.size(); j++)
						if (buffer == acc[i].get_code_of_subject())
							acc.erase(acc.begin() + j);
					wcout << L"Так как вы удалили данные о предмете, весь учет этого предмета тоже удален." << endl;
					account.change_data_in_file(acc, L"delete");
					break;
				}
			if (flag == 0) {
				flag = -1;
				error_message(L"Вы ввели неизвестный код предмета.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
	}
	else error_message(L"Нет информации по предметам.");
}

void subject::print(vector<subject> array) {
	int max_size_name = 0, max_size_teacher_name = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array.at(i).name.length() > max_size_name)
			max_size_name = array.at(i).name.size();
		if (array.at(i).teacher_name.length() > max_size_teacher_name)
			max_size_teacher_name = array.at(i).teacher_name.size();
	}
	int table_width = space_subjects + ((max_size_teacher_name > 18) ? max_size_teacher_name + 1 : 18) + (max_size_name > 18 ? max_size_name + 1 : 18);
	wcout << L"┌" << wstring(table_width, L'─') << L"┐" << endl;
	wcout << L"│";
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
	wcout << L"Код предмета " << setw(max_size_name > 18 ? max_size_name + 1 : 18) << left << L"Название предмета "
		<< setw(max_size_teacher_name > 18 ? max_size_teacher_name + 1 : 18) << L"ФИО Преподавателя "
		<< setw(6) << L"Часы"
		<< setw(7) << L"Семестр";
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	wcout << L"│" << endl;
	for (register int j = 0; j < array.size(); j++) {
		wcout << L"├" << wstring(table_width, L'─') << L"┤" << endl;
		wcout << L"│" << setw(13) << left << array[j].code_of_subject << setw(max_size_name > 18 ? max_size_name + 1 : 18) << left << array[j].name
			<< setw(max_size_teacher_name > 18 ? max_size_teacher_name + 1 : 18) << array[j].teacher_name
			<< setw(6) << array[j].hours
			<< setw(7) << array[j].number_of_semester << L"│" << endl;
	}
	wcout << L"└" << wstring(table_width, L'─') << L"┘" << endl;
}