#include "main.h"
#include "Classes.h"

struct student_account {
	student st;
	float marks;
};

vector<accounting> accounting::load_from_file() {
	vector<accounting> acc;
	accounting buffer;
	fstream fin;
	fin.open(file_accounting, ios_base::in);
	if (!fin.is_open()) cout << "Ошибка открытия файла." << endl;
	else
		while (fin >> buffer.code_of_student)
		{
			fin.ignore(1);
			fin >> buffer.code_of_subject;
			fin.ignore(1);
			getline(fin, buffer.date, ',');
			fin >> buffer.mark;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			acc.push_back(buffer);
		}
	return(acc);
}

void accounting::add_info() {
}

void accounting::change_info() {
}

void accounting::delete_info_or_sort_info(string type) {
}

void accounting::show_info(string sort_type) {
	vector<student> stud;
	student st;
	stud = st.load_from_file();
	vector<subject> subj;
	subject sub;
	subj = sub.load_from_file();
	vector<accounting> acc;
	acc = load_from_file();
	if (sort_type == "sorted") {
		int sw;
		cout << "Выберите опцию:" << endl;
		cout << "1)Отсортировать по информации студентов." << endl;
		cout << "2)Отсортировать по успеваемости студентов." << endl;
		while (!(cin >> sw) || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка. Вы можете ввести только цифры." << endl;
		}
		switch (sw) {
		case 1:
			stud = st.sort_array(stud);
			break;
		case 2:
			vector<student_account> st_acc;
			student_account tmp;
			vector<int> marks;
			float av_sc;
			for (register int i = 0; i < stud.size(); i++)
			{
				for (register int j = 0; j < acc.size(); j++)
					if (stud[i].code_of_student == acc[j].code_of_student)
					{
						tmp.st = stud[i];
						marks.push_back(acc[j].mark);
					}
				for (register int j = 0; j < marks.size(); j++)
					av_sc += marks[j];
				av_sc = (float)av_sc / marks.size();
				marks.clear();
				tmp.marks = av_sc;
				st_acc.push_back(tmp);
			}
			switch (switch_sort()) {
			case 1:
				for (register int i = 0; i < st_acc.size(); i++) {
					for (register int j = 0; j < st_acc.size() - i - 1; j++) {
						if (st_acc[j].marks > st_acc[j + 1].marks) {
							tmp = st_acc[j];
							st_acc[j] = st_acc[j + 1];
							st_acc[j + 1] = tmp;
						}
					}
				}
				break;
			case 2:
				for (register int i = 0; i < st_acc.size(); i++) {
					for (register int j = 0; j < st_acc.size() - i - 1; j++) {
						if (st_acc[j].marks < st_acc[j + 1].marks) {
							tmp = st_acc[j];
							st_acc[j] = st_acc[j + 1];
							st_acc[j + 1] = tmp;
						}
					}
				}
				break;
			}
			for (register int i = 0; i < stud.size(); i++)
				stud[i] = st_acc[i].st;
			break;
		}
	}
	cout << "Таблица успеваемости студентов." << endl;
	cout << "Код студента " << setw(40) << left << "Имя Студента"
		<< setw(20) << "Предмет"
		<< "Дата сдачи "
		<< "Оценка" << endl;
	for (register int k = 0; k < stud.size(); k++)
	{
		cout << "\r";
		cout << setw(13) << left << stud[k].code_of_student
			<< setw(40) << left << stud[k].full_name;
		for (register int j = 0; j < acc.size(); j++)
		{
			if (stud[k].code_of_student == acc[j].code_of_student)
				for (register int g = 0; g < subj.size(); g++)
					if (acc[j].code_of_subject == subj[g].code)
					{
						cout << setw(20) << left << subj[g].name
							<< setw(11) << left << acc[j].date
							<< acc[j].mark << endl;
						cout << setw(53) << "";
					}
		}
	}
}

void accounting::show_info_about_three() {
}