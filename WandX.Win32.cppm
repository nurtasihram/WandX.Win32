module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.h"

export module WandX.Win32;

import WandX;

export namespace WandX {

#pragma region WandX.Win32 API Wrappers

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnDirect = BridgeAPI<file, name, decltype(fn)>
	::template Ref<fn>
	::Passby;

template<auto file, auto name, auto fn,
	AssertOperatorType auto assert,
	class NewRet = ReturnTypeOf<fn>,
	auto GetLastError = ::GetLastError>
using RefReturnAssert = BridgeAPI<file, name, decltype(fn)>
	::template Ref<fn>
	::template AssertReturn<assert, NewRet, GetLastError>;

inline bool HandleNotInvalid(HANDLE h) { return h != INVALID_HANDLE_VALUE; }
constexpr auto AssertHandleNotInvalid = AssertOperator<
	HANDLE, AssertOps::CustomTest, HandleNotInvalid,
	LiString(" == INVALID_HANDLE_VALUE")>();
template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
	requires(IsSame<ReturnTypeOf<fn>, HANDLE>)
using RefReturnHandle = RefReturnAssert<
	file, name, fn,
	AssertHandleNotInvalid,
	HANDLE, GetLastError>;

inline bool ResultSuccess(HRESULT hr) {
	if (SUCCEEDED(hr)) return true;
	SetLastError(hr);
	return false;
}
constexpr auto AssertResultSuccess = AssertOperator<
	HRESULT, AssertOps::CustomTest, ResultSuccess,
	LiString(" is failed")>();
template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
	requires(IsSameSize<ReturnTypeOf<fn>, HRESULT>)
using RefReturnSuccess = RefReturnAssert<
	file, name, fn,
	AssertResultSuccess,
	HRESULT, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnTrue = RefReturnAssert<
	file, name, fn,
	AssertTrue<ReturnTypeOf<fn>>,
	void, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnNotZero = RefReturnAssert<
	file, name, fn,AssertNotZero<ReturnTypeOf<fn>>,
	ReturnTypeOf<fn>, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnNotNull = RefReturnAssert<
	file, name, fn,AssertNotNull<ReturnTypeOf<fn>>,
	ReturnTypeOf<fn>, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnPositive = RefReturnAssert<
	file, name, fn,AssertPositive<ReturnTypeOf<fn>>,
	ReturnTypeOf<fn>, GetLastError>;

template<auto file, auto name, auto fn,
	ReturnTypeOf<fn> fault_val, auto fault_str,
	auto GetLastError = ::GetLastError>
using RefReturnFault = RefReturnAssert<
	file, name, fn,
	AssertFaultValue<ReturnTypeOf<fn>, fault_val, fault_str>,
	ReturnTypeOf<fn>, GetLastError>;

///

template<auto fnW, auto fnA>
concept WinAPIPair =
	IsSame<ReturnTypeOf<fnW>, ReturnTypeOf<fnA>> &&
	ParaCountOf(fnW) == ParaCountOf(fnA) &&
	!InvokableAmbiguous<fnW, fnA>;

template<
	template<auto file, auto name, auto fn, auto GetLastError> class RefReturnType,
	auto file, auto name, auto fnW, auto fnA,
	auto GetLastError = ::GetLastError>
	requires(WinAPIPair<fnW, fnA>)
using RefReturnWA = OverrideFunctor<
	RefReturnType<file, name + "W", fnW, GetLastError>,
	RefReturnType<file, name + "A", fnA, GetLastError>>;

#pragma endregion

}

static constexpr auto ThisFile = WandX::LiString("WandX.Win32");

export namespace WandX::Native {

constexpr bool IsUnicode =
#ifdef UNICODE
	UNICODE;
#elif defined(_UNICODE)
	_UNICODE;
#else
	false;
#endif

#pragma region WinBase.h
// GlobalAlloc
// GlobalReAlloc
// GlobalSize
// GlobalUnlock
// GlobalLock
// GlobalFlags
// GlobalHandle
// GlobalFree
// GlobalMemoryStatus
// LocalAlloc
// LocalReAlloc
// LocalLock
// LocalHandle
// LocalUnlock
// LocalSize
// LocalFlags
// LocalFree
// GetBinaryType
wapi_ret_WAO(GetBinaryType, true);
wapi_ret_WAO(GetLongPathNameTransacted, positive);
// GetProcessAffinityMask
// SetProcessAffinityMask
// GetProcessIoCounters
// FatalExit
// SwitchToFiber
// DeleteFiber
// ConvertFiberToThread
// CreateFiberEx
// ConvertThreadToFiberEx
// CreateFiber
// ConvertThreadToFiber
// CreateUmsCompletionList
// DequeueUmsCompletionListItems
// GetUmsCompletionListEvent
// ExecuteUmsThread
// UmsThreadYield
// DeleteUmsCompletionList
// GetCurrentUmsThread
// GetNextUmsListItem
// QueryUmsThreadInformation
// SetUmsThreadInformation
// DeleteUmsThreadContext
// CreateUmsThreadContext
// EnterUmsSchedulingMode
// GetUmsSystemThreadInformation
// SetThreadAffinityMask
// SetProcessDEPPolicy
// GetProcessDEPPolicy
// RequestWakeupLatency
// IsSystemResumeAutomatic
// GetThreadSelectorEntry
// SetThreadExecutionState
// PowerCreateRequest
// PowerSetRequest
// PowerClearRequest
// SetFileCompletionNotificationModes
// Wow64GetThreadSelectorEntry
// DebugSetProcessKillOnExit
// DebugBreakProcess
wapi_ret(PulseEvent, true);
wapi_ret(GlobalDeleteAtom, true);
// InitAtomTable
wapi_ret(DeleteAtom, true);
// SetHandleCount
// GetDevicePowerState
wapi_ret_WAO(SetFileShortName, true);
// LoadModule
// WinExec
wapi_ret(ClearCommBreak, true);
wapi_ret(ClearCommError, true);
wapi_ret(SetupComm, true);
wapi_ret(EscapeCommFunction, true);
wapi_ret(GetCommConfig, true);
wapi_ret(GetCommMask, true);
wapi_ret(GetCommProperties, true);
wapi_ret(GetCommModemStatus, true);
wapi_ret(GetCommState, true);
wapi_ret(GetCommTimeouts, true);
wapi_ret(PurgeComm, true);
wapi_ret(SetCommBreak, true);
wapi_ret(SetCommConfig, true);
wapi_ret(SetCommMask, true);
wapi_ret(SetCommState, true);
wapi_ret(SetCommTimeouts, true);
wapi_ret(TransmitCommChar, true);
wapi_ret(WaitCommEvent, true);
#if (NTDDI_VERSION >= NTDDI_WIN10_RS3)
wapi_ret(OpenCommPort, validhd);
wapi_ret(GetCommPorts, success);
#endif
// SetTapePosition
// GetTapePosition
// PrepareTape
// EraseTape
// CreateTapePartition
// WriteTapemark
// GetTapeStatus
// GetTapeParameters
// SetTapeParameters
// GetSystemDEPPolicy
// GetSystemRegistryQuota
// FileTimeToDosDateTime
// DosDateTimeToFileTime
wapi_ret_WAO(FormatMessage, positive);
wapi_ret_WAO(CreateMailslot, notnull);
// GetMailslotInfo
// SetMailslotInfo
wapi_ret_WAO(EncryptFile, true);
wapi_ret_WAO(DecryptFile, true);
wapi_ret_WAO(FileEncryptionStatus, true);
wapi_ret_WAO(OpenEncryptedFileRaw, success);
// ReadEncryptedFileRaw
// WriteEncryptedFileRaw
// CloseEncryptedFileRaw
// OpenFile
// IsTextUnicode
// BackupRead
// BackupSeek
// BackupWrite
// CreateFileMapping
inline HANDLE CreateFileMapping(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCSTR lpName)
	safe_ret_as(auto h = ::CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName), h);
// from fileapi.h
inline HANDLE CreateFileMapping(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName)
	safe_ret_as(auto h = ::CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName), h);
// CreateFileMappingNuma
inline HANDLE CreateFileMappingNuma(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCSTR lpName, DWORD nndPreferred)
	safe_ret_as(auto h = ::CreateFileMappingNumaA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName, nndPreferred), h);
// from fileapi.h
inline HANDLE CreateFileMappingNuma(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName, DWORD nndPreferred)
	safe_ret_as(auto h = ::CreateFileMappingNumaW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName, nndPreferred), h);
// OpenFileMapping
inline HANDLE OpenFileMapping(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName)
	safe_ret_as(auto h = ::OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName), h);
// from fileapi.h
inline HANDLE OpenFileMapping(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName)
	safe_ret_as(auto h = ::OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName), h);
