#include "FunctionBuilder.h"
#include "WriteString.h"

std::shared_ptr<AbstractFunction> FunctionBuilder::generateFunction(const std::wstring& name, const  std::wstring* data)
{
	if (name == L"STRING")
	{
		if (data == nullptr)
		{
			return nullptr;
		}
		std::shared_ptr<WriteString> function{ new WriteString };
		if (function->build(*data))
		{
			return function;
		}
	}
	return nullptr;
}