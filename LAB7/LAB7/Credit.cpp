#include "Credit.h"

int Credit::authorization()
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

void Credit::available_credits()
{
	std::cout << "�������� ���������� ������:\n";
	std::cout << "1. �� 100 �.� \n 2. �� 100 �� 500 �.� \n 3. �� "
		<< std::endl;
	int x;
	std::cin >> x;
	switch (x)
	{ 
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	default:
		break;
	}
}
