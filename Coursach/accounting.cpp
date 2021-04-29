#include "main.h"
#include "Classes.h"

struct student_account {
	student st;
	vector<int> marks;
	float average_score;
};

void accounting::save_to_file(accounting new_acc) {
	fstream fout;
	fout.open(file_accounting, ios_base::app);
	if (!fout.is_open())
		cout << "������ �������� �����" << endl;
	else {
		fout << new_acc.st.code_of_student << ','
			<< new_acc.sub.code_of_subject << ','
			<< new_acc.date << ','
			<< new_acc.mark << ','
			<< new_acc.code_of_acc << endl;
	}
	fout.close();
}

void accounting::change_data_in_file(vector<accounting> array, string type_sort) {
	fstream fout;
	fout.open(file, ios_base::out);
	if (!fout.is_open())
		cout << "������ �������� �����." << endl;
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].st.code_of_student << ','
				<< array[i].sub.code_of_subject << ','
				<< array[i].date << ','
				<< array[i].mark << ','
				<< array[i].code_of_acc << endl;
		}
		remove(file_accounting);
		char old_name[] = file, new_name[] = file_accounting;
		fout.close();
		if (rename(old_name, new_name) == 0)
			if (rename(old_name, new_name) == 0 && type_sort == "sort")
				cout << "�� ������� ������������� ������." << endl;
			else if (rename(old_name, new_name) == 0)
				cout << "�� ������� ������� ������." << endl;
			else cout << "������ � �������������� ������." << endl;
	}
}

vector<accounting> accounting::load_from_file() {
	vector<accounting> acc;
	accounting buffer;
	fstream fin;
	fin.open(file_accounting, ios_base::in);
	if (!fin.is_open()) cout << "������ �������� �����." << endl;
	else
		while (fin >> buffer.st.code_of_student)
		{
			fin.ignore(1);
			fin >> buffer.sub.code_of_subject;
			fin.ignore(1);
			getline(fin, buffer.date, ',');
			fin >> buffer.mark;
			fin.ignore(1);
			fin >> buffer.code_of_acc;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			acc.push_back(buffer);
		}
	return(acc);
}

vector<student> student::sort_array_of_accounting(vector<student> array_of_stud)
{
	vector<accounting> array_of_acc;
	accounting acc;
	array_of_acc = acc.load_from_file();
	int sw;
	cout << "�������� �����:" << endl;
	cout << "1)������������� �� ���������� ���������." << endl;
	cout << "2)������������� �� ������������ ���������." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������. �� ������ ������ ������ �����." << endl;
	}
	switch (sw)
	{
	case 1:
		array_of_stud = sort_array(array_of_stud);
		return (array_of_stud);
	case 2:
	{
		vector<student_account> stud_acc;
		student_account tmp;
		for (register int i = 0; i < array_of_stud.size(); i++)
		{
			for (register int j = 0; j < array_of_acc.size(); j++)
				if (array_of_stud[i].code_of_student == array_of_acc[j].st.code_of_student)
				{
					tmp.st = array_of_stud[i];
					tmp.marks.push_back(array_of_acc[j].mark);
				}
			for (register int j = 0; j < tmp.marks.size(); j++)
				tmp.average_score += tmp.marks[j];
			tmp.average_score = tmp.average_score / tmp.marks.size();
			stud_acc.push_back(tmp);
		}
		switch (switch_sort())
		{
		case 1:
			for (register int i = 0; i < stud_acc.size(); i++) {
				for (register int j = 0; j < stud_acc.size() - i - 1; j++) {
					if (stud_acc[j].marks > stud_acc[j + 1].marks) {
						tmp = stud_acc[j];
						stud_acc[j] = stud_acc[j + 1];
						stud_acc[j + 1] = tmp;
					}
				}
			}
			break;
		case 2:
			for (register int i = 0; i < stud_acc.size(); i++) {
				for (register int j = 0; j < stud_acc.size() - i - 1; j++) {
					if (stud_acc[j].marks < stud_acc[j + 1].marks) {
						tmp = stud_acc[j];
						stud_acc[j] = stud_acc[j + 1];
						stud_acc[j + 1] = tmp;
					}
				}
			}
			break;
		}
		for (register int i = 0; i < array_of_stud.size(); i++)
			array_of_stud[i] = stud_acc[i].st;
		return(array_of_stud);
	}
	}
}

