// GoodPreviewerDoc.h : GoodPreviewerDoc 类的实现

#pragma once

#include <atlhandlerimpl.h>

using namespace ATL;

class GoodPreviewerDoc : public CAtlDocumentImpl
{
public:
	GoodPreviewerDoc(void)
	{
	}

	virtual ~GoodPreviewerDoc(void)
	{
	}

	virtual HRESULT LoadFromStream(IStream* pStream, DWORD grfMode);
	virtual void InitializeSearchContent();

protected:
	void SetSearchContent(CString& value);
	virtual void OnDrawThumbnail(HDC hDrawDC, LPRECT lprcBounds);
};
