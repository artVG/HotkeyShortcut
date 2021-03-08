#pragma once
#include <string>
#include <codecvt>
#include <fstream>
#include <memory>
#include "KeyMap.h"
#include "CommandKeyboard.h"
#include "FunctionBuilder.h"
#include "Helper.h"

#define COMMENT '#'
#define DELIMITER ' '


/// <summary>
/// creator of command keyboard
/// </summary>
class Configurator
{
public:
	/// <summary>
	/// generate command keyboard fron config file
	/// </summary>
	/// <param name="configFile">file address</param>
	/// <returns></returns>
	static CommandKeyboard generateKeyboard(const std::wstring& configFile);

private:
	/// <summary>
	/// check if line is user defined command
	/// </summary>
	/// <param name="line"></param>
	/// <returns></returns>
	static bool isCommandLine(const std::wstring& line);
};



