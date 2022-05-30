#include <stdlib.h>
#include "Credit.h"
#include "Conio.h"



Credit::Credit() : user_(0)
{
	int acc;
	std::string passw;
	std::cout << "������� ����� ����������� �����: ";
	std::cin >> acc;
	std::cout << "\n������� ������: ";
	std::cin >> passw;
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (acc == data_acc[i] && passw == password[i]) {
			user_ = i;
			flag = 1;
			Menu();
			break;
		}
	}
	if (flag == 0) {
		std::cout << "������������ �� ������" << std::endl;
		Menu();
	}
}

void Credit::Authorization()
{
	int acc;
	std::string passw;
	std::cout << "������� ����� ����������� �����: ";
	std::cin >> acc;
	std::cout << "\n������� ������: ";
	std::cin >> passw;
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (acc == data_acc[i] && passw == password[i]) {
			user_ = i;
			flag = 1;
			Menu();
			break;
		}
	}
	if (flag == 0) {
		std::cout << "������������ �� ������" << std::endl;
		Menu();
	}
}

void Credit::ShowTheRates()
{
	std::cout <<"������:\n1. �� 100 �.�. (10% / 6 ���.)\n2. �� 100 �� 500 �.�. (8% / 12 ���.)\n3. �� 500 �.�. �� 1 ���.�. (6% / 20 ���.)\n4. �� 1 �� 3 ���.�. (4% / 36 ���.)" << std::endl;
	EscapeBind();
}


void Credit::TakeTheCredit()
{
	if (credit_info[0][user_] == 0) {
		std::cout << "������� �������� ����� ������� :\n";
		std::cin >> credit_info[1][user_];
		std::cout << "������ ��������!" << std::endl;
		credit_info[0][user_] = 1;
		if (0 < credit_info[1][user_] && credit_info[1][user_] < 100000) {
			credit_info[4][user_] = 6;
			credit_info[6][user_] = 10;
		}
		if (100000 <= credit_info[1][user_] && credit_info[1][user_] < 500000) {
			credit_info[4][user_] = 12;
			credit_info[6][user_] = 8;

		}
		if (500000 <= credit_info[1][user_] && credit_info[1][user_] < 1000000) {
			credit_info[4][user_] = 20;
			credit_info[6][user_] = 6;

		}
		if (1000000 <= credit_info[1][user_] && credit_info[1][user_] < 3000000) {
			credit_info[4][user_] = 36;
			credit_info[6][user_] = 4;
		}
		money[user_] += credit_info[1][user_];
		credit_info[2][user_] = (credit_info[1][user_] / 100 * (100 + credit_info[6][user_])) / credit_info[4][user_];
		credit_info[3][user_] = credit_info[1][user_] / 100 * (100 + credit_info[6][user_]);
		credit_info[5][user_] = credit_info[4][user_];
		EscapeBind();
	}
	else {
		std::cout << "���������� ������� ����������\n";
		EscapeBind();
	}
}

void Credit::IsCredit()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "������ ���� ������: ";
		if (0 < credit_info[1][user_] && credit_info[1][user_] < 100000)
			std::cout << " ������ �� 100 �.�. (10% / 6 ���.)" << std::endl;
		if (100000 <= credit_info[1][user_] && credit_info[1][user_] < 500000)
			std::cout << " ������ 100-500 �.�. (8% / 12 ���.)" << std::endl;
		if (500000 <= credit_info[1][user_] && credit_info[1][user_] < 1000000)
			std::cout << " ������ 500 �.�. - 1 ���.�. (6% / 20 ���.)" << std::endl;
		if (1000000 <= credit_info[1][user_] && credit_info[1][user_] < 3000000)
			std::cout << " ������ 1 - 3 ���.�. (4% / 36 ���.)" << std::endl;
		std::cout << "\n����� �������: " << credit_info[1][user_] << std::endl;
		EscapeBind();
	}
	else {
		std::cout << "������ �������� ���." << std::endl;
		EscapeBind();
	}
	
}

void Credit::IsCreditAvailable()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "������ ��� ����. ������ ������� ������� ����������." << std::endl;
	}
	else {
		std::cout << "���������� ������� ��������." << std::endl;
	}
	EscapeBind();
}

