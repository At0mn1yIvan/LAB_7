#pragma once

#include <iostream>
#include <string>


class ProcCenter
{
public:
	//data
	uint16_t data_acc[5] = {3457, 7865, 3462, 9999, 1233};
	std::string name_sername_patro[5] = {
		"������ ���� ���������",
		"������� Ը��� ���������",
		"��������� ������� ���������",
		"�������� ����� ��������",
		"�������� ������ ����������"
	};
	int money[5] = {350000, 120000, 67000, 50000, 1300000};
	std::string password[5] = {"asd45", "ku67ku", "arh455", "564drg", "hoho88"};
	char credit_info[2][5] = {
		{0, 0, 1, 1, 0},         // ���� �� ������
		{0, 0, 2, 3, 0},         // ����� ������� �������
	};
};

