#pragma once

#define S(str) T(str##_S)

#pragma region Compilation Informations
//----------- _WX_COMPILED_TIME ----------------------------------------------------------//
#      define _WX_COMPILED_TIME               __DATE__ " " __TIME__                       //
//----------- _WX_CPP_STANDARD -----------------------------------------------------------//
#      define _WX_CPP_STANDARD                macro_str(__cplusplus)                         //
//----------- _WX_CHAR_MODE --------------------------------------------------------------//
#if   defined                                 UNICODE                                     //
#      define _WX_CHAR_MODE                   "Unicode"                                   //
#else                                                                                     //
#      define _WX_CHAR_MODE                   "MultiByte"                                 //
#endif                                                                                    //
//----------- _WX_BUILD_MODE -------------------------------------------------------------//
#if   defined                                 _DEBUG                                      //
#      define _WX_BUILD_MODE                  "Debug"                                     //
#else                                                                                     //
#      define _WX_BUILD_MODE                  "Release"                                   //
#endif                                                                                    //
//----------- _WX_PLATFORM_BITS ----------------------------------------------------------//
#if   defined                                 _WIN64                                      //
#      define _WX_PLATFORM_BITS               "64-bits"                                   //
#elif defined                                 _WIN32                                      //
#      define _WX_PLATFORM_BITS               "32-bits"                                   //
#else                                                                                     //
#      define _WX_PLATFORM_BITS               "Unknown"                                   //
#endif                                                                                    //
//----------- _WX_ARCHITECTURE -----------------------------------------------------------//
#if   defined                                 _M_X64                                      //
#      define _WX_ARCHITECTURE                "x64"                                       //
#elif defined                                 _M_IX86                                     //
#      define _WX_ARCHITECTURE                "x86"                                       //
#elif defined                                 _M_AMD64                                    //
#      define _WX_ARCHITECTURE                "AMD64"                                     //
#elif defined                                 _M_ARM64                                    //
#      define _WX_ARCHITECTURE                "ARM64"                                     //
#elif defined                                 _M_ARM                                      //
#      define _WX_ARCHITECTURE                "ARM"                                       //
#elif defined                                 _M_ARM64EC                                  //
#      define _WX_ARCHITECTURE                "ARM64EC"                                   //
#else                                                                                     //
#      define _WX_ARCHITECTURE                "Unknown"                                   //
#endif                                                                                    //
//----------- _WX_COMPILER ---------------------------------------------------------------//
#if   defined                                 __clang__                                   //
#      define _WX_COMPILER                    "Clang "       macro_str(__clang_version__)    //
#elif defined                                 __GNUC__                                    //
#      define _WX_COMPILER                    "GCC "         macro_str(__VERSION__)          //
#elif defined                                 _MSC_VER                                    //
#      define _WX_COMPILER                    "MSVC "        macro_str(_MSC_FULL_VER)        //
#else                                                                                     //
#      define _WX_COMPILER                    "Unknown"                                   //
#endif                                                                                    //
//----------- _NTDDI_ --------------------------------------------------------------------//
#if            NTDDI_VERSION >=               NTDDI_WIN11_GE                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Germanium'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN11_GA                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Gallium'"                      //
#elif          NTDDI_VERSION >=               NTDDI_WIN11_ZN                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Zinc'"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_CU                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Copper'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_NI                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Nickel'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_CO                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Cobalt'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_FE                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Iron'"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_MN                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Manganese'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_VB                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Vibranium'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_19H1                            //
#      define _WX_NTDDI_NAME                  "Windows 10 1903 '19H1''"                   //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS5                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1809 'Redstone 5'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS4                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1803 'Redstone 4'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS3                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1709 'Redstone 3'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS2                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1703 'Redstone 2'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS1                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1607 'Redstone 1'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_TH2                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1511 'Threshold 2'"             //
#elif          NTDDI_VERSION >=               NTDDI_WIN10                                 //
#      define _WX_NTDDI_NAME                  "Windows 10 1507 'Threshold'"               //
#elif          NTDDI_VERSION >=               NTDDI_WINBLUE                               //
#      define _WX_NTDDI_NAME                  "Windows 8.1"                               //
#elif          NTDDI_VERSION >=               NTDDI_WIN8                                  //
#      define _WX_NTDDI_NAME                  "Windows 8"                                 //
#elif          NTDDI_VERSION >=               NTDDI_WIN7                                  //
#      define _WX_NTDDI_NAME                  "Windows 7"                                 //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP4                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP4"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP3                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP3"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP2                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP2"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP1                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP1"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6                                  //
#      define _WX_NTDDI_NAME                  "Windows Vista"                             //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP4                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP4"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP3                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP3"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP2                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP2"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP1                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP1"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03                                  //
#      define _WX_NTDDI_NAME                  "Windows Server 2003"                       //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP4                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP4"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP3                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP3"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP2                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP2"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP1                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP1"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXP                                 //
#      define _WX_NTDDI_NAME                  "Windows XP"                                //
#else                                                                                     //
#      define _WX_NTDDI_NAME                  "Windows Unknown"                           //
#endif                                                                                    //
#      define _NTDDI_INFO                     _WX_NTDDI_NAME " - " macro_str(NTDDI_VERSION)  //
//-------------------------------- _WX_COMPILATION_INFO ----------------------------------//
#             define                          _WX_COMPILATION_INFO                         \
			  "Compiled Date: "               _WX_COMPILED_TIME                       "\n" \
			  "C++ Standard:  "               _WX_CPP_STANDARD                        "\n" \
			  "Char Mode:     "               _WX_CHAR_MODE                           "\n" \
			  "Build Mode:    "               _WX_BUILD_MODE                          "\n" \
			  "Platform Bits: "               _WX_PLATFORM_BITS                       "\n" \
			  "Architecture:  "               _WX_ARCHITECTURE                        "\n" \
			  "Compiler:      "               _WX_COMPILER                            "\n" \
			  "NTDDI Version: "               _WX_NTDDI_NAME                              //
