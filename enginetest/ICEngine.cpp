#include "ICEngine.h"

ICEngine::ICEngine() : Engine() {}

ICEngine::ICEngine(double TArea_) : Engine(TArea_) {}

ICEngine::ICEngine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_) : Engine (TArea_, TOver_, Hm_, Hv_, C_, I_, M_, V_) {}

int ICEngine::VHeat(int i) {
	int f = 0; // ������������� ����� ��� ������������ ������
	W += A; // ������ �������� 
	double m = -1.0; // �������� ������ 
	if (i == 0) {
		m = M1[i]; // � ��������� ������ ������� m = 20
	} else {
		for (int j = 0; j < V1.size(); j++) {
			if (abs(W - V1[j]) <= 0.075) { // ������������ ����� �������� W � �������
				m = M1[j]; // ����� ����������� �� ���������������� ������� �������� ��������� �������
				break;
			}
		}
	}
	if (m < 0) {
		f = 1; // ���� �� ��� �������� �������� ������, �� ������ �������� �����
	} else {
		A = m / I; // ����� ������� ��������� 
		THeat = m * Hm + W * W * Hv; // � ����-�� ����������
	}
	return f; // ���������� �������� �����
}

void ICEngine::VChill() {
	TChill = C * (TArea - TEngine); // ������������ �������� ����-�� ����������
}

bool ICEngine::TChange() {
	bool f = false;
	TEngine = TEngine + TChill + THeat; // ������������ ����-�� ���������
	if (TEngine >= TOver) { // ���� ��������� ����������, ������ ��-� �����
		f = true;
	}
	return f; // ���������� �������� �����
}