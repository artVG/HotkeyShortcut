#pragma once
#include <string>
#include <memory>
#include "AbstractFunction.h"

/// <summary>
/// hotkey function factory
/// </summary>
class FunctionBuilder
{
public:
	/// <summary>
	/// create hotkey function from user object
	/// </summary>
	/// <param name="name">function name</param>
	/// <param name="data">data pointer. must be null if function does not require data</param>
	/// <returns>pointer to AbstractFunction object</returns>
	static std::shared_ptr<AbstractFunction> generateFunction(const std::wstring& name, const  std::wstring* data);
};

