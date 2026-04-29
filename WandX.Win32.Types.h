#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Types;
#endif

#include "WandX.Win32.String.h"

// from DateTimeApi.h
#undef GetDateFormat
#undef GetTimeFormat

// from SysInfoApi.h
#undef GetSystemDirectory
#undef GetWindowsDirectory
#undef GetSystemWindowsDirectory
#undef GetComputerNameEx
#undef GetVersionEx
#undef SetComputerName
