#include <stdlib.h>
#include "Credit.h"
#include "Conio.h"



Credit::Credit() : user_(0)
{
	int acc;
	std::string passw;
	std::cout << "Введите номер зарплатного счёта: ";
	std::cin >> acc;
	std::cout << "\nВведите пароль: ";
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
		std::cout << "Пользователь не найден" << std::endl;
		Menu();
	}
}

void Credit::Authorization()
{
	int acc;
	std::string passw;
	std::cout << "Введите номер зарплатного счёта: ";
	std::cin >> acc;
	std::cout << "\nВведите пароль: ";
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
		std::cout << "Пользователь не найден" << std::endl;
		Menu();
	}
}

void Credit::ShowTheRates()
{
	std::cout <<"Тарифы:\n1. До 100 т.р. (10% / 6 мес.)\n2. От 100 до 500 т.р. (8% / 12 мес.)\n3. От 500 т.р. до 1 млн.р. (6% / 20 мес.)\n4. От 1 до 3 млн.р. (4% / 36 мес.)" << std::endl;
	EscapeBind();
}


void Credit::TakeTheCredit()
{
	if (credit_info[0][user_] == 0) {
		std::cout << "Введите желаемую сумму кредита :\n";
		std::cin >> credit_info[1][user_];
		std::cout << "Кредит оформлен!" << std::endl;
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
		std::cout << "Оформление кредита недоступно\n";
		EscapeBind();
	}
}

void Credit::IsCredit()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "Взятый вами кредит: ";
		if (0 < credit_info[1][user_] && credit_info[1][user_] < 100000)
			std::cout << " Кредит до 100 т.р. (10% / 6 мес.)" << std::endl;
		if (100000 <= credit_info[1][user_] && credit_info[1][user_] < 500000)
			std::cout << " Кредит 100-500 т.р. (8% / 12 мес.)" << std::endl;
		if (500000 <= credit_info[1][user_] && credit_info[1][user_] < 1000000)
			std::cout << " Кредит 500 т.р. - 1 млн.р. (6% / 20 мес.)" << std::endl;
		if (1000000 <= credit_info[1][user_] && credit_info[1][user_] < 3000000)
			std::cout << " Кредит 1 - 3 млн.р. (4% / 36 мес.)" << std::endl;
		std::cout << "\nСумма кредита: " << credit_info[1][user_] << std::endl;
		EscapeBind();
	}
	else {
		std::cout << "Взятых кредитов нет." << std::endl;
		EscapeBind();
	}
	
}

void Credit::IsCreditAvailable()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "Кредит уже взят. Взятие второго кредита невозможно." << std::endl;
	}
	else {
		std::cout << "Оформление кредита доступно." << std::endl;
	}
	EscapeBind();
}

void Credit::CreditStatus()
{
	std::cout << "Пользователь: " << name_sername_patro[user_] << std::endl;
	std::cout << "Сумма денег на счету: " << money[user_] << std::endl;
	if (credit_info[0][user_] == 1) {
		std::cout << "Сумма кредита: " << credit_info[1][user_] << std::endl;
		std::cout << "Ежемесячный платёж: " << credit_info[2][user_] << std::endl;
		std::cout << "Остаток по кредиту: " << credit_info[3][user_] << std::endl;
		std::cout << "Кредитный период (мес.): " << credit_info[4][user_] << " || Осталось месяцев: " << credit_info[5][user_] << std::endl;
	}
	else
		std::cout << "Взятых кредитов нет." << std::endl;
	EscapeBind();
}

void Credit::RepayTheDept()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "Пользователь: " << name_sername_patro[user_] << std::endl;
		std::cout << "Сумма денег на счету: " << money[user_] << std::endl;
		std::cout << "Осталось месяцев: " << credit_info[5][user_] << std::endl;
		std::cout << "Остаток по кредиту: " << credit_info[3][user_] << std::endl;
		std::cout << "Ежемесячный платёж: " << credit_info[2][user_] << std::endl;
		std::cout << "\nПогасить кредитную задолженность за текущий месяц?" << std::endl;
		if (_getch() == 13) {
			if (money[user_] >= credit_info[2][user_]) {
				money[user_] -= credit_info[2][user_];
				credit_info[3][user_] -= credit_info[2][user_];
				credit_info[5][user_]--;
				system("cls");
				if (credit_info[3][user_] == 0) {
					credit_info[0][user_] = 0;
					system("cls");
					std::cout << "\nПоздравляем! Вы полностью погасили свой кредит!" << std::endl;
					EscapeBind();
				}
				RepayTheDept();
			}
			else
				std::cout << "На счету недостаточно средств для погашения кредитной задолженности" << std::endl;
		}
		else
			RepayTheDept();
	}
	else
		std::cout << "Взятых кредитов нет." << std::endl;
	EscapeBind();
}

void Credit::RepayTheDeptEarly()
{
	if (credit_info[0][user_] == 1) {
		std::cout << "Пользователь: " << name_sername_patro[user_] << std::endl;
		std::cout << "Сумма денег на счету: " << money[user_] << std::endl;
		std::cout << "Осталось месяцев: " << credit_info[5][user_] << std::endl;
		std::cout << "Остаток по кредиту: " << credit_info[3][user_] << std::endl;
		std::cout << "Ежемесячный платёж: " << credit_info[2][user_] << std::endl;
		std::cout << "\nДосрочно погасить кредит?" << std::endl;
		if (_getch() == 13) {
			if (money[user_] >= credit_info[3][user_]) {
				money[user_] -= credit_info[3][user_];
				credit_info[3][user_] = 0;
				credit_info[5][user_] = 0;
				credit_info[0][user_] = 0;
				system("cls");
				std::cout << "\nПоздравляем! Вы досрочно погасили свой кредит!" << std::endl;
			}
			else
				std::cout << "На счету недостаточно средств для погашения кредита досрочно" << std::endl;
		}
		else
			RepayTheDeptEarly();
	}
	else
		std::cout << "Взятых кредитов нет." << std::endl;
	EscapeBind();
}

void Credit::Menu()
{
	std::cout << "\nВыберите функцию:\n" << std::endl;
	std::cout << "1) Авторизация клиента.\n2) Информация о доступных кредитах.\n3) Проверить наличие взятого в банке кредита.\n4) Проверить возможность получения выбранного кредита.\n";
	std::cout << "5) Получить выбранный кредит.\n6) Показать текущее состояние кредита.\n7) Погасить начисления по кредиту.\n8) Досрочно погасить кредит.\n";
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



