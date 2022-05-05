#include "TestICE.h"

double TestICE::enterValue() {
	double temp;
	while (true) { // ��������� ����� ����������� ������ �� ��� ���, ���� �� ����� ������� ���������� ��������
		cout << "Enter the temperature: ";
		cin >> temp;

		if (cin.fail()) { // �������� �� ������������ ��������� ������
			cin.clear();
			cin.ignore(32767, '\n');
		} else {
			break;
		}
	}
	return temp;
}

void TestICE::getResult(double temp) {
	ICEngine test(temp); // ������� ���

	int time = start(test); // �������� ������� �����
	switch (time) {
	case -1:
		cout << "The engine hasn't overheated\n"; // �� �������� ����� ��������� �� ����������
		break;
	case -2:
		cout << "Not enough data to simulate\n"; // ������������ ������ ��� ��������� ������ ���������
		break;
	default:
		cout << "The time it took for the engine to overheat: " << time << " seconds\n"; // ����� ������� ������������ ���������
	}
}

int TestICE::start(ICEngine& test) {
	int i, j = -1;

	for (i = 0; i < B; i++) {
		if (test.VHeat(i)) { // ������ ����-�� ����������
			j = -2; //���� �� ��� �������� �������� ������ - ����� �� �����
			break;
		}
		test.VChill(); // ������ ����-�� ����������
		if (test.TChange()) { // ���� ��������� ����������, �� ������� �� �����
			j = i;
			break;
		}
	}

	return j; // ���������� ����� ��� ������
}