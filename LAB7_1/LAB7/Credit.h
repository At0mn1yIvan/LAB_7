#pragma once

#include "ProcCenter.h"

class Credit : public ProcCenter
{
public:
	int Authorization();
	void TakeTheCredit(int i);
	bool IsCredit(int i);
	bool IsCreditAvailable(int i);
};