#pragma endregion //////////////////////////////////////////////////////////////////////////

#ifdef WANDX_CPPM_EXPORT_NATIVE

#	pragma region Windows API Reflectors

#	define __wapi_info(name) ThisFile, GetLastError, LiString(#name)

#	define __wapi_rops_noreturn(...)         RefNoReturn
#	define __wapi_rops_direct(...)           RefReturnDirect
#	define __wapi_rops_true(...)             RefReturnTrue
#	define __wapi_rops_positive(...)         RefReturnPositive
#	define __wapi_rops_notzero(...)          RefReturnNotZero
#	define __wapi_rops_natural(...)          RefReturnNatural
#	define __wapi_rops_notnull(...)          RefReturnNotNull
#	define __wapi_rops_validhd(...)          RefReturnHandle
#	define __wapi_rops_success(...)          RefReturnSuccess
#	define __wapi_rops_fault(fault_val)      RefReturnFaultBy<fault_val, LiString(#fault_val)>::template Value

#	define __wapi_rops(type, ...)            macro_call(macro_cat(__wapi_rops_, type), __VA_ARGS__)

/* Macro Windows API reflectors */

#	define wapi_ret(name, type, ...)         constexpr              __wapi_rops(type, __VA_ARGS__)< __wapi_info(name   ), ::name   > name
#	define wapi_ret_W(name, type, ...)       constexpr              __wapi_rops(type, __VA_ARGS__)< __wapi_info(name##W), ::name##W> name
#	define wapi_ret_A(name, type, ...)       constexpr              __wapi_rops(type, __VA_ARGS__)< __wapi_info(name##A), ::name##A> name
#	define wapi_ret_WAO(name, type, ...)     constexpr RefReturnWAO<__wapi_rops(type, __VA_ARGS__), __wapi_info(name   ), ::name##W, ::name##A> name
#	define wapi_ret_WAT(name, type, ...)     template<bool IsUnicode = Native::IsUnicode> \
                                             constexpr RefReturnWAT<__wapi_rops(type, __VA_ARGS__), __wapi_info(name   ), ::name##W, ::name##A, IsUnicode> name