// GetLogicalDriveStrings
inline DWORD GetLogicalDriveStrings(LPSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto h = ::GetLogicalDriveStringsA(nSize, lpBuffer), h);
// from fileapi.h
inline DWORD GetLogicalDriveStrings(LPWSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto h = ::GetLogicalDriveStringsW(nSize, lpBuffer), h);
// LoadPackagedLibrary
wapi_ret_WAO(QueryFullProcessImageName, true);
wapi_ret_WAO(GetFirmwareEnvironmentVariable, positive);
wapi_ret_WAO(GetFirmwareEnvironmentVariableEx, positive);
wapi_ret_WAO(SetFirmwareEnvironmentVariable, true);
wapi_ret_WAO(SetFirmwareEnvironmentVariableEx, true);
// GetFirmwareType
// IsNativeVhdBoot
wapi_ret_WAO(EnumResourceTypes, true);
wapi_ret_WAO(EnumResourceLanguages, true);
wapi_ret_WAO(BeginUpdateResource, notnull);
wapi_ret_WAO(UpdateResource, true);
wapi_ret_WAT(EndUpdateResource, true);
wapi_ret_WAO(GlobalAddAtom, positive);
wapi_ret_WAO(GlobalAddAtomEx, positive);
wapi_ret_WAO(GlobalFindAtom, positive);
wapi_ret_WAO(GlobalGetAtomName, positive);
wapi_ret_WAO(AddAtom, positive);
wapi_ret_WAO(FindAtom, positive);
wapi_ret_WAO(GetAtomName, positive);
wapi_ret_WAO(GetProfileInt, direct);
wapi_ret_WAO(GetProfileString, direct);
wapi_ret_WAO(WriteProfileString, true);
wapi_ret_WAO(GetProfileSection, direct);
wapi_ret_WAO(WriteProfileSection, true);
wapi_ret_WAO(GetPrivateProfileInt, direct);
wapi_ret_WAO(GetPrivateProfileString, positive);
wapi_ret_WAO(WritePrivateProfileString, true);
wapi_ret_WAO(GetPrivateProfileSection, positive);
wapi_ret_WAO(WritePrivateProfileSection, true);
wapi_ret_WAO(GetPrivateProfileSectionNames, positive);
wapi_ret_WAO(GetPrivateProfileStruct, true);
wapi_ret_WAO(WritePrivateProfileStruct, true);
wapi_ret_WAO(SetDllDirectory, true);
wapi_ret_WAO(GetDllDirectory, positive);
// SetSearchPathMode
wapi_ret_WAO(CreateDirectoryEx, true);
wapi_ret_WAO(CreateDirectoryTransacted, true);
// RemoveDirectory
// from fileapi.h
inline void RemoveDirectory(LPCSTR lpPathName)
	safe_ret_as(::RemoveDirectoryA(lpPathName));
// from fileapi.h
inline void RemoveDirectory(LPCWSTR lpPathName)
	safe_ret_as(::RemoveDirectoryW(lpPathName));
wapi_ret_WAO(RemoveDirectoryTransacted, true);
// GetFullPathName
// from fileapi.h
inline DWORD GetFullPathName(LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart)
	safe_ret_as(auto h = ::GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart), h);
// from fileapi.h
inline DWORD GetFullPathName(LPCWSTR lpFileName, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart)
	safe_ret_as(auto h = ::GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart), h);
wapi_ret_WAO(GetFullPathNameTransacted, positive);
// DefineDosDevice
inline void DefineDosDevice(DWORD dwFlags, LPCSTR lpDeviceName, LPCSTR lpTargetPath)
	safe_ret_as(::DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath));
// from fileapi.h
inline void DefineDosDevice(DWORD dwFlags, LPCWSTR lpDeviceName, LPCWSTR lpTargetPath)
	safe_ret_as(::DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath));
// QueryDosDevice
inline DWORD QueryDosDevice(LPCSTR lpDeviceName, LPSTR lpTargetPath, DWORD ucchMax)
	safe_ret_as(auto h = ::QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax), h);
// from fileapi.h
inline DWORD QueryDosDevice(LPCWSTR lpDeviceName, LPWSTR lpTargetPath, DWORD ucchMax)
	safe_ret_as(auto h = ::QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax), h);
// CreateFileTransacted
inline HANDLE CreateFileTransacted(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile, HANDLE hTransaction, PUSHORT pusMiniVersion, PVOID  lpExtendedParameter)
	safe_ret_as(auto h = ::CreateFileTransactedA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile,hTransaction, pusMiniVersion, lpExtendedParameter); h != INVALID_HANDLE_VALUE, h);
inline HANDLE CreateFileTransacted(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile, HANDLE hTransaction, PUSHORT pusMiniVersion, PVOID  lpExtendedParameter)
	safe_ret_as(auto h = ::CreateFileTransactedW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile,hTransaction, pusMiniVersion, lpExtendedParameter); h != INVALID_HANDLE_VALUE, h);
// ReOpenFile
// SetFileAttributes
// from fileapi.h
inline void SetFileAttributes(LPCSTR lpFileName, DWORD dwFileAttributes)
	safe_ret_as(::SetFileAttributesA(lpFileName, dwFileAttributes));
// from fileapi.h
inline void SetFileAttributes(LPCWSTR lpFileName, DWORD dwFileAttributes)
	safe_ret_as(::SetFileAttributesW(lpFileName, dwFileAttributes));
wapi_ret_WAO(SetFileAttributesTransacted, true);
// GetFileAttributes
// from fileapi.h
inline DWORD GetFileAttributes(LPCSTR lpFileName)
	safe_ret_as(auto h = ::GetFileAttributesA(lpFileName); h != INVALID_FILE_ATTRIBUTES, h);
// from fileapi.h
inline DWORD GetFileAttributes(LPCWSTR lpFileName)
	safe_ret_as(auto h = ::GetFileAttributesW(lpFileName); h != INVALID_FILE_ATTRIBUTES, h);
//wapi_ret_WAO(GetFileAttributesEx, true);
wapi_ret_WAO(GetFileAttributesTransacted, true);
// GetCompressedFileSize
// from fileapi.h
inline DWORD GetCompressedFileSize(LPCSTR lpFileName, LPDWORD lpFileSizeHigh)
	safe_ret_as(auto h = ::GetCompressedFileSizeA(lpFileName, lpFileSizeHigh); h != INVALID_FILE_SIZE, h);
// from fileapi.h
inline DWORD GetCompressedFileSize(LPCWSTR lpFileName, LPDWORD lpFileSizeHigh)
	safe_ret_as(auto h = ::GetCompressedFileSizeW(lpFileName, lpFileSizeHigh); h != INVALID_FILE_SIZE, h);
// GetCompressedFileSizeTransacted
inline DWORD GetCompressedFileSizeTransacted(LPCSTR lpFileName, LPDWORD lpFileSizeHigh, HANDLE hTransaction)
	safe_ret_as(auto h = ::GetCompressedFileSizeTransactedA(lpFileName, lpFileSizeHigh, hTransaction); h != INVALID_FILE_SIZE, h);
inline DWORD GetCompressedFileSizeTransacted(LPCWSTR lpFileName, LPDWORD lpFileSizeHigh, HANDLE hTransaction)
	safe_ret_as(auto h = ::GetCompressedFileSizeTransactedW(lpFileName, lpFileSizeHigh, hTransaction); h != INVALID_FILE_SIZE, h);
wapi_ret_WAO(DeleteFileTransacted, true);
wapi_ret_WAO(CheckNameLegalDOS8Dot3, true);
// FindFirstFile
// from fileapi.h
inline HANDLE FindFirstFile(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
	safe_ret_as(auto h = ::FindFirstFileA(lpFileName, lpFindFileData); h != INVALID_HANDLE_VALUE, h);
// from fileapi.h
inline HANDLE FindFirstFile(LPCWSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData)
	safe_ret_as(auto h = ::FindFirstFileW(lpFileName, lpFindFileData); h != INVALID_HANDLE_VALUE, h);
// FindFirstFileEx
// from fileapi.h
inline HANDLE FindFirstFile(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags)
	safe_ret_as(auto h = ::FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData,   fSearchOp, lpSearchFilter, dwAdditionalFlags); h != INVALID_HANDLE_VALUE, h);
// from fileapi.h
inline HANDLE FindFirstFile(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags)
	safe_ret_as(auto h = ::FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData,   fSearchOp, lpSearchFilter, dwAdditionalFlags); h != INVALID_HANDLE_VALUE, h);
// FindFirstFileTransacted
inline HANDLE FindFirstFileTransacted(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstFileTransactedA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags, hTransaction); h != INVALID_HANDLE_VALUE, h);
inline HANDLE FindFirstFileTransacted(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstFileTransactedW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags, hTransaction); h != INVALID_HANDLE_VALUE, h);
wapi_ret_WAO(CopyFile, true);
wapi_ret_WAO(CopyFileEx, true);
// CopyFileTransacted
// CopyFile2
wapi_ret_WAO(MoveFile, true);
wapi_ret_WAO(MoveFileEx, true);
wapi_ret_WAO(MoveFileWithProgress, true);
wapi_ret_WAO(ReplaceFile, true);
wapi_ret_WAO(CreateHardLink, true);
wapi_ret_WAO(CreateHardLinkTransacted, true);
// FindFirstStreamTransacted
inline HANDLE FindFirstStreamTransacted(LPCWSTR lpFileName, STREAM_INFO_LEVELS InfoLevel, LPVOID lpFindStreamData, DWORD dwFlags, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstStreamTransactedW(lpFileName, InfoLevel, lpFindStreamData, dwFlags, hTransaction); h != INVALID_HANDLE_VALUE, h);
// FindFirstFileName
inline HANDLE FindFirstFileNameTransacted(LPCWSTR lpFileName, DWORD dwFlags, LPDWORD StringLength, PWSTR LinkName, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstFileNameTransactedW(lpFileName, dwFlags, StringLength, LinkName, hTransaction); h != INVALID_HANDLE_VALUE, h);
// CreateNamedPipe
inline HANDLE CreateNamedPipe(LPCSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(auto h = ::CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes); h != INVALID_HANDLE_VALUE, h);
// from namedpipeapi.h
inline HANDLE CreateNamedPipe(LPCWSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize,  DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(auto h = ::CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes); h != INVALID_HANDLE_VALUE, h);
// GetNamedPipeHandleState
inline void GetNamedPipeHandleState(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout, LPSTR lpUserName, DWORD nMaxUserNameSize)
	safe_ret_as(::GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount,  lpCollectDataTimeout, lpUserName, nMaxUserNameSize));
// from namedpipeapi.h
inline void GetNamedPipeHandleState(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout, LPWSTR lpUserName, DWORD nMaxUserNameSize)
	safe_ret_as(::GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount,  lpCollectDataTimeout, lpUserName, nMaxUserNameSize));
// CallNamedPipe
inline void CallNamedPipe(LPCSTR lpNamedPipeName, LPVOID lpInBuffer, DWORD nInBufferSize,  LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesRead, DWORD nTimeOut)
	safe_ret_as(::CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut));
