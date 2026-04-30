module;

#include <Windows.h>
#include <SynchApi.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Realtime.h"

export module WandX.Realtime;

import WandX;
import WandX.Win32;
import WandX.Win32.Types;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Realtime");

export namespace WandX {
namespace Native {

#pragma region ProcessThreadsApi.h
wapi_ret(QueueUserAPC, true);
#if (NTDDI_VERSION >= NTDDI_WIN10_MN)
wapi_ret(QueueUserAPC2, true);
#endif
wapi_ret(GetProcessTimes, true);
wapi_ret(GetCurrentProcess, direct);
wapi_ret(GetCurrentProcessId, direct);
[[noreturn]] inline void ExitProcess(UINT uExitCode) {
	::ExitProcess(uExitCode);
}
wapi_ret(TerminateProcess, true);
wapi_ret(GetExitCodeProcess, true);
wapi_ret(SwitchToThread, true);
wapi_ret(CreateThread, notnull);
wapi_ret(CreateRemoteThread, notnull);
wapi_ret(GetCurrentThread, direct);
wapi_ret(GetCurrentThreadId, direct);
wapi_ret(OpenThread, notnull);
wapi_ret(SetThreadPriority, true);
wapi_ret(SetThreadPriorityBoost, true);
wapi_ret(GetThreadPriorityBoost, true);
wapi_ret(GetThreadPriority, fault, THREAD_PRIORITY_ERROR_RETURN);
[[noreturn]] inline void ExitThread(DWORD dwExitCode) {
	::ExitThread(dwExitCode);
}
wapi_ret(TerminateThread, true);
wapi_ret(GetExitCodeThread, true);
// SuspendThread
inline DWORD SuspendThread(HANDLE hThread)
safe_ret_as(auto res = ::SuspendThread(hThread); res >= 0, res);
// ResumeThread
inline DWORD ResumeThread(HANDLE hThread)
safe_ret_as(auto res = ::ResumeThread(hThread); res >= 0, res);
wapi_ret(TlsAlloc, fault, TLS_OUT_OF_INDEXES);
wapi_ret(TlsGetValue, notnull);
wapi_ret(TlsSetValue, true);
wapi_ret(TlsFree, true);
wapi_ret_WAO(CreateProcess, true);
wapi_ret_WAT(GetStartupInfo, direct); // GetStartupInfoA from WinBase.h
wapi_ret(SetProcessShutdownParameters, true);
wapi_ret(GetProcessVersion, notzero);
wapi_ret_WAO(CreateProcessAsUser, true);
wapi_ret(GetCurrentProcessToken, direct);
wapi_ret(GetCurrentThreadToken, direct);
wapi_ret(GetCurrentThreadEffectiveToken, direct);
wapi_ret(SetThreadToken, true);
wapi_ret(OpenProcessToken, true);
wapi_ret(OpenThreadToken, true);
wapi_ret(SetPriorityClass, true);
wapi_ret(GetPriorityClass, notzero);
wapi_ret(SetThreadStackGuarantee, true);
wapi_ret(ProcessIdToSessionId, true);
wapi_ret(GetProcessId, notzero);
wapi_ret(GetThreadId, notzero);
wapi_ret(FlushProcessWriteBuffers, direct);
wapi_ret(GetProcessIdOfThread, notzero);
wapi_ret(InitializeProcThreadAttributeList, true);
wapi_ret(DeleteProcThreadAttributeList, direct);
wapi_ret(UpdateProcThreadAttribute, true);
#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
wapi_ret(SetProcessDynamicEHContinuationTargets, true);
#endif
#if (NTDDI_VERSION >= NTDDI_WIN10_FE)
wapi_ret(SetProcessDynamicEnforcedCetCompatibleRanges, true);
#endif
wapi_ret(SetProcessAffinityUpdateMode, true);
wapi_ret(QueryProcessAffinityUpdateMode, true);
wapi_ret(CreateRemoteThreadEx, notnull);
wapi_ret(GetCurrentThreadStackLimits, direct);
wapi_ret(GetThreadContext, true);
wapi_ret(GetProcessMitigationPolicy, true);
wapi_ret(SetThreadContext, true);
wapi_ret(SetProcessMitigationPolicy, true);
wapi_ret(FlushInstructionCache, true);
wapi_ret(GetThreadTimes, true);
wapi_ret(OpenProcess, notnull);
wapi_ret(IsProcessorFeaturePresent, direct);
wapi_ret(GetProcessHandleCount, true);
wapi_ret(GetCurrentProcessorNumber, direct);
wapi_ret(SetThreadIdealProcessorEx, true);
wapi_ret(GetThreadIdealProcessorEx, true);
wapi_ret(GetCurrentProcessorNumberEx, direct);
wapi_ret(GetProcessPriorityBoost, true);
wapi_ret(SetProcessPriorityBoost, true);
wapi_ret(GetThreadIOPendingFlag, true);
wapi_ret(GetSystemTimes, true);
wapi_ret(GetThreadInformation, true);
wapi_ret(SetThreadInformation, true);
wapi_ret(IsProcessCritical, true);
wapi_ret(SetProtectedPolicy, true);
wapi_ret(QueryProtectedPolicy, true);
// SetThreadIdealProcessor
inline DWORD SetThreadIdealProcessor(HANDLE hThread, DWORD dwIdealProcessor)
safe_ret_as(auto res = ::SetThreadIdealProcessor(hThread, dwIdealProcessor); res >= 0, res);
wapi_ret(SetProcessInformation, true);
wapi_ret(GetProcessInformation, true);
wapi_ret(GetProcessShutdownParameters, true);
// SetThreadDescription
// GetThreadDescription
#pragma endregion

#pragma region PsApi.h
#pragma endregion

#pragma region SynchApi.h
wapi_ret(InitializeSRWLock, direct);
wapi_ret(ReleaseSRWLockExclusive, direct);
wapi_ret(ReleaseSRWLockShared, direct);
wapi_ret(AcquireSRWLockExclusive, direct);
wapi_ret(AcquireSRWLockShared, direct);
wapi_ret(TryAcquireSRWLockExclusive, direct);
wapi_ret(TryAcquireSRWLockShared, direct);
wapi_ret(InitializeCriticalSection, direct);
wapi_ret(EnterCriticalSection, direct);
wapi_ret(LeaveCriticalSection, direct);
wapi_ret(InitializeCriticalSectionAndSpinCount, true);
wapi_ret(InitializeCriticalSectionEx, true);
wapi_ret(SetCriticalSectionSpinCount, direct);
wapi_ret(TryEnterCriticalSection, direct);
wapi_ret(DeleteCriticalSection, direct);
wapi_ret(InitOnceInitialize, direct);
wapi_ret(InitOnceExecuteOnce, true);
wapi_ret(InitOnceBeginInitialize, true);
wapi_ret(InitOnceComplete, true);
wapi_ret(InitializeConditionVariable, direct);
wapi_ret(WakeConditionVariable, direct);
wapi_ret(WakeAllConditionVariable, direct);
wapi_ret(SleepConditionVariableCS, true);
wapi_ret(SleepConditionVariableSRW, true);
wapi_ret(SetEvent, true);
wapi_ret(ResetEvent, true);
wapi_ret(ReleaseSemaphore, true);
wapi_ret(ReleaseMutex, true);
wapi_ret(Sleep, direct);
wapi_ret(SleepEx, direct);
wapi_ret(SignalObjectAndWait, fault, WAIT_FAILED);
wapi_ret(WaitForSingleObject, fault, WAIT_FAILED);
wapi_ret(WaitForSingleObjectEx, fault, WAIT_FAILED);
wapi_ret(WaitForMultipleObjects, fault, WAIT_FAILED);
wapi_ret(WaitForMultipleObjectsEx, fault, WAIT_FAILED);
wapi_ret_WAO(CreateMutex, true);
wapi_ret_WAO(OpenMutex, true); // OpenMutexA from WinBase.h
wapi_ret_WAO(CreateEvent, true);
wapi_ret_WAO(OpenSemaphore, true); // OpenSemaphoreA from WinBase.h
wapi_ret_WAO(OpenWaitableTimer, true); // OpenWaitableTimerA from WinBase.h
wapi_ret(SetWaitableTimer, true);
wapi_ret(CancelWaitableTimer, true);
wapi_ret_WAO(CreateMutexEx, notnull);
wapi_ret_WAO(CreateEventEx, notnull);
wapi_ret_WAO(CreateSemaphore, true); // CreateSemaphoreA from WinBase.h
wapi_ret_WAO(CreateSemaphoreEx, true); // CreateSemaphoreExA from WinBase.h
wapi_ret_WAO(CreateWaitableTimer, true); // CreateWaitableTimerA from WinBase.h
wapi_ret_WAO(CreateWaitableTimerEx, true); // CreateWaitableTimerExA from WinBase.h
#pragma endregion

#pragma region NamespaceApi.h
wapi_ret_WAO(CreatePrivateNamespace, true); // CreatePrivateNamespaceA from WinBase.h
wapi_ret_WAO(OpenPrivateNamespace, true); // OpenPrivateNamespaceA from WinBase.h
wapi_ret(ClosePrivateNamespace, true);
wapi_ret_WAO(CreateBoundaryDescriptor, true); // CreateBoundaryDescriptorA from WinBase.h
wapi_ret(AddSIDToBoundaryDescriptor, true);
wapi_ret(DeleteBoundaryDescriptor, direct);
#pragma endregion

#pragma region JobApi.h
// IsProcessInJob
#pragma endregion

#pragma region JobApi2.h
wapi_ret_WAO(CreateJobObject, notnull); // CreateJobObjectA from WinBase.h
wapi_ret(FreeMemoryJobObject, direct);
wapi_ret_WAO(OpenJobObject, notnull); // OpenJobObject from WinBase.h
wapi_ret(AssignProcessToJobObject, true);
wapi_ret(TerminateJobObject, true);
wapi_ret(SetInformationJobObject, true);
wapi_ret(SetIoRateControlInformationJobObject, true);
wapi_ret(QueryInformationJobObject, true);
wapi_ret(QueryIoRateControlInformationJobObject, true);
#pragma endregion

}

template<class AnyChild>
class WaitableBase : public KernalObject<AnyChild> {
public:
	using Super = KernalObject<AnyChild>;

