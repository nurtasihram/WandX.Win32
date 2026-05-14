module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Types.h"

export module WandX.Win32.Types;

import WandX;
import WandX.Win32;
import WandX.Win32.String;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Types");

export namespace WandX {
namespace Native {

#pragma region WinBase.h
// InitAtomTable
wapi_ret(DeleteAtom, true);
wapi_ret_WAO(AddAtom, positive);
wapi_ret_WAO(FindAtom, positive);
wapi_ret_WAO(GetAtomName, positive);
wapi_ret(GlobalDeleteAtom, true);
wapi_ret_WAO(GlobalAddAtom, positive);
wapi_ret_WAO(GlobalAddAtomEx, positive);
wapi_ret_WAO(GlobalFindAtom, positive);
wapi_ret_WAO(GlobalGetAtomName, positive);
#pragma endregion

#pragma region WinUser.h
wapi_ret_WAO(MessageBox, notzero);
wapi_ret_WAO(MessageBoxEx, notzero);
wapi_ret_WAO(MessageBoxIndirect, notzero);
#pragma endregion

#pragma region DateTimeApi.h
wapi_ret_WAO(GetDateFormat, positive);
wapi_ret_WAO(GetTimeFormat, positive);
wapi_ret(GetTimeFormatEx, positive);
wapi_ret(GetDateFormatEx, positive);
// GetDurationFormatEx - deprecated
#pragma endregion

#pragma region HandleApi.h
wapi_ret(CloseHandle, true);
wapi_ret(DuplicateHandle, true);
wapi_ret(CompareObjectHandles, direct);
wapi_ret(GetHandleInformation, true);
wapi_ret(SetHandleInformation, true);
#pragma endregion

#pragma region SysInfoApi.h
wapi_ret(GlobalMemoryStatusEx, true);
wapi_ret(GetSystemInfo, direct);
wapi_ret(GetSystemTime, direct);
wapi_ret(GetSystemTimeAsFileTime, direct);
wapi_ret(GetLocalTime, direct);
wapi_ret(IsUserCetAvailableInEnvironment, direct);
#ifdef GetSystemLeapSecondInformation
wapi_ret(GetSystemLeapSecondInformation, true);
#endif
// GetVersion - deprecated
wapi_ret(SetLocalTime, true);
wapi_ret(GetTickCount, direct);
wapi_ret(GetTickCount64, direct);
wapi_ret(GetSystemTimeAdjustment, true);
#ifdef GetSystemTimeAdjustmentPrecise
wapi_ret(GetSystemTimeAdjustmentPrecise, true);
#endif
wapi_ret_WAO(GetSystemDirectory, positive);
wapi_ret_WAO(GetWindowsDirectory, positive);
wapi_ret_WAO(GetSystemWindowsDirectory, positive);
wapi_ret_WAO(GetComputerNameEx, true);
wapi_ret(SetComputerNameExW, true);
wapi_ret(SetSystemTime, true);
// GetVersionEx - deprecated
wapi_ret(GetLogicalProcessorInformation, true);
wapi_ret(GetLogicalProcessorInformationEx, true);
wapi_ret(GetNativeSystemInfo, direct);
wapi_ret(GetSystemTimePreciseAsFileTime, direct);
wapi_ret(GetProductInfo, true);
wapi_ret(VerSetConditionMask, direct);
wapi_ret(GetOsSafeBootMode, true);
wapi_ret(EnumSystemFirmwareTables, positive);
wapi_ret(GetSystemFirmwareTable, positive);
// DnsHostnameToComputerNameExW
wapi_ret(GetPhysicallyInstalledSystemMemory, true);
#ifdef SetComputerNameEx2W
wapi_ret(SetComputerNameEx2W, true);
#endif
wapi_ret(SetSystemTimeAdjustment, true);
#ifdef SetSystemTimeAdjustmentPrecise
wapi_ret(SetSystemTimeAdjustmentPrecise, true);
#endif
#ifdef InstallELAMCertificateInfo
wapi_ret(InstallELAMCertificateInfo, true);
#endif
wapi_ret(GetProcessorSystemCycleTime, true);
#ifdef GetOsManufacturingMode
wapi_ret(GetOsManufacturingMode, true);
#endif
#ifdef GetIntegratedDisplaySize
wapi_ret(GetIntegratedDisplaySize, success);
#endif
wapi_ret_WAO(SetComputerName, true);
wapi_ret(SetComputerNameExA, true);
#ifdef GetDeveloperDriveEnablementState
wapi_ret(GetDeveloperDriveEnablementState, fault, DeveloperDriveEnablementStateError);
#endif
#ifdef GetRuntimeAttestationReport
wapi_ret(GetRuntimeAttestationReport, true);
#endif
#pragma endregion

}

#pragma region Point Size Rect
struct Point : public POINT {
	constexpr Point() : POINT{ 0 } {}
	constexpr Point(const POINT &p) : POINT(p) {}
	constexpr Point(const Point &p) : POINT(p) {}
	constexpr Point(LONG a) : POINT{ a, a } {}
	constexpr Point(LONG x, LONG y) : POINT{ x, y } {}

