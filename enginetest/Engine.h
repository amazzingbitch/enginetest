#pragma once
#include <vector>
using namespace std;
class Engine
{
public:
	Engine(); // ����������� �� ���������
	Engine(double TArea_); // ����������� � ���������� �����������
	Engine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_); // ����������� � �����������
	virtual int VHeat(int i) = 0; // ����� ����������� ������� ������� ����-�� ����������
	virtual void VChill() = 0; // ����� ����������� ������� ������� ����-�� ����������

protected:
	double THeat = 0, TChill = 0, W = 0, // ���� ����-�� ����������, ����������, ������� ��������
		A = 0, TEngine, TArea, TOver, // ���������, ����-�� ���������, ���. �����, ���������
		Hm, Hv, C, I; // �����-�� ������������
	vector <double> M, V, M1, V1; // ������� �� ���������� ��������� ������� � ��������
	void SetValues(); // �������, �������� �������� ����� ������� ������
	void SetMV(); // �������, ������������ ��������� ��� ��������� ������� � ����������� �� ��������

};

