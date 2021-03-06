#include "Configurator.h"

std::wstring address = L"E:\\PP\\HotkeyShortcut\\x64\\Debug\\td.txt";

LRESULT CALLBACK LowLevelKeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam);
HHOOK keyHook;
bool hkp = false;
CommandKeyboard k;

int main()
{
    Configurator c{ L"E:\\PP\\HotkeyShortcut\\x64\\Debug\\vkc" };
    k = c.generateKeyboard(address);

    k.run(VK_F1);
    if (!RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, VK_F11))
    {
        exit(1);
    }

    HHOOK keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, (HINSTANCE)NULL, NULL);
    if (keyHook == NULL)
    {
        exit(2);
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            hkp = true;
        }
    }

    UnhookWindowsHookEx(keyHook);
    return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    if (hkp)
    {
        KBDLLHOOKSTRUCT* kbdStruct = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vkCode = kbdStruct->vkCode;
        if ((wParam == WM_KEYUP && kbdStruct->vkCode == VK_F11) || (wParam == WM_KEYUP && kbdStruct->vkCode == VK_RMENU))
        {
            return CallNextHookEx(keyHook, code, wParam, lParam);
        }
        else
        {
            if (wParam == WM_KEYUP)
            {
                hkp = false;
                k.run(kbdStruct->vkCode);
                return 1;
            }
            else
            {
                return 1;
            }
        }
    }
    return CallNextHookEx(keyHook, code, wParam, lParam);
}