// from namedpipeapi.h
inline void CallNamedPipe(LPCWSTR lpNamedPipeName, LPVOID lpInBuffer, DWORD nInBufferSize,  LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesRead, DWORD nTimeOut)
	safe_ret_as(::CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut));
// WaitNamedPipe
inline void WaitNamedPipe(LPCSTR lpNamedPipeName, DWORD nTimeOut)
	safe_ret_as(::WaitNamedPipeA(lpNamedPipeName, nTimeOut));
// from namedpipeapi.h
inline void WaitNamedPipe(LPCWSTR lpNamedPipeName, DWORD nTimeOut)
	safe_ret_as(::WaitNamedPipeW(lpNamedPipeName, nTimeOut));
// GetNamedPipeClientComputerName
inline void GetNamedPipeClientComputerName(HANDLE Pipe, LPSTR ClientComputerName, ULONG ClientComputerNameLength)
	safe_ret_as(::GetNamedPipeClientComputerNameA(Pipe, ClientComputerName, ClientComputerNameLength));
// from namedpipeapi.h
inline void GetNamedPipeClientComputerName(HANDLE Pipe, LPWSTR ClientComputerName, ULONG ClientComputerNameLength)
	safe_ret_as(::GetNamedPipeClientComputerNameW(Pipe, ClientComputerName, ClientComputerNameLength));
// GetNamedPipeClientProcessId
// GetNamedPipeClientSessionId
// GetNamedPipeServerProcessId
// GetNamedPipeServerSessionId
wapi_ret_WAO(SetVolumeLabel, true);
// SetFileBandwidthReservation
// GetFileBandwidthReservation
// ClearEventLog
wapi_ret_WAO(BackupEventLog, true);
// CloseEventLog
// DeregisterEventSource
// NotifyChangeEventLog
// GetNumberOfEventLogRecords
// GetOldestEventLogRecord
wapi_ret_WAO(OpenEventLog, notnull);
wapi_ret_WAO(RegisterEventSource, notnull);
wapi_ret_WAO(OpenBackupEventLog, notnull);
wapi_ret_WAT(ReadEventLog, positive);
wapi_ret_WAO(ReportEvent, true);
// GetEventLogInformation
// OperationStart
// OperationEnd
// AddConditionalAce
// ReadDirectoryChanges
inline void ReadDirectoryChanges(HANDLE hDirectory, LPVOID lpBuffer, DWORD nBufferLength, BOOL bWatchSubtree, DWORD dwNotifyFilter, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
	safe_ret_as(::ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree,   dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine));
#if (NTDDI_VERSION >= NTDDI_WIN10_RS3)
// ReadDirectoryChangesEx
inline void ReadDirectoryChangesEx(HANDLE hDirectory, LPVOID lpBuffer, DWORD nBufferLength, BOOL bWatchSubtree, DWORD dwNotifyFilter, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine, READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass)
	safe_ret_as(::ReadDirectoryChangesExW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine, ReadDirectoryNotifyInformationClass));
#endif
// MapViewOfFileExNuma
// IsBadReadPtr - deprecated
// IsBadWritePtr - deprecated
// IsBadCodePtr - deprecated
// IsBadStringPtr - deprecated
wapi_ret_WAO(LookupAccountSid, true);
wapi_ret_WAO(LookupAccountName, true);
wapi_ret_WAO(LookupAccountNameLocal, true);
wapi_ret_WAO(LookupAccountSidLocal, true);
wapi_ret_WAO(LookupPrivilegeValue, true);
wapi_ret_WAO(LookupPrivilegeName, true);
wapi_ret_WAO(LookupPrivilegeDisplayName, true);
wapi_ret_WAO(BuildCommDCB, true);
wapi_ret_WAO(BuildCommDCBAndTimeouts, true);
wapi_ret_WAO(CommConfigDialog, true);
wapi_ret_WAO(GetDefaultCommConfig, true);
wapi_ret_WAO(SetDefaultCommConfig, true);
wapi_ret_WAO(GetComputerName, true);
wapi_ret_WAO(DnsHostnameToComputerName, true);
wapi_ret_WAO(GetUserName, true);
wapi_ret_WAO(LogonUser, true);
wapi_ret_WAO(LogonUserEx, true);
// CreateProcessWithLogon
inline void CreateProcessWithLogon(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags,   LPCWSTR lpApplicationName, LPWSTR lpCommandLine,   DWORD dwCreationFlags, LPVOID lpEnvironment,   LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo,   LPPROCESS_INFORMATION lpProcessInformation)
	safe_ret_as(::CreateProcessWithLogonW(lpUsername, lpDomain, lpPassword, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation));
// CreateProcessWithToken
inline void CreateProcessWithToken(HANDLE hToken, DWORD dwLogonFlags, LPCWSTR lpApplicationName,   LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment,   LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo,   LPPROCESS_INFORMATION lpProcessInformation)
	safe_ret_as(::CreateProcessWithTokenW(hToken, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation));
