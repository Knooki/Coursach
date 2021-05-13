#include "main.h"
#include "Classes.h"

int main() {
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	string* login = new string;
	string* group = new string;
	entrance person(login, group);
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) {
		switch (person.entering()) {
		case 2: break;
		case -1: return (0);
		case 1:
		{
			admin adm(login);
			adm.operation();
		}
		break;
		case 0:
		{
			user student(login, group);
			student.operation();
		}
		break;
		default: cout << "?" << endl;
			break;
		}
	}
	return(0);
}