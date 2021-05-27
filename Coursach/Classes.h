#pragma once
#include "main.h"

class user {
private:
	wstring* login, * group;
	int menu_user();
protected:
	void show_info(wstring group);
	void show_sorted_info(wstring group);
	void search_info(wstring group);
public:
	user(wstring* login, wstring* group) {
		this->login = login;
		this->group = group;
	}
	user(wstring* login, wstring group) {
		this->login = login;
		this->group = &group;
	}
	void operation();
};

class admin : private user {
private:
	wstring* login;
	int menu_admin();
	void add_data();
	void change_data();
	void delete_data();
	void sort_data();
	void user_manage();
public:
	admin(wstring* login) :user(login, L"admin") {
		this->login = login;
	}
	void operation();
};

class student {
private:
	wstring birth_date;
	wstring speciality;
	wstring faculty;
	vector<student> sort_array(vector<student> array);
	vector<student> sort_date(vector<student> array, int type);
	void save_to_file(student new_stud);
	void change_data_in_file(vector<student> array, wstring type_sort);
	int search_menu(wstring type);
	void print(vector<student> array, wstring group);
protected:
	int code_of_student;
	wstring full_name;
	wstring group;
	int course;
	vector<student> load_from_file();
public:
	student() {}
	int get_code_of_student() {
		return (code_of_student);
	}
	wstring get_full_name() {
		return(full_name);
	}
	wstring get_group() {
		return(group);
	}
	int get_course() {
		return(course);
	}
	void show_info_stud(wstring group, wstring sort_type);
	void search_student(wstring group);
	void add_stud();
	void change_stud();
	void delete_stud_or_sort_stud(wstring type);
};

class entrance : protected student {
private:
	vector<wstring> _login, _password, _group;
	vector<int> _type;
	wstring* log;
	wstring* gr;
	int entr_menu();
	int load_from_file();
	bool save_to_file(wstring login, wstring password, int type, wstring group);
	void change_data_in_file();
public:
	entrance() {}
	entrance(wstring* log, wstring* group) :student() {
		this->log = log;
		this->gr = group;
	}
	bool change_pas(wstring* login);
	int entering();
	void delete_users_with_group(wstring group);
};

class subject {
private:
	int hours;
	vector<subject> sort_array(vector<subject> arr);
	int search_menu();
	void save_to_file(subject new_subj);
	void change_data_in_file(vector<subject> array, wstring type_sort);
	void print(vector<subject> array);
protected:
	int code_of_subject;
	wstring name;
	wstring teacher_name;
	int number_of_semester;
	vector<subject> load_from_file();
public:
	subject() {}
	int get_code_of_subject() {
		return (code_of_subject);
	}
	wstring get_name() {
		return(name);
	}
	wstring get_teacher_name()
	{
		return (teacher_name);
	}
	int get_number_of_semester() {
		return(number_of_semester);
	}
	void show_info_subj(wstring sort_type);
	void search_subject();
	void add_subj();
	void change_subj();
	void delete_subj_or_sort_subj(wstring type);
};

struct accounting : public student, public subject {
private:
	wstring date;
	int mark;
	int code_of_acc;
	void save_to_file(accounting new_acc);
	int search_menu(wstring group);
	vector<accounting> sort_array_of_accounting(vector<accounting> array_of_acc);
	void print(vector<accounting> acc, wstring group);
	void print(vector<accounting> array);
public:
	accounting() : student(), subject() {}
	vector<accounting> load_from_file();
	void change_data_in_file(vector<accounting> array, wstring type_sort);
	void show_info(wstring group, wstring sort_type);
	void search_info(wstring group);
	void add_info();
	void change_info();
	void delete_info_or_sort_info(wstring type);
	void show_info_about_three();
	void delete_all_info_about_student(int code_of_student);
};

struct student_account {
	int code_of_student;
	wstring full_name;
	int code_of_subject;
	wstring name_of_subject;
	wstring teacher_name;
	vector<int> marks;
	int amount_of_negative_marks;
	float average_score;
};