wapi_ret(RegisterWaitForSingleObject, true);
wapi_ret(UnregisterWait, true);
// BindIoCompletionCallback
// AddIntegrityLabelToBoundaryDescriptor
wapi_ret_WAO(GetCurrentHwProfile, true);
// VerifyVersionInfo
//inline void VerifyVersionInfo(LPOSVERSIONINFOEXA lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
//	safe_ret_as(::VerifyVersionInfoA(lpVersionInfo, dwTypeMask, dwlConditionMask));
//inline void VerifyVersionInfo(LPOSVERSIONINFOEXW lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
//	safe_ret_as(::VerifyVersionInfoW(lpVersionInfo, dwTypeMask, dwlConditionMask));// SetSystemPowerState
// GetSystemPowerStatus
// MapUserPhysicalPagesScatter
// FindFirstVolume
inline HANDLE FindFirstVolume(LPSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeA(lpszVolumeName, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
// from fileapi.h
inline HANDLE FindFirstVolume(LPWSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeW(lpszVolumeName, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
// FindNextVolume
inline void FindNextVolume(HANDLE hFindVolume, LPSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::FindNextVolumeA(hFindVolume, lpszVolumeName, cchBufferLength));
// from fileapi.h
inline void FindNextVolume(HANDLE hFindVolume, LPWSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::FindNextVolumeW(hFindVolume, lpszVolumeName, cchBufferLength));
// FindFirstVolumeMountPoint
inline HANDLE FindFirstVolumeMountPoint(LPCSTR lpszRootPathName, LPSTR lpszVolumeMountPoint, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeMountPointA(lpszRootPathName, lpszVolumeMountPoint, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
inline HANDLE FindFirstVolumeMountPoint(LPCWSTR lpszRootPathName, LPWSTR lpszVolumeMountPoint, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeMountPointW(lpszRootPathName, lpszVolumeMountPoint, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
wapi_ret_WAO(FindNextVolumeMountPoint, true);
// FindVolumeMountPointClose
wapi_ret_WAO(SetVolumeMountPoint, true);
// DeleteVolumeMountPoint
inline void DeleteVolumeMountPoint(LPCSTR lpszVolumeMountPoint)
	safe_ret_as(::DeleteVolumeMountPointA(lpszVolumeMountPoint));
// from fileapi.h
inline void DeleteVolumeMountPoint(LPCWSTR lpszVolumeMountPoint)
	safe_ret_as(::DeleteVolumeMountPointW(lpszVolumeMountPoint));
// GetVolumeNameForVolumeMountPoint
inline void GetVolumeNameForVolumeMountPoint(LPCSTR lpszVolumeMountPoint, LPSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumeNameForVolumeMountPointA(lpszVolumeMountPoint, lpszVolumeName, cchBufferLength));
// from fileapi.h
inline void GetVolumeNameForVolumeMountPoint(LPCWSTR lpszVolumeMountPoint, LPWSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumeNameForVolumeMountPointW(lpszVolumeMountPoint, lpszVolumeName, cchBufferLength));
// GetVolumePathName
inline void GetVolumePathName(LPCSTR lpszFileName, LPSTR lpszVolumePathName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumePathNameA(lpszFileName, lpszVolumePathName, cchBufferLength));
// from fileapi.h
inline void GetVolumePathName(LPCWSTR lpszFileName, LPWSTR lpszVolumePathName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumePathNameW(lpszFileName, lpszVolumePathName, cchBufferLength));
// GetVolumePathNamesForVolumeName
inline void GetVolumePathNamesForVolumeName(LPCSTR lpszVolumeName, LPSTR lpszVolumePathNames, DWORD cchBufferLength,LPDWORD lpcchReturnLength)
	safe_ret_as(::GetVolumePathNamesForVolumeNameA(lpszVolumeName, lpszVolumePathNames, cchBufferLength,  lpcchReturnLength));
// from fileapi.h
inline void GetVolumePathNamesForVolumeName(LPCWSTR lpszVolumeName, LPWSTR lpszVolumePathNames, DWORD cchBufferLength,LPDWORD lpcchReturnLength)
	safe_ret_as(::GetVolumePathNamesForVolumeNameW(lpszVolumeName, lpszVolumePathNames, cchBufferLength,  lpcchReturnLength));
// CreateActCtx
inline HANDLE CreateActCtx(PCACTCTXA pActCtx)
	safe_ret_as(auto h = ::CreateActCtxA(pActCtx); h != INVALID_HANDLE_VALUE, h);
inline HANDLE CreateActCtx(PCACTCTXW pActCtx)
	safe_ret_as(auto h = ::CreateActCtxW(pActCtx); h != INVALID_HANDLE_VALUE, h);
// AddRefActCtx
// ReleaseActCtx
// ZombifyActCtx
// ActivateActCtx
// DeactivateActCtx
// GetCurrentActCtx
wapi_ret_WAO(FindActCtxSectionString, true);
// FindActCtxSectionGuid
// QueryActCtx
inline void QueryActCtx(DWORD dwFlags, HANDLE hActCtx,PVOID pvSubInstance, ULONG ulInfoClass,PVOID pvBuffer, SIZE_T cbBuffer, SIZE_T *pcbWrittenOrRequired)
	safe_ret_as(::QueryActCtxW(dwFlags, hActCtx,  pvSubInstance, ulInfoClass,  pvBuffer, cbBuffer, pcbWrittenOrRequired));
// WTSGetActiveConsoleSessionId
// GetActiveProcessorGroupCount
// GetMaximumProcessorGroupCount
// GetActiveProcessorCount
// GetMaximumProcessorCount
// GetNumaProcessorNode
// GetNumaNodeNumberFromHandle
// GetNumaProcessorNodeEx
// GetNumaNodeProcessorMask
// GetNumaAvailableMemoryNode
// GetNumaAvailableMemoryNodeEx
// GetNumaProximityNode
// RegisterApplicationRecoveryCallback
// UnregisterApplicationRecoveryCallback
// RegisterApplicationRestart
// UnregisterApplicationRestart
// GetApplicationRecoveryCallback
// GetApplicationRestartSettings
// ApplicationRecoveryInProgress
// ApplicationRecoveryFinished
// GetFileInformationByHandleEx
// GetFileInformationByName
// OpenFileById
wapi_ret_WAO(CreateSymbolicLink, true);
// QueryActCtxSettings
inline void QueryActCtxSettings(DWORD dwFlags, HANDLE hActCtx,PCWSTR settingsNameSpace, PCWSTR settingName,PWSTR pvBuffer, SIZE_T dwBuffer, SIZE_T *pdwWrittenOrRequired)
	safe_ret_as(::QueryActCtxSettingsW(dwFlags, hActCtx,  settingsNameSpace, settingName,  pvBuffer, dwBuffer, pdwWrittenOrRequired));
wapi_ret_WAO(CreateSymbolicLinkTransacted, true);
// AddSecureMemoryCacheCallback
// RemoveSecureMemoryCacheCallback
// CopyContext
// InitializeContext
// InitializeContext2
// GetEnabledXStateFeatures
// GetXStateFeaturesMask
// LocateXStateFeature
// SetXStateFeaturesMask
// GetThreadEnabledXStateFeatures
// EnableProcessOptionalXStateFeatures
// EnableThreadProfiling
// DisableThreadProfiling
// QueryThreadProfiling
// ReadThreadProfilingData
// DestroyThreadpoolEnvironment
// InitializeThreadpoolEnvironment
// InterlockedExchangeSubtract
// SetThreadpoolCallbackCleanupGroup
// SetThreadpoolCallbackLibrary
// SetThreadpoolCallbackPersistent
// SetThreadpoolCallbackPool
// SetThreadpoolCallbackPriority
// SetThreadpoolCallbackRunsLong
#pragma endregion

#pragma region WinUser.h
// wvsprintf - Deprecated
// wsprintf - Deprecated
wapi_ret_WAO(LoadKeyboardLayout, notnull);
wapi_ret(ActivateKeyboardLayout, notnull);
wapi_ret(ToUnicodeEx, direct);
wapi_ret(UnloadKeyboardLayout, true);
wapi_ret_WAO(GetKeyboardLayoutName, true);
// GetKeyboardLayoutList
inline int GetKeyboardLayoutList(int nBuff, HKL FAR *lpList)
	safe_ret_as(auto h = ::GetKeyboardLayoutList(nBuff, lpList), h);
wapi_ret(GetKeyboardLayout, direct);
// GetMouseMovePointsEx
inline int GetMouseMovePointsEx(UINT cbSize, LPMOUSEMOVEPOINT lppt, LPMOUSEMOVEPOINT lpptBuf, int nBufPoints, DWORD resolution)
	safe_ret_as(auto h = ::GetMouseMovePointsEx(cbSize, lppt, lpptBuf, nBufPoints, resolution), h);
wapi_ret_WAO(CreateDesktop, notnull);
wapi_ret_WAO(CreateDesktopEx, notnull);
wapi_ret_WAO(OpenDesktop, notnull);
wapi_ret(OpenInputDesktop, notnull);
wapi_ret_WAO(EnumDesktops, true);
wapi_ret(EnumDesktopWindows, true);
wapi_ret(SwitchDesktop, true);
wapi_ret(SetThreadDesktop, true);
wapi_ret(CloseDesktop, true);
wapi_ret(GetThreadDesktop, notnull);
wapi_ret_WAO(CreateWindowStation, notnull);
wapi_ret_WAO(OpenWindowStation, notnull);
wapi_ret_WAO(EnumWindowStations, true);
wapi_ret(CloseWindowStation, true);
wapi_ret(SetProcessWindowStation, true);
wapi_ret(GetProcessWindowStation, notnull);
wapi_ret(SetUserObjectSecurity, true);
wapi_ret(GetUserObjectSecurity, true);
wapi_ret_WAT(GetUserObjectInformation, true);
wapi_ret_WAT(SetUserObjectInformation, true);
wapi_ret(IsHungAppWindow, direct);
wapi_ret(DisableProcessWindowsGhosting, direct);
wapi_ret_WAO(RegisterWindowMessage, positive);
wapi_ret(TrackMouseEvent, true);
wapi_ret(DrawFrameControl, true);
wapi_ret(DrawCaption, true);
wapi_ret(DrawAnimatedRects, true);
// GetMessage
template<bool IsUnicode = Native::IsUnicode>
inline bool GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) {
	if constexpr (IsUnicode)
		 safe_ret_as(auto h = ::GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax); h >= 0, h)
	else safe_ret_as(auto h = ::GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax); h >= 0, h)
}
// TranslateMessage
inline bool TranslateMessage(CONST MSG *lpMsg)
	ret_as(::TranslateMessage(lpMsg));
wapi_ret_WAT(DispatchMessage, direct);
// SetMessageQueue
// PeekMessage
template<bool IsUnicode = Native::IsUnicode>
inline bool PeekMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) {
	if constexpr (IsUnicode)
		 ret_as(::PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg))
	else ret_as(::PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg))
}
wapi_ret(RegisterHotKey, true);
wapi_ret(UnregisterHotKey, true);
wapi_ret(ExitWindowsEx, true);
wapi_ret(SwapMouseButton, direct);
wapi_ret(GetMessagePos, direct);
wapi_ret(GetMessageTime, direct);
wapi_ret(GetMessageExtraInfo, direct);
wapi_ret(GetUnpredictedMessagePos, direct);
wapi_ret(IsWow64Message, direct);
wapi_ret(SetMessageExtraInfo, direct);
// SendMessage
template<bool IsUnicode = Native::IsUnicode>
inline LRESULT SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::SendMessageW(hWnd, Msg, wParam, lParam), h)
	else ret_safe_to(auto h = ::SendMessageA(hWnd, Msg, wParam, lParam), h)
}
// SendMessageTimeout
template<bool IsUnicode = Native::IsUnicode>
inline LRESULT SendMessageTimeout(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult), h)
	else ret_safe_to(auto h = ::SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult), h)
}
wapi_ret_WAT(SendNotifyMessage, true);
wapi_ret_WAT(SendMessageCallback, true);
// BroadcastSystemMessageEx
template<bool IsUnicode = Native::IsUnicode>
inline long BroadcastSystemMessageEx(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo) {
	if constexpr (IsUnicode)
		 safe_ret_as(auto h = ::BroadcastSystemMessageExW(flags, lpInfo, Msg, wParam, lParam, pbsmInfo), h)
	else safe_ret_as(auto h = ::BroadcastSystemMessageExA(flags, lpInfo, Msg, wParam, lParam, pbsmInfo), h)
}
// BroadcastSystemMessage
template<bool IsUnicode = Native::IsUnicode>
inline long BroadcastSystemMessage(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
	if constexpr (IsUnicode)
		 safe_ret_as(auto h = ::BroadcastSystemMessageW(flags, lpInfo, Msg, wParam, lParam), h)
	else safe_ret_as(auto h = ::BroadcastSystemMessageA(flags, lpInfo, Msg, wParam, lParam), h)
}
wapi_ret_WAT(RegisterDeviceNotification, notnull);
wapi_ret(UnregisterDeviceNotification, true);
wapi_ret(RegisterPowerSettingNotification, notnull);
wapi_ret(UnregisterPowerSettingNotification, true);
wapi_ret(RegisterSuspendResumeNotification, notnull);
wapi_ret(UnregisterSuspendResumeNotification, true);
wapi_ret_WAT(PostMessage, true);
wapi_ret_WAT(PostThreadMessage, true);
wapi_ret(AttachThreadInput, true);
wapi_ret(ReplyMessage, direct);
wapi_ret(WaitMessage, true);
wapi_ret(WaitForInputIdle, positive);
wapi_ret_WAT(DefWindowProc, direct);
wapi_ret(PostQuitMessage, direct);
wapi_ret_WAT(CallWindowProc, direct);
wapi_ret(InSendMessage, direct);
wapi_ret(InSendMessageEx, direct);
wapi_ret(GetDoubleClickTime, direct);
wapi_ret(SetDoubleClickTime, true);
wapi_ret_WAO(RegisterClass, positive);
wapi_ret_WAO(UnregisterClass, true);
wapi_ret_WAO(GetClassInfo, true);
wapi_ret_WAO(RegisterClassEx, positive);
wapi_ret_WAO(GetClassInfoEx, true);
wapi_ret_WAO(CreateWindowEx, notnull);
wapi_ret(IsWindow, direct);
wapi_ret(IsMenu, direct);
wapi_ret(IsChild, direct);
wapi_ret(DestroyWindow, true);
wapi_ret(ShowWindow, direct);
wapi_ret(AnimateWindow, true);
wapi_ret(UpdateLayeredWindow, true);
wapi_ret(UpdateLayeredWindowIndirect, true);
wapi_ret(GetLayeredWindowAttributes, true);
wapi_ret(PrintWindow, direct);
wapi_ret(SetLayeredWindowAttributes, true);
wapi_ret(ShowWindowAsync, direct);
wapi_ret(FlashWindow, direct);
wapi_ret(FlashWindowEx, direct);
wapi_ret(ShowOwnedPopups, true);
wapi_ret(OpenIcon, true);
wapi_ret(CloseWindow, true);
wapi_ret(MoveWindow, true);
wapi_ret(SetWindowPos, true);
wapi_ret(GetWindowPlacement, true);
wapi_ret(SetWindowPlacement, true);
wapi_ret(GetWindowDisplayAffinity, true);
wapi_ret(SetWindowDisplayAffinity, true);
wapi_ret(BeginDeferWindowPos, notnull);
wapi_ret(DeferWindowPos, notnull);
wapi_ret(EndDeferWindowPos, true);
wapi_ret(IsWindowVisible, direct);
wapi_ret(IsIconic, direct);
wapi_ret(AnyPopup, direct);
wapi_ret(BringWindowToTop, true);
wapi_ret(IsZoomed, direct);
wapi_ret_WAO(CreateDialogParam, notnull);
wapi_ret_WAT(CreateDialogIndirectParam, notnull);
#undef DialogBoxParam
inline INT_PTR DialogBoxParam(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
	ret_safe_to(auto h = ::DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam), h);
