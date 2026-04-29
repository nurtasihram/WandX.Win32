#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Console;
#endif

#include "WandX.Win32.String.h"

// from ConsoleApi.h
#undef ReadConsoleInput
#undef PeekConsoleInput
#undef ReadConsole
#undef WriteConsole

// from ConsoleApi2.h
#undef FillConsoleOutputCharacter
#undef WriteConsoleOutputCharacter
#undef ReadConsoleOutputCharacter
#undef WriteConsoleInput
#undef ScrollConsoleScreenBuffer
#undef WriteConsoleOutput
#undef ReadConsoleOutput
#undef GetConsoleTitle
#undef GetConsoleOriginalTitle
#undef SetConsoleTitle

// from ConsoleApi3.h
#undef AddConsoleAlias
#undef GetConsoleAlias
#undef GetConsoleAliasesLength
#undef GetConsoleAliasExesLength
#undef GetConsoleAliases
#undef GetConsoleAliasExes
