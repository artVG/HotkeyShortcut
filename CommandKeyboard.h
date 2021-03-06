#pragma once
#include "InputCommand.h"
#include <string>
#include <map>

#define KEYBOARD_SIZE 255

class CommandKeyboard
{
public:
	void insert(const InputCommand& command, const int& at);
	void run(const int& key) const;
private:
	std::map<int, InputCommand> keyboard;
};

