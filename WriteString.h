#pragma once
#include "AbstractFunction.h"
#include <windows.h>
#include <vector>


/// <summary>
/// hotkey function to write single string
/// </summary>
class WriteString :
    public AbstractFunction
{
public:
    void run() override;
    bool build(const std::wstring& data) override;
private:
    std::vector<INPUT> inputs;
};

