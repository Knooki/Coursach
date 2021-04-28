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
#include "sha1.h"

#define file_log_pas "file_log_pas.txt"
#define file "file.txt"
#define file_student "student_data.txt"
#define file_subject "subject_data.txt"
#define file_accounting "accounting_data.txt"

using namespace std;

bool check_date(string str);
bool is_repeat_operation();