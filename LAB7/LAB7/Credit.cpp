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
	std::cout << "Пользователь не найден" << std::endl;
	return 0;
}

void Credit::available_credits()
{
	std::cout << "Выберите подходящий кредит:\n";
	std::cout << "1. До 100 т.р \n 2. От 100 до 500 т.р \n 3. От "
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
