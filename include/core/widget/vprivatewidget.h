#pragma once

#include "../stl-ex/vstring.h"
#include "../vbasiccore.h"
#include <functional>
#include <map>

#pragma comment(lib, "Imm32.lib")

VLIB_BEGIN_NAMESPACE

namespace Core {
/*
 * VWin32ThreadPipe structure:
 *  Description : This structure is like a pipe between win32 thread and widget

 */
struct VWin32ThreadPipe {
	int IMEX = -1;
	int IMEY = -2;

	LOGFONT IMEFontStyle;

	bool InFrameless   = false;
	bool UseMaxMinSize = false;
	bool Sizable	   = false;
	bool BorderLess	   = false;

	VGeometry WindowMaxSize;
	VGeometry WindowMiniSize;

	VString GlobalFocusID;

	bool LockFocus		 = false;
	bool IMEInput		 = false;
	bool SelfDrawCaption = false;

	bool   EnableRadius = false;
	VPoint BorderRadius = {0, 0};

	std::function<void()>					  WinRepaintMessage;
	std::function<void()>					  StartIMEInput;
	std::function<void()>					  EndIMEInput;
	std::function<void()>					  LosedUserFocus;
	std::function<bool()>					  WindowQuitOnClicked;
	std::function<void(std::vector<VString>)> WindowOnFileDrag;
	std::function<void(int, int)>			  WindowOnSize;

	WNDPROC OriginWindowProcess;
};

extern bool								  MainThreadEnd;
extern std::map<HWND, VWin32ThreadPipe *> _VMainConfigs;

LRESULT _VWidgetWNDPROC(HWND Handle, UINT Message, WPARAM wParameter, LPARAM lParameter);

}; // namespace Core

VLIB_END_NAMESPACE