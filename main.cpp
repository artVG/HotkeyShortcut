#include "App.h"

// тут КСТЫЛЬ нужно сделать, чтоб этот ваил брался всегда из хомяка.
// на данный момент нужен точный адрес
const std::wstring configAddress = L"hkConfig.txt";

LRESULT CALLBACK LowLevelKeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam);
App* app;

int main()
{
    app = new App(LowLevelKeyboardProc, configAddress);
    app->run();
    delete app;
    return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
    return app->processHotKey(code, wParam, lParam);
}




