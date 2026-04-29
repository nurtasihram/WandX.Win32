module;

#include <Windows.h>
//#include <Winineti.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Internet.h"

export module WandX.Win32.Internet;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Internet");

export namespace WandX {
namespace Native {
}

//#include "WandX.Win32.Internet.h"

}

