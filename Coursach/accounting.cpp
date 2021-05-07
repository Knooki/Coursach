#include "main.h"
#include "Classes.h"

//����� �������� ������������� ������������ ����������� ����� �� ������� ���, ������ � ������ ������, �� ��� ����, 2 ���� ����� � ��

void accounting::save_to_file(accounting new_acc) {
	fstream fout;
	fout.open(file_accounting, ios_base::app);
	if (!fout.is_open())
		error_message("������ �������� �����");
	else {
		fout << new_acc.code_of_student << ','
			<< new_acc.code_of_subject << ','
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
		error_message("������ �������� �����.");
	else {
		for (register int i = 0; i < array.size(); i++)
		{
			fout << array[i].code_of_student << ','
				<< array[i].code_of_subject << ','
				<< array[i].date << ','
				<< array[i].mark << ','
				<< array[i].code_of_acc << endl;
		}
		remove(file_accounting);
		char old_name[] = file, new_name[] = file_accounting;
		fout.close();
		if (rename(old_name, new_name) != 0)
			error_message("������ � �������������� ������.");
		else if (type_sort == "sort")
			complete_message("�� ������� ������������� ������.");
		else if (type_sort == "student")
			complete_message("������ � �������� ������� �������.");
		else
			complete_message("�� ������� ������� ������.");
	}
}

vector<accounting> accounting::load_from_file() {
	vector<accounting> acc;
	accounting buffer;
	fstream fin;
	fin.open(file_accounting, ios_base::in);
	if (!fin.is_open()) error_message("������ �������� �����.");
	else
		while (fin >> buffer.code_of_student)
		{
			fin.ignore(1);
			fin >> buffer.code_of_subject;
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

vector<student> accounting::sort_array_of_accounting(vector<student> array_of_stud)
{
	vector<accounting> array_of_acc;
	accounting acc;
	array_of_acc = acc.load_from_file();
	if (array_of_acc.size() != 0)
	{
		system("cls");
		int sw;
		cout << "�������� �����:" << endl;
		cout << "1)������������� �� ���������� ���������." << endl;
		cout << "2)������������� �� ������������ ���������." << endl;
		cout << "3)������������� �� ������� �����." << endl;
		cout << "4)�����." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("������. �� ������ ������ ������ �����.");
		}
		switch (sw)
		{
		case 1:
			array_of_stud = student::sort_array(array_of_stud);
			return (array_of_stud);
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
			//	//���� ������� ���������� �� ������� ����� ......
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
		default: error_message("�� ����� ����������� �����");
			break;
		}
	}
	else error_message("��� ������ �� ����� ���������");
}

void accounting::show_info(string group, string sort_type) {
	vector<accounting> acc;
	acc = load_from_file();
	if (acc.size() != 0) {
		vector<student> stud;
		stud = student::load_from_file();
		vector<subject> subj;
		subj = subject::load_from_file();
		if (sort_type == "sorted")
			stud = sort_array_of_accounting(stud);
		cout << "������� ������������ ���������." << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "��� �������� " << setw(40) << left << "��� ��������"
			<< setw(20) << "�������"
			<< "���� ����� "
			<< "������ "
			<< "������� "
			<< "��� ������" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		for (register int k = 0; k < stud.size(); k++)
		{
			if (group != "admin")
			{
				if (stud[k].get_group().compare(0, 4, group, 0, 4) == 0)
				{
					cout << "\r";
					cout << setw(13) << left << stud[k].get_code_of_student()
						<< setw(40) << left << stud[k].get_full_name();
					for (register int j = 0; j < acc.size(); j++)
					{
						if (stud[k].get_code_of_student() == acc[j].code_of_student)
							for (register int g = 0; g < subj.size(); g++)
								if (acc[j].code_of_subject == subj[g].get_code_of_subject())
								{
									cout << setw(20) << left << subj[g].get_name()
										<< setw(11) << left << acc[j].date
										<< setw(7) << left << acc[j].mark
										<< setw(8) << left << subj[g].get_number_of_semester()
										<< acc[j].code_of_acc << endl;
									cout << setw(53) << "";
								}
					}
				}
			}
			else {
				cout << "\r";
				cout << setw(13) << left << stud[k].get_code_of_student()
					<< setw(40) << left << stud[k].get_full_name();
				for (register int j = 0; j < acc.size(); j++)
				{
					if (stud[k].get_code_of_student() == acc[j].code_of_student)
						for (register int g = 0; g < subj.size(); g++)
							if (acc[j].code_of_subject == subj[g].get_code_of_subject())
							{
								cout << setw(20) << left << subj[g].get_name()
									<< setw(11) << left << acc[j].date
									<< setw(7) << left << acc[j].mark
									<< setw(8) << left << subj[g].get_number_of_semester()
									<< acc[j].code_of_acc << endl;
								cout << setw(53) << "";
							}
				}
			}
		}
		cout << "\r";
	}
	else error_message("��� ������ �� ����� ���������");
	system("pause");
}

void accounting::search_info(string group) {
	vector<accounting> array;
	array = load_from_file();
	int buffer;
	string string_buffer;
	vector<accounting> array_to_show;
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
			case 3:
				cout << "������� ������� �������� ��������." << endl;
				while (1) {
					buffer = 1;
					rewind(stdin);
					getline(cin, string_buffer, '\n');
					if (string_buffer.size() > 20)
					{
						error_message("�������� �������� �� ������ ��������� 20 ��������.");
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
								if (string_buffer == array[i].name)
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
			case 4:
				cout << "������� ������� ��� ������." << endl;
				while (!(cin >> buffer) || cin.peek() != '\n' || buffer < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer < 0)
						error_message("���� �� ����� ���� �������������");
					else
						error_message("�� ������ ������ ������ �����");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buffer == array[i].code_of_acc)
						array_to_show.push_back(array[i]);
				break;
			case 5:
				cout << "������� ������� �������." << endl;
				while (!(cin >> buffer) || cin.peek() != '\n' || buffer < 1 || buffer > 8) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer < 1 || buffer > 8)
						error_message("������� ����� ���� �� 1 �� 8");
					else
						error_message("�� ������ ������ ������ �����");
				}
				for (register int i = 0; i < array.size(); i++)
					if (buffer == array[i].get_number_of_semester())
						array_to_show.push_back(array[i]);
				break;
			default:
				error_message("�� ����� ����������� �����");
				break;
			}
		if (array_to_show.size() == 0) {
			error_message("��� ������� � �������� �������");
			return;
		}
		cout << "��� �������� " << setw(40) << left << "��� ��������"
			<< setw(20) << "�������"
			<< "���� ����� "
			<< "������ "
			<< "������� "
			<< "��� ������" << endl;
		for (register int i = 0; i < array_to_show.size(); i++) {
			cout << setw(13) << left << array_to_show[i].get_code_of_student()
				<< setw(40) << left << array_to_show[i].get_full_name()
				<< setw(20) << left << array_to_show[i].get_name()
				<< setw(11) << left << array_to_show[i].date
				<< setw(7) << left << array_to_show[i].mark
				<< setw(8) << left << array_to_show[i].get_number_of_semester()
				<< array_to_show[i].code_of_acc << endl;
		}
	}
	else error_message("��� ������ �� ����� ������������.");
}

