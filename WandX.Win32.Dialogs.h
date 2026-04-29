#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Dialogs;
#endif

#include "WandX.Win32.Window.h"

// from CommDlg.h
#undef GetOpenFileName
#undef GetSaveFileName
#undef GetFileTitle
#undef ChooseColor
#undef FindText
#undef ReplaceText
#undef ChooseFont
#undef PrintDlg
#undef PrintDlgEx
#undef PageSetupDlg

#define SFINAE_Dialog(name) friend class WandX::DialogBase<name>; friend class WandX::WindowBase<name>
#define BaseOf_Dialog(name) name : public WandX::DialogBase<name>
