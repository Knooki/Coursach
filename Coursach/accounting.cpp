#include "main.h"
#include "Classes.h"

void accounting::add_info() {
}

void accounting::change_info() {
}

void accounting::delete_info() {
}

void accounting::show_info() {
	vector<student> stud;
	student st;
	stud = st.load_from_file();
	vector<subject> subj;
	subject sub;
	subj = sub.load_from_file();
	vector<accounting> acc;
	accounting buffer;
	fstream fin;
	fin.open(file_accounting, ios_base::in);
	if (!fin.is_open()) cout << "Ошибка открытия файла." << endl;
	else {
		int i = 0;
		while (i < stud.size() * subj.size())
		{
			fin >> buffer.code_of_student;
			fin.ignore(1);
			fin >> buffer.code_of_subject;
			fin.ignore(1);
			getline(fin, buffer.date, ',');
			fin >> buffer.mark;
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
			acc.push_back(buffer);
			i++;
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
			for (register int j = 0; j < stud.size() * subj.size(); j++)
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
}