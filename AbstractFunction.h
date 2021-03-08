#pragma once
#include <string>

/// <summary>
/// Base class for all hotkey functions.
/// </summary>
class AbstractFunction
{
public:
	/// <summary>
	/// Function executer
	/// </summary>
	virtual void run() = 0;

	/// <summary>
	/// Function builder. Must process function's data to 'ready for use' state
	/// </summary>
	/// <param name="data">Data from config file</param>
	/// <returns>True if functin was created correctly</returns>
	virtual bool build(const std::wstring& data) = 0;
};