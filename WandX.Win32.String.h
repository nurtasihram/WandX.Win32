#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.String;
#endif

#include "WandX.Win32.h"

// from StringApiSet.h
#undef CompareString
#undef FoldString
#undef GetStringTypeEx

// from StrSafe.h
#undef StringCchCopy
#undef StringCchCopyEx
#undef StringCbCopy
#undef StringCbCopyEx
#undef StringCchCopyN
#undef StringCbCopyN
#undef StringCchCopyNEx
#undef StringCbCopyNEx
#undef StringCchCat
#undef StringCbCat
#undef StringCchCatEx
#undef StringCbCatEx
#undef StringCchCatN
#undef StringCbCatN
#undef StringCchCatNEx
#undef StringCbCatNEx
#undef StringCchVPrintf
#undef StringCbVPrintf
#undef StringCchPrintf
#undef StringCbPrintf
#undef StringCchPrintfEx
#undef StringCbPrintfEx
#undef StringCchVPrintfEx
#undef StringCbVPrintfEx
#undef StringCchGets
#undef StringCbGets
#undef StringCchGetsEx
#undef StringCbGetsEx
#undef StringCchLength
#undef StringCbLength

// from WinBase.h
#undef FormatMessage
