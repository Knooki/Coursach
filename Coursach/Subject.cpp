#include "main.h"
#include "Classes.h"

void subject::save_to_file(subject new_subj) {
	fstream fout;
	fout.open(file_subject, ios_base::app);
	if (!fout.is_open())
		error_message("Ошибка открытия файла");
	else {
		fout << new_subj.code_of_subject << ','
			<< new_subj.name << ','
			<< new_subj.teacher_name << ','
			<< new_subj.hours << ','
			<< new_subj.number_of_semester << endl;
	}
	fout.close();
}

void subject::change_data_in_file(vector<subject> array, string type_sort) {
	fstream fout;
	fout.open(file, ios_base::out);
	if (!fout.is_open())
		error_message("Ошибка открытия файла.");
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].code_of_subject << ','
				<< array[i].name << ','
				<< array[i].teacher_name << ','
				<< array[i].hours << ','
				<< array[i].number_of_semester << endl;
		}
		remove(file_subject);
		char old_name[] = file, new_name[] = file_subject;
		fout.close();
		if (rename(old_name, new_name) != 0)
			error_message("Ошибка в переименовании файлов.");
		else if (type_sort == "sort")
			complete_message("Вы успешно отсортировали данные.");
		else
			complete_message("Вы успешно удалили запись.");
	}
}

