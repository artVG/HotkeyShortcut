#pragma once
#include "AbstractFunction.h"
#include <map>
#include <memory>

/// <summary>
/// Container for all functions
/// </summary>
class CommandKeyboard
{
public:
	/// <summary>
	/// Add new hotkey function to container. Function must have unique keybind.
	/// If key already exists in the container new will not be added
	/// </summary>
	/// <param name="command">Function to add</param>
	/// <param name="at">Key bind</param>
	void insert(const std::shared_ptr<AbstractFunction> command, const int& at);

	/// <summary>
	/// Execute function on key
	/// </summary>
	/// <param name="key">Key bind</param>
	void run(const int& key) const;
private:

	/// <summary>
	/// Container for all keys with binded functions
	/// </summary>
	std::map<int, std::shared_ptr<AbstractFunction>> keyboard;
};

