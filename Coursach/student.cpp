#include "main.h"
#include "Classes.h"

static wstring facult[10] = {
	L"ФДПиПО",
	L"ФКП",
	L"ФИТУ",
	L"ВФ",
	L"ФРЭ",
	L"ФКСиС",
	L"ФИК",
	L"ИЭФ",
	L"ИИТ",
	L"ФИНО"
};

void student::save_to_file(student new_stud) {
	wfstream fout;
	fout.open(file_student, ios_base::app);
	if (!fout.is_open())
		wcout << L"Ошибка открытия файла" << endl;
	else {
		fout << new_stud.code_of_student << L','
			<< new_stud.full_name << L','
			<< new_stud.birth_date << L','
			<< new_stud.speciality << L','
			<< new_stud.group << L','
			<< new_stud.faculty << L','
			<< new_stud.course << endl;
	}
	fout.close();
}

void student::change_data_in_file(vector<student> array, wstring type_sort) {
	wfstream fout;
	fout.open(file, ios_base::out);
	if (!fout.is_open())
		wcout << L"Ошибка открытия файла." << endl;
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].code_of_student << L','
				<< array[i].full_name << L','
				<< array[i].birth_date << L','
				<< array[i].speciality << L','
				<< array[i].group << L','
				<< array[i].faculty << L','
				<< array[i].course << endl;
		}
		remove(file_student);
		char old_name[] = file, new_name[] = file_student;
		fout.close();
		if (rename(old_name, new_name) != 0)
			error_message(L"Ошибка в переименовании файлов.");
		else if (type_sort == L"sort")
			complete_message(L"Вы успешно отсортировали данные.");
		else if (type_sort == L"delete")
			complete_message(L"Вы успешно удалили запись.");
		else
			complete_message(L"Вы успешно изменили запись");
	}
}

vector<student> student::load_from_file() {
	vector <student> array;
	wifstream fin;
	fin.open(file_student, ios_base::in);
	if (!fin.is_open())
	{
		wcout << L"Нет информации о предметах." << endl;
	}
	else {
		struct student buffer;
		int i = 0;
		while (fin >> buffer.code_of_student) {
			fin.ignore(1);
			getline(fin, buffer.full_name, L',');
			getline(fin, buffer.birth_date, L',');
			getline(fin, buffer.speciality, L',');
			getline(fin, buffer.group, L',');
			getline(fin, buffer.faculty, L',');
			fin >> buffer.course;
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

vector<student> student::sort_date(vector<student> array, int type) {
	wstring ye, mo, da;
	vector<int> amount_of_days;
	int temp;
	student tmp;
	for (register int i = 0; i < array.size(); i++)
	{
		da = array[i].birth_date.substr(0, 2);
		mo = array[i].birth_date.substr(3, 2);
		ye = array[i].birth_date.substr(6, 4);
		amount_of_days.push_back(stoi(ye) * 365 + stoi(mo) * 31 + stoi(da));
	}
	if (type == 1)
		for (register int i = 0; i < amount_of_days.size(); i++) {
			for (register int j = 0; j < amount_of_days.size() - i - 1; j++) {
				if (amount_of_days[j] > amount_of_days[j + 1]) {
					temp = amount_of_days[j];
					amount_of_days[j] = amount_of_days[j + 1];
					amount_of_days[j + 1] = temp;
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}
		}
	else
		for (register int i = 0; i < amount_of_days.size(); i++) {
			for (register int j = 0; j < amount_of_days.size() - i - 1; j++) {
				if (amount_of_days[j] < amount_of_days[j + 1]) {
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}
		}
	return(array);
}

vector<student> student::sort_array(vector<student> arr) {
	system("cls");
	wcout << L"Выберите опцию:" << endl;
	wcout << L"1)Отсортировать по ФИО студента." << endl;
	wcout << L"2)Отсортировать по дате рождения студента." << endl;
	wcout << L"3)Отсортировать по специальности студента." << endl;
	wcout << L"4)Отсортировать по группе студента." << endl;
	wcout << L"5)Выход." << endl;
	student temp;
	switch (input_check()) {
	case 1:
		if (switch_sort() == 1)
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].full_name > arr[j + 1].full_name) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].full_name < arr[j + 1].full_name) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		return (arr);
	case 2:
		if (switch_sort() == 1)
			arr = sort_date(arr, 1);
		else arr = sort_date(arr, 2);
		return (arr);
	case 3:
		if (switch_sort() == 1)
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].speciality > arr[j + 1].speciality) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].speciality < arr[j + 1].speciality) {
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
					if (arr[j].group > arr[j + 1].group) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].group < arr[j + 1].group) {
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
	}
}

