#pragma once

#include <iostream>
#include <string>


class ProcCenter
{
public:
	ProcCenter();
	//data
	uint16_t data_acc[5];
	std::string name_sername_patro[5];
	int money[5];
	std::string password[5];
	int credit_info[7][5];

	//uint16_t data_acc[5] = {3457, 7865, 3462, 9999, 1233};
	//std::string name_sername_patro[5] = {
	//	"?????? ???? ?????????",
	//	"??????? Ը??? ?????????",
	//	"????????? ??????? ?????????",
	//	"???????? ????? ????????",
	//	"???????? ?????? ??????????"
	//};
	//int money[5] = {350000, 120000, 67000, 50000, 1300000};
	//std::string password[5] = {"asd45", "ku67ku", "arh455", "564drg", "hoho88"};
	//int credit_info[7][5] = {
	//	{0, 0, 1, 1, 0},         // ???? ?? ??????
	//	{0, 0, 300000, 700000, 0}, // ????? ???????
	//	{0, 0, 27000, 37100, 0},  // ??????????? ?????? 
	//	{0, 0, 135000, 296800, 0}, // ??????? ?? ???????
	//	{0, 0, 12, 20, 0}, // ????????? ?????? (??????)
	//	{0, 0, 5, 8, 0}, // ???????? ???????
	//	{0, 0, 8, 6, 0}  // ????????
	//};
};

