#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Window;
#endif

#include "WandX.Win32.Resources.h"

#define SFINAE_Window(name) friend class Native::WindowBase<name>
#define BaseOf_Window(name) name : public Native::WindowBase<name>
