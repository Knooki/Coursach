#pragma once
#include "main.h"

class entrance {
private:
	vector<string> _login, _password;
	vector<int> _type;
	string* log;
	int entr_menu();
	int load_from_file();
	bool save_to_file(string login, string password, int type);
public:
	entrance(string* log) {
		this->log = log;
	}
	void change_pas(string* login);
	int entering();
};

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
	string* login;
	int menu_user();
public:
	user(string* login) {
		this->login = login;
	}
	void operation();
};

struct subject {
	int code_of_subject;
	string name;
	string teacher_name;
	int hours;
	int number_of_semester;
	vector<subject> load_from_file();
	vector<subject> sort_array(vector<subject> arr);
	void save_to_file(subject new_subj);
	void change_data_in_file(vector<subject> array, string type_sort);
	void show_info_subj(string sort_type);
	void add_subj();
	void change_subj();
	void delete_subj_or_sort_subj(string type);
};

struct student {
	int code_of_student;
	string full_name;
	string birth_date;
	string speciality;
	string group;
	int course;
	vector<student> load_from_file();
	vector<student> sort_array(vector<student> array);
	vector<student> sort_array_of_accounting(vector<student> array_of_stud);
	void save_to_file(student new_stud);
	void change_data_in_file(vector<student> array, string type_sort);
	void show_info_stud(string sort_type);
	void add_stud();
	void change_stud();
	void delete_stud_or_sort_stud(string type);
};

struct accounting {
	student st;
	subject sub;
	string date;
	int mark;
	int code_of_acc;
	vector<accounting> load_from_file();
	void save_to_file(accounting new_acc);
	void change_data_in_file(vector<accounting> array, string type_sort);
	void show_info(string sort_type);
	void add_info();
	void change_info();
	void delete_info_or_sort_info(string type);
	void show_info_about_three();
	void delete_all_info_about_student(int code_of_student);
};