#pragma once
#include <string>
#include <map>

/// <summary>
/// mapper of key names to its int values
/// </summary>
class KeyMap
{
public:
	/// <summary>
	/// return key value by name
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	static int getKeyCode(const std::wstring& name);
};

/// <summary>
/// virtual keys map 
/// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
/// </summary>
const std::map<std::wstring, int> KEY_MAP
{
	{L"VK_LBUTTON",					0x01},	//Left mouse button
	{L"VK_RBUTTON",					0x02},	//Right mouse button
	{L"VK_CANCEL",					0x03},	//Control - break processing
	{L"VK_MBUTTON",					0x04},	//Middle mouse button(three - button mouse)
	{L"VK_XBUTTON1",				0x05},	//X1 mouse button
	{L"VK_XBUTTON2",				0x06},	//X2 mouse button
	{L"Undefined0x07",				0x07},	//Undefined
	{L"VK_BACK",					0x08},	//BACKSPACE key
	{L"VK_TAB",						0x09},	//TAB key
	{L"Reserved0x0A",				0x0A},	//Reserved
	{L"Reserved0x0B",				0x0B},	//Reserved
	{L"VK_CLEAR",					0x0C},	//CLEAR key
	{L"VK_RETURN",					0x0D},	//ENTER key
	{L"Undefined0x0E",				0x0E},	//Undefined
	{L"Undefined0x0F",				0x0F},	//Undefined
	{L"VK_SHIFT",					0x10},	//SHIFT key
	{L"VK_CONTROL",					0x11},	//CTRL key
	{L"VK_MENU",					0x12},	//ALT key
	{L"VK_PAUSE",					0x13},	//PAUSE key
	{L"VK_CAPITAL",					0x14},	//CAPS LOCK key
	{L"VK_KANA",					0x15},	//IME Kana mode
	{L"VK_HANGUEL",					0x15},	//IME Hanguel mode(maintained for compatibility; use VK_HANGUL)
	{L"VK_HANGUL",					0x15},	//IME Hangul mode
	{L"VK_IME_ON",					0x16},	//IME On
	{L"VK_JUNJA",					0x17},	//IME Junja mode
	{L"VK_FINAL",					0x18},	//IME final mode
	{L"VK_HANJA",					0x19},	//IME Hanja mode
	{L"VK_KANJI",					0x19},	//IME Kanji mode
	{L"VK_IME_OFF",					0x1A},	//IME Off
	{L"VK_ESCAPE",					0x1B},	//ESC key
	{L"VK_CONVERT",					0x1C},	//IME convert
	{L"VK_NONCONVERT",				0x1D},	//IME nonconvert
	{L"VK_ACCEPT",					0x1E},	//IME accept
	{L"VK_MODECHANGE",				0x1F},	//IME mode change request
	{L"VK_SPACE",					0x20},	//SPACEBAR
	{L"VK_PRIOR",					0x21},	//PAGE UP key
	{L"VK_NEXT",					0x22},	//PAGE DOWN key
	{L"VK_END",						0x23},	//END key
	{L"VK_HOME",					0x24},	//HOME key
	{L"VK_LEFT",					0x25},	//LEFT ARROW key
	{L"VK_UP",						0x26},	//UP ARROW key
	{L"VK_RIGHT",					0x27},	//RIGHT ARROW key
	{L"VK_DOWN",					0x28},	//DOWN ARROW key
	{L"VK_SELECT",					0x29},	//SELECT key
	{L"VK_PRINT",					0x2A},	//PRINT key
	{L"VK_EXECUTE",					0x2B},	//EXECUTE key
	{L"VK_SNAPSHOT",				0x2C},	//PRINT SCREEN key
	{L"VK_INSERT",					0x2D},	//INS key
	{L"VK_DELETE",					0x2E},	//DEL key
	{L"VK_HELP",					0x2F},	//HELP key
	{L"0",							0x30},	//0 key
	{L"1",							0x31},	//1 key
	{L"2",							0x32},	//2 key
	{L"3",							0x33},	//3 key
	{L"4",							0x34},	//4 key
	{L"5",							0x35},	//5 key
	{L"6",							0x36},	//6 key
	{L"7",							0x37},	//7 key
	{L"8",							0x38},	//8 key
	{L"9",							0x39},	//9 key
	{L"Undefined0x3A",				0x3A},	//Undefined
	{L"Undefined0x3B",				0x3B},	//Undefined
	{L"Undefined0x3C",				0x3C},	//Undefined
	{L"Undefined0x3D",				0x3D},	//Undefined
	{L"Undefined0x3E",				0x3E},	//Undefined
	{L"Undefined0x3F",				0x3F},	//Undefined
	{L"Undefined0x40",				0x40},	//Undefined
	{L"A",							0x41},	//A key
	{L"B",							0x42},	//B key
	{L"C",							0x43},	//C key
	{L"D",							0x44},	//D key
	{L"E",							0x45},	//E key
	{L"F",							0x46},	//F key
	{L"G",							0x47},	//G key
	{L"H",							0x48},	//H key
	{L"I",							0x49},	//I key
	{L"J",							0x4A},	//J key
	{L"K",							0x4B},	//K key
	{L"L",							0x4C},	//L key
	{L"M",							0x4D},	//M key
	{L"N",							0x4E},	//N key
	{L"O",							0x4F},	//O key
	{L"P",							0x50},	//P key
	{L"Q",							0x51},	//Q key
	{L"R",							0x52},	//R key
	{L"S",							0x53},	//S key
	{L"T",							0x54},	//T key
	{L"U",							0x55},	//U key
	{L"V",							0x56},	//V key
	{L"W",							0x57},	//W key
	{L"X",							0x58},	//X key
	{L"Y",							0x59},	//Y key
	{L"Z",							0x5A},	//Z key
	{L"VK_LWIN",					0x5B},	//Left Windows key(Natural keyboard)
	{L"VK_RWIN",					0x5C},	//Right Windows key(Natural keyboard)
	{L"VK_APPS",					0x5D},	//Applications key(Natural keyboard)
	{L"Reserved0x5E",				0x5E},	//Reserved
	{L"VK_SLEEP",					0x5F},	//Computer Sleep key
	{L"VK_NUMPAD0",					0x60},	//Numeric keypad 0 key
	{L"VK_NUMPAD1",					0x61},	//Numeric keypad 1 key
	{L"VK_NUMPAD2",					0x62},	//Numeric keypad 2 key
	{L"VK_NUMPAD3",					0x63},	//Numeric keypad 3 key
	{L"VK_NUMPAD4",					0x64},	//Numeric keypad 4 key
	{L"VK_NUMPAD5",					0x65},	//Numeric keypad 5 key
	{L"VK_NUMPAD6",					0x66},	//Numeric keypad 6 key
	{L"VK_NUMPAD7",					0x67},	//Numeric keypad 7 key
	{L"VK_NUMPAD8",					0x68},	//Numeric keypad 8 key
	{L"VK_NUMPAD9",					0x69},	//Numeric keypad 9 key
	{L"VK_MULTIPLY",				0x6A},	//Multiply key
	{L"VK_ADD",						0x6B},	//Add key
	{L"VK_SEPARATOR",				0x6C},	//Separator key
	{L"VK_SUBTRACT",				0x6D},	//Subtract key
	{L"VK_DECIMAL",					0x6E},	//Decimal key
	{L"VK_DIVIDE",					0x6F},	//Divide key
	{L"VK_F1",						0x70},	//F1 key
	{L"VK_F2",						0x71},	//F2 key
	{L"VK_F3",						0x72},	//F3 key
	{L"VK_F4",						0x73},	//F4 key
	{L"VK_F5",						0x74},	//F5 key
	{L"VK_F6",						0x75},	//F6 key
	{L"VK_F7",						0x76},	//F7 key
	{L"VK_F8",						0x77},	//F8 key
	{L"VK_F9",						0x78},	//F9 key
	{L"VK_F10",						0x79},	//F10 key
	{L"VK_F11",						0x7A},	//F11 key
	{L"VK_F12",						0x7B},	//F12 key
	{L"VK_F13",						0x7C},	//F13 key
	{L"VK_F14",						0x7D},	//F14 key
	{L"VK_F15",						0x7E},	//F15 key
	{L"VK_F16",						0x7F},	//F16 key
	{L"VK_F17",						0x80},	//F17 key
	{L"VK_F18",						0x81},	//F18 key
	{L"VK_F19",						0x82},	//F19 key
	{L"VK_F20",						0x83},	//F20 key
	{L"VK_F21",						0x84},	//F21 key
	{L"VK_F22",						0x85},	//F22 key
	{L"VK_F23",						0x86},	//F23 key
	{L"VK_F24",						0x87},	//F24 key
	{L"Unassigned0x88",				0x88},	//Unassigned
	{L"Unassigned0x89",				0x89},	//Unassigned
	{L"Unassigned0x8A",				0x8A},	//Unassigned
	{L"Unassigned0x8B",				0x8B},	//Unassigned
	{L"Unassigned0x8C",				0x8C},	//Unassigned
	{L"Unassigned0x8D",				0x8D},	//Unassigned
	{L"Unassigned0x8E",				0x8E},	//Unassigned
	{L"Unassigned0x8F",				0x8F},	//Unassigned
	{L"VK_NUMLOCK",					0x90},	//NUM LOCK key
	{L"VK_SCROLL",					0x91},	//SCROLL LOCK key
	{L"OEM0x92",					0x92},	//OEM specific
	{L"OEM0x93",					0x93},	//OEM specific
	{L"OEM0x94",					0x94},	//OEM specific
	{L"OEM0x95",					0x95},	//OEM specific
	{L"OEM0x96",					0x96},	//OEM specific
	{L"Unassigned0x97",				0x97},	//Unassigned
	{L"Unassigned0x98",				0x98},	//Unassigned
	{L"Unassigned0x99",				0x99},	//Unassigned
	{L"Unassigned0x9A",				0x9A},	//Unassigned
	{L"Unassigned0x9B",				0x9B},	//Unassigned
	{L"Unassigned0x9C",				0x9C},	//Unassigned
	{L"Unassigned0x9D",				0x9D},	//Unassigned
	{L"Unassigned0x9E",				0x9E},	//Unassigned
	{L"Unassigned0x9F",				0x9F},	//Unassigned
	{L"VK_LSHIFT",					0xA0},	//Left SHIFT key
	{L"VK_RSHIFT",					0xA1},	//Right SHIFT key
	{L"VK_LCONTROL",				0xA2},	//Left CONTROL key
	{L"VK_RCONTROL",				0xA3},	//Right CONTROL key
	{L"VK_LMENU",					0xA4},	//Left MENU key
	{L"VK_RMENU",					0xA5},	//Right MENU key
	{L"VK_BROWSER_BACK",			0xA6},	//Browser Back key
	{L"VK_BROWSER_FORWARD",			0xA7},	//Browser Forward key
	{L"VK_BROWSER_REFRESH",			0xA8},	//Browser Refresh key
	{L"VK_BROWSER_STOP",			0xA9},	//Browser Stop key
	{L"VK_BROWSER_SEARCH",			0xAA},	//Browser Search key
	{L"VK_BROWSER_FAVORITES",		0xAB},	//Browser Favorites key
	{L"VK_BROWSER_HOME",			0xAC},	//Browser Start and Home key
	{L"VK_VOLUME_MUTE",				0xAD},	//Volume Mute key
	{L"VK_VOLUME_DOWN",				0xAE},	//Volume Down key
	{L"VK_VOLUME_UP",				0xAF},	//Volume Up key
	{L"VK_MEDIA_NEXT_TRACK",		0xB0},	//Next Track key
	{L"VK_MEDIA_PREV_TRACK",		0xB1},	//Previous Track key
	{L"VK_MEDIA_STOP",				0xB2},	//Stop Media key
	{L"VK_MEDIA_PLAY_PAUSE",		0xB3},	//Play / Pause Media key
	{L"VK_LAUNCH_MAIL",				0xB4},	//Start Mail key
	{L"VK_LAUNCH_MEDIA_SELECT",		0xB5},	//Select Media key
	{L"VK_LAUNCH_APP1",				0xB6},	//Start Application 1 key
	{L"VK_LAUNCH_APP2",				0xB7},	//Start Application 2 key
	{L"Reserved0xB8",				0xB8},	//Reserved
	{L"Reserved0xB9",				0xB9},	//Reserved
	{L"VK_OEM_1",					0xBA},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ';:' key
	{L"VK_OEM_PLUS",				0xBB},	//For any country / region, the '+' key
	{L"VK_OEM_COMMA",				0xBC},	//For any country / region, the ',' key
	{L"VK_OEM_MINUS",				0xBD},	//For any country / region, the '-' key
	{L"VK_OEM_PERIOD",				0xBE},	//For any country / region, the '.' key
	{L"VK_OEM_2",					0xBF},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '/?' key
	{L"VK_OEM_3",					0xC0},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '`~' key
	{L"Reserved0xC1",				0xC1},	//Reserved
	{L"Reserved0xC2",				0xC2},	//Reserved
	{L"Reserved0xC3",				0xC3},	//Reserved
	{L"Reserved0xC4",				0xC4},	//Reserved
	{L"Reserved0xC5",				0xC5},	//Reserved
	{L"Reserved0xC6",				0xC6},	//Reserved
	{L"Reserved0xC7",				0xC7},	//Reserved
	{L"Reserved0xC8",				0xC8},	//Reserved
	{L"Reserved0xC9",				0xC9},	//Reserved
	{L"Reserved0xCA",				0xCA},	//Reserved
	{L"Reserved0xCB",				0xCB},	//Reserved
	{L"Reserved0xCC",				0xCC},	//Reserved
	{L"Reserved0xCD",				0xCD},	//Reserved
	{L"Reserved0xCE",				0xCE},	//Reserved
	{L"Reserved0xCF",				0xCF},	//Reserved
	{L"Reserved0xD1",				0xD1},	//Reserved
	{L"Reserved0xD2",				0xD2},	//Reserved
	{L"Reserved0xD3",				0xD3},	//Reserved
	{L"Reserved0xD4",				0xD4},	//Reserved
	{L"Reserved0xD5",				0xD5},	//Reserved
	{L"Reserved0xD6",				0xD6},	//Reserved
	{L"Reserved0xD7",				0xD7},	//Reserved
	{L"Unassigned0xD8",				0xD8},	//Unassigned
	{L"Unassigned0xD9",				0xD9},	//Unassigned
	{L"Unassigned0xDA",				0xDA},	//Unassigned
	{L"VK_OEM_4",					0xDB},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '[{' key
	{L"VK_OEM_5",					0xDC},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the '\|' key
	{L"VK_OEM_6",					0xDD},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ']}' key
	{L"VK_OEM_7",					0xDE},	//Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the 'single-quote/double-quote' key
	{L"VK_OEM_8",					0xDF},	//Used for miscellaneous characters; it can vary by keyboard.
	{L"Reserved0xE0",				0xE0},	//Reserved
	{L"OEM0xE1",					0xE1},	//OEM specific
	{L"VK_OEM_102",					0xE2},	//Either the angle bracket key or the backslash key on the RT 102 - key keyboard
	{L"OEM0xE3",					0xE3},	//OEM specific
	{L"OEM0xE4",					0xE4},	//OEM specific
	{L"VK_PROCESSKEY",				0xE5},	//IME PROCESS key
	{L"OEM0xE6",					0xE6},	//OEM specific
	{L"VK_PACKET",					0xE7},	//Used to pass Unicode characters as if they were keystrokes.The VK_PACKET key is the low word of a 32 - bit Virtual Key value used for non - keyboard input methods.For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
	{L"Unassigned0xE8",				0xE8},	//Unassigned
	{L"OEM0xE9",					0xE9},	//OEM specific
	{L"OEM0xEA",					0xEA},	//OEM specific
	{L"OEM0xEB",					0xEB},	//OEM specific
	{L"OEM0xEC",					0xEC},	//OEM specific
	{L"OEM0xED",					0xED},	//OEM specific
	{L"OEM0xEE",					0xEE},	//OEM specific
	{L"OEM0xEF",					0xEF},	//OEM specific
	{L"OEM0xF1",					0xF1},	//OEM specific
	{L"OEM0xF2",					0xF2},	//OEM specific
	{L"OEM0xF3",					0xF3},	//OEM specific
	{L"OEM0xF4",					0xF4},	//OEM specific
	{L"OEM0xF5",					0xF5},	//OEM specific
	{L"VK_ATTN",					0xF6},	//Attn key
	{L"VK_CRSEL",					0xF7},	//CrSel key
	{L"VK_EXSEL",					0xF8},	//ExSel key
	{L"VK_EREOF",					0xF9},	//Erase EOF key
	{L"VK_PLAY",					0xFA},	//Play key
	{L"VK_ZOOM",					0xFB},	//Zoom key
	{L"VK_NONAME",					0xFC},	//Reserved
	{L"VK_PA1",						0xFD},	//PA1 key
	{L"VK_OEM_CLEAR",				0xFE},	//Clear key
};