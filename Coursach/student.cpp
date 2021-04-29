#include "main.h"
#include "Classes.h"

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
				<< array[i].course << endl;
		}
		remove(file_student);
		char old_name[] = file, new_name[] = file_student;
		fout.close();
		if (rename(old_name, new_name) == 0 && type_sort == "sort")
			cout << "�� ������� ������������� ������." << endl;
		else if (rename(old_name, new_name) == 0)
			cout << "�� ������� ������� ������." << endl;
		else cout << "������ � �������������� ������." << endl;
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
			fin >> buffer.course;
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

vector<student> student::sort_array(vector<student> arr) {
	int sw, sw_type;
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
		if (switch_sort())
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
		if (switch_sort())
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].birth_date > arr[j + 1].birth_date) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].birth_date < arr[j + 1].birth_date) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		return (arr);
	case 3:
		if (switch_sort())
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
		if (switch_sort())
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
	}
}

void student::show_info_stud(string sort_type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		if (sort_type == "sorted") array = sort_array(array);
		cout << "���������� � ���������." << endl;
		cout << "��� �������� " << setw(40) << left << "������ ��� ��������"
			<< "���� �������� "
			<< "������������� "
			<< "������ "
			<< "����" << endl;
		for (register int j = 0; j < array.size(); j++) {
			cout << setw(13) << left << array[j].code_of_student << setw(40) << left << array[j].full_name
				<< setw(14) << array[j].birth_date
				<< setw(13) << array[j].speciality
				<< setw(7) << array[j].group
				<< array[j].course << endl;
		}
	}
	else cout << "��� ������ � ���������." << endl;
}

void student::add_stud() {
	int flag = 0;
	while (flag == 0) {
		vector<student> array = load_from_file();
		student buffer;
		cout << "������� ����� ������ � ��������." << endl;
		cout << "��� ��������:" << endl;
		while (!(cin >> buffer.code_of_student) || cin.peek() != '\n' || buffer.code_of_student < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.code_of_student < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
			else
				cout << "�� ������ ������ ������ �����." << endl;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.code_of_student == array[i].code_of_student) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			cout << "����� ��� �������� ��� ������." << endl;
			continue;
		}
		cout << "������ ��� ��������:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.full_name, '\n');
			if (buffer.full_name.size() > 40)
			{
				cout << "��� �������� �� ������ ��������� 40 ��������." << endl;
				continue;
			}
			else break;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.full_name == array[i].full_name) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			cout << "����� ��� �������� ��� �������." << endl;
			continue;
		}
		cout << "������� ���� �������� (������ 01.01.2001):" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.birth_date, '\n');
			if (!check_date(buffer.birth_date, -123))
				continue;
			else break;
		}
		cout << "������� �������������:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.speciality, '\n');
			if (buffer.speciality.size() > 14)
			{
				cout << "������������� �� ������ ��������� 14 ��������." << endl;
				continue;
			}
			else break;
		}
		cout << "������� ������ ��������:" << endl;
		while (1) {
			time_t now = time(0);
			struct tm local;
			localtime_s(&local, &now);
			rewind(stdin);
			getline(cin, buffer.group, '\n');
			if (buffer.group.size() != 6)
			{
				cout << "������ ������ ���� 6-��������� ������." << endl;
				continue;
			}
			int course = int(buffer.group[0]);
			if (local.tm_mon + 1 > 8)
				if (course < ((local.tm_year + 1900) - 3) % 10 || course >(local.tm_year + 1900) % 10)
				{
					cout << "������� �� ��� ��������� � ����, ������� ������� � �������" << endl;
					continue;
				}
				else if (((local.tm_year + 1900) - 3) % 10 == course) buffer.course = 4;
				else if (((local.tm_year + 1900) - 2) % 10 == course) buffer.course = 3;
				else if (((local.tm_year + 1900) - 1) % 10 == course) buffer.course = 2;
				else if ((local.tm_year + 1900) % 10 == course) buffer.course = 1;
			if (local.tm_mon + 1 < 9)
				if (course < (local.tm_year + 1900) - 4 || course >(local.tm_year + 1900) - 1)
				{
					cout << "������� �� ��� ��������� � ����, ������� ������� � �������" << endl;
					continue;
				}
				else if (((local.tm_year + 1900) - 4) % 10 == course) buffer.course = 4;
				else if (((local.tm_year + 1900) - 3) % 10 == course) buffer.course = 3;
				else if (((local.tm_year + 1900) - 2) % 10 == course) buffer.course = 2;
				else if (((local.tm_year + 1900) - 1) % 10 == course) buffer.course = 1;
			break;
		}
		save_to_file(buffer);
		flag = 1;
	}
}

