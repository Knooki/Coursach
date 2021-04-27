//knooki     a1e4e860b0eebcfa323fa79c41a9989b4a9dfd95
//venia11let 21a56638304140b3099acee719c3ab0b6ebc6c4b
#include "main.h"
#include "Classes.h"
int main() {
	system("chcp 1251");
	string* login = new string;
	entrance person(login);
	while (1) {
		switch (person.entering()) {
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