#include "main.h"
#include "Classes.h"

bool is_repeat_operation() {
	cout << "Чтобы продолжить нажмите любую клавишу." << endl;
	cout << "Чтобы вернуться нажмите esc." << endl;
	return(_getch() != 27);
}