#include "main.h"
#include "Classes.h"

//можно добавить вариативности посреедством показывания учета за прошлый год, только о первых курсах, за все года, 2 года назад и тд
//надо сделать сортировку по учебным годам

void accounting::save_to_file(accounting new_acc) {
	wfstream fout(file_accounting, ios_base::app);
	fout.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fout.is_open())
		error_message(L"Ошибка открытия файла");
	else {
		fout << new_acc.code_of_student << L','
			<< new_acc.code_of_subject << L','
			<< new_acc.date << L','
			<< new_acc.mark << L','
			<< new_acc.code_of_acc << endl;
	}
	fout.close();
}

void accounting::change_data_in_file(vector<accounting> array, wstring type_sort) {
	wfstream fout(file, ios_base::out);
	fout.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fout.is_open())
		error_message(L"Ошибка открытия файла.");
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].code_of_student << L','
				<< array[i].code_of_subject << L','
				<< array[i].date << L','
				<< array[i].mark << L','
				<< array[i].code_of_acc << endl;
		}
		remove(file_accounting);
		char old_name[] = file, new_name[] = file_accounting;
		fout.close();
		if (rename(old_name, new_name) != 0)
			error_message(L"Ошибка в переименовании файлов.");
		else if (type_sort == L"sort")
			complete_message(L"Вы успешно отсортировали данные.");
		else if (type_sort == L"student")
			complete_message(L"Данные о студенте успешно удалены.");
		else
			complete_message(L"Вы успешно удалили запись.");
	}
}

vector<accounting> accounting::load_from_file() {
	vector<accounting> acc;
	accounting buffer;
	wfstream fin(file_accounting, ios_base::in);
	fin.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
	if (!fin.is_open()) error_message(L"Ошибка открытия файла.");
	else {
		while (fin >> buffer.code_of_student)
		{
			fin.ignore(1);
			fin >> buffer.code_of_subject;
			fin.ignore(1);
			getline(fin, buffer.date, L',');
			fin >> buffer.mark;
			fin.ignore(1);
			fin >> buffer.code_of_acc;
			fin.ignore(numeric_limits<streamsize>::max(), L'\n');
			acc.push_back(buffer);
		}
		vector<student> stud;
		stud = student::load_from_file();
		vector<subject> subj;
		subj = subject::load_from_file();
		for (register int i = 0; i < acc.size(); i++) {
			for (register int j = 0; j < stud.size(); j++)
				if (acc[i].code_of_student == stud[j].get_code_of_student()) {
					acc[i].full_name = stud[j].get_full_name();
					acc[i].group = stud[j].get_group();
					break;
				}
			for (register int j = 0; j < subj.size(); j++)
				if (acc[i].code_of_subject == subj[j].get_number_of_semester()) {
					acc[i].number_of_semester == subj[j].get_number_of_semester();
					break;
				}
		}
	}
	return(acc);
}

