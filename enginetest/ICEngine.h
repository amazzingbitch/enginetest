#pragma once
#include "Engine.h"

class ICEngine :
    public Engine
{
public:
	ICEngine(); // ����������� �� ���������
	ICEngine(double TArea_); // ����������� � ���������� �����������
	ICEngine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_); // ����������� � �����������
private:
	int VHeat(int i) override; // ������� ������� ����-�� ����������
	void VChill() override; // ������� ������� ����-�� ����������
	bool TChange(); // ������� ������� ����-�� ���������

	friend class TestICE; // ����� TestICE ������������� �� ���-� � ������ ICEngine
};

