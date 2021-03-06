#pragma once
#include <windows.h>
#include <string>
#include "InputCommand.h"

class Functions
{
public:
	static CommandFunction jornal(const std::wstring name);
	static void writeString(const void* chars, const int& arrSize);
};


