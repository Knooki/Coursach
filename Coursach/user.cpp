#include "main.h"
#include "user.h"

int user::menu_user() {
	int sw;
	cout << "Выберите опцию:" << endl;
	cout << "1)Просмотр всех данных в виде табличной формы." << endl;
	cout << "2)Вывести на экран 3 предмета по которым у вас больше всего отрицательных оценок." << endl;
	cout << "3)Поиск данных." << endl;
	cout << "4)Выход в меню первого уровня." << endl;
	while (!(cin >> sw) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ошибка. Вы можете ввести только цифры." << endl;
	}
	return (sw);
}

void user::show_information() {
}