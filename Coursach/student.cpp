#include "main.h"
#include "Classes.h"

static string facult[10] = {
	"ФДПиПО",
	"ФКП",
	"ФИТУ",
	"ВФ",
	"ФРЭ",
	"ФКСиС",
	"ФИК",
	"ИЭФ",
	"ИИТ",
	"ФИНО"
};

void student::save_to_file(student new_stud) {
	fstream fout;
	fout.open(file_student, ios_base::app);
	if (!fout.is_open())
		cout << "Ошибка открытия файла" << endl;
	else {
		fout << new_stud.code_of_student << ','
			<< new_stud.full_name << ','
			<< new_stud.birth_date << ','
			<< new_stud.speciality << ','
			<< new_stud.group << ','
			<< new_stud.faculty << ','
			<< new_stud.course << endl;
	}
	fout.close();
}

void student::change_data_in_file(vector<student> array, string type_sort) {
	fstream fout;
	fout.open(file, ios_base::out);
	if (!fout.is_open())
		cout << "Ошибка открытия файла." << endl;
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].code_of_student << ','
				<< array[i].full_name << ','
				<< array[i].birth_date << ','
				<< array[i].speciality << ','
				<< array[i].group << ','
				<< array[i].faculty << ','
				<< array[i].course << endl;
		}
		remove(file_student);
		char old_name[] = file, new_name[] = file_student;
		fout.close();
		if (rename(old_name, new_name) != 0)
			cout << "Ошибка в переименовании файлов." << endl;
		else if (type_sort == "sort")
			cout << "Вы успешно отсортировали данные." << endl;
		else
			cout << "Вы успешно удалили запись." << endl;
	}
}

