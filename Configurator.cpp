#include "Configurator.h"



CommandKeyboard Configurator::generateKeyboard(const std::wstring& configFile)
{
    std::wifstream file(configFile);
    CommandKeyboard keyboard;
    if (file)
    {
        file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
        for (std::wstring line; std::getline(file, line); )
        {
            if (isCommandLine(line))
            {
                std::vector<std::wstring> sLine = Helper::split(line, DELIMITER);
                if (sLine.size() >= 2)
                {
                    if (sLine.size() > 2)
                    {
                        int key = KeyMap::getKeyCode(sLine[0]);
                        std::wstring data = Helper::join(std::vector<std::wstring>(sLine.begin() + 2, sLine.end()));
                        std::shared_ptr<AbstractFunction> function = FunctionBuilder::generateFunction(sLine[1], &data);
                        if (function != nullptr)
                        {
                            keyboard.insert(function, key);
                        }
                    }
                    else
                    {
                        int key = KeyMap::getKeyCode(sLine[0]);
                        std::shared_ptr<AbstractFunction> function = FunctionBuilder::generateFunction(sLine[1], nullptr);
                        if (function != nullptr)
                        {
                            keyboard.insert(function, key);
                        }
                    }
                }
            }
        }
        file.close();
    }
    return keyboard;
}

bool Configurator::isCommandLine(const std::wstring& line)
{
    if (line.size() > 1)
    {
        return !(line[0] == COMMENT);
    }
    else
    {
        return true;
    }
}

