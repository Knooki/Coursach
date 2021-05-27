#pragma once
#include <iostream>
#include <cstdlib>

#include <conio.h>
#include <cctype>
#include <cwchar>

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include <cstdio>
#include <locale.h>
#include <ctime>
#include <io.h>
#include <fcntl.h>
#include <codecvt>

#include <algorithm>
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

#define space_students 48
#define space_subjects 26
#define space_accounting 49

int input_check();
void error_message(wstring message);
void complete_message(wstring message);
int switch_sort();
bool check_date(wstring str, wstring type);
bool check_date(wstring str, int number_of_semester, int course_of_stud);
bool is_russian_alpha(wchar_t c);
bool is_repeat_operation();