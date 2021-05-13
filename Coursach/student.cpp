#include "main.h"
#include "Classes.h"

static string facult[10] = {
	"������",
	"���",
	"����",
	"��",
	"���",
	"�����",
	"���",
	"���",
	"���",
	"����"
};

void student::save_to_file(student new_stud) {
	fstream fout;
	fout.open(file_student, ios_base::app);
	if (!fout.is_open())
		cout << "������ �������� �����" << endl;
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
		cout << "������ �������� �����." << endl;
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
			error_message("������ � �������������� ������.");
		else if (type_sort == "sort")
			complete_message("�� ������� ������������� ������.");
		else if (type_sort == "delete")
			complete_message("�� ������� ������� ������.");
		else
			complete_message("�� ������� �������� ������");
	}
}

vector<student> student::load_from_file() {
	vector <student> array;
	ifstream fin;
	fin.open(file_student, ios_base::in);
	if (!fin.is_open())
	{
		cout << "��� ���������� � ���������." << endl;
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
	cout << "�������� �����:" << endl;
	cout << "1)������������� �� ��� ��������." << endl;
	cout << "2)������������� �� ���� �������� ��������." << endl;
	cout << "3)������������� �� ������������� ��������." << endl;
	cout << "4)������������� �� ������ ��������." << endl;
	cout << "5)�����." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
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
		cout << "�� ����� ����������� �����." << endl;
		return(arr);
	}
}

