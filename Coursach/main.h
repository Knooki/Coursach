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
#include <io.h>
#include <fcntl.h>

#define file_authentication "authentication_data.txt"
#define file "file.txt"
#define file_student "student_data.txt"
#define file_subject "subject_data.txt"
#define file_accounting "accounting_data.txt"
#define file_faculty "faculty_data.txt"

using namespace std;
static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

#define space_between_columns 4

int input_check();
void error_message(wstring message);
void complete_message(wstring message);
void show_info(wstring type);
void show_sorted_info(wstring type);
int switch_sort();
void search_info(wstring group);
bool check_date(wstring str, wstring type);
bool check_date(wstring str, int number_of_semester, int course_of_stud);
bool is_russian_alpha(char c);
bool is_repeat_operation();