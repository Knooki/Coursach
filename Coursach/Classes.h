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
	int code_of_student;
	string full_name;
	string birth_date;
	string speciality;
	int group;
	string* login;
	int menu_user();
public:
	user(string* login) {
		this->login = login;
	}
	user(string* login, int code_of_student, string full_name, string birth_date, string speciality, int group) {
		this->login = login;
		this->code_of_student = code_of_student;
		this->full_name = full_name;
		this->birth_date = birth_date;
		this->speciality = speciality;
		this->group = group;
	}
	void operation();
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