/* Macro exception system reflect for Windows */

#	define wx_throw_line_nt(sent) throw WandX::Exception(__FILE__, __FUNCTION__, #sent, __LINE__, GetLastError())
#	define nt_assert(sent) { using namespace WandX; if (!(sent)) wx_throw_line_nt(sent); }

#	pragma endregion

#	pragma region ////////////////////////

// Macro Of Property

#	define  wx_class_prop_set(type, name, set) inline auto&name(type value) ret_to_self(macro_kill_brace0(set))
#	define  wx_class_prop_get(type, name, get) inline type name(          ) const { macro_kill_brace0(get); }

#	define  class_prop_getas(type, name, get) wx_class_prop_get(type, name, (return get))
#	define  class_prop_getto(type, name, get) wx_class_prop_get(type, name, (ret_to get))
#	define  class_prop_getof(type, name, get) wx_class_prop_get(type, name, (type value; macro_kill_brace0(get); return value))

#	define  class_prop_set(type, name, set) wx_class_prop_set(type, name, set)
#	define  class_prop_get(type, name, d, get) macro_call(macro_cat(class_prop_get, d), type, name, get)

#	define  class_prop_map(type, name, d, get, set) \
			class_prop_get(type, name, d, get); \
			class_prop_set(type, name, set)

//

#	define  class_method(name, ret, arg, body) inline ret name arg ret_##body

#	pragma endregion

///////////////////////////////////////////// !!!!DEPRECATE SOON!!!! /////////////////////////////////////////////

#	define safe_ret_as(sent, ...) { if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#	define safe_ret_to(defs, sent, ...) { defs; if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#	define ret_safe_to(sent, ...) { SetLastError(ERROR_SUCCESS); sent; if (GetLastError()) wx_throw_line_nt(sent); return __VA_ARGS__; }

/* Macro string branch selector */
#	define locale_symbolx(name)     static constexpr auto name = AnyX<IsUnicode>(name##W, name##A)
#	define const_stringx(name, str) static constexpr auto name##A = str; \
									static constexpr auto name##W = L##str
#	define auto_stringx(name, str)  const_stringx(name, str); \
									locale_symbolx(name)
#	define structx(name)            TypeIf<IsUnicode, name##W, name##A>
#	define using_structx(name)      using name = TypeIf<IsUnicode, name##W, name##A>

#endif

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32;
#endif

#include "WandX.h"

#undef min
#undef max