inline INT_PTR DialogBoxParam(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
	ret_safe_to(auto h = ::DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam), h);
#undef DialogBoxIndirectParam
template<bool IsUnicode = Native::IsUnicode>
inline INT_PTR DialogBoxIndirectParam(HINSTANCE hInstance, LPCDLGTEMPLATE hDialogTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam), h)
	else ret_safe_to(auto h = ::DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam), h)
}
wapi_ret(EndDialog, true);
wapi_ret(GetDlgItem, notnull);
wapi_ret(SetDlgItemInt, true);
// GetDlgItemInt
inline UINT GetDlgItemInt(HWND hDlg, int nIDDlgItem, BOOL *lpTranslated, BOOL bSigned)
	safe_ret_as(auto h = ::GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned); h != !*lpTranslated, h);
wapi_ret_WAO(SetDlgItemText, true);
wapi_ret_WAO(GetDlgItemText, positive);
wapi_ret(CheckDlgButton, true);
wapi_ret(CheckRadioButton, true);
wapi_ret(IsDlgButtonChecked, direct);
// SendDlgItemMessage
template<bool IsUnicode = Native::IsUnicode>
inline LRESULT SendDlgItemMessage(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam), h)
	else ret_safe_to(auto h = ::SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam), h)
}
wapi_ret(GetNextDlgGroupItem, notnull);
wapi_ret(GetNextDlgTabItem, notnull);
// GetDlgCtrlID
inline int GetDlgCtrlID(HWND hWnd)
	safe_ret_as(auto h = ::GetDlgCtrlID(hWnd), h);
wapi_ret(GetDialogBaseUnits, direct);
wapi_ret_WAT(DefDlgProc, direct);
wapi_ret(SetDialogControlDpiChangeBehavior, true);
// GetDialogControlDpiChangeBehavior
inline DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS GetDialogControlDpiChangeBehavior(HWND hWnd)
	safe_ret_as(auto h = ::GetDialogControlDpiChangeBehavior(hWnd), h);
wapi_ret(SetDialogDpiChangeBehavior, true);
// GetDialogDpiChangeBehavior
inline DIALOG_DPI_CHANGE_BEHAVIORS GetDialogDpiChangeBehavior(HWND hDlg)
	safe_ret_as(auto h = ::GetDialogDpiChangeBehavior(hDlg), h);
wapi_ret_WAT(CallMsgFilter, direct);
wapi_ret(OpenClipboard, true);
wapi_ret(CloseClipboard, true);
wapi_ret(GetClipboardSequenceNumber, direct);
wapi_ret(GetClipboardOwner, notnull);
wapi_ret(SetClipboardViewer, notnull);
wapi_ret(GetClipboardViewer, notnull);
wapi_ret(ChangeClipboardChain, direct);
wapi_ret(SetClipboardData, notnull);
wapi_ret(GetClipboardData, notnull);
// GetClipboardMetadata
wapi_ret_WAO(RegisterClipboardFormat, direct);
// CountClipboardFormats
inline int CountClipboardFormats()
	safe_ret_as(auto h = ::CountClipboardFormats(), h);
wapi_ret(EnumClipboardFormats, positive);
// GetClipboardFormatName
inline int GetClipboardFormatName(UINT format, LPSTR lpszFormatName, int cchMaxCount)
	safe_ret_as(auto h = ::GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount), h);
inline int GetClipboardFormatName(UINT format, LPWSTR lpszFormatName, int cchMaxCount)
	safe_ret_as(auto h = ::GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount), h);
wapi_ret(EmptyClipboard, true);
wapi_ret(IsClipboardFormatAvailable, direct);
// GetPriorityClipboardFormat
inline int GetPriorityClipboardFormat(UINT *paFormatPriorityList, int cFormats)
	safe_ret_as(auto h = ::GetPriorityClipboardFormat(paFormatPriorityList, cFormats), h);
inline HWND GetOpenClipboardWindow()
	safe_ret_as(auto h = ::GetOpenClipboardWindow(), h);
wapi_ret(AddClipboardFormatListener, true);
wapi_ret(RemoveClipboardFormatListener, true);
wapi_ret(GetUpdatedClipboardFormats, true);
// CharToOem - Deprecated
// OemToChar - Deprecated
// CharToOemBuff - Deprecated
// OemToCharBuff - Deprecated
// CharUpper - Deprecated
// CharUpperBuff - Deprecated
// CharLower - Deprecated
// CharLowerBuff - Deprecated
// CharNext - Deprecated
// CharPrev - Deprecated
// CharNextExA
// CharPrevExA
// IsCharAlpha - Deprecated
// IsCharAlphaNumeric - Deprecated
// IsCharUpper - Deprecated
// IsCharLower - Deprecated
wapi_ret(SetFocus, notnull);
wapi_ret(GetActiveWindow, direct);
wapi_ret(GetFocus, direct);
wapi_ret(GetKBCodePage, direct);
wapi_ret(GetKeyState, direct);
wapi_ret(GetAsyncKeyState, direct);
wapi_ret(GetKeyboardState, true);
wapi_ret(SetKeyboardState, true);
// GetKeyNameText
inline int GetKeyNameText(LONG lParam, LPSTR lpString, int cchSize)
	safe_ret_as(auto h = ::GetKeyNameTextA(lParam, lpString, cchSize), h);
inline int GetKeyNameText(LONG lParam, LPWSTR lpString, int cchSize)
	safe_ret_as(auto h = ::GetKeyNameTextW(lParam, lpString, cchSize), h);
// GetKeyboardType
inline int GetKeyboardType(int nTypeFlag)
	ret_safe_to(auto h = ::GetKeyboardType(nTypeFlag), h);
wapi_ret(ToAscii, direct);
wapi_ret(ToAsciiEx, direct);
wapi_ret(ToUnicode, direct);
wapi_ret(OemKeyScan, direct);
// VkKeyScan
inline SHORT VkKeyScan(CHAR ch)
	ret_as(::VkKeyScanA(ch));
inline SHORT VkKeyScan(WCHAR ch)
	ret_as(::VkKeyScanW(ch));
// VkKeyScanEx
inline SHORT VkKeyScanEx(CHAR ch, HKL dwhkl)
	ret_as(::VkKeyScanExA(ch, dwhkl));
inline SHORT VkKeyScanEx(WCHAR ch, HKL dwhkl)
	ret_as(::VkKeyScanExW(ch, dwhkl));
// keybd_event
// mouse_event
wapi_ret(SendInput, positive);
wapi_ret(GetTouchInputInfo, true);
wapi_ret(CloseTouchInputHandle, true);
wapi_ret(RegisterTouchWindow, true);
wapi_ret(UnregisterTouchWindow, true);
wapi_ret(IsTouchWindow, direct);
wapi_ret(InitializeTouchInjection, true);
wapi_ret(InjectTouchInput, true);
wapi_ret(GetPointerType, true);
wapi_ret(GetPointerCursorId, true);
wapi_ret(GetPointerInfo, true);
wapi_ret(GetPointerInfoHistory, true);
wapi_ret(GetPointerFrameInfo, true);
wapi_ret(GetPointerFrameInfoHistory, true);
wapi_ret(GetPointerTouchInfo, true);
wapi_ret(GetPointerTouchInfoHistory, true);
wapi_ret(GetPointerFrameTouchInfo, true);
wapi_ret(GetPointerFrameTouchInfoHistory, true);
wapi_ret(GetPointerPenInfo, true);
wapi_ret(GetPointerPenInfoHistory, true);
wapi_ret(GetPointerFramePenInfo, true);
wapi_ret(GetPointerFramePenInfoHistory, true);
wapi_ret(SkipPointerFrameMessages, true);
wapi_ret(RegisterPointerInputTarget, true);
wapi_ret(UnregisterPointerInputTarget, true);
// RegisterPointerInputTargetEx
// UnregisterPointerInputTargetEx
#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
wapi_ret(CreateSyntheticPointerDevice, notnull);
wapi_ret(InjectSyntheticPointerInput, true);
wapi_ret(DestroySyntheticPointerDevice, direct);
#endif
wapi_ret(EnableMouseInPointer, true);
wapi_ret(IsMouseInPointerEnabled, direct);
// EnableMouseInPointerForThread
wapi_ret(RegisterTouchHitTestingWindow, true);
wapi_ret(EvaluateProximityToRect, true);
wapi_ret(EvaluateProximityToPolygon, true);
// PackTouchHitTestingProximityEvaluation
inline LRESULT PackTouchHitTestingProximityEvaluation(const TOUCH_HIT_TESTING_INPUT *pHitTestingInput, const TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *pProximityEval)
	ret_safe_to(auto h = ::PackTouchHitTestingProximityEvaluation(pHitTestingInput, pProximityEval), h);
