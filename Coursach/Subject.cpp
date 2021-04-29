#include "main.h"
#include "Classes.h"

vector<subject> subject::load_from_file() {
	vector <subject> array;
	ifstream fin;
	fin.open(file_subject, ios_base::in);
	if (!fin.is_open())
	{
		cout << "��� ���������� � ���������." << endl;
	}
	else {
		struct subject buffer;
		int i = 0;
		while (fin >> buffer.code) {
			fin.ignore(1);
			getline(fin, buffer.name, ',');
			getline(fin, buffer.teacher_name, ',');
			fin >> buffer.hours;
			fin.ignore(1);
			fin >> buffer.semester;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			array.push_back(buffer);
			i++;
		}
	}
	fin.close();
	return(array);
}

vector<subject> subject::sort_array(vector<subject> arr) {
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)������������� �� �������� ��������." << endl;
	cout << "2)������������� ��� �������������." << endl;
	cout << "3)������������� �� ���������� �����." << endl;
	cout << "4)������������� �� ��������." << endl;
	cout << "5)�����." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
	}
	subject temp;
	switch (sw) {
	case 1:
		if (switch_sort())
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
		if (switch_sort())
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
		if (switch_sort())
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
		if (switch_sort())
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].semester > arr[j + 1].semester) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		else
			for (register int i = 0; i < arr.size(); i++) {
				for (register int j = 0; j < arr.size() - i - 1; j++) {
					if (arr[j].semester < arr[j + 1].semester) {
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

void subject::show_info_subj(string sort_type) {
	vector<subject> array = load_from_file();
	if (sort_type == "sorted") array = sort_array(array);
	cout << "���������� � ���������." << endl;
	cout << "��� �������� " << setw(20) << left << "�������� ��������"
		<< setw(20) << "��� �������������"
		<< setw(6) << "����"
		<< setw(7) << "�������" << endl;
	for (register int j = 0; j < array.size(); j++) {
		cout << setw(13) << left << array[j].code << setw(20) << left << array[j].name
			<< setw(20) << array[j].teacher_name
			<< setw(6) << array[j].hours
			<< setw(7) << array[j].semester << endl;
	}
}

void subject::add_subj() {
	int flag = 0;
	while (flag == 0) {
		vector<subject> array = load_from_file();
		subject buffer;
		cout << "������� ����� ������ �� ��������." << endl;
		cout << "��� ��������" << endl;
		while (!(cin >> buffer.code) || cin.peek() != '\n' || buffer.code < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.code < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
			else
				cout << "�� ������ ������ ������ �����." << endl;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.code == array[i].code) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			cout << "����� ��� �������� ��� ������." << endl;
			continue;
		}
		cout << "�������� ��������:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.name, '\n');
			if (buffer.name.size() > 20)
			{
				cout << "��� �������� �� ������ ��������� 20 ��������." << endl;
				continue;
			}
			else break;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer.name == array[i].name) {
				flag = 1;
				break;
			}
		if (flag == 1) {
			flag = 0;
			cout << "����� �������� �������� ��� �������." << endl;
			continue;
		}
		cout << "��� �������������:" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.teacher_name, '\n');
			if (buffer.name.size() > 20)
			{
				cout << "��� ������������� �� ������ ��������� 20 ��������." << endl;
				continue;
			}
			else break;
		}
		cout << "���������� �����:" << endl;
		while (!(cin >> buffer.hours) || cin.peek() != '\n' || buffer.hours < 2 || buffer.hours % 2 != 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.hours < 2 || buffer.hours % 2 != 0) cout << "���������� ����� �� ����� ���� ������������� ��� �� ������� 2." << endl;
			else
				cout << "�� ������ ������ ������ �����." << endl;
		}
		cout << "����� �� ����� �������:" << endl;
		while (!(cin >> buffer.semester) || cin.peek() != '\n' || buffer.semester > 8 || buffer.semester < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.semester > 8 || buffer.semester < 1) cout << "����� ����� ���� ������ 8 ���������." << endl;
			else cout << "�� ������ ������ ������ �����." << endl;
		}
		save_to_file(buffer);
		flag = 1;
	}
}

