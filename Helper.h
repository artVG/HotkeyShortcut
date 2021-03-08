#pragma once
#include <vector>
#include <string>
#include "Configurator.h"

/// <summary>
/// support functions
/// </summary>
class Helper
{
public:
	/// <summary>
	/// split string by delimiter
	/// </summary>
	/// <param name="str"></param>
	/// <param name="delimiter"></param>
	/// <returns>vector of strings</returns>
	static std::vector<std::wstring> split(const std::wstring& str, wchar_t delimiter);
	static std::wstring join(const std::vector<std::wstring> strings);
};