#pragma region WinBase.h
#undef GetBinaryType
#undef GetShortPathName
#undef GetLongPathNameTransacted
#undef SetEnvironmentStrings
#undef SetFileShortName
#undef FormatMessage
#undef CreateMailslot
#undef EncryptFile
#undef DecryptFile
#undef FileEncryptionStatus
#undef OpenEncryptedFileRaw
#undef CreateFileMapping
#undef CreateFileMappingNuma
#undef OpenFileMapping
#undef GetLogicalDriveStrings
#undef QueryFullProcessImageName
#undef GetFirmwareEnvironmentVariable
#undef GetFirmwareEnvironmentVariableEx
#undef SetFirmwareEnvironmentVariable
#undef SetFirmwareEnvironmentVariableEx
#undef FindResource
#undef FindResourceEx
#undef EnumResourceTypes
#undef EnumResourceLanguages
#undef BeginUpdateResource
#undef UpdateResource
#undef EndUpdateResource
#undef GlobalAddAtom
#undef GlobalAddAtomEx
#undef GlobalFindAtom
#undef GlobalGetAtomName
#undef AddAtom
#undef FindAtom
#undef GetAtomName
#undef GetProfileInt
#undef GetProfileString
#undef WriteProfileString
#undef GetProfileSection
#undef WriteProfileSection
#undef GetPrivateProfileInt
#undef GetPrivateProfileString
#undef WritePrivateProfileString
#undef GetPrivateProfileSection
#undef WritePrivateProfileSection
#undef GetPrivateProfileSectionNames
#undef GetPrivateProfileStruct
#undef WritePrivateProfileStruct
#undef SetDllDirectory
#undef GetDllDirectory
#undef CreateDirectoryEx
#undef CreateDirectoryTransacted
#undef RemoveDirectoryTransacted
#undef GetFullPathNameTransacted
#undef DefineDosDevice
#undef QueryDosDevice
#undef CreateFileTransacted
#undef SetFileAttributesTransacted
#undef GetFileAttributesTransacted
#undef GetCompressedFileSizeTransacted
#undef DeleteFileTransacted
#undef CheckNameLegalDOS8Dot3
#undef FindFirstFileTransacted
#undef CopyFile
#undef CopyFileEx
#undef CopyFileTransacted
#undef MoveFile
#undef MoveFileEx
#undef MoveFileWithProgress
#undef MoveFileTransacted
#undef ReplaceFile
#undef CreateHardLink
#undef CreateHardLinkTransacted
#undef CreateNamedPipe
#undef GetNamedPipeHandleState
#undef CallNamedPipe
#undef WaitNamedPipe
#undef GetNamedPipeClientComputerName
#undef SetVolumeLabel
#undef ClearEventLog
#undef BackupEventLog
#undef OpenEventLog
#undef RegisterEventSource
#undef OpenBackupEventLog
#undef ReadEventLog
#undef ReportEvent
#undef AccessCheckAndAuditAlarm
#undef AccessCheckByTypeAndAuditAlarm
#undef AccessCheckByTypeResultListAndAuditAlarm
#undef AccessCheckByTypeResultListAndAuditAlarmByHandle
#undef ObjectOpenAuditAlarm
#undef ObjectPrivilegeAuditAlarm
#undef ObjectCloseAuditAlarm
#undef ObjectDeleteAuditAlarm
#undef PrivilegedServiceAuditAlarm
#undef SetFileSecurity
#undef GetFileSecurity
#undef IsBadStringPtr
#undef LookupAccountSid
#undef LookupAccountName
#undef LookupAccountNameLocal
#undef LookupAccountSidLocal
#undef LookupPrivilegeValue
#undef LookupPrivilegeName
#undef LookupPrivilegeDisplayName
#undef BuildCommDCB
#undef BuildCommDCBAndTimeouts
#undef CommConfigDialog
#undef GetDefaultCommConfig
#undef SetDefaultCommConfig
#undef GetComputerName
#undef DnsHostnameToComputerName
#undef GetUserName
#undef LogonUser
#undef LogonUserEx
#undef GetCurrentHwProfile
#undef VerifyVersionInfo
#undef CreateJobObject
#undef OpenJobObject
#undef FindFirstVolume
#undef FindNextVolume
#undef FindFirstVolumeMountPoint
#undef FindNextVolumeMountPoint
#undef SetVolumeMountPoint
#undef DeleteVolumeMountPoint
#undef GetVolumeNameForVolumeMountPoint
#undef GetVolumePathName
#undef GetVolumePathNamesForVolumeName
#undef CreateActCtx
#undef FindActCtxSectionString
#undef CreateSymbolicLink
#undef CreateSymbolicLinkTransacted
#pragma endregion

