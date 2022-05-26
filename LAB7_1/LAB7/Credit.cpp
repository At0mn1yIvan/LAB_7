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
	std::cout << "Пользователь не найден" << std::endl;
	return 0;
}

void Credit::TakeTheCredit(int i)
{
	std::cout << "Выберите подходящий кредит:\n";
	std::cout << "1. До 100 т.р\n2. От 100 до 500 т.р\n3. От 500 т.р до 1 млн.р\n4. От 1 до 3 млн.р"<< std::endl;
	do {
		std::cin >> credit_info[1][i];
	} while ( credit_info[1][i] > 4 || credit_info[1][i] < 1);
	credit_info[0][i] = 1;
}

bool Credit::IsCredit(int i)
{
	if (credit_info[0][i] == 1) {
		std::cout << "Взятый вами кредит:" << std::endl;
		switch (credit_info[1][i])
		{
		case 1: std::cout << "Кредит до 100 т.р\n"; break;
		case 2:	std::cout << "Кредит от 100 до 500 т.р\n"; break;
		case 3:	std::cout << "Кредит от 500 т.р до 1 млн.р\n"; break;
		case 4:	std::cout << "Кредит от 1 до 3 млн.р\n"; break;
		default:break;
		}
		return true;
	}
	else {
		std::cout << "Взятых кредитов нет." << std::endl;
		return false;
	}
}

bool Credit::IsCreditAvailable(int i)
{
	if (credit_info[0][i] == 1) {
		std::cout << "Кредит уже взят. Взятие второго кредита невозможно." << std::endl;
		return false;
	}
	else {
		std::cout << "Оформление кредита доступно." << std::endl;
		return true;
	}
}