vector<accounting> accounting::sort_array_of_accounting(vector<accounting> array_of_acc)
{
	vector<accounting> array_of_acc;
	array_of_acc = load_from_file();
	if (array_of_acc.size() != 0)
	{
		system("cls");
		wcout << L"Выберите опцию:" << endl;
		wcout << L"1)Отсортировать по информации студентов." << endl;
		wcout << L"2)Отсортировать по успеваемости студентов." << endl;
		wcout << L"3)Отсортировать по учебным годам." << endl;
		wcout << L"4)Выход." << endl;
		switch (input_check())
		{
		case 1:
		{
			vector<student> stud = student::load_from_file();
			stud = student::sort_array(stud);
			bruh
				return (); }
		case 2:
		{
			vector<student_account> stud_acc;
			student_account tmp;
			for (register int i = 0; i < array_of_stud.size(); i++)
			{
				tmp.average_score = 0;
				tmp.marks.clear();
				for (register int j = 0; j < array_of_acc.size(); j++)
					if (array_of_stud[i].get_code_of_student() == array_of_acc[j].code_of_student)
					{
						tmp.code_of_student = array_of_stud[i].get_code_of_student();
						tmp.full_name = array_of_stud[i].get_full_name();
						tmp.marks.push_back(array_of_acc[j].mark);
					}
				for (register int j = 0; j < tmp.marks.size(); j++)
					tmp.average_score += tmp.marks[j];
				tmp.average_score = tmp.average_score / tmp.marks.size();
				tmp.code_of_student = array_of_stud[i].get_code_of_student();
				tmp.full_name = array_of_stud[i].get_full_name();
				stud_acc.push_back(tmp);
			}
			student temp;
			switch (switch_sort())
			{
			case 1:
				for (register int i = 0; i < stud_acc.size(); i++) {
					for (register int j = 0; j < stud_acc.size() - i - 1; j++) {
						if (stud_acc[j].average_score > stud_acc[j + 1].average_score) {
							tmp = stud_acc[j];
							stud_acc[j] = stud_acc[j + 1];
							stud_acc[j + 1] = tmp;
							temp = array_of_stud[j];
							array_of_stud[j] = array_of_stud[j + 1];
							array_of_stud[j + 1] = temp;
						}
					}
				}
				break;
			case 2:
				for (register int i = 0; i < stud_acc.size(); i++) {
					for (register int j = 0; j < stud_acc.size() - i - 1; j++) {
						if (stud_acc[j].average_score < stud_acc[j + 1].average_score) {
							tmp = stud_acc[j];
							stud_acc[j] = stud_acc[j + 1];
							stud_acc[j + 1] = tmp;
							temp = array_of_stud[j];
							array_of_stud[j] = array_of_stud[j + 1];
							array_of_stud[j + 1] = temp;
						}
					}
				}
				break;
			}
			return(array_of_stud);
		}
		case 3: {
			//string year, month;
			//vector<int> amount_of_month;
			//for (register int i = 0; i < array_of_acc.size(); i++)
			//{
			//	month = array_of_acc[i].date.substr(3, 2);
			//	year = array_of_acc[i].date.substr(6, 4);
			//	//надо сделать сортировку по учебным годам ......
			//		amount_of_month.push_back(stoi(year) * 12 + stoi(month));
			//}
			//switch (switch_sort())
			//{
			//	if (type == 1)
			//		for (register int i = 0; i < amount_of_days.size(); i++) {
			//			for (register int j = 0; j < amount_of_days.size() - i - 1; j++) {
			//				if (amount_of_days[j] > amount_of_days[j + 1]) {
			//					temp = amount_of_days[j];
			//					amount_of_days[j] = amount_of_days[j + 1];
			//					amount_of_days[j + 1] = temp;
			//					tmp = array[j];
			//					array[j] = array[j + 1];
			//					array[j + 1] = tmp;
			//				}
			//			}
			//		}
			//	else
			//		for (register int i = 0; i < amount_of_days.size(); i++) {
			//			for (register int j = 0; j < amount_of_days.size() - i - 1; j++) {
			//				if (amount_of_days[j] < amount_of_days[j + 1]) {
			//					tmp = array[j];
			//					array[j] = array[j + 1];
			//					array[j + 1] = tmp;
			//				}
			//			}
			//		}
			//}
		}
			  break;
		case 4:
			return(array_of_stud);
		default: error_message(L"Вы ввели неизвестную опцию");
			break;
		}
	}
	else error_message(L"Нет данных об учете студентов");
}

void accounting::show_info(wstring group, wstring sort_type) {
	vector<accounting> acc;
	acc = load_from_file();
	if (acc.size() != 0) {
		if (sort_type == L"sorted")
			acc = sort_array_of_accounting(acc);
		wcout << L"Таблица успеваемости студентов." << endl;
		print(acc, group);
	}
	else error_message(L"Нет данных об учете студентов");
}

void accounting::search_info(wstring group) {
	vector<accounting> array;
	array = load_from_file();
	int buffer;
	wstring string_buffer;
	vector<accounting> array_to_show;
	if (array.size() != 0) {
		buffer = search_menu(group);
		if (buffer < 4)
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
			case 3:
				wcout << L"Введите искомое название предмета." << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(wcin, string_buffer, L'\n');
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
								if (string_buffer == array[i].name)
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
			case 4:
				wcout << L"Введите искомый код записи." << endl;
				while (!(wcin >> buffer) || wcin.peek() != L'\n' || buffer < 0) {
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buffer < 0)
						error_message(L"Код записи не может быть отрицательным");
					else
						error_message(L"Вы можете ввести только цифры");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buffer == array[i].code_of_acc)
						array_to_show.push_back(array[i]);
				break;
			case 5:
				wcout << L"Введите искомый семестр." << endl;
				while (!(wcin >> buffer) || wcin.peek() != L'\n' || buffer < 1 || buffer > 8) {
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buffer < 1 || buffer > 8)
						error_message(L"Семестр может быть от 1 до 8");
					else
						error_message(L"Вы можете ввести только цифры");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buffer == array[i].get_number_of_semester())
						array_to_show.push_back(array[i]);
				break;
			default:
				error_message(L"Вы ввели неизвестную опцию");
				break;
			}
		if (array_to_show.size() == 0) {
			error_message(L"Нет записей с искомыми данными");
			return;
		}
		print(array_to_show);
	}
	else error_message(L"Нет данных об учете успеваемости.");
}

