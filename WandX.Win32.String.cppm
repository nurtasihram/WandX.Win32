module;

#include <Windows.h>
#define STRSAFE_LIB
#include <StrSafe.h>
#undef STRSAFE_LIB

#pragma comment(lib, "legacy_stdio_definitions.lib")

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.String.h"

export module WandX.Win32.String;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.String");

export namespace WandX {
namespace Native {

#pragma region StringApiSet.h
wapi_ret(CompareStringEx, notzero);
wapi_ret(CompareStringOrdinal, notzero);
wapi_ret_WAO(CompareString, notzero); // CompareStringA from WinNls.h
wapi_ret_WAO(FoldString, positive); // FoldStringA from WinNls.h
wapi_ret_WAO(GetStringTypeEx, true); // GetStringTypeExA from WinNls.h
wapi_ret_WAO(GetStringType, true); // GetStringTypeA from WinNls.h
wapi_ret(MultiByteToWideChar, positive);
wapi_ret(WideCharToMultiByte, positive);
#pragma endregion

#pragma region StrSafe.h
wapi_ret_WAO(StringCchCopy, success);
wapi_ret_WAO(StringCchCopyEx, success);
wapi_ret_WAO(StringCbCopy, success);
wapi_ret_WAO(StringCbCopyEx, success);
wapi_ret_WAO(StringCchCopyN, success);
wapi_ret_WAO(StringCbCopyN, success);
wapi_ret_WAO(StringCchCopyNEx, success);
wapi_ret_WAO(StringCbCopyNEx, success);
wapi_ret_WAO(StringCchCat, success);
wapi_ret_WAO(StringCbCat, success);
wapi_ret_WAO(StringCchCatEx, success);
wapi_ret_WAO(StringCbCatEx, success);
wapi_ret_WAO(StringCchCatN, success);
wapi_ret_WAO(StringCbCatN, success);
wapi_ret_WAO(StringCchCatNEx, success);
wapi_ret_WAO(StringCbCatNEx, success);
wapi_ret_WAO(StringCchVPrintf, success);
wapi_ret_WAO(StringCbVPrintf, success);
//wapi_ret_WAO(StringCchPrintf, success);
//wapi_ret_WAO(StringCbPrintf, success);
//wapi_ret_WAO(StringCchPrintfEx, success);
//wapi_ret_WAO(StringCbPrintfEx, success);
wapi_ret_WAO(StringCchVPrintfEx, success);
wapi_ret_WAO(StringCbVPrintfEx, success);
wapi_ret_WAO(StringCchGets, success);
wapi_ret_WAO(StringCbGets, success);
wapi_ret_WAO(StringCchGetsEx, success);
wapi_ret_WAO(StringCbGetsEx, success);
wapi_ret_WAO(StringCchLength, success);
wapi_ret_WAO(StringCbLength, success);
#pragma endregion

#pragma region WinBase.h
wapi_ret_WAO(FormatMessage, positive);
#pragma endregion

}

template<bool IsUnicode>
using XCHAR = TypeIf<IsUnicode, WCHAR, CHAR>;
template<bool IsUnicode>
using LPXSTR = TypeIf<IsUnicode, LPWSTR, LPSTR>;
template<bool IsUnicode>
using LPCXSTR = TypeIf<IsUnicode, LPCWSTR, LPCSTR>;

template<class TCHAR>
concept IsCharA = IsSame<TCHAR, CHAR> || IsSame<TCHAR, LPSTR> || IsSame<TCHAR, LPCSTR>;
template<class TCHAR>
concept IsCharW = IsSame<TCHAR, WCHAR> || IsSame<TCHAR, LPWSTR> || IsSame<TCHAR, LPCWSTR>;

template<bool IsUnicode, class AnyTypeW, class AnyTypeA>
constexpr auto AnyX(AnyTypeW *w, AnyTypeA *a) {
	if constexpr (IsUnicode)
		 return w;
	else return a;
}
template<bool IsUnicode, class AnyTypeW, class AnyTypeA>
constexpr auto &AnyX(AnyTypeW &w, AnyTypeA &a) {
	if constexpr (IsUnicode)
		 return w;
	else return a;
}
template<bool IsUnicode, class AnyTypeW, class AnyTypeA>
constexpr auto AnyX(AnyTypeW &&w, AnyTypeA &&a) {
	if constexpr (IsUnicode)
		 return w;
	else return a;
}

constexpr SizeT MaxLenPath = MAX_PATH;
constexpr SizeT MaxLenTitle = MaxLenPath * 3;
constexpr SizeT MaxLenClass = 256;
constexpr SizeT MaxLenNotice = 32767;

#pragma region Strings
enum_class(CodePages, UINT,
	Active       = CP_ACP,
	OEM          = CP_OEMCP,
	Macintosh    = CP_MACCP,
	ThreadActive = CP_THREAD_ACP,
	Symbol       = CP_SYMBOL,
	UTF7         = CP_UTF7,
	UTF8         = CP_UTF8);
template<class TCHAR>
class StringBase;
template<class CharType = TCHAR> const StringBase<CharType> CString(SizeT uLen, const CharType *lpString);
template<class CharType = TCHAR> const StringBase<CharType> CString(const CharType *lpString, SizeT maxLen);
template<class CharType>
inline SizeT Length(const CharType *lpString, SizeT MaxLen) {
	Native::StringCchLength(lpString, MaxLen, &MaxLen);
	return MaxLen;
}
template<class TCHAR>
class StringBase {
	using LPTSTR = TCHAR *;
	using LPCTSTR = const TCHAR *;
	enum StrFlags : SizeT {
		STR_REF = 0,
		STR_READONLY = 1,
		STR_MUTABLE = 2,
		STR_RELEASE = 4
	};
	mutable LPTSTR lpsz = O;
	mutable SizeT Len : sizeof(void *) * 8 - 3;
	mutable SizeT Flags : 3;
private:
	template<class _TCHAR> friend const StringBase<_TCHAR> CString(SizeT, const _TCHAR *);
	template<class _TCHAR> friend const StringBase<_TCHAR> CString(const _TCHAR *, SizeT );
	StringBase(const StringBase &) = delete;
	StringBase(LPTSTR lpBuffer, SizeT len, UINT flags) :
		lpsz(lpBuffer), Len((UINT)len), Flags(flags) {
		if (len <= 0 || !lpBuffer) {
			Len = 0;
			lpsz = O;
		}
	}
	StringBase(SizeT len, LPCTSTR lpString) : StringBase(const_cast<LPTSTR>(lpString), len, STR_READONLY) {}
public:
	StringBase() : Len(0), Flags(0) {}
	StringBase(Nu) : Len(0), Flags(0) {}
	StringBase(StringBase &&str) : StringBase(str.lpsz, str.Len, str.Flags) { str.lpsz = O, str.Len = 0, str.Flags = STR_REF; }
	explicit StringBase(SizeT Len) : lpsz(Alloc(Len)), Len(Len), Flags(STR_MUTABLE | STR_RELEASE) {}
	StringBase(SizeT Len, LPTSTR lpBuffer) : StringBase(lpBuffer, Len, STR_MUTABLE | STR_RELEASE) {}
	StringBase(TCHAR ch) : lpsz(Alloc(1)), Len(1), Flags(STR_MUTABLE | STR_RELEASE) ret_to(lpsz[0] = ch);
	template<SizeT len> StringBase(TCHAR(&str)[len]) : StringBase(str, len - 1, STR_REF) {}
	template<SizeT len> StringBase(const TCHAR(&str)[len]) : StringBase(const_cast<LPTSTR>(str), len - 1, STR_READONLY) {}
	~StringBase() ret_to(Free());
public: // Memories Management
	static inline LPTSTR Realloc(SizeT len, LPTSTR lpsz) {
		if (!lpsz && len <= 0) return O;
		if (lpsz && len <= 0) {
			Free(lpsz);
			return O;
		}
		if (!lpsz) return Alloc(len);
		return (LPTSTR)realloc(lpsz, (len + 1) * sizeof(TCHAR));
	}
	static inline LPTSTR Alloc(SizeT len) {
		if (len == 0) return O;
		auto nlen = (len + 1) * sizeof(TCHAR);
		auto lpsz = (LPTSTR)malloc(nlen);
		ZeroMemory(lpsz, nlen);
		return lpsz;
	}
	static inline void Free(void *lpsz) ret_to(if (lpsz) free(lpsz));
	static inline LPTSTR Resize(LPTSTR &lpsz, SizeT len) ret_as(lpsz = Realloc(len, lpsz));
	static inline void AutoFree(LPTSTR &lpsz) ret_to(Free(lpsz); lpsz = O);
	static inline void AutoCopy(LPTSTR &lpsz, const StringBase &str) {
		Resize(lpsz, str.Length());
		str.CopyTo(lpsz, str.Length() + 1);
	}
public:
	inline bool IsAlloced() const ret_as(lpsz && (Flags &STR_RELEASE));
	inline void Free() {
		if (IsAlloced()) {
			Free(lpsz);
			lpsz = O;
		}
		Len = 0;
	}
	inline bool IsReadOnly() const ret_as(Flags & STR_READONLY);
	inline bool IsMutable() const ret_as(Flags & STR_MUTABLE);
	inline auto&ToMutable() {
		if (!IsMutable())
			self = +self;
		retself;
	}
	inline auto&Shrink() {
		Len = (UINT)WandX::Length(lpsz, Len + 1);
		if (IsMutable())
			lpsz = Realloc(Len, lpsz);
		retself;
	}
	inline auto&Resize(SizeT NewLen) {
		if (NewLen <= 0) retself;
		Len = (UINT)NewLen;
		if (IsReadOnly()) retself;
		if (!IsMutable()) retself;
		auto OldLen = WandX::Length(lpsz, Len + 1);
		lpsz = Realloc(NewLen, lpsz);
		if (NewLen < OldLen)
			lpsz[OldLen] = 0;
		retself;
	}
	inline auto&Copy(LPCTSTR lpSrc)
		ret_to_self(Native::StringCchCopy(lpsz, Length(), lpSrc));
	inline auto&CopyTo(LPTSTR lpDst, SizeT lenDst) const {
		if (!lpDst && lenDst) retself;
		if (auto len = Length())
			Native::StringCchCopy(lpDst, lenDst, lpsz);
		else
			lpDst[0] = '\0';
		retself;
	}
public:
	inline LPTSTR str() {
		if (!lpsz || !Len) return O;
		nt_assert(!IsReadOnly());
		return lpsz;
	}
	inline LPCTSTR c_str() const ret_as(lpsz && Len ? lpsz : O);
	inline LPCTSTR c_str_safe() const {
		if (Len && lpsz) 
			return lpsz;
		if constexpr (IsCharW<TCHAR>)
			 return L"";
		else return "";
	}
public:
	inline SizeT Length() const ret_as(lpsz ? Len : 0);
	inline SizeT Size() const ret_as(lpsz ? (Len + 1) * sizeof(TCHAR) : 0);
public:
	inline LPTSTR begin() ret_as(Len ? lpsz : O);
	inline LPTSTR end() ret_as(Len && lpsz ? lpsz + Len : O);
	inline LPCTSTR begin() const ret_as(Len ? lpsz : O);
	inline LPCTSTR end() const ret_as(Len &&lpsz ? lpsz + Len : O);
public:
	inline operator LPTSTR () ret_as(str());
	inline operator bool() const ret_as(lpsz && Len);
	inline operator LPCTSTR () const ret_as(Len ? lpsz : O);
	inline StringBase operator&() ret_as({ Len, 0, lpsz });
	inline const StringBase operator&() const ret_as({ Len, lpsz });
	inline LPTSTR operator*() const {
		if (!lpsz || !Len) return O;
		auto lpsz = StringBase::Alloc(Len);
		CopyMemory(lpsz, this->lpsz, (Len + 1) * sizeof(TCHAR));
		lpsz[Len] = '\0';
		return lpsz;
	}
	inline StringBase operator+() const {
		if (!lpsz || !Len) return O;
		auto lpsz = StringBase::Alloc(Len);
		CopyMemory(lpsz, this->lpsz, (Len + 1) * sizeof(TCHAR));
		lpsz[Len] = '\0';
		return { Len, lpsz };
	}
	inline StringBase operator-() const {
		SizeT nLen = WandX::Length(lpsz, Len + 1);
		if (nLen <= 0) return O;
		auto lpsz = StringBase::Alloc(nLen);
		CopyMemory(lpsz, this->lpsz, (nLen + 1) * sizeof(TCHAR));
		lpsz[nLen] = '\0';
		return{ nLen, lpsz };
	}
public:
	auto operator=(const StringBase &str) = delete;
	inline auto &operator=(const StringBase &str) const noexcept {
		lpsz = str.lpsz;
		Len = str.Len;
		Flags = STR_READONLY;
		retself;
	}
	inline auto &operator=(StringBase &&str) noexcept {
		lpsz = str.lpsz, str.lpsz = O;
		Len = str.Len, str.Len = 0;
		Flags = str.Flags, str.Flags = STR_REF;
		retself;
	}
	inline auto &operator=(StringBase &str) noexcept {
		lpsz = str.lpsz;
		Len = str.Len;
		Flags = STR_REF;
		retself;
	}
	inline auto &operator+=(const StringBase &str) {
		if (!str.lpsz || !str.Len) retself;
		if (!lpsz || !Len) return self = +str;
		auto nLen = Len + str.Len;
		if (!IsMutable() || IsReadOnly()) {
			auto lpsz = StringBase::Alloc(Len);
			CopyMemory(lpsz, this->lpsz, (Len + 1) * sizeof(TCHAR));
			if (!(Flags & STR_RELEASE))
				Free(this->lpsz);
			this->lpsz = lpsz;
		}
		else lpsz = Realloc(nLen, lpsz);
		CopyMemory(lpsz + Len, str.lpsz, (str.Len + 1) * sizeof(TCHAR));
		Len = nLen;
		retself;
	}
};
using String = StringBase<TCHAR>;
using StringA = StringBase<CHAR>;
using StringW = StringBase<WCHAR>;
template<bool IsUnicode>
using StringX = structx(String);
/* CString */
template<class CharType>
inline const StringBase<CharType> CString(SizeT Len, const CharType *lpString) {
	if (Len == 0 || !*lpString) return O;
	return { Len, lpString };
}
template<class CharType>
inline const StringBase<CharType> CString(const CharType *lpString, SizeT MaxLen) {
	if (!lpString) return O;
	return { WandX::Length(lpString, MaxLen), lpString };
}	 
/* Literal operator of String  */
inline const StringA operator ""_A(LPCSTR lpString, SizeT uLen) {
	if (uLen == 0 || !*lpString) return O;
	return CString(uLen, lpString);
}
inline const StringW operator ""_W(LPCWSTR lpString, SizeT uLen) {
	if (uLen == 0 || !*lpString) return O;
	return CString(uLen, lpString);
}
inline const String operator ""_S(LPCTSTR lpString, SizeT uLen) {
	if (uLen == 0 || !*lpString) return O;
	return CString(uLen, lpString);
}
/* Fits */
inline StringA FitsA(const StringW &str, CodePages cp = CodePages::Active) {
	if (!str) return O;
	int tLen, uLen = (int)str.Length();
	LPCWSTR lpString = str;
	nt_assert((tLen = WideCharToMultiByte(cp.yield(), 0, lpString, (int)uLen, O, 0, O, O)) > 0);
	// if (tLen != uLen) warnning glyphs missing 
	auto lpsz = StringA::Alloc(tLen);
	nt_assert(tLen == WideCharToMultiByte(cp.yield(), 0, lpString, (int)uLen, lpsz, tLen, O, O));
	lpsz[tLen] = 0;
	return{ (SizeT)tLen, lpsz };
}
inline StringW FitsW(const StringA &str, CodePages cp = CodePages::Active) {
	if (!str) return O;
	int tLen, uLen = (int)str.Length();
	LPCSTR lpString = str;
	nt_assert((tLen = MultiByteToWideChar(cp.yield(), 0, lpString, (int)uLen, O, 0)) > 0);
	// if (tLen != uLen) warnning glyphs missing 
	auto lpsz = StringW::Alloc(tLen);
	nt_assert(tLen == MultiByteToWideChar(cp.yield(), 0, lpString, (int)uLen, lpsz, tLen));
	lpsz[tLen] = 0;
	return{ (SizeT)tLen, lpsz };
}
template<bool IsUnicode = Native::IsUnicode, class TCHAR = ::TCHAR>
inline auto Fits(StringBase<TCHAR> str) {
	if constexpr (IsSame<XCHAR<IsUnicode>, TCHAR>)
		 ret_as(str)
	elif constexpr (IsUnicode)
		 ret_as(FitsW(str))
	else ret_as(FitsA(str))
}
template<class CharType>
inline String Fits(const CharType *lpString, SizeT MaxLen, CodePages cp = CodePages::Active) {
	if (!lpString || !MaxLen) return O;
	auto uLen = WandX::Length(lpString, MaxLen);
	if (!uLen) return O;
	if constexpr (IsSame<CharType, TCHAR>) {
		auto lpsz = String::Alloc(uLen);
		CopyMemory(lpsz, lpString, (uLen + 1) * sizeof(TCHAR));
		return{ uLen, lpsz };
	}
	else {
		int tLen;
		if constexpr (Native::IsUnicode)
			 nt_assert((tLen = MultiByteToWideChar(cp.yield(), 0, lpString, (int)uLen, O, 0)) > 0)
		else nt_assert((tLen = WideCharToMultiByte(cp.yield(), 0, lpString, (int)uLen, O, 0, O, O)) > 0)
			// if (tLen != uLen) warnning glyphs missing 
			auto lpsz = String::Alloc(tLen);
		if constexpr (Native::IsUnicode)
			 nt_assert(tLen == MultiByteToWideChar(cp.yield(), 0, lpString, (int)uLen, lpsz, tLen))
		else nt_assert(tLen == WideCharToMultiByte(cp.yield(), 0, lpString, (int)uLen, lpsz, tLen, O, O))
			lpsz[tLen] = 0;
		return{ (SizeT)tLen, lpsz };
	}
}
/* Misc */
inline SizeT LengthOf(const StringBase<TCHAR> &str) ret_as(str.Length());
template<class TCHAR, class... Args>
inline SizeT LengthOf(const StringBase<TCHAR> &str, const Args&... args)
	ret_as(str.Length() + (LengthOf((const StringBase<TCHAR> &)args) + ...));
template<class TCHAR>
inline TCHAR *Copies(TCHAR *lpBuffer) ret_as(lpBuffer);
template<class TCHAR, class... Args>
inline TCHAR *Copies(TCHAR *lpBuffer, const StringBase<TCHAR> &str, const Args &... args) {
	auto uLen = str.Length();
	if (uLen > 0) CopyMemory(lpBuffer, str, uLen * sizeof(TCHAR));
	return Copies(lpBuffer + uLen, args...);
}
template<class TCHAR>
inline void Copy(StringBase<TCHAR> &str, const TCHAR *lpSrc)
	ret_to(StringCchCopy(str, str.Length(), lpSrc));
template<class TCHAR, SizeT len>
inline void Copy(TCHAR(&str)[len], const StringBase<TCHAR> &src)
	ret_to(StringCchCopy(str, len, src));
template<class TCHAR, class... Args>
inline StringBase<TCHAR> Concat(const StringBase<TCHAR> &str, const Args &... args) {
	SizeT totalLen = LengthOf(str, args...);
	auto lpsz = StringBase<TCHAR>::Alloc(totalLen);
	Copies(lpsz, str, args...);
	return{ totalLen, lpsz };
}
template<class AnyType>
inline void Fill(AnyType *lpArray, const AnyType &Sample, SizeT Len) {
	while (Len--)
		CopyMemory(lpArray++, &Sample, sizeof(AnyType));
}
/* format */
constexpr SizeT Len_sprintf_buff = 1024;
template<class TCHAR = ::TCHAR>
inline StringBase<TCHAR> format(const TCHAR *lpFormat, va_list argList) {
	TCHAR buff[Len_sprintf_buff];
	SizeT remain = 0;
	Native::StringCchVPrintfEx(buff, Len_sprintf_buff, O, &remain, STRSAFE_NULL_ON_FAILURE, lpFormat, argList);
	return +CString(buff, Len_sprintf_buff - remain + 1);
}
template<class TCHAR = ::TCHAR>
inline StringBase<TCHAR> format(const TCHAR *lpFormat, ...) {
	va_list argList;
	va_start(argList, lpFormat);
	auto &&str = format(lpFormat, argList);
	va_end(argList);
	return str;
}
#pragma endregion

/* toString - format_numeral */
//template<bool IsUnicode = Native::IsUnicode>
//inline StringX<IsUnicode> toString(const format_numeral &fn, Numeral auto i) {
//	XCHAR<IsUnicode> pBuffer[format_numeral::MaxLen];
//	auto len = fn.push(i, pBuffer);
//	return +CString(len, pBuffer);
//}
//template<bool IsUnicode = Native::IsUnicode>
//inline auto toString(Numeral auto i) ret_as(toString<IsUnicode>(DEC, i));
//template<bool IsUnicode = Native::IsUnicode>
//inline auto toString(FloatType auto f) ret_as(toString<IsUnicode>(FPT, f));

/* toString - Exception */
template<bool IsUnicode>
inline auto FormatMessage(DWORD dwErrorCode) {
	using LPTSTR = LPXSTR<IsUnicode>;
	LPTSTR lpsz;
	auto len = Native::FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		O, dwErrorCode, 0, (LPTSTR)&lpsz, 0, O);
	auto &&msg = CString(lpsz, len);
	LocalFree(lpsz);
	return +msg;
}
inline auto FormatMessageA(DWORD dwErrorCode) ret_as(FormatMessage<false>(dwErrorCode));
inline auto FormatMessageW(DWORD dwErrorCode) ret_as(FormatMessage<true>(dwErrorCode));
inline StringA toStringA(const Exception& err) {
	auto &&str = format(
		"File:          %s\n"
		"Function:      %s\n"
		"Sentence:      %s\n"
		"Line:          %d\n",
		err.File(),
		err.Function(),
		err.Sentence(),
		err.Line());
	if (auto dwError = err.ErrorCode())
		str += format(
			"Error Code:    %d\n"
			"Error Message: %s\n",
			dwError,
			(LPCSTR)FormatMessageA(dwError));
	return str;
}
inline StringW toStringW(const Exception &err) ret_as(FitsW(toStringA(err)));
template<bool IsUnicode = Native::IsUnicode>
inline auto toString(const Exception &err) {
	if constexpr (IsUnicode)
		 ret_as(toStringW(err))
	else ret_as(toStringA(err));
}

