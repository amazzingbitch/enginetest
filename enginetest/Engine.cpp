#include "Engine.h"

Engine::Engine() {
	TArea = 20.0; // ����������� ����� �� ��������� 20 ��������
	SetValues(); // ������ �������� ��� ��������� �����
}

Engine::Engine(double TArea_) {
	TArea = TArea_; // ����������� �������� �����������
	SetValues();
}

void Engine::SetValues() {
	TEngine = TArea; // ����������� ��������� ����� ����������� ���. �����
	TOver = 110;
	Hm = 0.01;
	Hv = 0.0001;
	C = 0.1;
	I = 10.0;
	M = { 20.0, 75.0, 100.0, 105.0, 75.0, 0 };
	V = { 0, 75.0, 150.0, 200.0, 250.0, 300.0 };
	SetMV(); // ��������� ������� ��� ����������� ��������
}

void Engine::SetMV() {
	for (int i = 0; i < M.size()-1; i++) {
		double dM = (M[i + 1] - M[i]) / 1000; // ����������� ��������, ������� ������������ ������ ��� ������� �������
		double dV = (V[i + 1] - V[i]) / 1000;
		for (int j = 0; j < 1000; j++) {
			M1.push_back(M[i] + j * dM); // ��������� ������� 
			V1.push_back(V[i] + j * dV);
		}
	}
}

Engine::Engine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_) {
	TArea = TArea_;
	TEngine = TArea;
	TOver = TOver_; 
	Hm = Hm_; 
	Hv = Hv_; 
	C = C_; 
	I = I_;
	M.swap(M_); 
	V.swap(V_);
	SetMV();
}