int accounting::search_menu(string group) {
	int sw;
	cout << "�������� �����." << endl;
	cout << "1)����� �� ���� ��������" << endl;
	cout << "2)����� �� ��� ��������" << endl;
	cout << "3)����� �� �������� ��������" << endl;
	if (group == "admin") {
		cout << "4)����� �� ���� ������" << endl;
		cout << "5)����� �� �������� " << endl;
	}
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error_message("�� ������ ������ ������ �����");
	}
	return(sw);
}

void accounting::add_info() {
	int flag = 0;
	vector<accounting> array = load_from_file();
	accounting buffer;
	vector<student> stud;
	stud = student::load_from_file();
	vector<subject> subj;
	subj = subject::load_from_file();
	system("cls");
	if (stud.size() != 0 && subj.size() != 0)
		while (1) {
			show_info("admin", "non_sorted");
			cout << "������� ����� ������ � ����� ��������." << endl;
			student::show_info_stud("admin", "non_sorted");
			cout << "��� ��������:" << endl;
			while (!(cin >> buffer.code_of_student) || cin.peek() != '\n' || buffer.code_of_student < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (buffer.code_of_student < 0) error_message("��� �������� �� ����� ���� �������������.");
				else
					error_message("�� ������ ������ ������ �����.");
			}
			int i = 0;
			while (i < stud.size())
			{
				if (buffer.code_of_student == stud[i].get_code_of_student())
				{
					buffer.course = stud[i].get_course();
					break;
				}
				i++;
			}
			if (i == stud.size()) {
				error_message("�� ����� �������������� ��� ��������.");
				continue;
			}
			int number_of_student = i;
			for (i = 0; i < array.size(); i++)
				if (buffer.code_of_student == array[i].code_of_student)
					flag++;
			if (flag >= subj.size())
			{
				error_message("� ����� �������� ����� ��� ��������.");
				flag = 1;
				continue;
			}
			subject::show_info_subj("non_sorted");
			cout << "��� ��������:" << endl;
			while (!(cin >> buffer.code_of_subject) || cin.peek() != '\n' || buffer.code_of_subject < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (buffer.code_of_subject < 0) error_message("��� �������� �� ����� ���� �������������.");
				else
					error_message("�� ������ ������ ������ �����.");
			}
			i = 0;
			while (i < subj.size())
			{
				if (buffer.code_of_subject == subj[i].get_code_of_subject())
					break;
				i++;
			}
			if (i == subj.size()) {
				error_message("�� ����� �������������� ��� ��������.");
				continue;
			}
			int number_of_subject = i;
			time_t now = time(0);
			struct tm local;
			localtime_s(&local, &now);
			int current_semester = 0;
			if (local.tm_mon + 1 > 8)
				current_semester = 1;//������ ���
			else if (local.tm_mon + 1 < 7)
				current_semester = 0;//������ ���
			else if (local.tm_mon > 6 && local.tm_mon < 9)
				current_semester = -1; //��������
			if (subj[i].get_number_of_semester() > (buffer.course * 2 - 1) - current_semester) {
				error_message("���� ������� ��� �� ��� ������� ���� �������.");
				flag = 0;
				continue;
			}
			for (i = 0; i < array.size(); i++)
				if (buffer.code_of_student == array[i].get_code_of_student())
				{
					for (register int j = 0; j < array.size(); j++)
						if (buffer.code_of_subject == array[j].code_of_subject)
						{
							error_message("� ����� �������� ��� ���� ������ �� ����� ��������.");
							flag = 1;
							break;
						}
					break;
				}
			if (flag == 1)
				continue;
			cout << "������� ���� c���� �������� (������ 01.01.2001):" << endl;
			while (1)
			{
				rewind(stdin);
				getline(cin, buffer.date, '\n');
				if (!check_date(buffer.date, subj[number_of_subject].get_number_of_semester(), stud[number_of_student].get_course()))
					continue;
				else break;
			}
			cout << "������� ������� �� ��������:" << endl;
			while (!(cin >> buffer.mark) || cin.peek() != '\n' || buffer.mark < 0 || buffer.mark > 10) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (buffer.mark < 0 || buffer.mark > 10) error_message("������� �� �������� ����� ���� �� 0 �� 10.");
				else
					error_message("�� ������ ������ ������ �����.");
			}
			cout << "������� ��� ������:" << endl;
			while (!(cin >> buffer.code_of_acc) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				error_message("�� ������ ������ ������ �����.");
			}
			for (i = 0; i < array.size(); i++)
				if (buffer.code_of_acc == array[i].code_of_acc)
				{
					flag = 1;
					error_message("����� ��� ������ ��� ������.");
					break;
				}
			if (flag == 1)
				continue;
			save_to_file(buffer);
			break;
		}
	else error_message("� ���� ��� ������ � ��������� ��� �� ��������.");
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
		show_info("admin", "non_sorted");
		int buf;
		int flag = 1;
		cout << "������� ��� ������, ������� ������ ��������." << endl;
		while (!(cin >> buf) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			error_message("�� ������ ������ ������ �����.");
		}
		for (register int i = 0; i < array.size(); i++)
			if (buf == array[i].code_of_acc) {
				buf = i;
				flag = 0;
				break;
			}
		if (flag == 0) {
			while (1) {
				system("cls");
				cout << "������� ����� ������ � ����� ��������." << endl;
				cout << "��� ��������:" << endl;
				while (!(cin >> buffer.code_of_student) || cin.peek() != '\n' || buffer.code_of_student < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer.code_of_student < 0) error_message("��� �������� �� ����� ���� �������������.");
					else
						error_message("�� ������ ������ ������ �����.");
				}
				int i = 0;
				while (i < stud.size())
				{
					if (buffer.code_of_student == stud[i].get_code_of_student())
					{
						buffer.course = stud[i].get_course();
						break;
					}
					i++;
				}
				if (i == stud.size()) {
					error_message("�� ����� �������������� ��� ��������.");
					continue;
				}
				int number_of_student = i;
				for (i = 0; i < array.size(); i++)
					if (buffer.code_of_student == array[i].get_code_of_student())
						flag++;
				if (flag >= subj.size() - 1)
				{
					error_message("� ����� �������� ����� ��� ��������.");
					flag = 1;
					continue;
				}
				subject::show_info_subj("non_sorted");
				cout << "��� ��������:" << endl;
				while (!(cin >> buffer.code_of_subject) || cin.peek() != '\n' || buffer.get_code_of_subject() < 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer.code_of_subject < 0) error_message("��� �������� �� ����� ���� �������������.");
					else
						error_message("�� ������ ������ ������ �����.");
				}
				i = 0;
				while (i < subj.size())
				{
					if (buffer.code_of_subject == subj[i].get_code_of_subject())
						break;
					i++;
				}
				if (i == subj.size()) {
					error_message("�� ����� �������������� ��� ��������.");
					continue;
				}
				int number_of_subject = i;
				time_t now = time(0);
				struct tm local;
				localtime_s(&local, &now);
				int current_semester = 0;
				if (local.tm_mon + 1 > 8)
					current_semester = 1;//������ ���
				else if (local.tm_mon + 1 < 7)
					current_semester = 0;//������ ���
				else if (local.tm_mon > 6 && local.tm_mon < 9)
					current_semester = -1; //��������
				if (subj[i].get_number_of_semester() > (buffer.course * 2 - 1) - current_semester)
				{
					error_message("���� ������� ��� �� ��� ������� ���� �������.");
					flag = 0;
					continue;
				}
				for (i = 0; i < array.size(); i++)
					if (buffer.code_of_student == array[i].code_of_student)
					{
						for (register int j = 0; j < array.size(); j++)
						{
							if (buffer.code_of_subject == array[buf].code_of_subject) continue;
							if (buffer.code_of_subject == array[j].code_of_subject)
							{
								error_message("� ����� �������� ��� ���� ������ �� ����� ��������.");
								flag = 1;
								break;
							}
						}
						break;
					}
				if (flag == 1)
					continue;
				cout << "������� ���� c���� �������� (������ 01.01.2001):" << endl;
				while (1)
				{
					rewind(stdin);
					getline(cin, buffer.date, '\n');
					if (!check_date(buffer.date, subj[number_of_subject].get_number_of_semester(), stud[number_of_student].get_course()))
						continue;
					else break;
				}
				cout << "������� ������� �� ��������:" << endl;
				while (!(cin >> buffer.mark) || cin.peek() != '\n' || buffer.mark < 0 || buffer.mark > 10) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (buffer.mark < 0 || buffer.mark > 10) error_message("������� �� �������� ����� ���� �� 0 �� 10.");
					else
						error_message("�� ������ ������ ������ �����.");
				}
				cout << "������� ��� ������:" << endl;
				while (!(cin >> buffer.code_of_acc) || cin.peek() != '\n') {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					error_message("�� ������ ������ ������ �����.");
				}
				for (i = 0; i < array.size(); i++) {
					if (buffer.code_of_acc == array[buf].code_of_acc) continue;
					if (buffer.code_of_acc == array[i].code_of_acc)
					{
						flag = 1;
						error_message("����� ��� ������ ��� ������.");
						break;
					}
				}
				if (flag == 1)
					continue;
				array[buf] = buffer;
				change_data_in_file(array, "non_sort");
				break;
			}
		}
		else error_message("�� ����� ����������� ��� ������.");
	}
	else error_message("��� ���������� �� �������.");
	system("pause");
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
		cout << "���������� � ���� ��������� � ���������� ������� ������." << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "��� �������� " << setw(20) << left << "�������� ��������"
			<< setw(20) << "��� �������������"
			<< "���-�� ���-��� ������ "
			<< "������� ����" << endl;
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		for (register int j = 0; j < stud_acc.size(); j++) {
			cout << setw(13) << left << stud_acc[j].code_of_subject << setw(20) << left << stud_acc[j].name_of_subject
				<< setw(20) << stud_acc[j].teacher_name
				<< setw(22) << stud_acc[j].amount_of_negative_marks
				<< fixed << setprecision(2) << stud_acc[j].average_score << endl;
		}
	}
	else error_message("��� ������ �� ����� ���������.");
}

void accounting::delete_info_or_sort_info(string type) {
	vector<accounting> array = load_from_file();
	if (array.size() != 0) {
		system("cls");
		int flag = 0;
		if (type == "sort")
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
			show_info("admin", "non_sorted");
			int buffer;
			cout << "������� ��� ������, ������� ������ �������." << endl;
			while (!(cin >> buffer) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				error_message("�� ������ ������ ������ �����.");
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
				error_message("�� ����� ����������� ��� ������.");
			}
		}
		if (flag != -1)
			change_data_in_file(array, type);
	}
	else error_message("��� ���������� �� ���������.");
	system("pause");
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
			change_data_in_file(array, "student");
	}
}