int accounting::search_menu(wstring group) {
	wcout << L"Выберите опцию." << endl;
	wcout << L"1)Поиск по коду студента" << endl;
	wcout << L"2)Поиск по ФИО студента" << endl;
	wcout << L"3)Поиск по названию предмета" << endl;
	if (group == L"admin") {
		wcout << L"4)Поиск по коду записи" << endl;
		wcout << L"5)Поиск по семестру " << endl;
	}
	return(input_check());
}

void accounting::add_info() {
	int flag = 0;
	vector<accounting> array = load_from_file();
	accounting buffer;
	vector<student> stud;
	stud = student::load_from_file();
	vector<subject> subj;
	subj = subject::load_from_file();
	int i = 0, number_of_subject = -1, number_of_student = -1;
	system("cls");
	if (stud.size() != 0 && subj.size() != 0)
	{
		show_info(L"admin", L"non_sorted");
		wcout << L"Введите новую запись о сдаче предмета." << endl;
		student::show_info_stud(L"admin", L"non_sorted");
		wcout << L"Код студента:" << endl;
		while (1) {
			while (!(wcin >> buffer.code_of_student) || wcin.peek() != L'\n' || buffer.code_of_student < 0) {
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
				if (buffer.code_of_student < 0) error_message(L"Код студента не может быть отрицательным.");
				else
					error_message(L"Вы можете ввести только цифры.");
			}
			i = 0;
			while (i < stud.size())
			{
				if (buffer.code_of_student == stud[i].get_code_of_student())
				{
					buffer.course = stud[i].get_course();
					break;
				}
				i++;
			}
			if (i >= stud.size()) {
				error_message(L"Вы ввели несуществующий код студента.");
				continue;
			}
			number_of_student = i;
			flag = 0;
			for (i = 0; i < array.size(); i++)
				if (buffer.code_of_student == array[i].code_of_student)
					flag++;
			if (flag >= subj.size())
			{
				error_message(L"У этого студента сданы все предметы.");
				continue;
			}
			break;
		}
		subject::show_info_subj(L"non_sorted");
		wcout << L"Код предмета:" << endl;
		while (1) {
			while (!(wcin >> buffer.code_of_subject) || wcin.peek() != L'\n' || buffer.code_of_subject < 0) {
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
				if (buffer.code_of_subject < 0) error_message(L"Код предмета не может быть отрицательным.");
				else
					error_message(L"Вы можете ввести только цифры.");
			}
			i = 0;
			while (i < subj.size())
			{
				if (buffer.code_of_subject == subj[i].get_code_of_subject())
					break;
				i++;
			}
			if (i >= subj.size()) {
				error_message(L"Вы ввели несуществующий код предмета.");
				continue;
			}
			number_of_subject = i;
			time_t now = time(0);
			struct tm local;
			localtime_s(&local, &now);
			int current_semester = 0;
			if (local.tm_mon + 1 > 8)
				current_semester = 1;//первый сем
			else if (local.tm_mon + 1 < 7)
				current_semester = 0;//второй сем
			else if (local.tm_mon > 6 && local.tm_mon < 9)
				current_semester = -1; //каникулы
			if (subj[number_of_subject].get_number_of_semester() > (buffer.course * 2 - 1) - current_semester) {
				error_message(L"Этот студент еще не мог сдавать этот предмет.");
				continue;
			}
			flag = 0;
			for (i = 0; i < array.size(); i++)
				if (buffer.code_of_student == array[i].get_code_of_student())
				{
					for (register int j = 0; j < array.size(); j++)
						if (buffer.code_of_subject == array[j].code_of_subject)
						{
							error_message(L"У этого студента уже есть оценка по этому предмету.");
							flag = 1;
							break;
						}
					break;
				}
			if (flag == 1) continue;
			break;
		}
		wcout << L"Введите дату cдачи предмета (пример 01.01.2001):" << endl;
		while (1)
		{
			rewind(stdin);
			getline(wcin, buffer.date, L'\n');
			if (!check_date(buffer.date, subj[number_of_subject].get_number_of_semester(), stud[number_of_student].get_course()))
				continue;
			break;
		}
		wcout << L"Введите отметку по предмету:" << endl;
		while (!(wcin >> buffer.mark) || wcin.peek() != L'\n' || buffer.mark < 0 || buffer.mark > 10) {
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
			if (buffer.mark < 0 || buffer.mark > 10) error_message(L"Отметка по предмету может быть от 0 до 10.");
			else
				error_message(L"Вы можете ввести только цифры.");
		}
		wcout << L"Введите код записи:" << endl;
		while (1) {
			buffer.code_of_acc = input_check();
			for (i = 0; i < array.size(); i++)
				if (buffer.code_of_acc == array[i].code_of_acc)
				{
					flag = 1;
					error_message(L"Такой код записи уже введен.");
					break;
				}
			if (flag == 1)
				continue;
			break;
		}
		save_to_file(buffer);
	}
	else error_message(L"В базе нет данных о предметах или об учениках.");
}