/* toString - char */
inline StringA toStringA(CHAR ch) {
	CHAR buff[2] = { ch, '\0' };
	return +CString(1, buff);
}
inline StringW toStringW(WCHAR ch) {
	WCHAR buff[2] = { ch, L'\0' };
	return +CString(1, buff);
}

/* toString - bool */
template<bool IsUnicode = Native::IsUnicode>
inline const auto &toString(bool b) {
	static const auto trueStrA = "true"_A;
	static const auto falseStrA = "false"_A;
	static const auto trueStrW = L"true"_W;
	static const auto falseStrW = L"false"_W;
	if constexpr (IsUnicode)
		 ret_as(b ? trueStrW : falseStrW)
	else ret_as(b ? trueStrA : falseStrA)
}

#pragma region Enumerator

#pragma region Enum
template<bool IsUnicode>
class SimpleRegex {
	using TCHAR = XCHAR<IsUnicode>;
	using String = StringX<IsUnicode>;
	using LPCTSTR = LPCXSTR<IsUnicode>;
	static constexpr bool __a_z(TCHAR w) ret_as('a' <= w && w <= 'z');
	static constexpr bool __A_Z(TCHAR w) ret_as('A' <= w && w <= 'Z');
	static constexpr bool __0_9(TCHAR w) ret_as('0' <= w && w <= '9');
	static constexpr bool __A_z(TCHAR w) ret_as(__a_z(w) || __A_Z(w));
	static constexpr bool _word(TCHAR w) ret_as(__A_z(w) || __0_9(w));
	static constexpr bool _Word(TCHAR w) ret_as(_word(w) || w == '_');
	static constexpr bool __s(TCHAR w) ret_as(w == '\n' || w == '\r' || w == '\t' || w == ' ');
	struct Token {
		friend class SimpleRegex;
		LPCTSTR lpsz;
		SizeT len;
	public:
		constexpr Token() : lpsz(O), len(0) {}
		constexpr Token(LPCTSTR lpsz, LPCTSTR hpsz) : lpsz(lpsz), len(hpsz - lpsz) {}
		constexpr operator LPCTSTR() const ret_as(lpsz);
		operator const String() const;
	};
	struct Map { Token key, val; };
	template<SizeT len>
	class Maps {
		friend class SimpleRegex;
		Map map[len];
	public:
		static constexpr SizeT Length = len;
		constexpr Map operator[](SizeT ind) const { return map[ind]; }
	};
	struct MapN { Map map; LPCTSTR hpsz; };
	static constexpr MapN _GetMap(LPCTSTR lpsz) {
		LPCTSTR hpsz = lpsz;
		// skip blank
		while (auto ch = hpsz[0])
			if (__s(hpsz[0]))
				++hpsz;
			else
				break;
		// get key
		lpsz = hpsz;
		while (auto ch = hpsz[0])
			if (_Word(hpsz[0]))
				++hpsz;
			else
				break;
		Token key{ lpsz, hpsz };
		// skip blank
		while (auto ch = hpsz[0])
			if (__s(hpsz[0]))
				++hpsz;
			else
				break;
		// get equal
		if (hpsz[0] != '=')
			return{ {}, {} };
		++hpsz;
		// skip blank
		while (auto ch = hpsz[0])
			if (__s(hpsz[0]))
				++hpsz;
			else
				break;
		// get val
		lpsz = hpsz;
		while (auto ch = hpsz[0])
			if (hpsz[0] != ',')
				++hpsz;
			else
				break;
		Token val{ lpsz, hpsz };
		if (hpsz[0] == ',')
			++hpsz;
		return{ { key, val }, hpsz };
	}
	template<SizeT count>
	static constexpr Maps<count> GetMaps(LPCTSTR lpsz) {
		Maps<count> maps;
		for (SizeT i = 0; i < count; ++i) {
			auto map = _GetMap(lpsz);
			lpsz = map.hpsz;
			maps.map[i] = map.map;
		}
		return maps;
	}
public:
	template<EnumType AnyEnum>
	static constexpr auto Table() {
		if constexpr (EnumType<AnyEnum>) {
			if constexpr (IsCharW<TCHAR>)
				 ret_as(GetMaps<AnyEnum::Count>(AnyEnum::__EntriesW))
			else ret_as(GetMaps<AnyEnum::Count>(AnyEnum::__EntriesA))
		}
	}
};
/* EnumTableX */
template<EnumType AnyEnum, bool IsUnicode = Native::IsUnicode>
constexpr auto EnumTable = SimpleRegex<IsUnicode>::template Table<AnyEnum>();
template<EnumType AnyEnum>
constexpr auto EnumTableA = EnumTable<AnyEnum, false>;
template<EnumType AnyEnum>
constexpr auto EnumTableW = EnumTable<AnyEnum, true>;
#pragma endregion

