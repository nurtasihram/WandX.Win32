module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Types.h"

export module WandX.Win32.Types;

import WandX;
import WandX.Win32;
import WandX.Win32.String;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Types");

export namespace WandX {
namespace Native {

#pragma region DateTimeApi.h
wapi_ret_WAO(GetDateFormat, positive);
wapi_ret_WAO(GetTimeFormat, positive);
wapi_ret(GetTimeFormatEx, positive);
wapi_ret(GetDateFormatEx, positive);
// GetDurationFormatEx - deprecated
#pragma endregion

#pragma region HandleApi.h
wapi_ret(CloseHandle, true);
wapi_ret(DuplicateHandle, true);
wapi_ret(CompareObjectHandles, direct);
wapi_ret(GetHandleInformation, true);
wapi_ret(SetHandleInformation, true);
#pragma endregion

#pragma region SysInfoApi.h
wapi_ret(GlobalMemoryStatusEx, true);
wapi_ret(GetSystemInfo, direct);
wapi_ret(GetSystemTime, direct);
wapi_ret(GetSystemTimeAsFileTime, direct);
wapi_ret(GetLocalTime, direct);
wapi_ret(IsUserCetAvailableInEnvironment, direct);
wapi_ret(GetSystemLeapSecondInformation, true);
// GetVersion - deprecated
wapi_ret(SetLocalTime, true);
wapi_ret(GetTickCount, direct);
wapi_ret(GetTickCount64, direct);
wapi_ret(GetSystemTimeAdjustment, true);
wapi_ret(GetSystemTimeAdjustmentPrecise, true);
wapi_ret_WAO(GetSystemDirectory, positive);
wapi_ret_WAO(GetWindowsDirectory, positive);
wapi_ret_WAO(GetSystemWindowsDirectory, positive);
wapi_ret_WAO(GetComputerNameEx, true);
wapi_ret(SetComputerNameExW, true);
wapi_ret(SetSystemTime, true);
// GetVersionEx - deprecated
wapi_ret(GetLogicalProcessorInformation, true);
wapi_ret(GetLogicalProcessorInformationEx, true);
wapi_ret(GetNativeSystemInfo, direct);
wapi_ret(GetSystemTimePreciseAsFileTime, direct);
wapi_ret(GetProductInfo, true);
wapi_ret(VerSetConditionMask, direct);
wapi_ret(GetOsSafeBootMode, true);
wapi_ret(EnumSystemFirmwareTables, positive);
wapi_ret(GetSystemFirmwareTable, positive);
// DnsHostnameToComputerNameExW
wapi_ret(GetPhysicallyInstalledSystemMemory, true);
wapi_ret(SetComputerNameEx2W, true);
wapi_ret(SetSystemTimeAdjustment, true);
wapi_ret(SetSystemTimeAdjustmentPrecise, true);
wapi_ret(InstallELAMCertificateInfo, true);
wapi_ret(GetProcessorSystemCycleTime, true);
wapi_ret(GetOsManufacturingMode, true);
wapi_ret(GetIntegratedDisplaySize, success);
wapi_ret_WAO(SetComputerName, true);
wapi_ret(SetComputerNameExA, true);
wapi_ret(GetDeveloperDriveEnablementState, fault, DeveloperDriveEnablementStateError);
wapi_ret(GetRuntimeAttestationReport, true);
#pragma endregion

}

#include "WandX.Win32.Types.idl"

}