void accounting::show_info(string sort_type) {
	vector<student> stud;
	stud = st.load_from_file();
	vector<subject> subj;
	subj = sub.load_from_file();
	vector<accounting> acc;
	acc = load_from_file();
	if (sort_type == "sorted")
		stud = st.sort_array_of_accounting(stud);
	cout << "������� ������������ ���������." << endl;
	cout << "��� �������� " << setw(40) << left << "��� ��������"
		<< setw(20) << "�������"
		<< "���� ����� "
		<< "������ "
		<< "��� ������" << endl;
	for (register int k = 0; k < stud.size(); k++)
	{
		cout << "\r";
		cout << setw(13) << left << stud[k].code_of_student
			<< setw(40) << left << stud[k].full_name;
		for (register int j = 0; j < acc.size(); j++)
		{
			if (stud[k].code_of_student == acc[j].st.code_of_student)
				for (register int g = 0; g < subj.size(); g++)
					if (acc[j].sub.code_of_subject == subj[g].code_of_subject)
					{
						cout << setw(20) << left << subj[g].name
							<< setw(11) << left << acc[j].date
							<< setw(7) << left << acc[j].mark
							<< acc[j].code_of_acc;
						cout << setw(53) << "";
					}
		}
	}
}

void accounting::add_info() {
	int flag = 0;
	show_info("non_sorted");
	while (flag == 0) {
		vector<accounting> array = load_from_file();
		accounting buffer;
		vector<student> stud;
		stud = st.load_from_file();
		vector<subject> subj;
		subj = sub.load_from_file();
		cout << "������� ����� ������ � ����� ��������." << endl;
		cout << "��� ��������:" << endl;
		while (!(cin >> buffer.st.code_of_student) || cin.peek() != '\n' || buffer.st.code_of_student < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.st.code_of_student < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
			else
				cout << "�� ������ ������ ������ �����." << endl;
		}
		int i = 0;
		while (i < stud.size())
		{
			if (buffer.st.code_of_student == stud[i].code_of_student)
				break;
			i++;
		}
		if (i == stud.size()) {
			cout << "�� ����� �������������� ��� ��������." << endl;
			continue;
		}
		else {
			for (i = 0; i < array.size(); i++)
				if (buffer.st.code_of_student == array[i].st.code_of_student)
					flag++;
			if (flag >= subj.size())
			{
				cout << "� ����� �������� ����� ��� ��������." << endl;
				flag = 1;
				continue;
			}
		}
		cout << "��� ��������:" << endl;
		while (!(cin >> buffer.sub.code_of_subject) || cin.peek() != '\n' || buffer.sub.code_of_subject < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.sub.code_of_subject < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
			else
				cout << "�� ������ ������ ������ �����." << endl;
		}
		i = 0;
		while (i < subj.size())
		{
			if (buffer.sub.code_of_subject == subj[i].code_of_subject)
				break;
			i++;
		}
		if (i == subj.size()) {
			cout << "�� ����� �������������� ��� ��������." << endl;
			continue;
		}
		else {
			for (i = 0; i < array.size(); i++)
				if (buffer.sub.code_of_subject == array[i].sub.code_of_subject)
				{
					cout << "� ����� �������� ��� ���� ������ �� ����� ��������." << endl;
					continue;
				}
		}
		cout << "������� ���� c���� �������� (������ 01.01.2001):" << endl;
		while (1)
		{
			rewind(stdin);
			getline(cin, buffer.date, '\n');
			if (!check_date(buffer.date))
				continue;
			else break;
		}
		cout << "������� ������� �� ��������:" << endl;
		while (!(cin >> buffer.mark) || cin.peek() != '\n' || buffer.mark < 0 || buffer.mark > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (buffer.mark < 0 || buffer.mark > 10) cout << "������� �� �������� ����� ���� �� 0 �� 10." << endl;
			else
				cout << "�� ������ ������ ������ �����." << endl;
		}
		cout << "������� ��� ������:" << endl;
		while (!(cin >> buffer.code_of_acc) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ������ ������ ������ �����." << endl;
		}
		for (i = 0; i < array.size(); i++)
			if (buffer.code_of_acc == array[i].code_of_acc)
			{
				flag = 1;
				cout << "����� ��� ������� ��� ������." << endl;
				break;
			}
		if (flag == 1) {
			flag = 0;
			continue;
		}
		save_to_file(buffer);
		flag = 1;
	}
}