wapi_ret(GetWindowFeedbackSetting, true);
wapi_ret(SetWindowFeedbackSetting, true);
// GetPointerInputTransform - Deprecated
//inline void GetPointerInputTransform(UINT32 pointerId, UINT32 historyCount, INPUT_TRANSFORM *inputTransform)
//	safe_ret_as(::GetPointerInputTransform(pointerId, historyCount, inputTransform));
wapi_ret(GetLastInputInfo, true);
wapi_ret_WAT(MapVirtualKey, direct);
wapi_ret_WAT(MapVirtualKeyEx, direct);
wapi_ret(GetInputState, direct);
wapi_ret(GetQueueStatus, direct);
wapi_ret(GetCapture, direct);
wapi_ret(SetCapture, direct);
wapi_ret(ReleaseCapture, true);
// MsgWaitForMultipleObjects
inline DWORD MsgWaitForMultipleObjects(DWORD nCount, CONST HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask)
	safe_ret_as(auto h = ::MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask), h);
// MsgWaitForMultipleObjectsEx
inline DWORD MsgWaitForMultipleObjectsEx(DWORD nCount, CONST HANDLE *pHandles, DWORD dwMilliseconds, DWORD dwWakeMask, DWORD dwFlags)
	safe_ret_as(auto h = ::MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags), h);
// SetTimer
inline UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc)
	safe_ret_as(auto h = ::SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc), h);
// SetCoalescableTimer
inline UINT_PTR SetCoalescableTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc, ULONG uToleranceDelay)
	safe_ret_as(auto h = ::SetCoalescableTimer(hWnd, nIDEvent, uElapse, lpTimerFunc, uToleranceDelay), h);
wapi_ret(KillTimer, true);
wapi_ret(IsWindowUnicode, direct);
wapi_ret(EnableWindow, direct);
wapi_ret(IsWindowEnabled, direct);
wapi_ret_WAO(LoadAccelerators, notnull);
wapi_ret_WAT(CreateAcceleratorTable, notnull);
wapi_ret(DestroyAcceleratorTable, true);
wapi_ret_WAT(CopyAcceleratorTable, direct);
// TranslateAccelerator
template<bool IsUnicode = Native::IsUnicode>
inline int TranslateAccelerator(HWND hWnd, HACCEL hAccTable, LPMSG lpMsg) {
	if constexpr (IsUnicode)
		 safe_ret_as(auto h = ::TranslateAcceleratorW(hWnd, hAccTable, lpMsg), h)
	else safe_ret_as(auto h = ::TranslateAcceleratorA(hWnd, hAccTable, lpMsg), h)
}
// GetSystemMetrics
inline int GetSystemMetrics(int nIndex)
	safe_ret_as(auto h = ::GetSystemMetrics(nIndex), h);
// GetSystemMetricsForDpi
inline int GetSystemMetricsForDpi(int nIndex, UINT dpi)
	safe_ret_as(auto h = ::GetSystemMetricsForDpi(nIndex, dpi), h);
wapi_ret_WAO(LoadMenu, notnull);
wapi_ret_WAT(LoadMenuIndirect, notnull);
wapi_ret(GetMenu, direct);
wapi_ret(SetMenu, true);
// ChangeMenu - Undocumented
wapi_ret(HiliteMenuItem, direct);
// GetMenuString
inline int GetMenuString(HMENU hMenu, UINT uIDItem, LPSTR lpString, int cchMax, UINT flags)
	safe_ret_as(auto h = ::GetMenuStringA(hMenu, uIDItem, lpString, cchMax, flags), h);
inline int GetMenuString(HMENU hMenu, UINT uIDItem, LPWSTR lpString, int cchMax, UINT flags)
	safe_ret_as(auto h = ::GetMenuStringW(hMenu, uIDItem, lpString, cchMax, flags), h);
wapi_ret(GetMenuState, direct);
wapi_ret(DrawMenuBar, true);
wapi_ret(GetSystemMenu, direct);
wapi_ret(CreateMenu, notnull);
wapi_ret(CreatePopupMenu, notnull);
wapi_ret(DestroyMenu, true);
// CheckMenuItem
inline DWORD CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck)
	safe_ret_as(auto h = ::CheckMenuItem(hMenu, uIDCheckItem, uCheck), h);
wapi_ret(EnableMenuItem, true);
wapi_ret(GetSubMenu, direct);
wapi_ret(GetMenuItemID, direct);
// GetMenuItemCount
inline int GetMenuItemCount(HMENU hMenu)
	safe_ret_as(auto h = ::GetMenuItemCount(hMenu), h);
wapi_ret_WAO(InsertMenu, true);
wapi_ret_WAO(AppendMenu, true);
wapi_ret_WAO(ModifyMenu, true);
wapi_ret(RemoveMenu, true);
wapi_ret(DeleteMenu, true);
wapi_ret(SetMenuItemBitmaps, true);
wapi_ret(GetMenuCheckMarkDimensions, direct);
wapi_ret(TrackPopupMenu, true);
wapi_ret(TrackPopupMenuEx, true);
wapi_ret(CalculatePopupWindowPosition, true);
wapi_ret(GetMenuInfo, true);
wapi_ret(SetMenuInfo, true);
wapi_ret(EndMenu, true);
wapi_ret_WAO(InsertMenuItem, true);
wapi_ret_WAO(GetMenuItemInfo, true);
wapi_ret_WAO(SetMenuItemInfo, true);
// GetMenuDefaultItem
inline UINT GetMenuDefaultItem(HMENU hMenu, UINT fByPos, UINT gmdiFlags)
	safe_ret_as(auto h = ::GetMenuDefaultItem(hMenu, fByPos, gmdiFlags); h != -1, h);
wapi_ret(SetMenuDefaultItem, true);
wapi_ret(GetMenuItemRect, true);
wapi_ret(MenuItemFromPoint, direct);
// DragObject
wapi_ret(DragDetect, direct);
wapi_ret(UpdateWindow, true);
inline HWND SetActiveWindow(HWND hWnd)
	safe_ret_as(auto h = ::SetActiveWindow(hWnd), h);
wapi_ret(GetForegroundWindow, direct);
inline void SwitchToThisWindow(HWND hwnd, BOOL fUnknown)
	ret_as(::SwitchToThisWindow(hwnd, fUnknown));
wapi_ret(SetForegroundWindow, true);
wapi_ret(AllowSetForegroundWindow, true);
wapi_ret(LockSetForegroundWindow, true);
wapi_ret(GetDC, notnull);
wapi_ret(GetDCEx, notnull);
wapi_ret(GetWindowDC, notnull);
// ReleaseDC
inline int ReleaseDC(HWND hWnd, HDC hDC)
	safe_ret_as(auto h = ::ReleaseDC(hWnd, hDC), h);
wapi_ret(BeginPaint, notnull);
wapi_ret(EndPaint, true);
wapi_ret(GetUpdateRect, direct);
// GetUpdateRgn
inline int GetUpdateRgn(HWND hWnd, HRGN hRgn, BOOL bErase)
	safe_ret_as(auto h = ::GetUpdateRgn(hWnd, hRgn, bErase), h);
// SetWindowRgn
inline int SetWindowRgn(HWND hWnd, HRGN hRgn, BOOL bRedraw)
	safe_ret_as(auto h = ::SetWindowRgn(hWnd, hRgn, bRedraw), h);
// GetWindowRgn
inline int GetWindowRgn(HWND hWnd, HRGN hRgn)
	safe_ret_as(auto h = ::GetWindowRgn(hWnd, hRgn), h);
// GetWindowRgnBox
inline int GetWindowRgnBox(HWND hWnd, LPRECT lprc)
	safe_ret_as(auto h = ::GetWindowRgnBox(hWnd, lprc), h);
wapi_ret(InvalidateRect, true);
wapi_ret(ValidateRect, true);
wapi_ret(InvalidateRgn, true);
wapi_ret(ValidateRgn, true);
wapi_ret(RedrawWindow, true);
wapi_ret(LockWindowUpdate, true);
wapi_ret(ScrollWindow, true);
// ScrollWindowEx
inline int ScrollWindowEx(HWND hWnd, int dx, int dy, CONST RECT *prcScroll, CONST RECT *prcClip, HRGN hrgnUpdate, LPRECT prcUpdate, UINT flags)
	safe_ret_as(auto h = ::ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags), h);
// SetScrollPos
inline int SetScrollPos(HWND hWnd, int nBar, int nPos, BOOL bRedraw)
	safe_ret_as(auto h = ::SetScrollPos(hWnd, nBar, nPos, bRedraw), h);
// GetScrollPos
inline int GetScrollPos(HWND hWnd, int nBar)
	safe_ret_as(auto h = ::GetScrollPos(hWnd, nBar), h);
wapi_ret(SetScrollRange, true);
wapi_ret(GetScrollRange, true);
wapi_ret(ShowScrollBar, true);
wapi_ret(EnableScrollBar, true);
wapi_ret_WAO(SetProp, true);
wapi_ret_WAO(GetProp, direct);
// RemoveProp
inline HANDLE RemoveProp(HWND hWnd, LPCSTR lpString)
	ret_safe_to(auto h = ::RemovePropA(hWnd, lpString), h);
inline HANDLE RemoveProp(HWND hWnd, LPCWSTR lpString)
	ret_safe_to(auto h = ::RemovePropW(hWnd, lpString), h);
// EnumPropsEx
inline int EnumPropsEx(HWND hWnd, PROPENUMPROCEXA lpEnumFunc, LPARAM lParam)
	safe_ret_as(auto h = ::EnumPropsExA(hWnd, lpEnumFunc, lParam), h);
inline int EnumPropsEx(HWND hWnd, PROPENUMPROCEXW lpEnumFunc, LPARAM lParam)
	safe_ret_as(auto h = ::EnumPropsExW(hWnd, lpEnumFunc, lParam), h);
