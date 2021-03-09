#include "Configurator.h"



CommandKeyboard Configurator::generateKeyboard(const std::wstring& configFile)
{
    // open file
    std::wifstream file(configFile);
    // create keyboard
    CommandKeyboard keyboard;
    // if file opned
    if (file)
    {
        // convert utf-8
        file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
        // for each line in file
        for (std::wstring line; std::getline(file, line); )
        {
            if (isCommandLine(line))
            {
                std::vector<std::wstring> sLine = Helper::split(line, DELIMITER);
                if (sLine.size() >= 2)
                {
                    // if line has data
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
                    // if line has no data for function
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
    // if line not empty
    if (line.size() > 1)
    {
        // check if it starts with COMMENT symbol
        return !(line[0] == COMMENT);
    }
    else
    {
        return false;
    }
}