void accounting::change_info() {
	vector<accounting> array = load_from_file();
	accounting buffer;
	vector<student> stud;
	stud = student::load_from_file();
	vector<subject> subj;
	subj = subject::load_from_file();
	if (array.size() != 0 && stud.size() != 0 && subj.size() != 0) {
		system("cls");
		show_info(L"admin", L"non_sorted");
		int buf;
		int flag = 1;
		int number_of_student = 0, number_of_subject = 0;
		wcout << L"Введите код записи, которую хотите поменять." << endl;
		buf = input_check();
		for (register int i = 0; i < array.size(); i++)
			if (buf == array[i].code_of_acc) {
				buf = i;
				flag = 0;
				break;
			}
		if (flag == 0) {
			while (1) {
				system("cls");
				wcout << L"Введите новую запись о сдаче предмета." << endl;
				wcout << L"Код студента:" << endl;
				while (1) {
					while (!(wcin >> buffer.code_of_student) || wcin.peek() != L'\n' || buffer.code_of_student < 0) {
						wcin.clear();
						wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
						if (buffer.code_of_student < 0) error_message(L"Код студента не может быть отрицательным.");
						else
							error_message(L"Вы можете ввести только цифры.");
					}
					flag = 0;
					while (flag < stud.size())
					{
						if (buffer.code_of_student == stud[flag].get_code_of_student())
						{
							buffer.course = stud[flag].get_course();
							break;
						}
						flag++;
					}
					if (flag >= stud.size()) {
						error_message(L"Вы ввели несуществующий код студента.");
						continue;
					}
					number_of_student = flag;
					flag = 0;
					for (register int i = 0; i < array.size(); i++)
						if (buffer.code_of_student == array[i].get_code_of_student())
							flag++;
					if (flag >= subj.size() - 1)
					{
						error_message(L"У этого студента сданы все предметы.");
						continue;
					}
					break;
				}
				subject::show_info_subj(L"non_sorted");
				wcout << L"Код предмета:" << endl;
				while (1) {
					while (!(wcin >> buffer.code_of_subject) || wcin.peek() != L'\n' || buffer.get_code_of_subject() < 0) {
						wcin.clear();
						wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
						if (buffer.code_of_subject < 0) error_message(L"Код предмета не может быть отрицательным.");
						else
							error_message(L"Вы можете ввести только цифры.");
					}
					flag = 0;
					while (flag < subj.size())
					{
						if (buffer.code_of_subject == subj[flag].get_code_of_subject())
							break;
						flag++;
					}
					if (flag >= subj.size()) {
						error_message(L"Вы ввели несуществующий код предмета.");
						continue;
					}
					number_of_subject = flag;
					time_t now = time(0);
					struct tm local;
					localtime_s(&local, &now);
					int current_semester = 0;
					if (local.tm_mon + 1 > 8)
						current_semester = 1;//первый сем
					else if (local.tm_mon + 1 < 7)
						current_semester = 0;//второй сем
					else if (local.tm_mon > 6 && local.tm_mon < 9)
						current_semester = -1; //каникулы
					if (subj[number_of_subject].get_number_of_semester() > (buffer.course * 2 - 1) - current_semester)
					{
						error_message(L"Этот студент еще не мог сдавать этот предмет.");
						continue;
					}
					for (register int i = 0; i < array.size(); i++)
						if (buffer.code_of_student == array[i].code_of_student)
						{
							for (register int j = 0; j < array.size(); j++)
							{
								if (buffer.code_of_subject == array[buf].code_of_subject) continue;
								if (buffer.code_of_subject == array[j].code_of_subject)
								{
									error_message(L"У этого студента уже есть оценка по этому предмету.");
									flag = 1;
									break;
								}
							}
							break;
						}
					if (flag == 1)
						continue;
					break;
				}
				wcout << L"Введите дату cдачи предмета (пример 01.01.2001):" << endl;
				while (1)
				{
					rewind(stdin);
					getline(wcin, buffer.date, L'\n');
					if (!check_date(buffer.date, subj[number_of_subject].get_number_of_semester(), stud[number_of_student].get_course()))
						continue;
					else break;
				}
				wcout << L"Введите отметку по предмету:" << endl;
				while (!(wcin >> buffer.mark) || wcin.peek() != L'\n' || buffer.mark < 0 || buffer.mark > 10) {
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					if (buffer.mark < 0 || buffer.mark > 10) error_message(L"Отметка по предмету может быть от 0 до 10.");
					else
						error_message(L"Вы можете ввести только цифры.");
				}
				wcout << L"Введите код записи:" << endl;
				while (1) {
					while (!(wcin >> buffer.code_of_acc) || wcin.peek() != L'\n' || buffer.code_of_acc < 0) {
						wcin.clear();
						wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
						if (buffer.code_of_acc < 0) error_message(L"Код записи не может быть отрицательным.");
						error_message(L"Вы можете ввести только цифры.");
					}
					for (register int i = 0; i < array.size(); i++) {
						if (buffer.code_of_acc == array[buf].code_of_acc) continue;
						if (buffer.code_of_acc == array[i].code_of_acc)
						{
							flag = 1;
							error_message(L"Такой код записи уже введен.");
							break;
						}
					}
					if (flag == 1)
						continue;
					break;
				}
				array[buf] = buffer;
				change_data_in_file(array, L"non_sort");
				break;
			}
		}
		else error_message(L"Вы ввели неизвестный код записи.");
	}
	else error_message(L"Нет информации по записям.");
}

