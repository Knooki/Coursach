#include "main.h"
#include "Classes.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	wstring* login = new wstring;
	wstring* group = new wstring;
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
		default: wcout << L"?" << endl;
			break;
		}
	}
	return(0);
}