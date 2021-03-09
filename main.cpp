#include "App.h"
#include <iostream>

const std::wstring configAddress = L"hkConfig.txt";

/// <summary>
/// https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms644985(v=vs.85)
/// </summary>
LRESULT CALLBACK LowLevelKeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam);

App* app;

int main(int argc, char** argv)
{
    //hide console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    // create hotkey keyboard from config
    app = new App(LowLevelKeyboardProc, configAddress);
    // run main loop
    app->run();
    // unhook keyboard and free memory on exit
    delete app;
    return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    return app->processHotKey(code, wParam, lParam);
}


