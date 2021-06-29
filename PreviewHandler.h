// PreviewHandler.h: 预览处理程序的声明

#pragma once
#include "resource.h"       // 主符号

#define AFX_PREVIEW_STANDALONE
#include <atlhandler.h>
#include <atlhandlerimpl.h>
#include "GoodPreviewerDoc.h"
#include <atlpreviewctrlimpl.h>

#include "GoodPreviewer_i.h"
#include "GoodPreviewerCtrl.h"

using namespace ATL;

// CPreviewCtrl 实现
class CPreviewCtrl : public CAtlPreviewCtrlImpl
{
protected:
	virtual void DoPaint(HDC hdc)
	{
		// 可以获取指向 IDocument 的指针，如下所示
		// CMyDoc* pDoc = (CMyDoc*)m_pDocument;
		CString strData = _T("在此处绘制丰富的预览内容。");
		TextOut(hdc, 10, 20, strData, strData.GetLength());
	}
};

// CPreviewHandler

class ATL_NO_VTABLE CPreviewHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPreviewHandler, &CLSID_Preview>,
	public CPreviewHandlerImpl <CPreviewHandler>,
	public IInitializeWithFile
{
public:
	CPreviewHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PREVIEW_HANDLER)
DECLARE_NOT_AGGREGATABLE(CPreviewHandler)

BEGIN_COM_MAP(CPreviewHandler)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IOleWindow)
	//COM_INTERFACE_ENTRY(IInitializeWithStream)
	COM_INTERFACE_ENTRY(IPreviewHandler)
	COM_INTERFACE_ENTRY(IPreviewHandlerVisuals)
	COM_INTERFACE_ENTRY(IInitializeWithFile)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		CPreviewHandlerImpl<CPreviewHandler>::FinalRelease();
	}


	virtual HRESULT STDMETHODCALLTYPE Initialize( LPCWSTR pszFilePath, /* [in] */ DWORD grfMode) {


		if (pszFilePath != NULL) {
			mFileName = pszFilePath;
		}

		return 0;
	}

protected:
	virtual IPreviewCtrl* CreatePreviewControl()
	{
		// 此类在此标头的开始位置定义
		CGoodPreviewerCtrl *pPreviewCtrl = nullptr;
		ATLTRY(pPreviewCtrl = new CGoodPreviewerCtrl(mFileName));
		return pPreviewCtrl;
	}

	virtual IDocument* CreateDocument()
	{
		GoodPreviewerDoc *pDocument = nullptr;
		ATLTRY(pDocument = new GoodPreviewerDoc());
		return pDocument;
	}

protected:
	CString mFileName;
};

OBJECT_ENTRY_AUTO(__uuidof(Preview), CPreviewHandler)
