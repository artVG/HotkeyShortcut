#include "WriteString.h"


void WriteString::run()
{
    SendInput(inputs.size(), inputs.data(), sizeof(INPUT));
}

bool WriteString::build(const std::wstring& data)
{
    if (data.size() > 0)
    {
        for (auto ch = data.begin(); ch < data.end(); ch++)
        {
            INPUT inputDown;
            inputDown.type = INPUT_KEYBOARD;
            inputDown.ki.wVk = 0;
            inputDown.ki.wScan = *ch;
            inputDown.ki.dwFlags = KEYEVENTF_UNICODE;
            inputDown.ki.time = 0;
            inputDown.ki.dwExtraInfo = 0;
            inputs.push_back(inputDown);

            INPUT inputUp;
            inputUp.type = INPUT_KEYBOARD;
            inputUp.ki.wVk = 0;
            inputUp.ki.wScan = *ch;
            inputUp.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
            inputUp.ki.time = 0;
            inputUp.ki.dwExtraInfo = 0;
            inputs.push_back(inputUp);
        }
    }
    return inputs.size() > 0;
}
