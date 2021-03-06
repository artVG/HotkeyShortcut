#include "Functions.h"



void Functions::writeString(const void* chars, const int& arrSize)
{
    UINT uSent = SendInput(arrSize, (INPUT*)chars, sizeof(INPUT));
}

CommandFunction Functions::jornal(const std::wstring name)
{
    if (name == L"STRING")
    {
        return writeString;
    }
    return nullptr;
}