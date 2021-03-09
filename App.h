#pragma once
#include <windows.h>
#include "Configurator.h"

/// <summary>
/// Main app logick
/// </summary>
class App
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="hkp">keyboard hook</param>
	/// <param name="configFile">config file address</param>
	App(HOOKPROC hkp, const std::wstring& configFile);

	/// <summary>
	/// unhook keyboard
	/// </summary>
	~App();

	/// <summary>
	/// keyboard hook logick
	/// </summary>
	/// <returns>CallNextHookEx if event was not processed, 1 if key event was processed</returns>
	LRESULT CALLBACK processHotKey(_In_ int code, _In_ WPARAM wParam, _In_ LPARAM lParam);

	/// <summary>
	/// run main loop
	/// </summary>
	void run();
private:

	/// <summary>
	/// 
	/// </summary>
	/// <returns>path of exe file</returns>
	std::wstring getExePath();

	/// <summary>
	/// keyboard hook
	/// </summary>
	HHOOK keyHook;

	/// <summary>
	/// state. true if user has pressed hotkey combination to activate hotkeys
	/// </summary>
	bool waitingForHK = false;

	/// <summary>
	/// hashmap of hotkeys
	/// </summary>
	CommandKeyboard keyboard;
};