void student::show_info_stud(wstring group, wstring sort_type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		if (sort_type == L"sorted") array = sort_array(array);

		//int amount_of_symbols_name, amount_of_symbols_speciality; //amount_of_symbols_name_of_teacher;
		//int table_width;

		//amount_of_symbols_name = 0;
		//amount_of_symbols_speciality = 0;
		//for (register int i = 0; i < array.size(); i++) {
		//	if (amount_of_symbols_name > array[i].full_name.size()) amount_of_symbols_name = array[i].full_name.size();
		//	if (amount_of_symbols_speciality > array[i].speciality.size()) amount_of_symbols_speciality = array[i].speciality.size();
		//}
		//table_width = 4 + amount_of_symbols_name + amount_of_symbols_speciality + 4 + 6 + 10 + 6;

		//cout << "Информация о студентах." << endl;

		//cout << char(218) << setw(table_width) << char(191) << endl;

		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		wcout << L"Код студента " << setw(40) << left << L"Полное имя студента"
			<< L"Дата рождения "
			<< L"Специальность "
			<< L"Группа "
			<< L"Факультет "
			<< L"Курс" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		for (register int j = 0; j < array.size(); j++) {
			if (group != L"admin")
			{
				if (array[j].group.compare(0, 4, group, 0, 4) == 0)
				{
					/*cout << setw(4) << left << array[j].code_of_student << setw(amount_of_symbols_name) << left << array[j].full_name
						<< setw(10) << array[j].birth_date
						<< setw(amount_of_symbols_speciality) << array[j].speciality
						<< setw(6) << array[j].group
						<< setw(6) << array[j].faculty
						<< array[j].course << endl;*/
				}
			}
			else {
				wcout << setw(13) << left << array[j].code_of_student << setw(40) << left << array[j].full_name
					<< setw(14) << array[j].birth_date
					<< setw(14) << array[j].speciality
					<< setw(7) << array[j].group
					<< setw(10) << array[j].faculty
					<< array[j].course << endl;
			}
		}
	}
	else error_message(L"Нет данных о студентах.");
	system("pause");
}

