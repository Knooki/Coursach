#include "main.h"
#include "Classes.h"

bool is_repeat_operation() {
	cout << "����� ���������� ������� ����� �������." << endl;
	cout << "����� ��������� ������� esc." << endl;
	return(_getch() != 27);
}