	/* const */ class_method(Wait, DWORD, (DWORD dwMilliseconds = INFINITE), as(Native::WaitForSingleObject(self, dwMilliseconds) == WAIT_OBJECT_0));
};

enum_flags(EventAccess , KernalAccess       ,
		   All         = EVENT_ALL_ACCESS   ,
		   Modify      = EVENT_MODIFY_STATE );
class Event : public WaitableBase<Event> {
public:
	using Super = WaitableBase<Event>;

	class_method(Set, void, (), to(Native::SetEvent(self)));
	class_method(Reset, void, (), to(Native::ResetEvent(self)));
	class_method(Pulse, void, (), to(Native::PulseEvent(self)));
};
using CEvent = ProxyView<Event>;

enum_flags(MutexAccess  , KernalAccess       ,
		   All          = MUTEX_ALL_ACCESS   ,
		   Modify       = MUTEX_MODIFY_STATE );
class Mutex : public WaitableBase<Mutex> {
public:
	using Super = WaitableBase<Mutex>;
	using Access = MutexAccess;

	class_method(Release, void, (), to(Native::ReleaseMutex(self)));
};
using CMutex = ProxyView<Mutex>;

enum_flags(SemaphoreAccess , KernalAccess           ,
		   All             = SEMAPHORE_ALL_ACCESS   ,
		   Modify          = SEMAPHORE_MODIFY_STATE );
class Semaphore : public WaitableBase<Semaphore> {
public:
	using Super = WaitableBase<Semaphore>;
	using Access = SemaphoreAccess;

	class_method(Release, LONG, (LONG ReleaseCount), to(LONG preCount = 0, Native::ReleaseSemaphore(self, ReleaseCount, &preCount), preCount));
};

enum_flags(TimerAccess , KernalAccess       ,
		   All         = TIMER_ALL_ACCESS   ,
		   Modify      = TIMER_MODIFY_STATE );
using WaitableTimerAccess = TimerAccess;
class WaitableTimer : public WaitableBase<WaitableTimer> {
public:
	using Super = WaitableBase<WaitableTimer>;
	using Access = TimerAccess;

};
using Timer = WaitableTimer;

class PrivateNamespace : public KernalObject<PrivateNamespace> {
public:
	using Super = KernalObject<PrivateNamespace>;

};

// #include "WandX.Win32.Realtime.h"

}
