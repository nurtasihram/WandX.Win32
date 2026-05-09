module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Resources.h"

export module WandX.Resource;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Resources");

export namespace WandX {
namespace Native {

#pragma region WinUser.h
wapi_ret_WAO(LoadString, natural);
#pragma endregion

#pragma region LibLoaderApi.h
wapi_ret(DisableThreadLibraryCalls, true);
wapi_ret_WAO(FindResource, notnull); // FindResourceA from WinBase.h
wapi_ret_WAO(FindResourceEx, notnull); // FindResourceExA from WinBase.h
wapi_ret(FindStringOrdinal, natural);
wapi_ret(FreeLibrary, true);
[[noreturn]] inline void FreeLibraryAndExitThread(HMODULE hLibModule, DWORD dwExitCode) {
	::FreeLibraryAndExitThread(hLibModule, dwExitCode);
}
wapi_ret(FreeResource, true);
wapi_ret_WAO(GetModuleFileName, positive);
wapi_ret_WAO(GetModuleHandle, notnull);
wapi_ret_WAO(GetModuleHandleEx, true);
wapi_ret(GetProcAddress, notnull);
wapi_ret_WAO(LoadLibrary, notnull);
wapi_ret_WAO(LoadLibraryEx, notnull);
wapi_ret(LoadResource, notnull);
wapi_ret(LockResource, notnull);
wapi_ret(SizeofResource, positive);
wapi_ret(AddDllDirectory, notnull);
wapi_ret(RemoveDllDirectory, true);
wapi_ret(SetDefaultDllDirectories, true);
wapi_ret_WAO(EnumResourceLanguagesEx, true);
wapi_ret_WAO(EnumResourceTypesEx, true);
wapi_ret_WAO(EnumResourceNames, true);
wapi_ret_WAO(EnumResourceNamesEx, true);
#pragma endregion

}

//#include "WandX.Win32.Resource.idl"

}
