#pragma once

#include "i4pch.h"


#ifdef I4_WND_PLATFORM

I4GE::I4GEApp* I4GE::MakeApp();

int main(int, char**)
{

	auto* app = I4GE::MakeApp();
	if (app->isRightCreatedWindow == 0)
	{
		return 0;
	}
	else if (app->isRightCreatedWindow == 1)
	{
		app->Run();
	}
	

	return 0;
}
#endif // I4_WND_PLATFORM