vector<student> student::load_from_file() {
	vector <student> array;
	ifstream fin;
	fin.open(file_student, ios_base::in);
	if (!fin.is_open())
	{
		cout << "Нет информации о предметах." << endl;
	}
	else {
		struct student buffer;
		int i = 0;
		while (fin >> buffer.code_of_student) {
			fin.ignore(1);
			getline(fin, buffer.full_name, ',');
			getline(fin, buffer.birth_date, ',');
			getline(fin, buffer.speciality, ',');
			getline(fin, buffer.group, ',');
			getline(fin, buffer.faculty, ',');
			fin >> buffer.course;
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

vector<student> student::sort_date(vector<student> array, int type) {
	string ye, mo, da;
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
	int sw;
	system("cls");
	cout << "Выберите опцию:" << endl;
	cout << "1)Отсортировать по ФИО студента." << endl;
	cout << "2)Отсортировать по дате рождения студента." << endl;
	cout << "3)Отсортировать по специальности студента." << endl;
	cout << "4)Отсортировать по группе студента." << endl;
	cout << "5)Выход." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	student temp;
	switch (sw) {
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
		cout << "Вы ввели неизвестную опцию." << endl;
		return(arr);
	}
}

void student::show_info_stud(string group, string sort_type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		if (sort_type == "sorted") array = sort_array(array);
		cout << "Информация о студентах." << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "Код студента " << setw(40) << left << "Полное имя студента"
			<< "Дата рождения "
			<< "Специальность "
			<< "Группа "
			<< "Факультет "
			<< "Курс" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		for (register int j = 0; j < array.size(); j++) {
			if (group != "admin")
			{
				string stream_of_study, stream_of_study_1;
				stream_of_study = group.substr(0, 4);
				stream_of_study_1 = array[j].group.substr(0, 4);
				if (stream_of_study == stream_of_study_1)
				{
					cout << setw(13) << left << array[j].code_of_student << setw(40) << left << array[j].full_name
						<< setw(14) << array[j].birth_date
						<< setw(14) << array[j].speciality
						<< setw(7) << array[j].group
						<< setw(10) << array[j].faculty
						<< array[j].course << endl;
				}
			}
			else {
				cout << setw(13) << left << array[j].code_of_student << setw(40) << left << array[j].full_name
					<< setw(14) << array[j].birth_date
					<< setw(14) << array[j].speciality
					<< setw(7) << array[j].group
					<< setw(10) << array[j].faculty
					<< array[j].course << endl;
			}
		}
	}
	else error_message("Нет данных о студентах.");
	system("pause");
}

void student::add_stud() {
	int flag = 0;
	while (flag == 0) {
		vector<student> array = load_from_file();
		student buffer;
		system("cls");
		cout << "Введите новые данные о студенте." << endl;
		cout << "Код студента:" << endl;
		while (!(cin >> buffer.code_of_student) || cin.peek() != '\n' || buffer.code_of_student < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.code_of_student < 0) error_message("Код студента не может быть отрицательным.");
			else
				error_message("Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.code_of_student == array[i].code_of_student) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			error_message("Такой код студента уже введен.");
			continue;
		}
		cout << "Полное имя студента:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.full_name, '\n');
			if (buffer.full_name.size() > 40)
			{
				error_message("Имя студента не должно превышать 40 символов.");
				continue;
			}
			for (register int i = 0; i < buffer.full_name.size(); i++)
				if (!is_russian_alpha(buffer.full_name[i])) {
					error_message("Пожaлуйста, используйте только русские буквы.");
					flag = 1;
					break;
				}
			for (register int i = 0; i < array.size(); i++)
				if (buffer.full_name == array[i].full_name) {
					flag = 1;
					error_message("Такое имя студента уже введено.");
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		cout << "Введите дату рождения (пример 01.01.2001):" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.birth_date, '\n');
			if (!check_date(buffer.birth_date, "stud"))
				continue;
			else break;
		}
		cout << "Введите специальность:" << endl;
		while (1)
		{
			flag = 0;
			rewind(stdin);
			getline(cin, buffer.speciality, '\n');
			if (buffer.speciality.size() > 14)
			{
				error_message("Специальность не должна превышать 14 символов.");
				continue;
			}
			for (register int i = 0; i < buffer.speciality.size(); i++)
				if (!is_russian_alpha(buffer.speciality[i]) && buffer.speciality[i] != '(' && buffer.speciality[i] != ')' && buffer.speciality[i] != ' ') {
					error_message("Пожaлуйста, используйте русские буквы и круглые скобки.");
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		cout << "Введите группу студента:" << endl;
		while (1) {
			flag = 0;
			time_t now = time(0);
			struct tm local;
			localtime_s(&local, &now);
			rewind(stdin);
			getline(cin, buffer.group, '\n');
			if (buffer.group.size() != 6)
			{
				error_message("Группа должна быть 6-тизначным числом.");
				continue;
			}
			for (register int i = 0; i < buffer.group.size(); i++) {
				if (!isdigit(buffer.group[i]))
				{
					error_message("В группе могут быть только цифры.");
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			int course = buffer.group[0] - '0';
			if (local.tm_mon + 1 > 8)
			{
				buffer.course = ((local.tm_year + 1900) + 1 - course) % 10;
				if (buffer.course < 1 || buffer.course > 4)
				{
					error_message("Студент не мог поступить в году, который написан в группе");
					continue;
				}
			}
			else
			{
				buffer.course = ((local.tm_year + 1900) - course) % 10;
				if (buffer.course < 1 || buffer.course > 4)
				{
					error_message("Студент не мог поступить в году, который написан в группе");
					continue;
				}
			}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			buffer.faculty = facult[(buffer.group[1] - '0')];
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
		show_info_stud("admin", "non_sorted");
		int buffer;
		int flag = 1;
		cout << "Введите код студента, который хотите поменять." << endl;
		while (!(cin >> buffer) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer == array[i].code_of_student) {
				buffer = i;
				flag = 0;
				break;
			}
		student buf;
		if (flag == 0) {
			while (1) {
				cout << "Введите новые данные о студенте." << endl;
				cout << "Код студента" << endl;
				while (!(cin >> buf.code_of_student) || cin.peek() != '\n' || buf.code_of_student < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.code_of_student < 0) error_message("Код студента не может быть отрицательным.");
					else
						error_message("Вы можете ввести только цифры.");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.code_of_student == array[i].code_of_student && buf.code_of_student != array[buffer].code_of_student) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					error_message("Такой код студента уже введен.");
					continue;
				}
				cout << "Полное имя студента:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buf.full_name, '\n');
					if (buf.full_name.size() > 40)
					{
						error_message("Имя студента не должно превышать 40 символов.");
						continue;
					}
					for (register int i = 0; i < buf.full_name.size(); i++)
						if (!is_russian_alpha(buf.full_name[i])) {
							error_message("Пожaлуйста, используйте только русские буквы.");
							flag = 1;
							break;
						}
					for (register int i = 0; i < array.size(); i++)
						if (buf.full_name == array[i].full_name && buf.full_name != array[buffer].full_name) {
							flag = 1;
							error_message("Такое имя студента уже введено.");
							break;
						}
					if (flag == 1)
						continue;
					break;
				}
				cout << "Введите дату рождения (пример 01.01.2001):" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buf.birth_date, '\n');
					if (!check_date(buf.birth_date, "stud"))
						continue;
					else break;
				}
				cout << "Введите специальность:" << endl;
				while (1)
				{
					flag = 0;
					rewind(stdin);
					getline(cin, buf.speciality, '\n');
					if (buf.speciality.size() > 14)
					{
						error_message("Специальность не должна превышать 14 символов.");
						continue;
					}
					for (register int i = 0; i < buf.speciality.size(); i++)
						if (!is_russian_alpha(buf.speciality[i]) && buf.speciality[i] != '(' && buf.speciality[i] != ')' && buf.speciality[i] != ' ') {
							error_message("Пожaлуйста, используйте русские буквы и круглые скобки.");
							flag = 1;
							break;
						}
					if (flag == 1) {
						flag = 0;
						continue;
					}
					break;
				}
				cout << "Введите группу студента:" << endl;
				while (1) {
					flag = 0;
					time_t now = time(0);
					struct tm local;
					localtime_s(&local, &now);
					rewind(stdin);
					getline(cin, buf.group, '\n');
					if (buf.group.size() != 6)
					{
						error_message("Группа должна быть 6-тизначным числом.");
						continue;
					}
					for (register int i = 0; i < buf.group.size(); i++) {
						if (!isdigit(buf.group[i]))
						{
							error_message("В группе могут быть только цифры.");
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						continue;
					}
					int course = buf.group[0] - '0';
					if (local.tm_mon + 1 > 8)
					{
						buf.course = ((local.tm_year + 1900) + 1 - course) % 10;
						if (buf.course < 1 || buf.course > 4)
						{
							error_message("Студент не мог поступить в году, который написан в группе");
							continue;
						}
					}
					else
					{
						buf.course = ((local.tm_year + 1900) - course) % 10;
						if (buf.course < 1 || buf.course > 4)
						{
							error_message("Студент не мог поступить в году, который написан в группе");
							continue;
						}
					}
					break;
				}
				if (array[buffer].group[0] != buf.group[0])
				{
					accounting acc;
					acc.delete_all_info_about_student(buf.code_of_student);
					cout << "Весь учет данного студента удален, так как вы изменили его курс." << endl;
				}
				else if (array[buffer].code_of_student != buf.code_of_student)
				{
					accounting acc;
					vector<accounting> account;
					account = acc.load_from_file();
					for (register int i = 0; i < account.size(); i++)
						if (account[i].get_code_of_student() == array[buffer].code_of_student)
							account[i].code_of_student = buf.code_of_student;
					complete_message("Код данного студента в учете отметок успешно заменен на новый.");
				}
				buf.faculty = facult[(buf.group[1] - '0')];
				break;
			}
			array[buffer] = buf;
			change_data_in_file(array, "non_sort");
		}
		else error_message("Вы ввели неизвестный код студента.");
	}
	else error_message("Нет информации по студентам.");
	system("pause");
}

void student::delete_stud_or_sort_stud(string type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		int flag = 0;
		if (type == "sort") array = sort_array(array);
		else {
			system("cls");
			show_info_stud("admin", "non_sorted");
			int buffer;
			cout << "Введите код студента, который хотите удалить." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				error_message("Вы можете ввести только цифры.");
			}
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
						cout << "Так как студент, которого вы удалили был единственным из группы, то все пользователи этой группы удалены." << endl;
					}
					array.erase(array.begin() + i);
					flag = 1;
					accounting account;
					vector<accounting> acc;
					acc = account.load_from_file();
					for (register int j = 0; j < acc.size(); j++)
						if (acc[j].get_code_of_student() == buffer)
							acc.erase(acc.begin() + j);
					cout << "Так как вы удалили данные о студенте, то весь учет об этом студенте тоже удален." << endl;
					account.change_data_in_file(acc, "");
					break;
				}
			if (flag == 0)
			{
				flag = -1;
				error_message("Вы ввели неизвестный код студента.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
		else error_message("Нет информации о студентах.");
		system("pause");
	}
}