vector<subject> subject::load_from_file() {
	vector <subject> array;
	ifstream fin;
	fin.open(file_subject, ios_base::in);
	if (!fin.is_open())
	{
		error_message("Нет информации о предметах.");
	}
	else {
		struct subject buffer;
		int i = 0;
		while (fin >> buffer.code_of_subject) {
			fin.ignore(1);
			getline(fin, buffer.name, ',');
			getline(fin, buffer.teacher_name, ',');
			fin >> buffer.hours;
			fin.ignore(1);
			fin >> buffer.number_of_semester;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

vector<subject> subject::sort_array(vector<subject> arr) {
	system("cls");
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Отсортировать по названию предмета." << endl;
	cout << "2)Отсортировать ФИО преподавателя." << endl;
	cout << "3)Отсортировать по количеству часов." << endl;
	cout << "4)Отсортировать по семестру." << endl;
	cout << "5)Выход." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("Ошибка. Вы можете ввести только цифры.");
	}
	subject temp;
	switch (sw) {
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
		error_message("Вы ввели неизвестную опцию.");
		return(arr);
		break;
	}
}

void subject::show_info_subj(string sort_type) {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		if (sort_type == "sorted") array = sort_array(array);
		cout << "Информация о предметах." << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "Код предмета " << setw(20) << left << "Название предмета"
			<< setw(20) << "ФИО Преподавателя"
			<< setw(6) << "Часы"
			<< setw(7) << "Семестр" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		for (register int j = 0; j < array.size(); j++) {
			cout << setw(13) << left << array[j].code_of_subject << setw(20) << left << array[j].name
				<< setw(20) << array[j].teacher_name
				<< setw(6) << array[j].hours
				<< setw(7) << array[j].number_of_semester << endl;
		}
	}
	else error_message("Нет данных о предметах.");
	system("pause");
}

void subject::add_subj() {
	int flag = 0;
	while (flag == 0) {
		system("cls");
		vector<subject> array = load_from_file();
		subject buffer;
		cout << "Введите новые данные по предмету." << endl;
		cout << "Код предмета" << endl;
		while (!(cin >> buffer.code_of_subject) || cin.peek() != '\n' || buffer.code_of_subject < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.code_of_subject < 0) error_message("Код предмета не может быть отрицательным.");
			else
				error_message("Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.code_of_subject == array[i].code_of_subject) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			error_message("Такой код предмета уже введен.");
			continue;
		}
		cout << "Название предмета:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.name, '\n');
			if (buffer.name.size() > 20)
			{
				error_message("Имя предмета не должно превышать 20 символов.");
				continue;
			}
			else break;
		}
		cout << "ФИО преподавателя:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.teacher_name, '\n');
			if (buffer.name.size() > 20)
			{
				error_message("Имя преподавателя не должно превышать 20 символов.");
				continue;
			}
			else break;
		}
		cout << "Количество часов:" << endl;
		while (!(cin >> buffer.hours) || cin.peek() != '\n' || buffer.hours < 2 || buffer.hours % 2 != 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.hours < 2 || buffer.hours % 2 != 0) error_message("Количество часов не может быть отрицательным или не кратным 2.");
			else
				error_message("Вы можете ввести только цифры.");
		}

		cout << "Какой по счету семестр:" << endl;
		while (!(cin >> buffer.number_of_semester) || cin.peek() != '\n' || buffer.number_of_semester > 8 || buffer.number_of_semester < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.number_of_semester > 8 || buffer.number_of_semester < 1) error_message("Всего может быть только 8 семестров.");
			else error_message("Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.name == array[i].name)
				if (buffer.number_of_semester == array[i].number_of_semester)
				{
					error_message("Этот предмет уже записан. Не совпадают семестры.");
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
		show_info_subj("non_sorted");
		int buffer;
		int flag = 1;
		cout << "Введите код предмета, который хотите поменять." << endl;
		while (!(cin >> buffer) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("Вы можете ввести только цифры.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer == array[i].code_of_subject) {
				buffer = i;
				flag = 0;
				break;
			}
		if (flag == 0) {
			subject buf;
			while (1) {
				cout << "Введите новые данные по предмету." << endl;
				cout << "Код предмета" << endl;
				while (!(cin >> buf.code_of_subject) || cin.peek() != '\n' || buf.code_of_subject < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.code_of_subject < 0) error_message("Код предмета не может быть отрицательным.");
					else
						error_message("Вы можете ввести только цифры.");
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
					error_message("Такой код предмета уже введен.");
					continue;
				}
				cout << "Название предмета:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buf.name, '\n');
					if (buf.name.size() > 20)
					{
						error_message("Имя предмета не должно превышать 20 символов.");
						continue;
					}
					else break;
				}
				cout << "ФИО преподавателя:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buf.teacher_name, '\n');
					if (buf.teacher_name.size() > 20)
					{
						error_message("Имя преподавателя не должно превышать 20 символов.");
						continue;
					}
					else break;
				}
				cout << "Количество часов:" << endl;
				while (!(cin >> buf.hours) || cin.peek() != '\n' || buf.hours < 2 || buf.hours % 2 != 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.hours < 2 || buf.hours % 2 != 0) error_message("Количество часов не может быть отрицательным или не кратным 2.");
					else
						error_message("Вы можете ввести только цифры.");
				}
				cout << "Какой по счету семестр:" << endl;
				while (!(cin >> buf.number_of_semester) || cin.peek() != '\n' || buf.number_of_semester > 8 || buf.number_of_semester < 1)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.number_of_semester > 8 || buf.number_of_semester < 1) error_message("Всего может быть только 8 семестров.");
					else error_message("Вы можете ввести только цифры.");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.name == array[i].name)
						if (buf.number_of_semester == array[i].number_of_semester)
						{
							error_message("Этот предмет уже записан. Не совпадает семестр.");
							flag = 0;
							break;
						}
				if (flag == 0)
					continue;
				array[buffer] = buf;
				change_data_in_file(array, "non_sort");
				break;
			}
		}
		else error_message("Вы ввели неизвестный код предмета.");
	}
	else error_message("Нет информации по предметам.");
	system("pause");
}

void subject::delete_subj_or_sort_subj(string type) {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		int flag = 0;
		if (type == "sort") array = sort_array(array);
		else {
			show_info_subj("non_sorted");
			int buffer;
			cout << "Введите код предмета, который хотите удалить." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				error_message("Вы можете ввести только цифры.");
			}
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
					cout << "Так как вы удалили данные о предмете, весь учет этого предмета тоже удален." << endl;
					account.change_data_in_file(acc, " ");
					break;
				}
			if (flag == 0) {
				flag = -1;
				error_message("Вы ввели неизвестный код предмета.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
	}
	else error_message("Нет информации по предметам.");
	system("pause");
}