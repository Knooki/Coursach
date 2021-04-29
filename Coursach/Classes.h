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
	admin() {}
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

struct accounting {
	int code_of_student;
	int code_of_subject;
	string date;
	int mark;
	vector<accounting> load_from_file();
	void show_info(string sort_type);
	void add_info();
	void change_info();
	void delete_info_or_sort_info(string type);
	void show_info_about_three();
};

struct subject {
	int code;
	string name;
	string teacher_name;
	int hours;
	int semester;
	vector<subject> load_from_file();
	vector<subject> sort_array(vector<subject> arr);
	void save_to_file(subject new_subj);
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
	vector<student> load_from_file();
	vector<student> sort_array(vector<student> array);
	void save_to_file(student new_stud);
	void show_info_stud(string sort_type);
	void add_stud();
	void change_stud();
	void delete_stud_or_sort_stud(string type);
};