#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.File;
#endif

#include "WandX.Win32.String.h"

// from FileApi.h
#undef FindFirstChangeNotification
#undef FindNextFile
#undef GetDiskFreeSpace
#undef GetDiskFreeSpaceEx
#undef GetDiskSpaceInformation
#undef GetDriveType
#undef GetFinalPathNameByHandle
#undef GetLongPathName
#undef GetShortPathName
#undef GetTempFileName
#undef GetVolumeInformation
#undef GetTempPath
#undef FindFirstFileName
#undef GetTempPath2
#undef CreateFile
#undef CreateDirectory
#undef CreateDirectory2
#undef RemoveDirectory2
#undef DeleteFile
#undef DeleteFile2
