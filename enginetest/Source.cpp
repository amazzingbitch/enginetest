#include "TestICE.h"

void init();

int main() {
	init();
	return 0;
}

void init() { // ������� ������� ��������� ������
	TestICE stand; // ������� �������� ����� ��� ���
	stand.getResult(stand.enterValue()); // ���� �������� � ��������� ����������
}