	constexpr Point(SIZE s) : POINT{ s.cx, s.cy } {}
	constexpr Point(COORD c) : POINT{ c.X, c.Y } {}

	constexpr operator COORD () const ret_as({ (SHORT)x, (SHORT)y });
	constexpr operator SIZE  () const ret_as({ x, y });
	
	constexpr bool  operator==(Point  p) const ret_as(p.x == x && p.y == y);
	constexpr bool  operator!=(Point  p) const ret_as(p.x != x || p.y != y);
	
	constexpr Point operator+ (        ) const retself;
	constexpr Point operator- (        ) const ret_as({ -x, -y });
	constexpr Point operator~ (        ) const ret_as({  y,  x });
	
	constexpr Point operator+ (long   p) const ret_as({ x + p  , y + p   });
	constexpr Point operator- (long   p) const ret_as({ x - p  , y - p   });
	constexpr Point operator* (long   p) const ret_as({ x * p  , y * p   });
	constexpr Point operator/ (long   p) const ret_as({ x / p  , y / p   });
	constexpr Point operator+ (Point  p) const ret_as({ x + p.x, y + p.y });
	constexpr Point operator- (Point  p) const ret_as({ x - p.x, y - p.y });

	constexpr Point&operator+=(long   p)       ret_to_self(x += p  , y += p  );
	constexpr Point&operator-=(long   p)       ret_to_self(x -= p  , y -= p  );
	constexpr Point&operator*=(long   p)       ret_to_self(x *= p  , y *= p  );
	constexpr Point&operator/=(long   p)       ret_to_self(x /= p  , y /= p  );
	constexpr Point&operator+=(Point  p)       ret_to_self(x += p.x, y += p.y);
	constexpr Point&operator-=(Point  p)       ret_to_self(x -= p.x, y -= p.y);

	constexpr Point&operator =(Point  p)       ret_to_self(x  = p.x, y  = p.y);
};

struct Size : public SIZE {
	constexpr Size() : SIZE{ 0 } {}
	constexpr Size(const SIZE &s) : SIZE(s) {}
	constexpr Size(const Size &s) : SIZE(s) {}
	constexpr Size(LONG c) : SIZE{ c, c } {}
	constexpr Size(LONG cx, LONG cy) : SIZE{ cx, cy } {}

	constexpr Size(COORD c) : SIZE{ c.X, c.Y } {}
	constexpr Size(POINT p) : SIZE{ p.x, p.y } {}

	constexpr auto Square() const ret_as(cx * cy);

	constexpr operator COORD () const ret_as({ (SHORT)cx, (SHORT)cy });
	constexpr operator POINT () const ret_as({ cx, cy });

	constexpr bool operator==(Size   p) const ret_as(p.cx == cx && p.cy == cy);
	constexpr bool operator!=(Size   p) const ret_as(p.cx != cx || p.cy != cy);

	constexpr Size operator+ (        ) const retself;
	constexpr Size operator- (        ) const ret_as({ -cx, -cy });
	constexpr Size operator~ (        ) const ret_as({  cy,  cx });

	constexpr Size operator+ (long   p) const ret_as({ cx + p  , cy + p   });
	constexpr Size operator- (long   p) const ret_as({ cx - p  , cy - p   });
	constexpr Size operator* (long   p) const ret_as({ cx * p  , cy * p   });
	constexpr Size operator/ (long   p) const ret_as({ cx / p  , cy / p   });
	constexpr Size operator+ (Size   p) const ret_as({ cx + p.cx, cy + p.cy });
	constexpr Size operator- (Size   p) const ret_as({ cx - p.cx, cy - p.cy });

