#include "WriteString.h"


void WriteString::run()
{
    SendInput(inputs.size(), inputs.data(), sizeof(INPUT));
}

bool WriteString::build(const std::wstring& data)
{
    //https://docs.microsoft.com/en-gb/windows/win32/api/winuser/nf-winuser-sendinput?redirectedfrom=MSDN
    // id data is not empty
    if (data.size() > 0)
    {
        // for each char in user input string
        for (auto ch = data.begin(); ch < data.end(); ch++)
        {
            // add key press event
            INPUT inputDown;
            inputDown.type = INPUT_KEYBOARD;
            inputDown.ki.wVk = 0;
            inputDown.ki.wScan = *ch;
            inputDown.ki.dwFlags = KEYEVENTF_UNICODE;
            inputDown.ki.time = 0;
            inputDown.ki.dwExtraInfo = 0;
            inputs.push_back(inputDown);

            // add key release event
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
    // true if inputs vector has key events
    return inputs.size() > 0;
}
