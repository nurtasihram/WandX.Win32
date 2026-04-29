module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Console.h"

export module WandX.Win32.Console;

import WandX;
import WandX.Win32;
import WandX.Win32.String;
import WandX.Win32.Types;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Console");

export namespace WandX {
namespace Native {

#pragma region ProcessEnv.h (part)
wapi_ret(GetStdHandle, validhd);
wapi_ret(SetStdHandle, true);
wapi_ret(SetStdHandleEx, true);
#pragma endregion

#pragma region ConsoleApi.h
wapi_ret(AllocConsole, true);
// AllocConsoleWithOptions 
wapi_ret(FreeConsole, true);
wapi_ret(AttachConsole, true);
wapi_ret(GetConsoleCP, positive);
wapi_ret(GetConsoleOutputCP, positive);
wapi_ret(GetConsoleMode, true);
wapi_ret(SetConsoleMode, true);
wapi_ret(GetNumberOfConsoleInputEvents, true);
wapi_ret_WAT(ReadConsoleInput, true);
wapi_ret_WAT(PeekConsoleInput, true);
wapi_ret_WAT(ReadConsole, true);
wapi_ret_WAT(WriteConsole, true);
wapi_ret(SetConsoleCtrlHandler, true);
#pragma endregion

#pragma region ConsoleApi2.h
wapi_ret_WAT(FillConsoleOutputCharacter, true);
wapi_ret(FillConsoleOutputAttribute, true);
wapi_ret(GenerateConsoleCtrlEvent, true);
wapi_ret(CreateConsoleScreenBuffer, validhd);
wapi_ret(SetConsoleActiveScreenBuffer, true);
wapi_ret(FlushConsoleInputBuffer, true);
wapi_ret(SetConsoleCP, true);
wapi_ret(SetConsoleOutputCP, true);
wapi_ret(GetConsoleCursorInfo, true);
wapi_ret(SetConsoleCursorInfo, true);
wapi_ret(GetConsoleScreenBufferInfo, true);
wapi_ret(GetConsoleScreenBufferInfoEx, true);
wapi_ret(SetConsoleScreenBufferInfoEx, true);
wapi_ret(SetConsoleScreenBufferSize, true);
wapi_ret(SetConsoleCursorPosition, true);
// GetLargestConsoleWindowSize
inline COORD GetLargestConsoleWindowSize(HANDLE hConsoleOutput)
safe_ret_as(auto c = ::GetLargestConsoleWindowSize(hConsoleOutput); c.X &&c.Y, c);
wapi_ret(SetConsoleTextAttribute, true);
wapi_ret(SetConsoleWindowInfo, true);
wapi_ret_WAO(WriteConsoleOutputCharacter, true);
wapi_ret(WriteConsoleOutputAttribute, true);
wapi_ret_WAO(ReadConsoleOutputCharacter, true);
wapi_ret(ReadConsoleOutputAttribute, true);
wapi_ret_WAT(WriteConsoleInput, true);
wapi_ret_WAT(ScrollConsoleScreenBuffer, true);
wapi_ret_WAT(WriteConsoleOutput, true);
wapi_ret_WAT(ReadConsoleOutput, true);
wapi_ret_WAO(GetConsoleTitle, positive);
wapi_ret_WAO(GetConsoleOriginalTitle, positive);
wapi_ret_WAO(SetConsoleTitle, true);
#pragma endregion

#pragma region ConsoleApi3.h
wapi_ret(GetNumberOfConsoleMouseButtons, positive);
// GetConsoleFontSize
inline COORD GetConsoleFontSize(HANDLE hConsoleOutput, DWORD nFont)
safe_ret_as(auto c = ::GetConsoleFontSize(hConsoleOutput, nFont); c.X &&c.Y, c);
wapi_ret(GetCurrentConsoleFont, true);
wapi_ret(GetCurrentConsoleFontEx, true);
wapi_ret(SetCurrentConsoleFontEx, true);
wapi_ret(GetConsoleSelectionInfo, true);
wapi_ret(GetConsoleHistoryInfo, true);
wapi_ret(SetConsoleHistoryInfo, true);
wapi_ret(GetConsoleDisplayMode, true);
wapi_ret(SetConsoleDisplayMode, true);
wapi_ret(GetConsoleWindow, direct);
wapi_ret_WAO(AddConsoleAlias, true);
wapi_ret_WAO(GetConsoleAlias, true);
wapi_ret_WAO(GetConsoleAliasesLength, true);
wapi_ret_WAT(GetConsoleAliasExesLength, direct);
wapi_ret_WAO(GetConsoleAliases, true);
wapi_ret_WAO(GetConsoleAliasExes, true);
wapi_ret(GetConsoleProcessList, positive);
#pragma endregion

}

#include "WandX.Win32.Console.idl"

}
