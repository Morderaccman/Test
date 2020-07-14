#pragma once
#include "i4pch.h"
#include <d3d9.h>

struct ConvertSheet
{
	ConvertSheet();
	~ConvertSheet();
	std::wstring s2ws(const std::string& s);
	std::string StrtoChar(const char& c);
};

