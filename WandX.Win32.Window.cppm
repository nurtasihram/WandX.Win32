module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Window.h"

export module WandX.Win32.Window;

import WandX;
import WandX.Win32;
import WandX.Win32.Types;
import WandX.Win32.String;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Window");

export namespace WandX {
namespace Native {
}

enum_class(DPIHostingBehavior  , DPI_HOSTING_BEHAVIOR         ,
		   Invalid             = DPI_HOSTING_BEHAVIOR_INVALID ,
		   Default             = DPI_HOSTING_BEHAVIOR_DEFAULT ,
		   Mixed               = DPI_HOSTING_BEHAVIOR_MIXED   );
enum_class(DisplayAffinities   , DWORD                        ,
		   None                = WDA_NONE                     ,
		   Monitor             = WDA_MONITOR                  ,
		   Exclusion           = WDA_EXCLUDEFROMCAPTURE       );
enum_flags(ClassStyle          , UINT                         ,
		   VRedraw             = CS_VREDRAW                   ,
		   HRedraw             = CS_HREDRAW                   ,
		   Redraw              = CS_VREDRAW | CS_HREDRAW      ,
		   DoubleClick         = CS_DBLCLKS                   ,
		   OwnDC               = CS_OWNDC                     ,
		   ClassDC             = CS_CLASSDC                   ,
		   ParentDC            = CS_PARENTDC                  ,
		   NoClose             = CS_NOCLOSE                   ,
		   SaveBits            = CS_SAVEBITS                  ,
		   ByteAlignClient     = CS_BYTEALIGNCLIENT           ,
		   ByteAlignWindow     = CS_BYTEALIGNWINDOW           ,
		   GlobalClass         = CS_GLOBALCLASS               ,
		   IME                 = CS_IME                       ,
		   DropShadow          = CS_DROPSHADOW                );
enum_flags(WindowStyle         , LONG                         ,
		   Overlapped          = WS_OVERLAPPED                ,
		   Popup               = WS_POPUP                     ,
		   Child               = WS_CHILD                     ,
		   Minimize            = WS_MINIMIZE                  ,
		   Maximize            = WS_MAXIMIZE                  ,
		   MinimizeBox         = WS_MINIMIZEBOX               ,
		   MaximizeBox         = WS_MAXIMIZEBOX               ,
		   SizeBox             = WS_SIZEBOX                   ,
		   Visible             = WS_VISIBLE                   ,
		   Disabled            = WS_DISABLED                  ,
		   ClipSiblings        = WS_CLIPSIBLINGS              ,
		   ClipChildren        = WS_CLIPCHILDREN              ,
		   Caption             = WS_CAPTION                   ,
		   Border              = WS_BORDER                    ,
		   DlgFrame            = WS_DLGFRAME                  ,
		   VScroll             = WS_VSCROLL                   ,
		   HScroll             = WS_HSCROLL                   ,
		   SysMenu             = WS_SYSMENU                   ,
		   ThickFrame          = WS_THICKFRAME                ,
		   Group               = WS_GROUP                     ,
		   TabStop             = WS_TABSTOP                   ,
		   Tiled               = WS_TILED                     ,
		   Iconic              = WS_ICONIC                    ,
		   TiledWindow         = WS_TILEDWINDOW               ,
		   PopupWindow         = WS_POPUPWINDOW               ,
		   OverlappedWindow    = WS_OVERLAPPEDWINDOW          );
enum_flags(WindowStyleEx       , DWORD                        ,
		   No                  = 0                            ,
		   DlgModalFrame       = WS_EX_DLGMODALFRAME          ,
		   NoParentNotify      = WS_EX_NOPARENTNOTIFY         ,
		   TopMost             = WS_EX_TOPMOST                ,
		   AcceptFiles         = WS_EX_ACCEPTFILES            ,
		   Transparent         = WS_EX_TRANSPARENT            ,
		   MdiChild            = WS_EX_MDICHILD               ,
		   ToolWindow          = WS_EX_TOOLWINDOW             ,
		   WindowEdge          = WS_EX_WINDOWEDGE             ,
		   ClientEdge          = WS_EX_CLIENTEDGE             ,
		   ContextHelp         = WS_EX_CONTEXTHELP            ,
		   Right               = WS_EX_RIGHT                  ,
		   Left                = WS_EX_LEFT                   ,
		   ReadingR2L          = WS_EX_RTLREADING             ,
		   ReadingL2R          = WS_EX_LTRREADING             ,
		   LeftScrollBar       = WS_EX_LEFTSCROLLBAR          ,
		   RightScrollBar      = WS_EX_RIGHTSCROLLBAR         ,
		   ControlParent       = WS_EX_CONTROLPARENT          ,
		   StaticEdge          = WS_EX_STATICEDGE             ,
		   AppWindow           = WS_EX_APPWINDOW              ,
		   Layered             = WS_EX_LAYERED                ,
		   NoInheritLayout     = WS_EX_NOINHERITLAYOUT        ,
		   NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP    ,
		   LayoutR2L           = WS_EX_LAYOUTRTL              ,
		   Composited          = WS_EX_COMPOSITED             ,
		   NoActivate          = WS_EX_NOACTIVATE             ,
		   OverlappedWindow    = WS_EX_OVERLAPPEDWINDOW       ,
		   PaletteWindow       = WS_EX_PALETTEWINDOW          );
enum_flags(SysState            , DWORD                        ,
		   Unavailable         = STATE_SYSTEM_UNAVAILABLE     ,
		   Selected            = STATE_SYSTEM_SELECTED        ,
		   Focused             = STATE_SYSTEM_FOCUSED         ,
		   Pressed             = STATE_SYSTEM_PRESSED         ,
		   Checked             = STATE_SYSTEM_CHECKED         ,
		   Mixed               = STATE_SYSTEM_MIXED           ,
		   Indeterminate       = STATE_SYSTEM_INDETERMINATE   ,
		   ReadOnly            = STATE_SYSTEM_READONLY        ,
		   HotTracked          = STATE_SYSTEM_HOTTRACKED      ,
		   Default             = STATE_SYSTEM_DEFAULT         ,
		   Expanded            = STATE_SYSTEM_EXPANDED        ,
		   Collapsed           = STATE_SYSTEM_COLLAPSED       ,
		   Busy                = STATE_SYSTEM_BUSY            ,
		   Floating            = STATE_SYSTEM_FLOATING        ,
		   Marqueed            = STATE_SYSTEM_MARQUEED        ,
		   Animated            = STATE_SYSTEM_ANIMATED        ,
		   Invisible           = STATE_SYSTEM_INVISIBLE       ,
		   OffScreen           = STATE_SYSTEM_OFFSCREEN       ,
		   Sizeable            = STATE_SYSTEM_SIZEABLE        ,
		   Moveable            = STATE_SYSTEM_MOVEABLE        ,
		   SelfVoicing         = STATE_SYSTEM_SELFVOICING     ,
		   Focusable           = STATE_SYSTEM_FOCUSABLE       ,
		   Selectable          = STATE_SYSTEM_SELECTABLE      ,
		   Linked              = STATE_SYSTEM_LINKED          ,
		   Traversed           = STATE_SYSTEM_TRAVERSED       ,
		   MultiSelectable     = STATE_SYSTEM_MULTISELECTABLE ,
		   ExtSelectable       = STATE_SYSTEM_EXTSELECTABLE   ,
		   AlertLow            = STATE_SYSTEM_ALERT_LOW       ,
		   AlertMedium         = STATE_SYSTEM_ALERT_MEDIUM    ,
		   AlertHigh           = STATE_SYSTEM_ALERT_HIGH      ,
		   Protected           = STATE_SYSTEM_PROTECTED       ,
		   Valid               = STATE_SYSTEM_VALID           );
enum_class(Shows               , int                          ,
		   Hide                = SW_HIDE                      ,
		   ShowNormal          = SW_SHOWNORMAL                ,
		   Normal              = SW_NORMAL                    ,
		   ShowMinimized       = SW_SHOWMINIMIZED             ,
		   ShowMaximized       = SW_SHOWMAXIMIZED             ,
		   Maximize            = SW_MAXIMIZE                  ,
		   ShowNoActivate      = SW_SHOWNOACTIVATE            ,
		   Show                = SW_SHOW                      ,
		   Minimize            = SW_MINIMIZE                  ,
		   ShowMinNoActive     = SW_SHOWMINNOACTIVE           ,
		   ShowNA              = SW_SHOWNA                    ,
		   Restore             = SW_RESTORE                   ,
		   ShowDefault         = SW_SHOWDEFAULT               ,
		   ForceMinimize       = SW_FORCEMINIMIZE             ,
		   Max                 = SW_MAX                       );
enum_flags(FlashFlag           , DWORD                        ,
		   Stop                = FLASHW_STOP                  ,
		   Caption             = FLASHW_CAPTION               ,
		   Tray                = FLASHW_TRAY                  ,
		   All                 = FLASHW_ALL                   ,
		   Timer               = FLASHW_TIMER                 ,
		   TimerNoFG           = FLASHW_TIMERNOFG             );
proxy_struct       (MonitorInfo      , MONITORINFO                     ) {
	proxy_prop_size(                   cbSize          , DWORD         );
	proxy_prop_sync(Monitor          , rcMonitor       , Rect          );
	proxy_prop_sync(Work             , rcWork          , Rect          );
	proxy_prop_sync(Flags            , dwFlags         , DWORD         );}; // MONITORINFOF_PRIMARY
proxy_structWAT    (MonitorInfoEx    , MONITORINFOEX                   ) {
	proxy_prop_size(                   cbSize          , DWORD         );
	proxy_prop_sync(Monitor          , rcMonitor       , Rect          );
	proxy_prop_sync(Work             , rcWork          , Rect          );
	proxy_prop_sync(Flags            , dwFlags         , DWORD         );}; // MONITORINFOF_PRIMARY
//	proxy_prop_sync(DeviceName       , szDevice        , String        );
proxy_struct       (ScrollInfo       , SCROLLINFO                      ) {};
proxy_struct       (TitleBarInfo     , TITLEBARINFO                    ) {
	proxy_prop_size(                   cbSize          , DWORD         );
	proxy_prop_sync(Rect             , rcTitleBar      , WandX::Rect   );
	proxy_prop_sync(TitleState       , rgstate[0]      , SysState      );
	proxy_prop_sync(MinButtonState   , rgstate[2]      , SysState      );
	proxy_prop_sync(MaxButtonState   , rgstate[3]      , SysState      );
	proxy_prop_sync(HelpButtonState  , rgstate[4]      , SysState      );
	proxy_prop_sync(CloseButtonState , rgstate[5]      , SysState      );
	proxy_prop_arrc(States           , rgstate         , DWORD         );};
proxy_struct       (WindowFlash      , FLASHWINFO                      ) {
	proxy_prop_size(                   cbSize          , DWORD         );
	proxy_prop_sync(Window           , hwnd            , HWND          );
	proxy_prop_sync(Flags            , dwFlags         , FlashFlag     );
	proxy_prop_sync(Count            , uCount          , UINT          );
	proxy_prop_sync(Timeout          , dwTimeout       , DWORD         );};
proxy_struct       (WindowPlacement  , WINDOWPLACEMENT                 ) {
	proxy_prop_size(                   length	       , UINT          );
//	proxy_prop_sync(Flags            , flags           , DWORD         ); // WPP_HIDE
	proxy_prop_sync(Show             , showCmd         , Shows         );
	proxy_prop_sync(MinPosition      , ptMinPosition   , Point         );
	proxy_prop_sync(MaxPosition      , ptMaxPosition   , Point         );
	proxy_prop_sync(NormalPosition   , ptNormalPosition, Rect          );
	proxy_prop_sync(Device           , rcDevice        , Rect          );};
proxy_struct       (WindowInfo       , WINDOWINFO                      ) {
	proxy_prop_size(                   cbSize          , DWORD         );
	proxy_prop_sync(Rect             , rcWindow        , WandX::Rect   );
	proxy_prop_sync(Client           , rcClient        , WandX::Rect   );
	proxy_prop_sync(Style            , dwStyle         , WindowStyle   );
	proxy_prop_sync(StyleEx          , dwExStyle       , WindowStyleEx );
//	proxy_prop_sync(Status           , dwWindowStatus  , DWORD         ); // WS_ACTIVECAPTION, WS_ACTIVE, WS_CLICKACTIVE
	proxy_prop_sync(xBorders         , cxWindowBorders , UINT          );
	proxy_prop_sync(yBorders         , cyWindowBorders , UINT          );
	proxy_prop_sync(Atom             , atomWindowType  , WandX::Atom   );
	proxy_prop_sync(CreatorVersion   , wCreatorVersion , WORD          );};
proxy_struct       (WindowPosition   , WINDOWPOS                       ) {};

enum_flags(TrackMouseFlag      , DWORD          ,
		   Hover               = TME_HOVER      ,
		   Leave               = TME_LEAVE      ,
		   NoClient            = TME_NONCLIENT  ,
		   Query               = TME_QUERY      ,
		   Cancel              = TME_CANCEL     );
proxy_struct       (TrackMouseEvent , TRACKMOUSEEVENT) {};

//#include "WandX.Win32.Window.idl"

}
