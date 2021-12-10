#pragma once
#include "resource.h"       // 主符号

#define AFX_PREVIEW_STANDALONE
#include <atlhandler.h>
#include <atlhandlerimpl.h>
#include "GoodPreviewerDoc.h"
#include <atlpreviewctrlimpl.h>

#include "GoodPreviewer_i.h"
#include <string>
#include <Scintilla.h>

using namespace ATL;

class CGoodPreviewerCtrl: public CAtlPreviewCtrlImpl
{
public:
	BEGIN_MSG_MAP(CGoodPreviewerCtrl)
		MESSAGE_HANDLER(WM_SIZE, OnSize)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
	END_MSG_MAP()

	CGoodPreviewerCtrl(const CString& fileName) : 
		mFileName(fileName), mEditorFunc(NULL), mEditorHwnd(NULL), mEditorPtr(NULL)
	{
	}
protected:
	virtual void DoPaint(HDC hdc)
	{
		// 可以获取指向 IDocument 的指针，如下所示
		// CMyDoc* pDoc = (CMyDoc*)m_pDocument;
		CString strData = _T("在此处绘制丰富的预览内容。");
		TextOut(hdc, 10, 20, strData, strData.GetLength());
	}

	LRESULT OnSize( UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnCreate( UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);


private:
	void SetEditorText();


private:
	CString mFileName;
	HWND mEditorHwnd;
	SciFnDirectStatus mEditorFunc;
	sptr_t mEditorPtr;
};


void setThemeMonokai(SciFnDirect set, sptr_t ptr, const CStringA& ext);
