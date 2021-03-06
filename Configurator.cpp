#include "Configurator.h"



Configurator::Configurator(const std::wstring& vkAddress)
{
    loadVirtualCodes(vkAddress);
}

int Configurator::getKeyCode(const std::wstring& key) const
{
    return virtualCodes.find(key)->second;
}

CommandFunction Configurator::getFunction(const std::wstring& name) const
{
    return Functions::jornal(name);
}

void Configurator::loadVirtualCodes(const std::wstring& address)
{
    //open file
    std::wifstream configFile(address);
    //if file opened
    if (configFile)
    {
        //read as UTF-8 format
        configFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
        //for each line in file
        for (std::wstring line; std::getline(configFile, line); )
        {
            //find in line separator of key name and key code
            size_t separator = findSeparator(line, SEPARATOR, 0);
            //if separator found and it is not first or last symbol in line
            if ((separator > 1) && (separator != (line.size() -1)))
            {
                //get key code
                int keyNum = toKeyInt(line.substr(separator, line.size() - separator));
                //get key name
                std::wstring name = line.substr(0, separator);
                //if key code is valid and (in keyboard aaray size range) 
                //and has valid name
                if (keyNum > 0 && name.size() > 0)
                {
                    //add key to virtual  key codes hashmap
                    virtualCodes.insert(std::pair<std::wstring, int>(name, keyNum));
                }
            }
        }
    }
}

CommandKeyboard Configurator::generateKeyboard(const std::wstring& configFile) const
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
                size_t firstSeparator = findSeparator(line, SEPARATOR, 0);
                size_t secondSeparator = findSeparator(line, SEPARATOR, firstSeparator+1);
                
                int key = parseKeyCode(line, 0, firstSeparator);
                std::vector<INPUT> inputDataVector = parseKeyData(line, secondSeparator+1);
                CommandFunction function = parseKeyFunction(line, firstSeparator+1, secondSeparator);

                keyboard.insert(InputCommand(inputDataVector, function), key);
            }
        }
        file.close();
    }
    return keyboard;
}

int Configurator::parseKeyCode(const std::wstring& line, const size_t& begin, const size_t& end) const
{
    if (begin < end)
    {
        return getKeyCode(line.substr(begin, end - begin));
    }
    else
    {
        return -1;
    }
}

CommandFunction Configurator::parseKeyFunction(const std::wstring& line, const size_t& begin, const size_t& end) const
{
    if (begin > 0)
    {
        if (end > 0)
        {
            if (begin < end)
            {
                return getFunction(line.substr(begin, end - begin));
            }
        }
        else
        {
            return getFunction(line.substr(begin, end - begin));
        }
    }
    return nullptr;
}

std::vector<INPUT> Configurator::parseKeyData(const std::wstring& line, const size_t& begin) const
{
    if (begin > 2 && begin < line.size())
    {
        std::vector<INPUT> inputs;
        for (int key = begin; key < line.size(); key++)
        {
            INPUT inputDown;
            inputDown.type = INPUT_KEYBOARD;
            inputDown.ki.wVk = 0;
            inputDown.ki.wScan = line[key];
            inputDown.ki.dwFlags = KEYEVENTF_UNICODE;
            inputDown.ki.time = 0;
            inputDown.ki.dwExtraInfo = 0;
            inputs.push_back(inputDown);

            INPUT inputUp;
            inputUp.type = INPUT_KEYBOARD;
            inputUp.ki.wVk = 0;
            inputUp.ki.wScan = line[key];
            inputUp.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
            inputUp.ki.time = 0;
            inputUp.ki.dwExtraInfo = 0;
            inputs.push_back(inputUp);
        }
        return inputs;
    }
    return std::vector<INPUT>();
}

bool Configurator::isCommandLine(const std::wstring& line) const
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

size_t Configurator::findSeparator(const std::wstring& str, const wchar_t& separator, const size_t& start_at) const
{
    try
    {
        return str.find(separator, start_at);
    }
    catch (const std::exception&)
    {
        //if anything goes wrong return -1
        return -1;
    }
}

int Configurator::toKeyInt(const std::wstring& str) const
{
    try
    {
        //try to get int from string
        int code = std::stoi(str, nullptr, 10);
        //if code in range of keyboard array size
        if (code > 0 && code < KEYBOARD_SIZE)
        {
            return code;
        }
        else
        {
            return -1;
        }
    }
    catch (const std::exception&)
    {
        //if any error return -1
        return -1;
    }
}
