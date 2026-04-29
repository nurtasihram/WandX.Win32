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

#pragma region LibLoaderApi.h
wapi_ret(DisableThreadLibraryCalls, true);
wapi_ret_WAO(FindResource, notnull); // FindResourceA from WinBase.h
wapi_ret_WAO(FindResourceEx, notnull); // FindResourceExA from WinBase.h
inline int FindStringOrdinal(DWORD dwFindStringOrdinalFlags, LPCWSTR lpStringSource, int cchSource, LPCWSTR lpStringValue, int cchValue, BOOL bIgnoreCase)
safe_ret_as(auto ret = ::FindStringOrdinal(dwFindStringOrdinalFlags, lpStringSource, cchSource, lpStringValue, cchValue, bIgnoreCase); ret >= 0, ret);
wapi_ret(FreeLibrary, true);
wapi_ret(FreeLibraryAndExitThread, direct);
wapi_ret(FreeResource, true);
wapi_ret_WAO(GetModuleFileName, positive);
wapi_ret_WAO(GetModuleHandle, notnull);
wapi_ret_WAO(GetModuleHandleEx, true);
wapi_ret(GetProcAddress, notnull);
wapi_ret_WAO(LoadLibrary, notnull);
wapi_ret_WAO(LoadLibraryEx, notnull);
wapi_ret(LoadResource, notnull);
// from WinUser.h
inline int LoadString(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax)
safe_ret_as(auto ret = ::LoadStringA(hInstance, uID, lpBuffer, cchBufferMax); ret >= 0, ret);
inline int LoadString(HINSTANCE hInstance, UINT uID, PWSTR lpBuffer, int cchBufferMax)
safe_ret_as(auto ret = ::LoadStringW(hInstance, uID, lpBuffer, cchBufferMax); ret >= 0, ret);
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
