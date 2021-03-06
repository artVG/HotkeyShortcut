#pragma once
#include <functional>
#include <vector>
#include <windows.h>

typedef std::function<void(const void*, const int&)> CommandFunction;

class InputCommand
{
public:
	InputCommand(const std::vector<INPUT> data, const CommandFunction function);
	InputCommand();
	void run() const;
	bool isSet() const;
private:
    std::vector<INPUT> data;
	CommandFunction function;
};