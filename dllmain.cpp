// dllmain.cpp: DllMain 的实现。

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "GoodPreviewer_i.h"
#include "dllmain.h"
#include <Scintilla.h>

CGoodPreviewerModule _AtlModule;

// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	Scintilla_RegisterClasses(hInstance);
	return _AtlModule.DllMain(dwReason, lpReserved);
}
