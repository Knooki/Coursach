#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include "sha1.h"

#define file_log_pas "file_log_pas.txt"
#define file "file.txt"

using namespace std;

void show_data();
void search();
bool is_repeat_operation();