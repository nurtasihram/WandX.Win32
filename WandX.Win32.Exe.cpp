#include <Windows.h>

#pragma comment(lib,"Gdi32.lib")
#pragma comment(lib,"OneCore.lib")
#pragma comment(linker, "\"" \
	"/manifestdependency:" \
	" type='win32'" \
	" name='Microsoft.Windows.Common-Controls'" \
	" version='6.0.0.0'" \
	" processorArchitecture='*'" \
	" publicKeyToken='6595b64144ccf1df'" \
	" language='*'" \
"\"")

#include "WandX.Win32.Types.h"
#include "WandX.Win32.Console.h"

using namespace WandX;

int WxMain();

static int WxMain_safe() {
#ifndef WANDX_NO_CONSOLE_IN_WINMAIN
	Console.Alloc();
#endif
	try {
		return WxMain();
	} catch (WandX::Exception err) {
		Console.Write(T("WxMain Exception:\n"));
		Console.Write(toString(err));
		system("pause");
	}
	return -1;
}

int main() {
	return WxMain_safe();
}

int APIENTRY wWinMain(HINSTANCE hInstance,
					  HINSTANCE hPrevInstance,
					  LPWSTR    lpCmdLine,
					  int       nCmdShow) {
#ifndef WANDX_NO_CONSOLE_IN_WINMAIN

#else
#	undef WANDX_NO_CONSOLE_IN_WINMAIN
#endif
	return WxMain_safe();
}

int APIENTRY WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR    lpCmdLine,
					 int       nCmdShow) {

	return WxMain_safe();
}
