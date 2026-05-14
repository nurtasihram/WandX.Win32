module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.File.h"

export module WandX.File;

import WandX;
import WandX.Win32;
import WandX.Win32.String;
import WandX.Win32.Types;
// import WandX.Resource;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.File");

export namespace WandX {
namespace Native {

#pragma region FileApi.h
wapi_ret_WAO(FindFirstChangeNotification, validhd);
wapi_ret_WAO(FindNextFile, true);
wapi_ret_WAO(GetDiskFreeSpace, true);
wapi_ret_WAO(GetDiskFreeSpaceEx, true);
wapi_ret_WAO(GetDiskSpaceInformation, success);
wapi_ret_WAO(GetDriveType, direct);
wapi_ret_WAO(GetFinalPathNameByHandle, positive);
wapi_ret_WAO(GetLongPathName, positive);
wapi_ret_WAO(GetShortPathName, positive); // GetShortPathNameA from WinBase.h
wapi_ret_WAO(GetTempFileName, positive);
// GetVolumeInformationByHandle
wapi_ret_WAO(GetVolumeInformation, true);
// FindFirstStream
// FindNextStream
wapi_ret_WAO(GetTempPath, positive);
// FindFirstFileName
// FindNextFileName
#if (NTDDI_VERSION >= NTDDI_WIN10_FE)
wapi_ret_WAO(GetTempPath2, positive);
#endif
wapi_ret_WAO(CreateFile, validhd);
wapi_ret_WAO(CreateDirectory, true);
#if defined(NTDDI_WIN11_GE) && (NTDDI_VERSION >= NTDDI_WIN11_GE) && !__GNUC__
wapi_ret_WAO(CreateDirectory2, true);
wapi_ret_WAO(RemoveDirectory2, true);
wapi_ret_WAO(DeleteFile2, true);
#endif
wapi_ret_WAO(DeleteFile, true);
// SetFileInformationByHandle
#pragma endregion

#pragma region WinBase.h (part)
#pragma endregion

}

//#include "WandX.Win32.File.idl"

}
