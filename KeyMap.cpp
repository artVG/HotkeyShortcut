#include "KeyMap.h"


int KeyMap::getKeyCode(const std::wstring& name)
{
	auto item = KEY_MAP.find(name);
	if (item != KEY_MAP.end())
	{
		return item->second;
	}
	return -1;
}