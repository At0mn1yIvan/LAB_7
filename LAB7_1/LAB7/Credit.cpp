#include "Credit.h"

int Credit::Authorization()
{
	int acc;
	std::string passw;
	std::cin >> acc;
	std::cin >> passw;
	for (int i = 0; i < 5; i++) {
		if (acc == data_acc[i] && passw == password[i]) {
			return i;
		}
	}
	std::cout << "������������ �� ������" << std::endl;
	return 0;
}

void Credit::TakeTheCredit(int i)
{
	std::cout << "�������� ���������� ������:\n";
	std::cout << "1. �� 100 �.�\n2. �� 100 �� 500 �.�\n3. �� 500 �.� �� 1 ���.�\n4. �� 1 �� 3 ���.�"<< std::endl;
	do {
		std::cin >> credit_info[1][i];
	} while ( credit_info[1][i] > 4 || credit_info[1][i] < 1);
	credit_info[0][i] = 1;
}

bool Credit::IsCredit(int i)
{
	if (credit_info[0][i] == 1) {
		std::cout << "������ ���� ������:" << std::endl;
		switch (credit_info[1][i])
		{
		case 1: std::cout << "������ �� 100 �.�\n"; break;
		case 2:	std::cout << "������ �� 100 �� 500 �.�\n"; break;
		case 3:	std::cout << "������ �� 500 �.� �� 1 ���.�\n"; break;
		case 4:	std::cout << "������ �� 1 �� 3 ���.�\n"; break;
		default:break;
		}
		return true;
	}
	else {
		std::cout << "������ �������� ���." << std::endl;
		return false;
	}
}

bool Credit::IsCreditAvailable(int i)
{
	if (credit_info[0][i] == 1) {
		std::cout << "������ ��� ����. ������ ������� ������� ����������." << std::endl;
		return false;
	}
	else {
		std::cout << "���������� ������� ��������." << std::endl;
		return true;
	}
}