/* SimpleRegex::Token */
template<bool IsUnicode>
inline SimpleRegex<IsUnicode>::Token::operator const StringX<IsUnicode>() const ret_as(CString(len, lpsz));
/* EnumClassParsers */
//template<bool IsUnicode = Native::IsUnicode>
//StringX<IsUnicode> toString(EnumType auto e) {
//	using EnumType = typename decltype(e)::EnumType;
//	constexpr auto table = EnumTable<EnumType, IsUnicode>;
//	auto val = e.yield();
//	for (auto i = 0; i < EnumType::Count; ++i)
//		if (val == EnumType::__Vals[i])
//			return table[i].key;
//	if constexpr (EnumType::HasProtoEnum)
//		 return toString<IsUnicode>(reuse_cast<typename EnumType::ProtoEnum>(e));
//	else return toString<IsUnicode>(format_numeral("d"), val);
//}
//inline auto toStringA(EnumType auto e) ret_as(EnumClassParseX<false>(e));
//inline auto toStringW(EnumType auto e) ret_as(EnumClassParseX<true>(e));
#pragma endregion

/* Q - Quick Concatenate */
template<bool IsUnicode = Native::IsUnicode, class ...AnyType>
inline StringX<IsUnicode> Q(const AnyType & ... args) 
	ret_as(Concat(toString<IsUnicode>(args)...));

}