	constexpr Size&operator+=(long   p)       ret_to_self(cx += p  , cy += p   );
	constexpr Size&operator-=(long   p)       ret_to_self(cx -= p  , cy -= p   );
	constexpr Size&operator*=(long   p)       ret_to_self(cx *= p  , cy *= p   );
	constexpr Size&operator/=(long   p)       ret_to_self(cx /= p  , cy /= p   );
	constexpr Size&operator+=(Size   p)       ret_to_self(cx += p.cx, cy += p.cy);
	constexpr Size&operator-=(Size   p)       ret_to_self(cx -= p.cx, cy -= p.cy);

	constexpr Size&operator =(Size   p)       ret_to_self(cx  = p.cx, cy  = p.cy);
};
enum_flags(LAlign   , BYTE   ,
		   Left     = 1 << 0 ,
		   Right    = 2 << 0 ,
		   HCenter  = 3 << 0 ,
		   Top      = 1 << 2 ,
		   Bottom   = 2 << 2 ,
		   VCenter  = 3 << 2 );
struct Rect : public RECT {
	constexpr Rect() : RECT{ 0 } {}
	constexpr Rect(const RECT &rc) : RECT(rc) {}
	constexpr Rect(const Rect &rc) : RECT(rc) {}
	constexpr Rect(LONG a) : RECT{ a, a, a, a } {}
	constexpr Rect(LONG left, LONG top, LONG right, LONG bottom) : RECT{ left, top, right, bottom } {}

//	constexpr Rect(const MARGINS &m) : RECT({ m.cxLeftWidth, m.cyTopHeight, m.cxRightWidth, m.cyBottomHeight }) {}
	constexpr Rect(SMALL_RECT s) : RECT{ s.Left, s.Top, s.Right, s.Bottom } {}
	constexpr Rect(SIZE sz) : RECT{ 0, 0, sz.cx - 1, sz.cy - 1 } {}
	constexpr Rect(POINT p0,  POINT p1) : RECT{ p0.x, p0.y, p1.x, p1.y } {}

	void Align(LAlign a, const Rect &r2) {
		if (a == LAlign::HCenter)
			xMove((r2.left + r2.right - left - right) / 2);
		elif (a <= LAlign::Right) {
			left += r2.right - right;
			right = r2.right;
		}
		else /* if (a <= LAlign::Left) */ {
			right += r2.left - left;
			left = r2.left;
		}
		if (a == LAlign::VCenter)
			yMove((r2.top + r2.bottom - top - bottom) / 2);
		elif (a <= LAlign::Bottom) {
			top += r2.bottom - bottom;
			bottom = r2.bottom;
		}
		else /* if (a & LAlign::Top) */ {
			bottom += r2.top - top;
			top = r2.top;
		}
	}

	constexpr auto xSize() const ret_as(right - left + 1);
	constexpr auto ySize() const ret_as(bottom - top + 1);
	constexpr WandX::Size Size() const ret_as({xSize(), ySize()});
	
	constexpr auto xDiff() const ret_as(right - left);
	constexpr auto yDiff() const ret_as(bottom - top);
	constexpr WandX::Point Diff() const ret_as({ xDiff(), yDiff() });
	
	constexpr Rect &xMove(long dx) ret_to_self(right += dx, left += dx);
	constexpr Rect &yMove(long dy) ret_to_self(bottom += dy, top += dy);

	constexpr auto x0() const ret_as(left);
	constexpr auto y0() const ret_as(top);
	constexpr auto x1() const ret_as(right);
	constexpr auto y1() const ret_as(bottom);

	constexpr Point LeftTop    (       ) const ret_as     ({  left,    top });
	constexpr Point LeftBottom (       ) const ret_as     ({  left, bottom });
	constexpr Point RightTop   (       ) const ret_as     ({ right,    top });
	constexpr Point RightBottom(       ) const ret_as     ({ right, bottom });
	constexpr auto &LeftTop    (Point p)       ret_to_self(left  = p.x, top    = p.y);
	constexpr auto &LeftBottom (Point p)       ret_to_self(left  = p.x, bottom = p.y);
	constexpr auto &RightTop   (Point p)       ret_to_self(right = p.x, top    = p.y);
	constexpr auto &RightBottom(Point p)       ret_to_self(right = p.x, bottom = p.y);

	constexpr operator LPRECT    ()       ret_as(this);
	constexpr operator LPCRECT   () const ret_as(this);
	constexpr operator SIZE      () const ret_as(this->Size());
//	constexpr operator MARGINS   () const ret_as({ left, right, top, bottom });
	constexpr operator SMALL_RECT() const ret_as({ (SHORT)left, (SHORT)top, (SHORT)right, (SHORT)bottom });