void Credit::CreditStatus()
{
	std::cout << "������������: " << name_sername_patro[user_] << std::endl;
	std::cout << "����� ����� �� �����: " << money[user_] << std::endl;
	if (credit_info[0][user_] == 1) {
		std::cout << "����� �������: " << credit_info[1][user_] << std::endl;
		std::cout << "����������� �����: " << credit_info[2][user_] << std::endl;
		std::cout << "������� �� �������: " << credit_info[3][user_] << std::endl;
		std::cout << "��������� ������ (���.): " << credit_info[4][user_] << " || �������� �������: " << credit_info[5][user_] << std::endl;
	}
	else
		std::cout << "������ �������� ���." << std::endl;
	EscapeBind();
}

void Credit::RepayTheDept()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "������������: " << name_sername_patro[user_] << std::endl;
		std::cout << "����� ����� �� �����: " << money[user_] << std::endl;
		std::cout << "�������� �������: " << credit_info[5][user_] << std::endl;
		std::cout << "������� �� �������: " << credit_info[3][user_] << std::endl;
		std::cout << "����������� �����: " << credit_info[2][user_] << std::endl;
		std::cout << "\n�������� ��������� ������������� �� ������� �����?" << std::endl;
		if (_getch() == 13) {
			if (money[user_] >= credit_info[2][user_]) {
				money[user_] -= credit_info[2][user_];
				credit_info[3][user_] -= credit_info[2][user_];
				credit_info[5][user_]--;
				system("cls");
				if (credit_info[3][user_] == 0) {
					credit_info[0][user_] = 0;
					system("cls");
					std::cout << "\n�����������! �� ��������� �������� ���� ������!" << std::endl;
					EscapeBind();
				}
				RepayTheDept();
			}
			else
				std::cout << "�� ����� ������������ ������� ��� ��������� ��������� �������������" << std::endl;
		}
		else
			RepayTheDept();
	}
	else
		std::cout << "������ �������� ���." << std::endl;
	EscapeBind();
}

void Credit::RepayTheDeptEarly()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "������������: " << name_sername_patro[user_] << std::endl;
		std::cout << "����� ����� �� �����: " << money[user_] << std::endl;
		std::cout << "�������� �������: " << credit_info[5][user_] << std::endl;
		std::cout << "������� �� �������: " << credit_info[3][user_] << std::endl;
		std::cout << "����������� �����: " << credit_info[2][user_] << std::endl;
		std::cout << "\n�������� �������� ������?" << std::endl;
		if (_getch() == 13) {
			if (money[user_] >= credit_info[3][user_]) {
				money[user_] -= credit_info[3][user_];
				credit_info[3][user_] = 0;
				credit_info[5][user_] = 0;
				credit_info[0][user_] = 0;
				system("cls");
				std::cout << "\n�����������! �� �������� �������� ���� ������!" << std::endl;
			}
			else
				std::cout << "�� ����� ������������ ������� ��� ��������� ������� ��������" << std::endl;
		}
		else
			RepayTheDeptEarly();
	}
	else
		std::cout << "������ �������� ���." << std::endl;
	EscapeBind();
}

void Credit::Menu()
{
	std::cout << "\n�������� �������:\n" << std::endl;
	std::cout << "1) ����������� �������.\n2) ���������� � ��������� ��������.\n3) ��������� ������� ������� � ����� �������.\n4) ��������� ����������� ��������� ���������� �������.\n";
	std::cout << "5) �������� ��������� ������.\n6) �������� ������� ��������� �������.\n7) �������� ���������� �� �������.\n8) �������� �������� ������.\n";
	switch (_getch())
	{
	case 49: system("cls"); Authorization(); break;
	case 50: system("cls"); ShowTheRates(); break;
	case 51: system("cls"); IsCredit(); break;
	case 52: system("cls"); IsCreditAvailable(); break;
	case 53: system("cls"); TakeTheCredit(); break;
	case 54: system("cls"); CreditStatus(); break;
	case 55: system("cls"); RepayTheDept(); break;
	case 56: system("cls"); RepayTheDeptEarly(); break;
	case 27: EscapeBind(); break;
	}
}

void Credit::EscapeBind()
{
	if (_getch() == 27) {
		system("cls");
		Menu();
	}
}



