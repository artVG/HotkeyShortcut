#pragma once
#include <vector>
#include <fstream>
#include <codecvt>
#include <string>
#include <map>
#include <windows.h>
#include "CommandKeyboard.h"
#include "Functions.h"

#define COMMENT '#'
#define SEPARATOR ' '


/// <summary>
/// creator of command keyboard
/// </summary>
class Configurator
{
public:
	Configurator(const std::wstring& vkAddress);

	/// <summary>
	/// generate command keyboard fron config file
	/// </summary>
	/// <param name="configFile">file address</param>
	/// <returns></returns>
	CommandKeyboard generateKeyboard(const std::wstring& configFile) const;

private:
	/// <summary>
	/// hashmap of virtual keycodes
	/// </summary>
	std::map<std::wstring, int> virtualCodes;

	/// <summary>
	/// converts string name of key to its key code
	/// </summary>
	/// <param name="key">key name</param>
	/// <returns>virtual keycode of key or 0 if not found</returns>
	int getKeyCode(const std::wstring& key) const;

	/// <summary>
	/// converts string name of function type to adress
	/// </summary>
	/// <param name="type">neme of command type</param>
	/// <return>sfunction address or null if not found</returns>
	CommandFunction getFunction(const std::wstring& name) const;

	/// <summary>
	/// loader of virtual keycodes from resource file
	/// </summary>
	/// <param name="file">file address</param>
	void loadVirtualCodes(const std::wstring& address);

	/// <summary>
	/// get SEPARATOR position
	/// </summary>
	/// <param name="str">where to search</param>
	/// <param name="separator">what to search</param>
	/// <param name="start_at">position to start</param>
	/// <returns>separator index in string</returns>
	size_t findSeparator(const std::wstring& str, const wchar_t& separator, const size_t& start_at) const;

	/// <summary>
	/// convert string to key code
	/// </summary>
	/// <param name="str">what to convert</param>
	/// <returns>key code value</returns>
	int toKeyInt(const std::wstring& str) const;

	bool isCommandLine(const std::wstring& line) const;

	int parseKeyCode(const std::wstring& line, const size_t& begin, const size_t& end) const;
	CommandFunction parseKeyFunction(const std::wstring& line, const size_t& begin, const size_t& end) const;
	std::vector<INPUT> parseKeyData(const std::wstring& line, const size_t& begin) const;
};

