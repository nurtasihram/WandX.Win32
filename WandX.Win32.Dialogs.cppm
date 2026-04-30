module;

#include <Windows.h>
#include <CommDlg.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Dialogs.h"

export module WandX.Win32.Dialogs;

import WandX;
import WandX.Win32;
import WandX.Win32.GDI;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Dialogs");

export namespace WandX {
namespace Native {

//////////// ! -- TODO: Add exception system with CommDlgExtendedError -- !  ////////////

#define GetLastError ::CommDlgExtendedError

#pragma region CommDlg.h

inline bool GetOpenFileName(LPOPENFILENAMEA lpofn) ret_as(::GetOpenFileNameA(lpofn));
inline bool GetOpenFileName(LPOPENFILENAMEW lpofn) ret_as(::GetOpenFileNameW(lpofn));
inline bool GetSaveFileName(LPOPENFILENAMEA lpofn) ret_as(::GetSaveFileNameA(lpofn));
inline bool GetSaveFileName(LPOPENFILENAMEW lpofn) ret_as(::GetSaveFileNameW(lpofn));
inline short GetFileTitle(LPCSTR lpFileName, LPSTR lpBuffer, WORD cchSize) safe_ret_as(auto res = ::GetFileTitleA(lpFileName, lpBuffer, cchSize); res >= 0, res);
inline short GetFileTitle(LPCWSTR lpFileName, LPWSTR lpBuffer, WORD cchSize) safe_ret_as(auto res = ::GetFileTitleW(lpFileName, lpBuffer, cchSize); res >= 0, res);
inline bool ChooseColor(LPCHOOSECOLORA lpcc) ret_as(::ChooseColorA(lpcc));
inline bool ChooseColor(LPCHOOSECOLORW lpcc) ret_as(::ChooseColorW(lpcc));
inline HWND FindText(LPFINDREPLACEA lpfr) ret_as(::FindTextA(lpfr));
inline HWND FindText(LPFINDREPLACEW lpfr) ret_as(::FindTextW(lpfr));
inline HWND ReplaceText(LPFINDREPLACEA lpfr) ret_as(::ReplaceTextA(lpfr));
inline HWND ReplaceText(LPFINDREPLACEW lpfr) ret_as(::ReplaceTextW(lpfr));
inline bool ChooseFont(LPCHOOSEFONTA lpcf) ret_as(::ChooseFontA(lpcf));
inline bool ChooseFont(LPCHOOSEFONTW lpcf) ret_as(::ChooseFontW(lpcf));
inline bool PrintDlg(LPPRINTDLGA lppd) ret_as(::PrintDlgA(lppd));
inline bool PrintDlg(LPPRINTDLGW lppd) ret_as(::PrintDlgW(lppd));
inline bool PrintDlgEx(LPPRINTDLGEXA lppd) ret_as(::PrintDlgExA(lppd));
inline bool PrintDlgEx(LPPRINTDLGEXW lppd) ret_as(::PrintDlgExW(lppd));
inline bool PageSetupDlg(LPPAGESETUPDLGA lppsd) ret_as(::PageSetupDlgA(lppsd));
inline bool PageSetupDlg(LPPAGESETUPDLGW lppsd) ret_as(::PageSetupDlgW(lppsd));
#pragma endregion

}

//#include "WandX.Win32.Dialogs.idl"

}