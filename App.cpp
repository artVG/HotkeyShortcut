#include "App.h"



App::App(HOOKPROC hkp, const std::wstring& configFile)
{
	// generate keyboard
	keyboard = Configurator::generateKeyboard(configFile);

    // register ALT+F11 combination to enable hotkey mod
    if (!RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, VK_F11))
    {
        exit(1);
    }

    // register key hook to get key up and down events
    keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, hkp, (HINSTANCE)NULL, NULL);
    if (keyHook == NULL)
    {
        exit(2);
    }
}

App::~App()
{
    UnhookWindowsHookEx(keyHook);
}

LRESULT CALLBACK App::processHotKey(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    // if hotkey mode was enabled
    if (waitingForHK)
    {
        // get keyboard state
        KBDLLHOOKSTRUCT* kbdStruct = (KBDLLHOOKSTRUCT*)lParam;

        // if it was hotkey mode combination (ALT+F11) release -> pass
        if ((wParam == WM_KEYUP && kbdStruct->vkCode == VK_F11) || (wParam == WM_KEYUP && kbdStruct->vkCode == VK_RMENU))
        {
            return CallNextHookEx(keyHook, code, wParam, lParam);
        }
        else
        {
            // if hotkey was released -> run hotkey's function
            if (wParam == WM_KEYUP)
            {
                waitingForHK = false;
                keyboard.run(kbdStruct->vkCode);
                return 1;
            }
            // if hotkey was pressed -> do nothing
            else
            {
                return 1;
            }
        }
    }
    // if intkey maode was not enabled -> pass
    return CallNextHookEx(keyHook, code, wParam, lParam);
}

void App::run()
{
    // main loop
    // hotkey mode combination (ALT+F11) was pressed -> set hotkey mode as waiting for hotkey input 
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            waitingForHK = true;
        }
    }
}