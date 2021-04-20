#pragma once
#include "main.h"
class admin {
private:
	string* password, * login;
	int menu_admin();
	void add_data();
	void change_data();
	void delete_data();
	void user_manage();
	void change_pas();
public:
	admin(string* login, string* password) {
		this->login = login;
		this->password = password;
	}
	void operation();
};