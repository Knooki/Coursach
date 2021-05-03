#pragma once
#include "main.h"

class admin {
private:
	string* login;
	int menu_admin();
	void add_data();
	void change_data();
	void delete_data();
	void sort_data();
	void user_manage();
public:
	admin(string* login) {
		this->login = login;
	}
	void operation();
};

class user {
private:
	string* login, * group;
	int menu_user();
public:
	user(string* login, string* group) {
		this->login = login;
		this->group = group;
	}
	void operation();
};

class student {
protected:
	int code_of_student;
	string full_name;
	string birth_date;
	string speciality;
	string group;
	string faculty;
	int course;
	vector<student> load_from_file();
	vector<student> sort_array(vector<student> array);
	vector<student> sort_date(vector<student> array, int type);
	void save_to_file(student new_stud);
	void change_data_in_file(vector<student> array, string type_sort);
public:
	student() {}
	int get_code_of_student() {
		return (code_of_student);
	}
	string get_full_name() {
		return(full_name);
	}
	string get_group() {
		return(group);
	}
	int get_course() {
		return(course);
	}
	void show_info_stud(string group, string sort_type);
	void add_stud();
	void change_stud();
	void delete_stud_or_sort_stud(string type);
};

class entrance : protected student {
private:
	vector<string> _login, _password, _group;
	vector<int> _type;
	string* log;
	string* gr;
	int entr_menu();
	int load_from_file();
	bool save_to_file(string login, string password, int type, string group);
	void change_data_in_file();
public:
	entrance() {}
	entrance(string* log, string* group) :student() {
		this->log = log;
		this->gr = group;
	}
	bool change_pas(string* login);
	int entering();
	void delete_users_with_group(string group);
};

class subject {
protected:
	int code_of_subject;
	string name;
	string teacher_name;
	int hours;
	int number_of_semester;
	vector<subject> load_from_file();
	vector<subject> sort_array(vector<subject> arr);
	void save_to_file(subject new_subj);
	void change_data_in_file(vector<subject> array, string type_sort);
public:
	subject() {}
	int get_code_of_subject() {
		return (code_of_subject);
	}
	string get_name() {
		return(name);
	}
	string get_teacher_name()
	{
		return (teacher_name);
	}
	int get_number_of_semester() {
		return(number_of_semester);
	}
	void show_info_subj(string sort_type);
	void add_subj();
	void change_subj();
	void delete_subj_or_sort_subj(string type);
};

struct accounting : public student, public subject {
private:
	string date;
	int mark;
	int code_of_acc;
	void save_to_file(accounting new_acc);
	vector<student> sort_array_of_accounting(vector<student> array_of_stud);
public:
	accounting() : student(), subject() {}
	vector<accounting> load_from_file();
	void change_data_in_file(vector<accounting> array, string type_sort);
	void show_info(string group, string sort_type);
	void add_info();
	void change_info();
	void delete_info_or_sort_info(string type);
	void show_info_about_three();
	void delete_all_info_about_student(int code_of_student);
};

struct student_account {
	int code_of_student;
	string full_name;
	int code_of_subject;
	string name_of_subject;
	string teacher_name;
	vector<int> marks;
	int amount_of_negative_marks;
	float average_score;
};

struct faculty {
	int faculty;
	vector<string> speciality;
	vector<string> load_from_file();
};