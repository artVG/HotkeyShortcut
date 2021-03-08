#include "Helper.h"



std::vector<std::wstring> Helper::split(const std::wstring& str, wchar_t delimiter)
{
	std::vector<std::wstring> result;
	size_t start = -1;
	size_t end = str.find(delimiter);
	while (end != std::string::npos)
	{
		result.push_back(str.substr(start+1, end - start-1));
		start = end;
		end = str.find(delimiter, start+1);
		if (end == std::string::npos && str.size() > 0)
		{
			result.push_back(str.substr(start + 1, str.size() - start));
		}
	}
	return result;
}

std::wstring Helper::join(const std::vector<std::wstring> strings)
{
	std::wstring result;
	std::wstring delimiter = std::wstring{ DELIMITER };
	for (auto string = strings.begin(); string < strings.end(); string++)
	{
		if (string == strings.begin())
		{
			result += (*string);
		}
		else
		{
			result += (delimiter + *string);
		}
	}
	return result;
}