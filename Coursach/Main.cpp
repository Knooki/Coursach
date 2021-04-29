//knooki 1
//venia11let
//knukknakiknak 0
//venia11let
//knuks 0
//venia11let
#include "main.h"
#include "Classes.h"

int main() {
	setlocale(LC_ALL, "Rus");
	system("chcp 1251");
	string* login = new string;
	entrance person(login);
	while (1) {
		switch (person.entering()) {
		case 2: break;
		case -1: return (0);
		case 0:
		{
			user student(login);
			student.operation();
		}
		break;
		case 1:
		{
			admin adm(login);
			adm.operation();
		}
		break;
		default: cout << "?" << endl;
			break;
		}
	}
	return(0);
}