	constexpr operator bool      () const ret_as(left <= right && top <= bottom);

	constexpr bool operator==(Rect   r) const ret_as(r.left == left && r.top == top && r.right == right && r.bottom == bottom);
	constexpr bool operator!=(Rect   r) const ret_as(r.left != left || r.top != top || r.right != right || r.bottom != bottom);

	constexpr Rect operator+ (        ) const retself;
	constexpr Rect operator- (        ) const ret_as({ -left,   -top, -right, -bottom });
	constexpr Rect operator~ (        ) const ret_as({ right, bottom,   left,     top });

	constexpr Rect operator+ (long   l) const ret_as({ left + l     , top + l    , right + l      , bottom + l        });
	constexpr Rect operator- (long   l) const ret_as({ left - l     , top - l    , right - l      , bottom - l        });
	constexpr Rect operator+ (Point  p) const ret_as({ left + p.x   , top + p.y  , right + p.x    , bottom + p.y      });
	constexpr Rect operator- (Point  p) const ret_as({ left - p.x   , top - p.y  , right - p.x    , bottom - p.y      });
	constexpr Rect operator+ (Rect   r) const ret_as({ left + r.left, top + r.top, right + r.right, bottom + r.bottom });
	constexpr Rect operator- (Rect   r) const ret_as({ left - r.left, top - r.top, right - r.right, bottom - r.bottom });

	constexpr Rect operator* (long   l) const ret_as({ left - l, top - l, right + l, bottom + l });
	constexpr Rect operator/ (long   l) const ret_as({ left + l, top + l, right - l, bottom - l });

	constexpr Rect&operator+=(long   l)       ret_to_self(left += l     , top += l    , right += l      , bottom += l       );
	constexpr Rect&operator-=(long   l)       ret_to_self(left -= l     , top -= l    , right -= l      , bottom -= l       );
	constexpr Rect&operator+=(Point  p)       ret_to_self(left += p.x   , top += p.y  , right += p.x    , bottom += p.y     );
	constexpr Rect&operator-=(Point  p)       ret_to_self(left -= p.x   , top -= p.y  , right -= p.x    , bottom -= p.y     );
	constexpr Rect&operator+=(Rect   r)       ret_to_self(left += r.left, top += r.top, right += r.right, bottom += r.bottom);
	constexpr Rect&operator-=(Rect   r)       ret_to_self(left -= r.left, top -= r.top, right -= r.right, bottom -= r.bottom);

	constexpr Rect&operator/=(long   l)       ret_to_self(left -= l, top -= l, right += l, bottom += l);
	constexpr Rect&operator*=(long   l)       ret_to_self(left += l, top += l, right -= l, bottom -= l);

	constexpr Rect&operator =(Rect   r)       ret_to_self(left = r.left, top = r.top, right = r.right, bottom = r.bottom);
};
inline Rect operator+(Point p, const Rect &r) ret_as(r + p);
inline Rect operator-(Point p, const Rect &r) ret_as(-(r - p));
#pragma endregion

#pragma region Atoms
class Atom {
	ATOM atom = 0;
public:
	Atom(ATOM atom = 0) : atom(atom) {}
	~Atom() ret_to(Delete());

	static inline Atom Find(LPCSTR lpString) ret_as(Native::FindAtom(lpString));
	static inline Atom Find(LPCWSTR lpString) ret_as(Native::FindAtom(lpString));
	inline void Delete() ret_to(if (atom) (Native::DeleteAtom(atom), atom = 0));

	class_prop_strfix_getas_WAO(Name, MaxLenClass, Native::GetAtomName(self, value, (int)MaxLen));

};
class GlobalAtom {
	ATOM atom = 0;
public:
	GlobalAtom(ATOM atom = 0) : atom(atom) {}
	~GlobalAtom() ret_to(Delete());

	static inline ProxyView<GlobalAtom> Find(LPCSTR lpString) ret_as(Native::GlobalFindAtom(lpString));
	static inline ProxyView<GlobalAtom> Find(LPCWSTR lpString) ret_as(Native::GlobalFindAtom(lpString));
	inline void Delete() ret_to(if (atom) (Native::GlobalDeleteAtom(atom), atom = 0));

	class_prop_strfix_getas_WAO(Name, MaxLenClass, Native::GlobalGetAtomName(self, value, (int)MaxLen));

};
#pragma endregion

#include "WandX.Win32.Types.idl"

}
