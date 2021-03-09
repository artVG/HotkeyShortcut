#include "KeyMap.h"


int KeyMap::getKeyCode(const std::wstring& name)
{
	// find in KEY_MAP key by name
	auto item = KEY_MAP.find(name);
	// if found
	if (item != KEY_MAP.end())
	{
		// return key value
		return item->second;
	}
	// if not found
	return -1;
}