#pragma region WinUser.h
#undef wvsprintf
#undef wsprintf
#undef LoadKeyboardLayout
#undef GetKeyboardLayoutName
#undef CreateDesktop
#undef CreateDesktopEx
#undef OpenDesktop
#undef EnumDesktops
#undef CreateWindowStation
#undef OpenWindowStation
#undef EnumWindowStations
#undef GetUserObjectInformation
#undef SetUserObjectInformation
#undef RegisterWindowMessage
#undef GetMessage
#undef DispatchMessage
#undef PeekMessage
#undef SendMessage
#undef SendMessageTimeout
#undef SendNotifyMessage
#undef SendMessageCallback
#undef BroadcastSystemMessageEx
#undef BroadcastSystemMessage
#undef RegisterDeviceNotification
#undef PostMessage
#undef PostThreadMessage
#undef PostAppMessage
#undef DefWindowProc
#undef CallWindowProc
#undef RegisterClass
#undef UnregisterClass
#undef GetClassInfo
#undef RegisterClassEx
#undef GetClassInfoEx
#undef CreateWindowEx
#undef CreateWindow
#undef CreateDialogParam
#undef CreateDialogIndirectParam
#undef CreateDialog
#undef CreateDialogIndirect
#undef DialogBoxParam
#undef DialogBoxIndirectParam
#undef DialogBox
#undef DialogBoxIndirect
#undef SetDlgItemText
#undef GetDlgItemText
#undef SendDlgItemMessage
#undef DefDlgProc
#undef CallMsgFilter
#undef RegisterClipboardFormat
#undef GetClipboardFormatName
#undef CharToOem
#undef OemToChar
#undef CharToOemBuff
#undef OemToCharBuff
#undef CharUpper
#undef CharUpperBuff
#undef CharLower
#undef CharLowerBuff
#undef CharNext
#undef CharPrev
#undef IsCharAlpha
#undef IsCharAlphaNumeric
#undef IsCharUpper
#undef IsCharLower
#undef GetKeyNameText
#undef VkKeyScan
#undef VkKeyScanEx
#undef MapVirtualKey
#undef MapVirtualKeyEx
#undef LoadAccelerators
#undef CreateAcceleratorTable
#undef CopyAcceleratorTable
#undef TranslateAccelerator
#undef LoadMenu
#undef LoadMenuIndirect
#undef ChangeMenu
#undef GetMenuString
#undef InsertMenu
#undef AppendMenu
#undef ModifyMenu
#undef InsertMenuItem
#undef GetMenuItemInfo
#undef SetMenuItemInfo
#undef DrawText
#undef DrawTextEx
#undef GrayString
#undef DrawState
#undef TabbedTextOut
#undef GetTabbedTextExtent
#undef SetProp
#undef GetProp
#undef RemoveProp
#undef EnumPropsEx
#undef EnumProps
#undef SetWindowText
#undef GetWindowText
#undef GetWindowTextLength
#undef MessageBox
#undef MessageBoxEx
#undef MessageBoxIndirect
#undef GetWindowLong
#undef SetWindowLong
#undef GetWindowLongPtr
#undef SetWindowLongPtr
#undef GetClassLong
#undef SetClassLong
#undef GetClassLongPtr
#undef SetClassLongPtr
#undef FindWindow
#undef FindWindowEx
#undef GetClassName
#undef SetWindowsHook
#undef SetWindowsHookEx
#undef LoadBitmap
#undef LoadCursor
#undef LoadCursorFromFile
#undef LoadIcon
#undef PrivateExtractIcons
#undef LoadImage
#undef GetIconInfoEx
#undef IsDialogMessage
#undef DlgDirList
#undef DlgDirSelectEx
#undef DlgDirListComboBox
#undef DlgDirSelectComboBoxEx
#undef DefFrameProc
#undef DefMDIChildProc
#undef CreateMDIWindow
#undef WinHelp
#undef ChangeDisplaySettings
#undef ChangeDisplaySettingsEx
#undef EnumDisplaySettings
#undef EnumDisplaySettingsEx
#undef EnumDisplayDevices
#undef SystemParametersInfo
#undef GetMonitorInfo
#undef GetWindowModuleFileName
#undef RealGetWindowClass
#undef GetAltTabInfo
#undef GetRawInputDeviceInfo
#pragma endregion
