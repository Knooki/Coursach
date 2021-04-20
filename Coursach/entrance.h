#pragma once
#include "main.h"

class log_pas {
private:
	string login, password, * pas, * log;
	int type;
	vector<string> _login, _password;
	vector<int> _type;
	int entr_menu();
	int load_from_file();
	bool load_in_file(string login, string password, int type);
public:
	log_pas(string* log, string* pas) {
		this->pas = pas;
		this->log = log;
	}
	log_pas(string login, string password) {
		this->login = login;
		this->password = password;
	}
	int entrance();
	void change_pas();
};