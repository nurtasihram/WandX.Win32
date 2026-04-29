#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Realtime;
#endif

#include "WandX.Win32.Types.h"

// from ProcessThreadsApi.h
#undef CreateProcess
#undef GetStartupInfo
#undef CreateProcessAsUser

// from SynchApi.h
#undef CreateMutex
#undef OpenMutex
#undef CreateEvent
#undef OpenSemaphore
#undef OpenWaitableTimer
#undef CreateMutexEx
#undef CreateEventEx
#undef CreateSemaphore
#undef CreateSemaphoreEx
#undef CreateWaitableTimer
#undef CreateWaitableTimerEx

// from NamespaceApi.h
#undef CreatePrivateNamespace
#undef OpenPrivateNamespace
#undef CreateBoundaryDescriptor

// from JobApi2.h
#undef CreateJobObject
#undef OpenJobObject

#define BaseOf_Waitable(name) name : public WandX::WaitableBase<name>

#define SFINAE_Thread(name) friend class WandX::ThreadBase<name>; using Super = WandX::ThreadBase<name>
#define BaseOf_Thread(name) name : public WandX::ThreadBase<name>
