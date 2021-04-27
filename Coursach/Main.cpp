//knooki     a1e4e860b0eebcfa323fa79c41a9989b4a9dfd95
//venia11let 21a56638304140b3099acee719c3ab0b6ebc6c4b
#include "main.h"
#include "Classes.h"
//дружественные функции и классы friend
int main() {
	system("chcp 1251");
	string* login = new string;
	string* password = new string;
	entrance person(login, password);
	while (1) {
		switch (person.entering()) {
		case -1: return (0);
		case 0:
		{
			user student(login, password);
			student.operation();
		}
		break;
		case 1:
		{
			admin adm(login, password);
			adm.operation();
		}
		break;
		default: cout << "?" << endl;
			break;
		}
	}
	return(0);
}
