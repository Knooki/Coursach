#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <locale.h>
#include <ctime>
#include <time.h>
#include "sha1.h"
#define NOMINMAX
#include <Windows.h>

#define file_authentication "authentication_data.txt"
#define file "file.txt"
#define file_student "student_data.txt"
#define file_subject "subject_data.txt"
#define file_accounting "accounting_data.txt"

using namespace std;
static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void error_message(string message);
void complete_message(string message);
void show_info();
void show_sorted_info();
int switch_sort();
bool check_date(string str, string type);
bool check_date(string str, int number_of_semester, int course_of_stud);
bool is_russian_alpha(char c);
bool is_repeat_operation();