void student::search_student(wstring group) {
	vector<student> array;
	array = load_from_file();
	int buffer;
	wstring string_buffer;
	vector<student> array_to_show;
	if (array.size() != 0) {
		buffer = search_menu(group);
		if (buffer < 3)
			switch (buffer) {
			case 1:
				wcout << L"Введите искомый код студента" << endl;
				while (!(wcin >> buffer) || wcin.peek() != L'\n' || buffer < 0) {
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buffer < 0) error_message(L"Код студента не может быть отрицательным.");
					else
						error_message(L"Вы можете ввести только цифры.");
				}
				for (register int i = 0; i < array.size(); i++)
				{
					if (group == L"admin")
					{
						if (buffer == array[i].code_of_student)
							array_to_show.push_back(array[i]);
					}
					else
						if (array[i].group.compare(0, 4, group, 0, 4) == 0)
							if (buffer == array[i].code_of_student)
								array_to_show.push_back(array[i]);
				}
				break;
			case 2:
				wcout << L"Введите искомые ФИО студента" << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(wcin, string_buffer, L'\n');
					if (string_buffer.size() > 40)
					{
						error_message(L"Имя студента не должно превышать 40 символов.");
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
					{
						if (group == L"admin")
						{
							if (string_buffer == array[i].full_name)
								array_to_show.push_back(array[i]);
						}
						else
							if (array[i].group.compare(0, 4, group, 0, 4) == 0)
								if (string_buffer == array[i].full_name)
									array_to_show.push_back(array[i]);
					}
					break;
				}
				break;
			default: error_message(L"Вы ввели неизвестную опцию");
				break;
			}
		else
			switch (buffer) {
			case 3:
				wcout << L"Введите искомую специальность." << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(wcin, string_buffer, L'\n');
					if (string_buffer.size() > 14)
					{
						error_message(L"Специальность не должно превышать 14 символов.");
						continue;
					}
					for (register int i = 0; i < string_buffer.size(); i++)
						if (!is_russian_alpha(string_buffer[i]) && string_buffer[i] != L')' && string_buffer[i] != L'(') {
							error_message(L"Пожaлуйста, используйте только русские буквы.");
							buffer = -1;
							break;
						}
					if (buffer == -1)
						continue;
					for (register int i = 0; i < array.size(); i++)
					{
						if (string_buffer == array[i].speciality)
							array_to_show.push_back(array[i]);
					}
					break;
				}
				break;
			case 4:
				wcout << "Введите искомую группу." << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
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
							buffer = -1;
							break;
						}
					}
					if (buffer == -1)
						continue;
					for (register int i = 0; i < array.size(); i++)
					{
						if (string_buffer == array[i].group)
							array_to_show.push_back(array[i]);
					}
					break;
				}
				break;
			case 5:
				wcout << L"Введите искомый факультет." << endl;
				while (1) {
					rewind(stdin);
					getline(wcin, string_buffer, L'\n');
					buffer = -1;
					for (register int i = 0; i < 10; i++)
						if (string_buffer == facult[i])
						{
							buffer = 1;
							break;
						}
					if (buffer != 1)
					{
						error_message(L"Нет такого факультета, который вы ввели.");
						continue;
					}
					for (register int i = 0; i < array.size(); i++)
					{
						if (string_buffer == array[i].faculty)
							array_to_show.push_back(array[i]);
					}
					break;
				}
				break;
			case 6:
				wcout << L"Введите искомый курс." << endl;
				while (!(wcin >> buffer) || wcin.peek() != L'\n' || buffer > 4 || buffer < 1) {
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buffer > 4 || buffer < 1)
						error_message(L"Курс может быть от 1 до 4");
					else
						error_message(L"Вы можете ввести только цифры");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buffer == array[i].course)
						array_to_show.push_back(array[i]);
				break;
			default:
				error_message(L"Вы ввели неизвестную опцию");
				break;
			}
		if (array_to_show.size() == 0) {
			error_message(L"Нет студентов с искомыми данными");
			return;
		}
		wcout << L"Код студента " << setw(40) << left << L"Полное имя студента"
			<< L"Дата рождения "
			<< L"Специальность "
			<< L"Группа "
			<< L"Факультет "
			<< L"Курс" << endl;
		for (register int i = 0; i < array_to_show.size(); i++) {
			wcout << setw(13) << left << array_to_show[i].code_of_student << setw(40) << left << array_to_show[i].full_name
				<< setw(14) << array_to_show[i].birth_date
				<< setw(14) << array_to_show[i].speciality
				<< setw(7) << array_to_show[i].group
				<< setw(10) << array_to_show[i].faculty
				<< array_to_show[i].course << endl;
		}
	}
	else error_message(L"Нет данных о студентах.");
}

int student::search_menu(wstring group) {
	wcout << L"Выберите опцию." << endl;
	wcout << L"1)Поиск по коду студента" << endl;
	wcout << L"2)Поиск по ФИО студента" << endl;
	if (group == L"admin")
	{
		wcout << L"3)Поиск по специальности" << endl;
		wcout << L"4)Поиск по группе" << endl;
		wcout << L"5)Поиск по факультету" << endl;
		wcout << L"6)Поиск по курсу" << endl;
	}
	return(input_check());
}

