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
	void show_info();
	void add_info();
	void change_info();
	void delete_info();
};

struct subject {
	int code;
	string name;
	string teacher_name;
	int hours;
	int semester;
	vector<subject> load_from_file();
	void save_to_file(subject new_subj);
	void show_info_subj();
	void add_subj();
	void change_subj();
	void delete_subj();
};

struct student {
	int code_of_student;
	string full_name;
	string birth_date;
	string speciality;
	string group;
	vector<student> load_from_file();
	void save_to_file(student new_stud);
	void show_info_stud();
	void add_stud();
	void change_stud();
	void delete_stud();
};