void student::show_info_stud(string group, string sort_type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		if (sort_type == "sorted") array = sort_array(array);

		//int amount_of_symbols_name, amount_of_symbols_speciality; //amount_of_symbols_name_of_teacher;
		//int table_width;

		//amount_of_symbols_name = 0;
		//amount_of_symbols_speciality = 0;
		//for (register int i = 0; i < array.size(); i++) {
		//	if (amount_of_symbols_name > array[i].full_name.size()) amount_of_symbols_name = array[i].full_name.size();
		//	if (amount_of_symbols_speciality > array[i].speciality.size()) amount_of_symbols_speciality = array[i].speciality.size();
		//}
		//table_width = 4 + amount_of_symbols_name + amount_of_symbols_speciality + 4 + 6 + 10 + 6;

		//cout << "���������� � ���������." << endl;

		//cout << char(218) << setw(table_width) << char(191) << endl;

		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "��� �������� " << setw(40) << left << "������ ��� ��������"
			<< "���� �������� "
			<< "������������� "
			<< "������ "
			<< "��������� "
			<< "����" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		for (register int j = 0; j < array.size(); j++) {
			if (group != "admin")
			{
				if (array[j].group.compare(0, 4, group, 0, 4) == 0)
				{
					cout << setw(4) << left << array[j].code_of_student << setw(amount_of_symbols_name) << left << array[j].full_name
						<< setw(10) << array[j].birth_date
						<< setw(amount_of_symbols_speciality) << array[j].speciality
						<< setw(6) << array[j].group
						<< setw(6) << array[j].faculty
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
	else error_message("��� ������ � ���������.");
	system("pause");
}

void student::search_student(string group) {
	vector<student> array;
	array = load_from_file();
	int buffer;
	string string_buffer;
	vector<student> array_to_show;
	if (array.size() != 0) {
		buffer = search_menu(group);
		if (buffer < 3)
			switch (buffer) {
			case 1:
				cout << "������� ������� ��� ��������" << endl;
				while (!(cin >> buffer) || cin.peek() != '\n' || buffer < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer < 0) error_message("��� �������� �� ����� ���� �������������.");
					else
						error_message("�� ������ ������ ������ �����.");
				}
				for (register int i = 0; i < array.size(); i++)
				{
					if (group == "admin")
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
				cout << "������� ������� ��� ��������" << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(cin, string_buffer, '\n');
					if (string_buffer.size() > 40)
					{
						error_message("��� �������� �� ������ ��������� 40 ��������.");
						continue;
					}
					for (register int i = 0; i < string_buffer.size(); i++)
						if (!is_russian_alpha(string_buffer[i])) {
							error_message("���a������, ����������� ������ ������� �����.");
							buffer = -1;
							break;
						}
					if (buffer == -1)
						continue;
					for (register int i = 0; i < array.size(); i++)
					{
						if (group == "admin")
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
			default: error_message("�� ����� ����������� �����");
				break;
			}
		else
			switch (buffer) {
			case 3:
				cout << "������� ������� �������������." << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(cin, string_buffer, '\n');
					if (string_buffer.size() > 14)
					{
						error_message("������������� �� ������ ��������� 14 ��������.");
						continue;
					}
					for (register int i = 0; i < string_buffer.size(); i++)
						if (!is_russian_alpha(string_buffer[i]) && string_buffer[i] != ')' && string_buffer[i] != '(') {
							error_message("���a������, ����������� ������ ������� �����.");
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
				cout << "������� ������� ������." << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(cin, string_buffer, '\n');
					if (string_buffer.size() != 6)
					{
						error_message("������ ������ ���� 6-��������� ������.");
						continue;
					}
					for (register int i = 0; i < string_buffer.size(); i++) {
						if (!isdigit(string_buffer[i]))
						{
							error_message("� ������ ����� ���� ������ �����.");
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
				cout << "������� ������� ���������." << endl;
				while (1) {
					rewind(stdin);
					getline(cin, string_buffer, '\n');
					buffer = -1;
					for (register int i = 0; i < 10; i++)
						if (string_buffer == facult[i])
						{
							buffer = 1;
							break;
						}
					if (buffer != 1)
					{
						error_message("��� ������ ����������, ������� �� �����.");
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
				cout << "������� ������� ����." << endl;
				while (!(cin >> buffer) || cin.peek() != '\n' || buffer > 4 || buffer < 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer > 4 || buffer < 1)
						error_message("���� ����� ���� �� 1 �� 4");
					else
						error_message("�� ������ ������ ������ �����");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buffer == array[i].course)
						array_to_show.push_back(array[i]);
				break;
			default:
				error_message("�� ����� ����������� �����");
				break;
			}
		if (array_to_show.size() == 0) {
			error_message("��� ��������� � �������� �������");
			return;
		}
		cout << "��� �������� " << setw(40) << left << "������ ��� ��������"
			<< "���� �������� "
			<< "������������� "
			<< "������ "
			<< "��������� "
			<< "����" << endl;
		for (register int i = 0; i < array_to_show.size(); i++) {
			cout << setw(13) << left << array_to_show[i].code_of_student << setw(40) << left << array_to_show[i].full_name
				<< setw(14) << array_to_show[i].birth_date
				<< setw(14) << array_to_show[i].speciality
				<< setw(7) << array_to_show[i].group
				<< setw(10) << array_to_show[i].faculty
				<< array_to_show[i].course << endl;
		}
	}
	else error_message("��� ������ � ���������.");
}

int student::search_menu(string group) {
	int sw;
	cout << "�������� �����." << endl;
	cout << "1)����� �� ���� ��������" << endl;
	cout << "2)����� �� ��� ��������" << endl;
	if (group == "admin")
	{
		cout << "3)����� �� �������������" << endl;
		cout << "4)����� �� ������" << endl;
		cout << "5)����� �� ����������" << endl;
		cout << "6)����� �� �����" << endl;
	}
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("�� ������ ������ ������ �����");
	}
	return(sw);
}

void student::add_stud() {
	int flag = 0;
	while (flag == 0) {
		vector<student> array = load_from_file();
		student buffer;
		system("cls");
		cout << "������� ����� ������ � ��������." << endl;
		cout << "��� ��������:" << endl;
		while (!(cin >> buffer.code_of_student) || cin.peek() != '\n' || buffer.code_of_student < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.code_of_student < 0) error_message("��� �������� �� ����� ���� �������������.");
			else
				error_message("�� ������ ������ ������ �����.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.code_of_student == array[i].code_of_student) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			error_message("����� ��� �������� ��� ������.");
			continue;
		}
		cout << "������ ��� ��������:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.full_name, '\n');
			if (buffer.full_name.size() > 40)
			{
				error_message("��� �������� �� ������ ��������� 40 ��������.");
				continue;
			}
			for (register int i = 0; i < buffer.full_name.size(); i++)
				if (!is_russian_alpha(buffer.full_name[i])) {
					error_message("���a������, ����������� ������ ������� �����.");
					flag = 1;
					break;
				}
			for (register int i = 0; i < array.size(); i++)
				if (buffer.full_name == array[i].full_name) {
					flag = 1;
					error_message("����� ��� �������� ��� �������.");
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		cout << "������� ���� �������� (������ 01.01.2001):" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.birth_date, '\n');
			if (!check_date(buffer.birth_date, "stud"))
				continue;
			else break;
		}
		cout << "������� �������������:" << endl;
		while (1)
		{
			flag = 0;
			rewind(stdin);
			getline(cin, buffer.speciality, '\n');
			if (buffer.speciality.size() > 14)
			{
				error_message("������������� �� ������ ��������� 14 ��������.");
				continue;
			}
			for (register int i = 0; i < buffer.speciality.size(); i++)
				if (!is_russian_alpha(buffer.speciality[i]) && buffer.speciality[i] != '(' && buffer.speciality[i] != ')' && buffer.speciality[i] != ' ') {
					error_message("���a������, ����������� ������� ����� � ������� ������.");
					flag = 1;
					break;
				}
			if (flag == 1) {
				flag = 0;
				continue;
			}
			break;
		}
		cout << "������� ������ ��������:" << endl;
		while (1) {
			flag = 0;
			time_t now = time(0);
			struct tm local;
			localtime_s(&local, &now);
			rewind(stdin);
			getline(cin, buffer.group, '\n');
			if (buffer.group.size() != 6)
			{
				error_message("������ ������ ���� 6-��������� ������.");
				continue;
			}
			for (register int i = 0; i < buffer.group.size(); i++) {
				if (!isdigit(buffer.group[i]))
				{
					error_message("� ������ ����� ���� ������ �����.");
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				continue;
			int course = buffer.group[0] - '0';
			if (local.tm_mon + 1 > 8)
			{
				buffer.course = ((local.tm_year + 1900) + 1 - course) % 10;
				if (buffer.course < 1 || buffer.course > 4)
				{
					error_message("������� �� ��� ��������� � ����, ������� ������� � ������");
					continue;
				}
			}
			else
			{
				buffer.course = ((local.tm_year + 1900) - course) % 10;
				if (buffer.course < 1 || buffer.course > 4)
				{
					error_message("������� �� ��� ��������� � ����, ������� ������� � ������");
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
		cout << "������� ��� ��������, ������� ������ ��������." << endl;
		while (!(cin >> buffer) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("�� ������ ������ ������ �����.");
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
				cout << "������� ����� ������ � ��������." << endl;
				cout << "��� ��������" << endl;
				while (!(cin >> buf.code_of_student) || cin.peek() != '\n' || buf.code_of_student < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.code_of_student < 0) error_message("��� �������� �� ����� ���� �������������.");
					else
						error_message("�� ������ ������ ������ �����.");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.code_of_student == array[i].code_of_student && buf.code_of_student != array[buffer].code_of_student) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					error_message("����� ��� �������� ��� ������.");
					continue;
				}
				cout << "������ ��� ��������:" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buf.full_name, '\n');
					if (buf.full_name.size() > 40)
					{
						error_message("��� �������� �� ������ ��������� 40 ��������.");
						continue;
					}
					for (register int i = 0; i < buf.full_name.size(); i++)
						if (!is_russian_alpha(buf.full_name[i])) {
							error_message("���a������, ����������� ������ ������� �����.");
							flag = 1;
							break;
						}
					for (register int i = 0; i < array.size(); i++)
						if (buf.full_name == array[i].full_name && buf.full_name != array[buffer].full_name) {
							flag = 1;
							error_message("����� ��� �������� ��� �������.");
							break;
						}
					if (flag == 1)
						continue;
					break;
				}
				cout << "������� ���� �������� (������ 01.01.2001):" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buf.birth_date, '\n');
					if (!check_date(buf.birth_date, "stud"))
						continue;
					else break;
				}
				cout << "������� �������������:" << endl;
				while (1)
				{
					flag = 0;
					rewind(stdin);
					getline(cin, buf.speciality, '\n');
					if (buf.speciality.size() > 14)
					{
						error_message("������������� �� ������ ��������� 14 ��������.");
						continue;
					}
					for (register int i = 0; i < buf.speciality.size(); i++)
						if (!is_russian_alpha(buf.speciality[i]) && buf.speciality[i] != '(' && buf.speciality[i] != ')' && buf.speciality[i] != ' ') {
							error_message("���a������, ����������� ������� ����� � ������� ������.");
							flag = 1;
							break;
						}
					if (flag == 1) {
						flag = 0;
						continue;
					}
					break;
				}
				cout << "������� ������ ��������:" << endl;
				while (1) {
					flag = 0;
					time_t now = time(0);
					struct tm local;
					localtime_s(&local, &now);
					rewind(stdin);
					getline(cin, buf.group, '\n');
					if (buf.group.size() != 6)
					{
						error_message("������ ������ ���� 6-��������� ������.");
						continue;
					}
					for (register int i = 0; i < buf.group.size(); i++) {
						if (!isdigit(buf.group[i]))
						{
							error_message("� ������ ����� ���� ������ �����.");
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
							error_message("������� �� ��� ��������� � ����, ������� ������� � ������");
							continue;
						}
					}
					else
					{
						buf.course = ((local.tm_year + 1900) - course) % 10;
						if (buf.course < 1 || buf.course > 4)
						{
							error_message("������� �� ��� ��������� � ����, ������� ������� � ������");
							continue;
						}
					}
					break;
				}
				if (array[buffer].group[0] != buf.group[0])
				{
					accounting acc;
					acc.delete_all_info_about_student(buf.code_of_student);
					cout << "���� ���� ������� �������� ������, ��� ��� �� �������� ��� ����." << endl;
				}
				else if (array[buffer].code_of_student != buf.code_of_student)
				{
					accounting acc;
					vector<accounting> account;
					account = acc.load_from_file();
					for (register int i = 0; i < account.size(); i++)
						if (account[i].get_code_of_student() == array[buffer].code_of_student)
							account[i].code_of_student = buf.code_of_student;
					complete_message("��� ������� �������� � ����� ������� ������� ������� �� �����.");
				}
				buf.faculty = facult[(buf.group[1] - '0')];
				break;
			}
			array[buffer] = buf;
			change_data_in_file(array, "non_sort");
		}
		else error_message("�� ����� ����������� ��� ��������.");
	}
	else error_message("��� ���������� �� ���������.");
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
			cout << "������� ��� ��������, ������� ������ �������." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				error_message("�� ������ ������ ������ �����.");
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
						cout << "��� ��� �������, �������� �� ������� ��� ������������ �� ������, �� ��� ������������ ���� ������ �������." << endl;
					}
					array.erase(array.begin() + i);
					flag = 1;
					accounting account;
					vector<accounting> acc;
					acc = account.load_from_file();
					for (register int j = 0; j < acc.size(); j++)
						if (acc[j].get_code_of_student() == buffer)
							acc.erase(acc.begin() + j);
					cout << "��� ��� �� ������� ������ � ��������, �� ���� ���� �� ���� �������� ���� ������." << endl;
					account.change_data_in_file(acc, "");
					break;
				}
			if (flag == 0)
			{
				flag = -1;
				error_message("�� ����� ����������� ��� ��������.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
		else error_message("��� ���������� � ���������.");
		system("pause");
	}
}