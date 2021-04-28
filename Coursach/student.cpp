#include "main.h"
#include "Classes.h"

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
			getline(fin, buffer.group, '\n');
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

void student::show_info_stud() {
	vector<student> array = load_from_file();
	cout << "���������� � ���������." << endl;
	cout << "��� �������� " << setw(40) << left << "������ ��� ��������"
		<< "���� �������� "
		<< "������������� "
		<< setw(7) << "������" << endl;
	for (register int j = 0; j < array.size(); j++) {
		cout << setw(13) << left << array[j].code_of_student << setw(40) << left << array[j].full_name
			<< setw(14) << array[j].birth_date
			<< setw(14) << array[j].speciality
			<< setw(6) << array[j].group << endl;
	}
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
			if (check_date(buffer.birth_date))
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
			rewind(stdin);
			getline(cin, buffer.group, '\n');
			if (buffer.group.size() != 6)
			{
				cout << "������ ������ ���� 6-��������� ������." << endl;
				continue;
			}
			else break;
		}
		save_to_file(buffer);
		flag = 1;
	}
}

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
			<< new_stud.group << endl;
	}
	fout.close();
}

void student::change_stud() {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		show_info_stud();
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
					if (check_date(buf.birth_date))
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
					rewind(stdin);
					getline(cin, buf.group, '\n');
					if (buf.group.size() != 6) cout << "������ ������ ���� 6-��������� ������." << endl;
					else break;
				}
			}
			array[buffer] = buf;
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
						<< array[i].group << endl;
				}
				remove(file_student);
				char old_name[] = file, new_name[] = file_student;
				fout.close();
				if (rename(old_name, new_name) == 0)
					cout << "�� ������� �������� ������." << endl;
				else cout << "������ � �������������� ������." << endl;
			}
		}
		else cout << "�� ����� ����������� ��� ��������." << endl;
	}
	else cout << "��� ���������� �� ���������." << endl;
}

void student::delete_stud() {
	vector<student> array = load_from_file();
	if (array.size() != 0) {
		show_info_stud();
		int buffer;
		int flag = 0;
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
		if (flag == 0) cout << "�� ����� ����������� ��� ��������." << endl;
		else {
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
						<< array[i].group << endl;
				}
				remove(file_student);
				char old_name[] = file, new_name[] = file_student;
				fout.close();
				if (rename(old_name, new_name) == 0)
					cout << "�� ������� �������� ������." << endl;
				else cout << "������ � �������������� ������." << endl;
			}
		}
	}
	else cout << "��� ���������� �� ���������." << endl;
}