void accounting::show_info_about_three() {
	vector<accounting> array;
	array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		vector<subject> subj;
		subj = subject::load_from_file();
		vector<student_account> stud_acc;
		student_account tmp;
		for (register int i = 0; i < subj.size() && i < 3; i++)
		{
			tmp.average_score = 0;
			tmp.marks.clear();
			for (register int j = 0; j < array.size(); j++)
				if (subj[i].get_code_of_subject() == array[j].code_of_subject)
				{
					tmp.name_of_subject = subj[i].get_name();
					tmp.teacher_name = subj[i].get_teacher_name();
					tmp.marks.push_back(array[j].mark);
				}
			for (register int j = 0; j < tmp.marks.size(); j++)
				tmp.average_score += tmp.marks[j];
			tmp.average_score = tmp.average_score / tmp.marks.size();
			tmp.code_of_subject = subj[i].get_code_of_subject();
			tmp.name_of_subject = subj[i].get_name();
			tmp.teacher_name = subj[i].get_teacher_name();
			tmp.amount_of_negative_marks = 0;
			for (register int j = 0; j < tmp.marks.size(); j++)
				if (tmp.marks[j] < 4)
					tmp.amount_of_negative_marks++;
			stud_acc.push_back(tmp);
		}
		for (register int i = 0; i < stud_acc.size(); i++) {
			for (register int j = 0; j < stud_acc.size() - i - 1; j++) {
				if (stud_acc[j].average_score > stud_acc[j + 1].average_score) {
					tmp = stud_acc[j];
					stud_acc[j] = stud_acc[j + 1];
					stud_acc[j + 1] = tmp;
				}
			}
		}
		wcout << L"Информация о трех предметах с наименьшим средним баллом." << endl;
		int max_size_name = 0, max_size_teacher_name = 0;
		for (int i = 0; i < stud_acc.size(); i++)
		{
			if (stud_acc.at(i).name_of_subject.length() > max_size_name)
				max_size_name = stud_acc.at(i).name_of_subject.size();
			if (array.at(i).teacher_name.length() > max_size_teacher_name)
				max_size_teacher_name = array.at(i).teacher_name.size();
		}
		int table_width = 14 + 21 + 13 + ((max_size_teacher_name > 16) ? max_size_teacher_name + 1 : 16) + (max_size_name > 18 ? max_size_name + 1 : 18);
		wcout << L"┌" << wstring(table_width, L'─') << L"┐" << endl;
		wcout << L"│";
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		wcout << L"Код предмета " << setw(max_size_name > 18 ? max_size_name + 1 : 18) << left << L"Название предмета "
			<< setw(max_size_teacher_name > 16 ? max_size_teacher_name + 1 : 16) << L"ФИО Преподавателя "
			<< L"Кол-во отр-ных оценок "
			<< L"Средний балл";
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		wcout << L"│" << endl;
		for (register int j = 0; j < stud_acc.size(); j++) {
			wcout << L"├" << wstring(table_width, L'─') << L"┤" << endl;
			wcout << L"│" << setw(13) << left << stud_acc[j].code_of_subject << setw(max_size_name > 18 ? max_size_name + 1 : 18) << left << stud_acc[j].name_of_subject
				<< setw(max_size_teacher_name > 16 ? max_size_teacher_name + 1 : 16) << stud_acc[j].teacher_name
				<< setw(21) << stud_acc[j].amount_of_negative_marks
				<< setw(12) << fixed << setprecision(2) << stud_acc[j].average_score << L"│" << endl;
		}
		wcout << L"└" << wstring(table_width, L'─') << L"┘" << endl;
	}
	else error_message(L"Нет данных об учете студентов.");
}