void accounting::change_info() {
	vector<accounting> array = load_from_file();
	if (array.size() != 0) {
		show_info("non_sorted");
		int buf;
		int flag = 1;
		cout << "������� ��� ������, ������� ������ ��������." << endl;
		while (!(cin >> buf) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ������ ������ ������ �����." << endl;
		}
		for (register int i = 0; i < array.size(); i++)
			if (buf == array[i].code_of_acc) {
				buf = i;
				flag = 0;
				break;
			}
		if (flag == 0) {
			accounting buffer;
			vector<student> stud;
			stud = st.load_from_file();
			vector<subject> subj;
			subj = sub.load_from_file();
			while (flag == 0) {
				cout << "������� ����� ������." << endl;
				cout << "��� ��������:" << endl;
				while (!(cin >> buffer.st.code_of_student) || cin.peek() != '\n' || buffer.st.code_of_student < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer.st.code_of_student < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
					else
						cout << "�� ������ ������ ������ �����." << endl;
				}
				int i = 0;
				while (i < stud.size())
				{
					if (buffer.st.code_of_student == stud[i].code_of_student)
						break;
					i++;
				}
				if (i == stud.size()) {
					cout << "�� ����� �������������� ��� ��������." << endl;
					continue;
				}
				else {
					for (i = 0; i < array.size(); i++)
						if (buffer.st.code_of_student == array[i].st.code_of_student)
							flag++;
					if (flag >= subj.size())
					{
						cout << "� ����� �������� ����� ��� ��������." << endl;
						flag = 1;
						continue;
					}
				}
				cout << "��� ��������:" << endl;
				while (!(cin >> buffer.sub.code_of_subject) || cin.peek() != '\n' || buffer.sub.code_of_subject < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer.sub.code_of_subject < 0) cout << "��� �������� �� ����� ���� �������������." << endl;
					else
						cout << "�� ������ ������ ������ �����." << endl;
				}
				i = 0;
				while (i < subj.size())
				{
					if (buffer.sub.code_of_subject == subj[i].code_of_subject)
						break;
					i++;
				}
				if (i == subj.size()) {
					cout << "�� ����� �������������� ��� ��������." << endl;
					continue;
				}
				else {
					for (i = 0; i < array.size(); i++)
						if (buffer.sub.code_of_subject == array[i].sub.code_of_subject)
						{
							cout << "� ����� �������� ��� ���� ������ �� ����� ��������." << endl;
							continue;
						}
				}
				cout << "������� ���� c���� �������� (������ 01.01.2001):" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buffer.date, '\n');
					if (!check_date(buffer.date))
						continue;
					else break;
				}
				cout << "������� ������� �� ��������:" << endl;
				while (!(cin >> buffer.mark) || cin.peek() != '\n' || buffer.mark < 0 || buffer.mark > 10) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer.mark < 0 || buffer.mark > 10) cout << "������� �� �������� ����� ���� �� 0 �� 10." << endl;
					else
						cout << "�� ������ ������ ������ �����." << endl;
				}
				cout << "������� ��� ������:" << endl;
				while (!(cin >> buffer.code_of_acc) || cin.peek() != '\n') {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�� ������ ������ ������ �����." << endl;
				}
				for (i = 0; i < array.size(); i++)
					if (buffer.code_of_acc == array[i].code_of_acc)
					{
						flag = 1;
						cout << "����� ��� ������� ��� ������." << endl;
						break;
					}
				if (flag == 1) {
					flag = 0;
					continue;
				}
			}
			array[buf] = buffer;
			change_data_in_file(array, "non_sort");
		}
		else cout << "�� ����� ����������� ��� ������." << endl;
	}
	else cout << "��� ���������� �� �������." << endl;
}

void accounting::show_info_about_three() {
	vector<accounting> array;
	array = load_from_file();
}

void accounting::delete_info_or_sort_info(string type) {
	vector<accounting> array = load_from_file();
	if (array.size() != 0) {
		int flag = 0;
		if (type == "sort")
		{
			vector<student> stud;
			stud = st.load_from_file();
			stud = st.sort_array_of_accounting(stud);
			vector<accounting> tmp;
			for (register int k = 0; k < stud.size(); k++)
				for (register int j = 0; j < array.size(); j++)
					if (stud[k].code_of_student == array[j].st.code_of_student)
						tmp.push_back(array[j]);
			array = tmp;
		}
		else {
			show_info("non_sorted");
			int buffer;
			cout << "������� ��� ������, ������� ������ �������." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�� ������ ������ ������ �����." << endl;
			}
			for (register int i = 0; i < array.size(); i++)
				if (buffer == array[i].code_of_acc) {
					array.erase(array.begin() + i);
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				flag = -1;
				cout << "�� ����� ����������� ��� ������." << endl;
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
	}
	else cout << "��� ���������� �� ���������." << endl;
}