// EnumProps
inline int EnumProps(HWND hWnd, PROPENUMPROCA lpEnumFunc)
	safe_ret_as(auto h = ::EnumPropsA(hWnd, lpEnumFunc), h);
inline int EnumProps(HWND hWnd, PROPENUMPROCW lpEnumFunc)
	safe_ret_as(auto h = ::EnumPropsW(hWnd, lpEnumFunc), h);
wapi_ret_WAO(SetWindowText, true);
// GetWindowText
inline int GetWindowText(HWND hWnd, LPSTR lpString, int nMaxCount)
	ret_safe_to(auto h = ::GetWindowTextA(hWnd, lpString, nMaxCount), h);
inline int GetWindowText(HWND hWnd, LPWSTR lpString, int nMaxCount)
	ret_safe_to(auto h = ::GetWindowTextW(hWnd, lpString, nMaxCount), h);
// GetWindowTextLength
template<bool IsUnicode = Native::IsUnicode>
inline int GetWindowTextLength(HWND hWnd) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::GetWindowTextLengthW(hWnd), h)
	else ret_safe_to(auto h = ::GetWindowTextLengthA(hWnd), h)
}
wapi_ret(GetClientRect, true);
wapi_ret(GetWindowRect, true);
wapi_ret(AdjustWindowRect, true);
wapi_ret(AdjustWindowRectEx, true);
wapi_ret(AdjustWindowRectExForDpi, true);
wapi_ret(SetWindowContextHelpId, true);
wapi_ret(GetWindowContextHelpId, direct);
wapi_ret(SetMenuContextHelpId, true);
wapi_ret(GetMenuContextHelpId, direct);
wapi_ret_WAO(MessageBox, notzero);
wapi_ret_WAO(MessageBoxEx, notzero);
wapi_ret_WAO(MessageBoxIndirect, notzero);
wapi_ret(MessageBeep, true);
wapi_ret(ShowCursor, direct);
wapi_ret(SetCursorPos, true);
wapi_ret(SetPhysicalCursorPos, true);
wapi_ret(SetCursor, direct);
wapi_ret(GetCursorPos, true);
wapi_ret(GetPhysicalCursorPos, true);
wapi_ret(GetClipCursor, true);
wapi_ret(GetCursor, direct);
wapi_ret(CreateCaret, true);
// GetCaretBlinkTime
inline UINT GetCaretBlinkTime()
	safe_ret_as(auto h = ::GetCaretBlinkTime(), h);
wapi_ret(SetCaretBlinkTime, true);
wapi_ret(DestroyCaret, true);
wapi_ret(HideCaret, true);
wapi_ret(ShowCaret, true);
wapi_ret(SetCaretPos, true);
wapi_ret(GetCaretPos, true);
wapi_ret(ClientToScreen, true);
wapi_ret(ScreenToClient, true);
wapi_ret(LogicalToPhysicalPoint, true);
wapi_ret(PhysicalToLogicalPoint, true);
wapi_ret(LogicalToPhysicalPointForPerMonitorDPI, true);
wapi_ret(PhysicalToLogicalPointForPerMonitorDPI, true);
// MapWindowPoints
inline int MapWindowPoints(HWND hWndFrom, HWND hWndTo, LPPOINT lpPoints, UINT cPoints)
	ret_safe_to(auto h = ::MapWindowPoints(hWndFrom, hWndTo, lpPoints, cPoints), h);
wapi_ret(WindowFromPoint, direct);
wapi_ret(WindowFromPhysicalPoint, direct);
wapi_ret(ChildWindowFromPoint, direct);
wapi_ret(ClipCursor, true);
wapi_ret(ChildWindowFromPointEx, direct);
wapi_ret(GetSysColor, direct);
wapi_ret(GetSysColorBrush, direct);
wapi_ret(SetSysColors, true);
// SetRect
// SetRectEmpty
// CopyRect
// InflateRect
// IntersectRect
// UnionRect
// SubtractRect
// OffsetRect
// IsRectEmpty
// EqualRect
// PtInRect
// GetWindowWord
inline WORD GetWindowWord(HWND hWnd, int nIndex)
	ret_safe_to(auto h = ::GetWindowWord(hWnd, nIndex), h);
// SetWindowWord
inline WORD SetWindowWord(HWND hWnd, int nIndex, WORD wNewWord)
	ret_safe_to(auto h = ::SetWindowWord(hWnd, nIndex, wNewWord), h);
// GetWindowLong - Deprecated
// SetWindowLong - Deprecated
// GetWindowLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline LONG_PTR GetWindowLongPtr(HWND hWnd, int nIndex) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::GetWindowLongPtrW(hWnd, nIndex), h)
	else ret_safe_to(auto h = ::GetWindowLongPtrA(hWnd, nIndex), h)
}
// SetWindowLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline LONG_PTR SetWindowLongPtr(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::SetWindowLongPtrW(hWnd, nIndex, dwNewLong), h)
	else ret_safe_to(auto h = ::SetWindowLongPtrA(hWnd, nIndex, dwNewLong), h)
}
// GetClassWord
inline WORD GetClassWord(HWND hWnd, int nIndex)
	ret_safe_to(auto h = ::GetClassWord(hWnd, nIndex), h);
// SetClassWord
inline WORD SetClassWord(HWND hWnd, int nIndex, WORD wNewWord)
	ret_safe_to(auto h = ::SetClassWord(hWnd, nIndex, wNewWord), h);
// GetClassLong - Deprecated
// SetClassLong - Deprecated
// GetClassLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline ULONG_PTR GetClassLongPtr(HWND hWnd, int nIndex) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::GetClassLongPtrW(hWnd, nIndex), h)
	else ret_safe_to(auto h = ::GetClassLongPtrA(hWnd, nIndex), h)
}
// SetClassLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline ULONG_PTR SetClassLongPtr(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
	if constexpr (IsUnicode)
		 ret_safe_to(auto h = ::SetClassLongPtrW(hWnd, nIndex, dwNewLong), h)
	else ret_safe_to(auto h = ::SetClassLongPtrA(hWnd, nIndex, dwNewLong), h)
}
wapi_ret(GetProcessDefaultLayout, true);
wapi_ret(SetProcessDefaultLayout, true);
wapi_ret(GetDesktopWindow, direct);
// GetParent
inline HWND GetParent(HWND hWnd)
	ret_safe_to(auto h = ::GetParent(hWnd), h);
// SetParent
inline HWND SetParent(HWND hWndChild, HWND hWndNewParent)
	ret_safe_to(auto h = ::SetParent(hWndChild, hWndNewParent), h);
wapi_ret(EnumChildWindows, direct);
wapi_ret_WAO(FindWindow, direct);
wapi_ret_WAO(FindWindowEx, notnull);
wapi_ret(GetShellWindow, direct);
wapi_ret(RegisterShellHookWindow, true);
wapi_ret(DeregisterShellHookWindow, true);
wapi_ret(EnumWindows, true);
wapi_ret(EnumThreadWindows, direct);
// GetClassName
inline int GetClassName(HWND hWnd, LPSTR lpClassName, int nMaxCount)
	safe_ret_as(auto h = ::GetClassNameA(hWnd, lpClassName, nMaxCount), h);
inline int GetClassName(HWND hWnd, LPWSTR lpClassName, int nMaxCount)
	safe_ret_as(auto h = ::GetClassNameW(hWnd, lpClassName, nMaxCount), h);
inline HWND GetTopWindow(HWND hWnd)
	ret_safe_to(auto h = ::GetTopWindow(hWnd), h);
wapi_ret(IsGUIThread, direct);
wapi_ret(GetLastActivePopup, direct);
inline HWND GetWindow(HWND hWnd, UINT uCmd)
	ret_safe_to(auto h = ::GetWindow(hWnd, uCmd), h);
// SetWindowsHook - Undocumented
// UnhookWindowsHook
wapi_ret_WAT(SetWindowsHookEx, notnull);
wapi_ret(UnhookWindowsHookEx, true);
wapi_ret(CallNextHookEx, direct);
wapi_ret(CheckMenuRadioItem, true);
wapi_ret_WAO(LoadBitmap, notnull);
wapi_ret_WAO(LoadCursor, notnull);
wapi_ret_WAO(LoadCursorFromFile, notnull);
wapi_ret(CreateCursor, notnull);
wapi_ret(DestroyCursor, true);
wapi_ret(SetSystemCursor, true);
wapi_ret_WAO(LoadIcon, notnull);
// PrivateExtractIcons
inline UINT PrivateExtractIcons(LPCSTR szFileName, int nIconIndex, int cxIcon, int cyIcon, HICON *phicon, UINT *piconid, UINT nIcons, UINT flags)
	safe_ret_as(auto h = ::PrivateExtractIconsA(szFileName, nIconIndex, cxIcon, cyIcon, phicon, piconid, nIcons, flags); h != -1, h);
inline UINT PrivateExtractIcons(LPCWSTR szFileName, int nIconIndex, int cxIcon, int cyIcon, HICON *phicon, UINT *piconid, UINT nIcons, UINT flags)
	safe_ret_as(auto h = ::PrivateExtractIconsW(szFileName, nIconIndex, cxIcon, cyIcon, phicon, piconid, nIcons, flags); h != -1, h);
wapi_ret(CreateIcon, notnull);
wapi_ret(DestroyIcon, true);
// LookupIconIdFromDirectory
inline int LookupIconIdFromDirectory(PBYTE presbits, BOOL fIcon)
	safe_ret_as(auto h = ::LookupIconIdFromDirectory(presbits, fIcon), h);
// LookupIconIdFromDirectoryEx
inline int LookupIconIdFromDirectoryEx(PBYTE presbits, BOOL fIcon, int cxDesired, int cyDesired, UINT Flags)
	safe_ret_as(auto h = ::LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags), h);