void student::add_stud() {
	int flag = 0;
	while (flag == 0) {
		vector<student> array = load_from_file();
		student buffer;
		system("cls");
		wcout << L"Введите новые данные о студенте." << endl;
		wcout << L"Код студента:" << endl;
		while (!(wcin >> buffer.code_of_student) || wcin.peek() != L'\n' || buffer.code_of_student < 0) {
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
			if (buffer.code_of_student < 0) error_message(L"Код студента не может быть отрицательным.");
			else
				error_message(L"Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.code_of_student == array[i].code_of_student) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			error_message(L"Такой код студента уже введен.");
			continue;
		}
		wcout << L"Полное имя студента:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(wcin, buffer.full_name, L'\n');
			if (buffer.full_name.size() > 40)
			{
				error_message(L"Имя студента не должно превышать 40 символов.");
				continue;
			}
			for (register int i = 0; i < buffer.full_name.size(); i++)
				if (!is_russian_alpha(buffer.full_name[i])) {
					error_message(L"Пожaлуйста, используйте только русские буквы.");
					flag = 1;
					break;
				}
			for (register int i = 0; i < array.size(); i++)
				if (buffer.full_name == array[i].full_name) {
					flag = 1;
					error_message(L"Такое имя студента уже введено.");
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		wcout << L"Введите дату рождения (пример 01.01.2001):" << endl;
		while (1)
		{
			rewind(stdin);
			getline(wcin, buffer.birth_date, L'\n');
			if (!check_date(buffer.birth_date, L"stud"))
				continue;
			else break;
		}
		wcout << L"Введите специальность:" << endl;
		while (1)
		{
			flag = 0;
			rewind(stdin);
			getline(wcin, buffer.speciality, L'\n');
			if (buffer.speciality.size() > 14)
			{
				error_message(L"Специальность не должна превышать 14 символов.");
				continue;
			}
			for (register int i = 0; i < buffer.speciality.size(); i++)
				if (!is_russian_alpha(buffer.speciality[i]) && buffer.speciality[i] != L'(' && buffer.speciality[i] != L')' && buffer.speciality[i] != L' ') {
					error_message(L"Пожaлуйста, используйте русские буквы и круглые скобки.");
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		wcout << L"Введите группу студента:" << endl;
		while (1) {
			flag = 0;
			time_t now = time(0);
			struct tm local;
			localtime_s(&local, &now);
			rewind(stdin);
			getline(wcin, buffer.group, L'\n');
			if (buffer.group.size() != 6)
			{
				error_message(L"Группа должна быть 6-тизначным числом.");
				continue;
			}
			for (register int i = 0; i < buffer.group.size(); i++) {
				if (!isdigit(buffer.group[i]))
				{
					error_message(L"В группе могут быть только цифры.");
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				continue;
			int course = buffer.group[0] - L'0';
			if (local.tm_mon + 1 > 8)
			{
				buffer.course = ((local.tm_year + 1900) + 1 - course) % 10;
				if (buffer.course < 1 || buffer.course > 4)
				{
					error_message(L"Студент не мог поступить в году, который написан в группе");
					continue;
				}
			}
			else
			{
				buffer.course = ((local.tm_year + 1900) - course) % 10;
				if (buffer.course < 1 || buffer.course > 4)
				{
					error_message(L"Студент не мог поступить в году, который написан в группе");
					continue;
				}
			}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			buffer.faculty = facult[(buffer.group[1] - L'0')];
			break;
		}
		save_to_file(buffer);
		flag = 1;
	}
}

void student::change_stud() {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		show_info_stud(L"admin", L"non_sorted");
		int buffer;
		int flag = 1;
		wcout << L"Введите код студента, который хотите поменять." << endl;
		buffer = input_check();
		for (register int i = 0; i < array.size(); i++)
			if (buffer == array[i].code_of_student) {
				buffer = i;
				flag = 0;
				break;
			}
		student buf;
		if (flag == 0) {
			while (1) {
				wcout << L"Введите новые данные о студенте." << endl;
				wcout << L"Код студента" << endl;
				while (!(wcin >> buf.code_of_student) || wcin.peek() != L'\n' || buf.code_of_student < 0) {
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buf.code_of_student < 0) error_message(L"Код студента не может быть отрицательным.");
					else
						error_message(L"Вы можете ввести только цифры.");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.code_of_student == array[i].code_of_student && buf.code_of_student != array[buffer].code_of_student) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					error_message(L"Такой код студента уже введен.");
					continue;
				}
				wcout << L"Полное имя студента:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(wcin, buf.full_name, L'\n');
					if (buf.full_name.size() > 40)
					{
						error_message(L"Имя студента не должно превышать 40 символов.");
						continue;
					}
					for (register int i = 0; i < buf.full_name.size(); i++)
						if (!is_russian_alpha(buf.full_name[i])) {
							error_message(L"Пожaлуйста, используйте только русские буквы.");
							flag = 1;
							break;
						}
					for (register int i = 0; i < array.size(); i++)
						if (buf.full_name == array[i].full_name && buf.full_name != array[buffer].full_name) {
							flag = 1;
							error_message(L"Такое имя студента уже введено.");
							break;
						}
					if (flag == 1)
						continue;
					break;
				}
				wcout << L"Введите дату рождения (пример 01.01.2001):" << endl;
				while (1)
				{
					rewind(stdin);
					getline(wcin, buf.birth_date, L'\n');
					if (!check_date(buf.birth_date, L"stud"))
						continue;
					else break;
				}
				wcout << L"Введите специальность:" << endl;
				while (1)
				{
					flag = 0;
					rewind(stdin);
					getline(wcin, buf.speciality, L'\n');
					if (buf.speciality.size() > 14)
					{
						error_message(L"Специальность не должна превышать 14 символов.");
						continue;
					}
					for (register int i = 0; i < buf.speciality.size(); i++)
						if (!is_russian_alpha(buf.speciality[i]) && buf.speciality[i] != L'(' && buf.speciality[i] != L')' && buf.speciality[i] != L' ') {
							error_message(L"Пожaлуйста, используйте русские буквы и круглые скобки.");
							flag = 1;
							break;
						}
					if (flag == 1) {
						flag = 0;
						continue;
					}
					break;
				}
				wcout << L"Введите группу студента:" << endl;
				while (1) {
					flag = 0;
					time_t now = time(0);
					struct tm local;
					localtime_s(&local, &now);
					rewind(stdin);
					getline(wcin, buf.group, L'\n');
					if (buf.group.size() != 6)
					{
						error_message(L"Группа должна быть 6-тизначным числом.");
						continue;
					}
					for (register int i = 0; i < buf.group.size(); i++) {
						if (!isdigit(buf.group[i]))
						{
							error_message(L"В группе могут быть только цифры.");
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						continue;
					}
					int course = buf.group[0] - L'0';
					if (local.tm_mon + 1 > 8)
					{
						buf.course = ((local.tm_year + 1900) + 1 - course) % 10;
						if (buf.course < 1 || buf.course > 4)
						{
							error_message(L"Студент не мог поступить в году, который написан в группе");
							continue;
						}
					}
					else
					{
						buf.course = ((local.tm_year + 1900) - course) % 10;
						if (buf.course < 1 || buf.course > 4)
						{
							error_message(L"Студент не мог поступить в году, который написан в группе");
							continue;
						}
					}
					break;
				}
				if (array[buffer].group[0] != buf.group[0])
				{
					accounting acc;
					acc.delete_all_info_about_student(buf.code_of_student);
					wcout << L"Весь учет данного студента удален, так как вы изменили его курс." << endl;
				}
				else if (array[buffer].code_of_student != buf.code_of_student)
				{
					accounting acc;
					vector<accounting> account;
					account = acc.load_from_file();
					for (register int i = 0; i < account.size(); i++)
						if (account[i].get_code_of_student() == array[buffer].code_of_student)
							account[i].code_of_student = buf.code_of_student;
					complete_message(L"Код данного студента в учете отметок успешно заменен на новый.");
				}
				buf.faculty = facult[(buf.group[1] - L'0')];
				break;
			}
			array[buffer] = buf;
			change_data_in_file(array, L"non_sort");
		}
		else error_message(L"Вы ввели неизвестный код студента.");
	}
	else error_message(L"Нет информации по студентам.");
	system("pause");
}

void student::delete_stud_or_sort_stud(wstring type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		int flag = 0;
		if (type == L"sort") array = sort_array(array);
		else {
			system("cls");
			show_info_stud(L"admin", L"non_sorted");
			int buffer;
			wcout << "Введите код студента, который хотите удалить." << endl;
			buffer = input_check();
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code_of_student) {
					buffer = 0;
					for (register int j = 0; j < array.size(); j++) {
						if (array[i].group == array[j].group)
							buffer++;
					}
					if (buffer == 1)
					{
						entrance del;
						del.delete_users_with_group(array[i].group);
						wcout << L"Так как студент, которого вы удалили был единственным из группы, то все пользователи этой группы удалены." << endl;
					}
					array.erase(array.begin() + i);
					flag = 1;
					accounting account;
					vector<accounting> acc;
					acc = account.load_from_file();
					for (register int j = 0; j < acc.size(); j++)
						if (acc[j].get_code_of_student() == buffer)
							acc.erase(acc.begin() + j);
					wcout << L"Так как вы удалили данные о студенте, то весь учет об этом студенте тоже удален." << endl;
					account.change_data_in_file(acc, L"delete");
					break;
				}
			if (flag == 0)
			{
				flag = -1;
				error_message(L"Вы ввели неизвестный код студента.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
		else error_message(L"Нет информации о студентах.");
		system("pause");
	}
}