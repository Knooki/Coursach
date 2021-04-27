#pragma once
#include "main.h"
class entrance {
private:
	string login, password, * log, * pas;
	int type;
	vector<string> _login, _password;
	vector<int> _type;
	int entr_menu();
	int load_from_file();
	bool save_in_file(string login, string password, int type);
public:
	entrance(string* log, string* pas) {
		this->log = log;
		this->pas = pas;
	}
	entrance() {}
	void change_pas(string* login, string* password);
	int entering();
};

class admin {
private:
	string* login, * password;
	int menu_admin();
	void add_data();
	void change_data();
	void delete_data();
	void user_manage();
public:
	admin(string* login, string* password) {
		this->login = login;
		this->password = password;
	}
	admin() {}
	void three_subjects();//Вывести на экран 3 пред-мета по которым больше всего отрицательных оценок
	void show_info();
	void search();
	void operation();
};

class user {
private:
	//сделай счетчик с помощью static
	string* login, * password;
	int menu_user();
public:
	user(string* login, string* password) {
		this->login = login;
		this->password = password;
	}
	void operation();
};

class subject {
private:
	int code;
	string name;
	string teacher_name;
	int hours;
	int semester;
public:
	subject() {}
};