wapi_ret(CreateIconFromResource, notnull);
wapi_ret(CreateIconFromResourceEx, notnull);
#if (NTDDI_VERSION >= NTDDI_WIN10_CO) && !__GNUC__
wapi_ret(SetThreadCursorCreationScaling, direct);
#endif
wapi_ret_WAO(LoadImage, notnull);
//// CopyImage
//inline HANDLE CopyImage(HANDLE h, UINT type, int cx, int cy, UINT flags)
//	safe_ret_as(auto h = ::CopyImage(h, type, cx, cy, flags), h);
wapi_ret(CreateIconIndirect, notnull);
wapi_ret(CopyIcon, notnull);
wapi_ret(GetIconInfo, true);
wapi_ret_WAO(GetIconInfoEx, true);
wapi_ret_WAT(IsDialogMessage, direct);
wapi_ret(MapDialogRect, true);
// DlgDirList
inline int DlgDirList(HWND hDlg, LPSTR lpPathSpec, int nIDListBox, int nIDStaticPath, UINT uFileType)
	safe_ret_as(auto h = ::DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType), h);
inline int DlgDirList(HWND hDlg, LPWSTR lpPathSpec, int nIDListBox, int nIDStaticPath, UINT uFileType)
	safe_ret_as(auto h = ::DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType), h);
wapi_ret_WAO(DlgDirSelectEx, true);
// DlgDirListComboBox
inline int DlgDirListComboBox(HWND hDlg, LPSTR lpPathSpec, int nIDComboBox, int nIDStaticPath, UINT uFiletype)
	safe_ret_as(auto h = ::DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype), h);
inline int DlgDirListComboBox(HWND hDlg, LPWSTR lpPathSpec, int nIDComboBox, int nIDStaticPath, UINT uFiletype)
	safe_ret_as(auto h = ::DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype), h);
wapi_ret_WAO(DlgDirSelectComboBoxEx, true);
wapi_ret(SetScrollInfo, direct);
wapi_ret(GetScrollInfo, true);
wapi_ret_WAT(DefFrameProc, direct);
wapi_ret_WAT(DefMDIChildProc, direct);
wapi_ret(TranslateMDISysAccel, direct);
wapi_ret(ArrangeIconicWindows, positive);
wapi_ret_WAO(CreateMDIWindow, notnull);
wapi_ret(TileWindows, positive);
wapi_ret(CascadeWindows, positive);
wapi_ret_WAO(WinHelp, true);
wapi_ret(GetGuiResources, positive);
wapi_ret_WAO(ChangeDisplaySettings, direct);
wapi_ret_WAO(ChangeDisplaySettingsEx, direct);
wapi_ret_WAO(EnumDisplaySettings, true);
wapi_ret_WAO(EnumDisplaySettingsEx, true);
wapi_ret_WAO(EnumDisplayDevices, true);
wapi_ret(GetDisplayConfigBufferSizes, direct);
wapi_ret(SetDisplayConfig, direct);
wapi_ret(QueryDisplayConfig, direct);
wapi_ret(DisplayConfigGetDeviceInfo, direct);
wapi_ret(DisplayConfigSetDeviceInfo, direct);
wapi_ret_WAT(SystemParametersInfo, true);
wapi_ret(SystemParametersInfoForDpi, true);
wapi_ret(SoundSentry, true);
// SetDebugErrorLevel
// SetLastErrorEx
// InternalGetWindowText
inline int InternalGetWindowText(HWND hWnd, LPWSTR pString, int cchMaxCount)
	ret_safe_to(auto h = ::InternalGetWindowText(hWnd, pString, cchMaxCount), h);
// EndTask
// CancelShutdown
wapi_ret(MonitorFromPoint, direct);
wapi_ret(MonitorFromRect, direct);
wapi_ret(MonitorFromWindow, direct);
wapi_ret_WAT(GetMonitorInfo, true);
wapi_ret(EnumDisplayMonitors, true);
wapi_ret(NotifyWinEvent, direct);
wapi_ret(SetWinEventHook, notnull);
wapi_ret(IsWinEventHookInstalled, direct);
wapi_ret(UnhookWinEvent, true);
wapi_ret(GetGUIThreadInfo, true);
wapi_ret(BlockInput, true);
wapi_ret(SetProcessDPIAware, true);
wapi_ret(IsProcessDPIAware, direct);
wapi_ret(SetThreadDpiAwarenessContext, notzero);
wapi_ret(GetWindowDpiAwarenessContext, notzero);
wapi_ret(GetAwarenessFromDpiAwarenessContext, notzero);
wapi_ret(GetDpiFromDpiAwarenessContext, direct);
wapi_ret(AreDpiAwarenessContextsEqual, direct);
wapi_ret(IsValidDpiAwarenessContext, direct);
wapi_ret(GetDpiForWindow, positive);
wapi_ret(GetDpiForSystem, direct);
wapi_ret(GetSystemDpiForProcess, direct);
wapi_ret(EnableNonClientDpiScaling, true);
wapi_ret(InheritWindowMonitor, true);
wapi_ret(SetProcessDpiAwarenessContext, true);
#if (NTDDI_VERSION >= NTDDI_WIN10_19H1)
wapi_ret(GetDpiAwarenessContextForProcess, direct);
#endif
wapi_ret(SetThreadDpiHostingBehavior, notzero);
wapi_ret(GetThreadDpiHostingBehavior, direct);
wapi_ret(GetWindowDpiHostingBehavior, direct);
wapi_ret_WAO(GetWindowModuleFileName, positive);
wapi_ret(GetCursorInfo, true);
wapi_ret(GetWindowInfo, true);
wapi_ret(GetTitleBarInfo, true);
wapi_ret(GetMenuBarInfo, true);
wapi_ret(GetScrollBarInfo, true);
wapi_ret(GetComboBoxInfo, true);
wapi_ret(GetAncestor, direct);
wapi_ret(RealChildWindowFromPoint, direct);
wapi_ret_WAO(RealGetWindowClass, positive);
wapi_ret_WAO(GetAltTabInfo, true);
wapi_ret(GetListBoxInfo, direct);
wapi_ret(LockWorkStation, true);
wapi_ret(UserHandleGrantAccess, true);
// GetRawInputData
inline UINT GetRawInputData(HRAWINPUT hRawInput, UINT uiCommand, LPVOID pData, PUINT pcbSize, UINT cbSizeHeader)
	safe_ret_as(auto h = ::GetRawInputData(hRawInput, uiCommand, pData, pcbSize, cbSizeHeader); h != -1, h);
// GetRawInputDeviceInfo
template<bool IsUnicode = Native::IsUnicode>
inline UINT GetRawInputDeviceInfo(HANDLE hDevice, UINT uiCommand, LPVOID pData, PUINT pcbSize) {
	if constexpr (IsUnicode)
		 safe_ret_as(auto h = ::GetRawInputDeviceInfoW(hDevice, uiCommand, pData, pcbSize); h != -1, h)
	else safe_ret_as(auto h = ::GetRawInputDeviceInfoA(hDevice, uiCommand, pData, pcbSize); h != -1, h)
}
// GetRawInputBuffer
inline UINT GetRawInputBuffer(PRAWINPUT pData, PUINT pcbSize, UINT cbSizeHeader)
	safe_ret_as(auto h = ::GetRawInputBuffer(pData, pcbSize, cbSizeHeader); h != -1, h);
wapi_ret(RegisterRawInputDevices, true);
// GetRegisteredRawInputDevices
inline UINT GetRegisteredRawInputDevices(PRAWINPUTDEVICE pRawInputDevices, PUINT puiNumDevices, UINT cbSize)
	safe_ret_as(auto h = ::GetRegisteredRawInputDevices(pRawInputDevices, puiNumDevices, cbSize); h != -1, h);
// GetRawInputDeviceList
inline UINT GetRawInputDeviceList(PRAWINPUTDEVICELIST pRawInputDeviceList, PUINT puiNumDevices, UINT cbSize)
	safe_ret_as(auto h = ::GetRawInputDeviceList(pRawInputDeviceList, puiNumDevices, cbSize); h != -1, h);
// DefRawInputProc
inline LRESULT DefRawInputProc(PRAWINPUT *paRawInput, INT nInput, UINT cbSizeHeader)
safe_ret_as(auto h = ::DefRawInputProc(paRawInput, nInput, cbSizeHeader); h >= 0, h);
wapi_ret(GetPointerDevices, true);
wapi_ret(GetPointerDevice, true);
wapi_ret(GetPointerDeviceProperties, true);
wapi_ret(RegisterPointerDeviceNotifications, true);
wapi_ret(GetPointerDeviceRects, true);
wapi_ret(GetPointerDeviceCursors, true);
wapi_ret(GetRawPointerDeviceData, true);
wapi_ret(ChangeWindowMessageFilter, true);
wapi_ret(ChangeWindowMessageFilterEx, true);
wapi_ret(GetGestureInfo, true);
wapi_ret(GetGestureExtraArgs, true);
wapi_ret(CloseGestureInfoHandle, true);
wapi_ret(SetGestureConfig, true);
wapi_ret(GetGestureConfig, true);
wapi_ret(ShutdownBlockReasonCreate, true);
wapi_ret(ShutdownBlockReasonQuery, true);
wapi_ret(ShutdownBlockReasonDestroy, true);
wapi_ret(GetCurrentInputMessageSource, true);
// GetCIMSSM
wapi_ret(GetAutoRotationState, true);
wapi_ret(GetDisplayAutoRotationPreferences, true);
wapi_ret(GetDisplayAutoRotationPreferencesByProcessId, true);
wapi_ret(SetDisplayAutoRotationPreferences, true);
// IsImmersiveProcess
inline bool IsImmersiveProcess(HANDLE hProcess)
	ret_safe_to(auto h = ::IsImmersiveProcess(hProcess), h);
wapi_ret(SetProcessRestrictionExemption, true);
// ApplyWindowAction
// SetAdditionalForegroundBoostProcesses - Deprecated
// RegisterForTooltipDismissNotification - Deprecated
// IsWindowArranged - Deprecated
// GetCurrentMonitorTopologyId
// RegisterCloakedNotification
#pragma endregion

}