void student::change_stud() {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		show_info_stud("non_sorted");
		int buffer;
		int flag = 1;
		cout << "������� ��� ��������, ������� ������ ��������." << endl;
		while (!(cin >> buffer) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ������ ������ ������ �����." << endl;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer == array[i].code_of_student) {
				buffer = i;
				flag = 0;
				break;
			}
		student buf;
		if (flag == 0) {
			while (flag == 0) {
				cout << "������� ����� ������ � ��������." << endl;
				cout << "��� ��������" << endl;
				while (!(cin >> buf.code_of_student) || cin.peek() != '\n' || buf.code_of_student < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.code_of_student < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
					else
						cout << "�� ������ ������ ������ �����." << endl;
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.code_of_student == array[i].code_of_student) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					flag = 0;
					cout << "����� ��� �������� ��� ������." << endl;
					continue;
				}
				cout << "������ ��� ��������:" << endl;
				while (1)
				{
					getline(cin, buf.full_name, '\n');
					if (buf.full_name.size() > 40)
					{
						cout << "��� �������� �� ������ ��������� 40 ��������." << endl;
						continue;
					}
					else break;
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.full_name == array[i].full_name) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					flag = 0;
					cout << "����� ��� �������� ��� �������." << endl;
					continue;
				}
				cout << "���� �������� (������ 01.01.2001):" << endl;
				while (1)
				{
					getline(cin, buf.birth_date, '\n');
					if (!check_date(buf.birth_date, -123))
						continue;
					else break;
				}
				cout << "�������������:" << endl;
				while (1)
				{
					getline(cin, buf.speciality, '\n');
					if (buf.speciality.size() > 14)
					{
						cout << "������������� �� ������ ��������� 14 ��������." << endl;
						continue;
					}
					else break;
				}
				cout << "������:" << endl;
				while (1)
				{
					time_t now = time(0);
					struct tm local;
					localtime_s(&local, &now);
					rewind(stdin);
					getline(cin, buf.group, '\n');
					if (buf.group.size() != 6)
					{
						cout << "������ ������ ���� 6-��������� ������." << endl;
						continue;
					}
					int course = int(buf.group[0]);
					if (local.tm_mon + 1 > 8)
						if (course < (local.tm_year + 1900) - 3)
						{
							cout << "���� ���� ��� �������� ��������" << endl;
							continue;
						}
						else if (((local.tm_year + 1900) - 3) % 10 == course) buf.course = 4;
						else if (((local.tm_year + 1900) - 2) % 10 == course) buf.course = 3;
						else if (((local.tm_year + 1900) - 1) % 10 == course) buf.course = 2;
						else if ((local.tm_year + 1900) % 10 == course) buf.course = 1;
					if (local.tm_mon + 1 < 9)
						if (course < (local.tm_year + 1900) - 4)
						{
							cout << "���� ���� ��� �������� ��������" << endl;
							continue;
						}
						else if (((local.tm_year + 1900) - 4) % 10 == course) buf.course = 4;
						else if (((local.tm_year + 1900) - 3) % 10 == course) buf.course = 3;
						else if (((local.tm_year + 1900) - 2) % 10 == course) buf.course = 2;
						else if (((local.tm_year + 1900) - 1) % 10 == course) buf.course = 1;
					if (array[buffer].group[0] != buf.group[0])
					{
						accounting acc;
						acc.delete_all_info_about_student(buf.code_of_student);
						cout << "���� ���� ������� �������� ������, ��� ��� �� �������� ��� ����." << endl;
					}
					break;
				}
			}
			array[buffer] = buf;
			change_data_in_file(array, "non_sort");
		}
		else cout << "�� ����� ����������� ��� ��������." << endl;
	}
	else cout << "��� ���������� �� ���������." << endl;
}

void student::delete_stud_or_sort_stud(string type) {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		int flag = 0;
		if (type == "sort") array = sort_array(array);
		else {
			show_info_stud("non_sorted");
			int buffer;
			cout << "������� ��� ��������, ������� ������ �������." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ������ ������ ������ �����." << endl;
			}
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code_of_student) {
					array.erase(array.begin() + i);
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				flag = -1;
				cout << "�� ����� ����������� ��� ��������." << endl;
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
	}
	else cout << "��� ���������� �� ���������." << endl;
}