void accounting::delete_info_or_sort_info(wstring type) {
	vector<accounting> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		int flag = 0;
		if (type == L"sort")
		{
			vector<student> stud;
			stud = student::load_from_file();
			stud = sort_array_of_accounting(stud);
			vector<accounting> tmp;
			for (register int k = 0; k < stud.size(); k++)
				for (register int j = 0; j < array.size(); j++)
					if (stud[k].get_code_of_student() == array[j].code_of_student)
						tmp.push_back(array[j]);
			array = tmp;
		}
		else {
			show_info(L"admin", L"non_sorted");
			int buffer;
			wcout << L"Введите код записи, которую хотите удалить." << endl;
			buffer = input_check();
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code_of_acc) {
					array.erase(array.begin() + i);
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				flag = -1;
				error_message(L"Вы ввели неизвестный код записи.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
	}
	else error_message(L"Нет информации по предметам.");
}

void accounting::delete_all_info_about_student(int code_of_student) {
	vector<accounting> array;
	array = load_from_file();
	if (array.size() != 0) {
		int flag = 0;
		for (register int i = 0; i < array.size(); i++)
			if (code_of_student == array[i].code_of_student)
			{
				array.erase(array.begin() + i);
				flag++;
			}
		if (flag != 0)
			change_data_in_file(array, L"student");
	}
}

void accounting::print(vector<accounting> acc, wstring group) {
	int max_size_name = 0, max_size_full_name = 0;
	for (register int i = 0; i < acc.size(); i++)
	{
		if (acc.at(i).get_name().length() > max_size_name)
			max_size_name = acc.at(i).get_name().size();
		if (acc.at(i).get_full_name().length() > max_size_full_name)
			max_size_full_name = acc.at(i).get_full_name().size();
	}
	int table_width = space_accounting + ((max_size_full_name > 13) ? max_size_full_name + 1 : 13) + (max_size_name > 8 ? max_size_name + 1 : 8);
	wcout << L"┌" << wstring(table_width, L'─') << L"┐" << endl;
	wcout << L"│";
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
	wcout << L"Код студента " << setw(max_size_full_name > 13 ? max_size_full_name + 1 : 13) << left << L"Имя Студента "
		<< setw(max_size_name > 8 ? max_size_name + 1 : 8) << L"Предмет "
		<< L"Дата сдачи "
		<< L"Оценка "
		<< L"Семестр "
		<< L"Код записи";
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	wcout << L"│" << endl;

	vector <int> students;
	for (register int i = 0; i < acc.size(); i++)
		students.push_back(acc[i].code_of_student);

	for (register int k = 0; k < Set.size(); k++)
	{
		wcout << L"\r";
		if (group != L"admin")
		{
			if (acc[k].group.compare(0, 4, group, 0, 4) == 0)
			{
				wcout << L"├" << wstring(table_width, L'─') << L"┤" << endl;
				wcout << L"│" << setw(13) << left << stud[k].get_code_of_student()
					<< setw(max_size_full_name > 13 ? max_size_full_name + 1 : 13) << left << stud[k].get_full_name();
				for (register int j = 0; j < acc.size(); j++)
				{
					if (stud[k].get_code_of_student() == acc[j].code_of_student)
						for (register int g = 0; g < subj.size(); g++)
							if (acc[j].code_of_subject == subj[g].get_code_of_subject())
							{
								wcout << setw(max_size_name > 8 ? max_size_name + 1 : 8) << left << subj[g].get_name()
									<< setw(11) << left << acc[j].date
									<< setw(7) << left << acc[j].mark
									<< setw(8) << left << subj[g].get_number_of_semester()
									<< setw(10) << acc[j].code_of_acc << L"│" << endl;
								wcout << L"│" << setw(52) << "";
							}
				}
			}
		}
		else {
			wcout << L"├" << wstring(table_width, L'─') << L"┤" << endl;
			wcout << L"│" << setw(13) << left << stud[k].get_code_of_student()
				<< setw(max_size_full_name > 13 ? max_size_full_name + 1 : 13) << left << stud[k].get_full_name();
			for (register int j = 0; j < acc.size(); j++)
			{
				if (stud[k].get_code_of_student() == acc[j].code_of_student)
					for (register int g = 0; g < subj.size(); g++)
						if (acc[j].code_of_subject == subj[g].get_code_of_subject())
						{
							wcout << setw(max_size_name > 8 ? max_size_name + 1 : 8) << left << subj[g].get_name()
								<< setw(11) << left << acc[j].date
								<< setw(7) << left << acc[j].mark
								<< setw(8) << left << subj[g].get_number_of_semester()
								<< setw(10) << acc[j].code_of_acc << L"│" << endl;
							wcout << L"│" << setw(52) << "";
						}
			}
		}
	}
	wcout << L"\r";
	wcout << L"└" << wstring(table_width, L'─') << L"┘" << endl;
}

void accounting::print(vector<accounting> array) {
	int max_size_name = 0, max_size_full_name = 0;
	for (register int i = 0; i < array.size(); i++)
	{
		if (array.at(i).name.length() > max_size_name)
			max_size_name = array.at(i).name.size();
		if (array.at(i).full_name.length() > max_size_full_name)
			max_size_full_name = array.at(i).full_name.size();
	}
	int table_width = space_students + ((max_size_full_name > 13) ? max_size_full_name + 1 : 13) + (max_size_name > 8 ? max_size_name + 1 : 8);
	wcout << L"┌" << wstring(table_width, L'─') << L"┐" << endl;
	wcout << L"│";
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
	wcout << L"Код студента " << setw(max_size_full_name > 13 ? max_size_full_name + 1 : 13) << left << L"Имя Студента "
		<< setw(max_size_name > 8 ? max_size_name + 1 : 8) << L"Предмет "
		<< L"Дата сдачи "
		<< L"Оценка "
		<< L"Семестр "
		<< L"Код записи" << endl;
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	wcout << L"│" << endl;
	for (register int k = 0; k < array.size(); k++)
	{
		wcout << L"├" << wstring(table_width, L'─') << L"┤" << endl;
		wcout << L"│" << setw(13) << left << array[k].get_code_of_student()
			<< setw(max_size_full_name > 13 ? max_size_full_name + 1 : 13) << left << array[k].get_full_name()
			<< setw(max_size_name > 8 ? max_size_name + 1 : 8) << left << array[k].get_name()
			<< setw(11) << left << array[k].date
			<< setw(7) << left << array[k].mark
			<< setw(8) << left << array[k].get_number_of_semester()
			<< setw(10) << array[k].code_of_acc << L"│" << endl;
	}
	wcout << L"└" << wstring(table_width, L'─') << L"┘" << endl;
}