void subject::save_to_file(subject new_subj) {
	fstream fout;
	fout.open(file_subject, ios_base::app);
	if (!fout.is_open())
		cout << "������ �������� �����" << endl;
	else {
		fout << new_subj.code << ','
			<< new_subj.name << ','
			<< new_subj.teacher_name << ','
			<< new_subj.hours << ','
			<< new_subj.semester << endl;
	}
	fout.close();
}

void subject::change_subj() {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		show_info_subj("non_sorted");
		int buffer;
		int flag = 1;
		cout << "������� ��� ��������, ������� ������ ��������." << endl;
		while (!(cin >> buffer) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ������ ������ ������ �����." << endl;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buffer == array[i].code) {
				buffer = i;
				flag = 0;
				break;
			}
		if (flag == 0) {
			subject buf;
			while (flag == 0) {
				cout << "������� ����� ������ �� ��������." << endl;
				cout << "��� ��������" << endl;
				while (!(cin >> buf.code) || cin.peek() != '\n' || buf.code < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.code < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
					else
						cout << "�� ������ ������ ������ �����." << endl;
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.code == array[i].code) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					flag = 0;
					cout << "����� ��� �������� ��� ������." << endl;
					continue;
				}
				cout << "�������� ��������:" << endl;
				while (1)
				{
					getline(cin, buf.name, '\n');
					if (buf.name.size() > 20)
					{
						cout << "��� �������� �� ������ ��������� 20 ��������." << endl;
						continue;
					}
					else break;
				}
				for (register int i = 0; i < array.size(); i++)
					if (buf.name == array[i].name) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					flag = 0;
					cout << "����� �������� �������� ��� �������." << endl;
					continue;
				}
				cout << "��� �������������:" << endl;
				while (1)
				{
					getline(cin, buf.teacher_name, '\n');
					if (buf.teacher_name.size() > 20)
					{
						cout << "��� ������������� �� ������ ��������� 20 ��������." << endl;
						continue;
					}
					else break;
				}
				cout << "���������� �����:" << endl;
				while (!(cin >> buf.hours) || cin.peek() != '\n' || buf.hours < 2 || buf.hours % 2 != 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.hours < 2 || buf.hours % 2 != 0) cout << "���������� ����� �� ����� ���� ������������� ��� �� ������� 2." << endl;
					else
						cout << "�� ������ ������ ������ �����." << endl;
				}
				cout << "����� �� ����� �������:" << endl;
				while (!(cin >> buf.semester) || cin.peek() != '\n' || buf.semester > 8 || buf.semester < 1)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buf.semester > 8 || buf.semester < 1) cout << "����� ����� ���� ������ 8 ���������." << endl;
					else cout << "�� ������ ������ ������ �����." << endl;
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
					fout << array[i].code << ','
						<< array[i].name << ','
						<< array[i].teacher_name << ','
						<< array[i].hours << ','
						<< array[i].semester << endl;
				}
				remove(file_subject);
				char old_name[] = file, new_name[] = file_subject;
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

void subject::delete_subj_or_sort_subj(string type) {
	vector<subject> array = load_from_file();
	if (array.size() != 0) {
		int flag = 0;
		if (type != "sort") array = sort_array(array);
		else {
			show_info_subj("non_sorted");
			int buffer;
			cout << "������� ��� ��������, ������� ������ �������." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ������ ������ ������ �����." << endl;
			}
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code) {
					array.erase(array.begin() + i);
					flag = 1;
					break;
				}
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
					fout << array[i].code << ','
						<< array[i].name << ','
						<< array[i].teacher_name << ','
						<< array[i].hours << ','
						<< array[i].semester << endl;
				}
				remove(file_subject);
				char old_name[] = file, new_name[] = file_subject;
				fout.close();
				if (rename(old_name, new_name) == 0 || type == "sort")
					cout << "���������� ������ �������." << endl;
				else if (rename(old_name, new_name) == 0)
					cout << "�� ������� ������� ������ � ��������." << endl;
				else cout << "������ � �������������� ������." << endl;
			}
		}
	}
	else cout << "��� ���������� �� ���������." << endl;
}