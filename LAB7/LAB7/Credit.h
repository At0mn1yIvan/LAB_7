#pragma once

#include "ProcCenter.h"

class Credit : public ProcCenter
{
public:
	int authorization();
	void available_credits();
};

