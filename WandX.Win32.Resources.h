#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Resource;
#endif

#include "WandX.Win32.GDI.h"

// from LibLoaderApi.h
#undef FindResource
#undef FindResourceEx
#undef GetModuleFileName
#undef GetModuleHandle
#undef GetModuleHandleEx
#undef LoadLibrary
#undef LoadLibraryEx
#undef LoadString
#undef EnumResourceLanguagesEx
#undef EnumResourceTypesEx
#undef EnumResourceNames
#undef EnumResourceNamesEx
