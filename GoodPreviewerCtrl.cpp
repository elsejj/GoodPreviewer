#include "pch.h"
#include "GoodPreviewerCtrl.h"
#include <string>
#include <ILexer.h>
#include <Scintilla.h>
#include <Lexilla.h>
#include <ScintillaTypes.h>
#include <ScintillaCall.h>
#include "FileLexInfo.h"



FileLexInfo* fileExt(const CStringA& fileName) {
	auto pos = fileName.ReverseFind('.');
	CStringA ext("cpp");
	if (pos > 0) {
		ext = fileName.Mid(pos + 1).MakeLower();
	}

	ext = " " + ext + " ";

	for (FileLexInfo* fi = knonwLexInfos; fi->exts != NULL; fi++) {
		if (StrStrA(fi->exts, ext) != NULL) {
			return fi;
		}
	}
	return NULL;
}





LRESULT CGoodPreviewerCtrl::OnCreate( UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {


	mEditorHwnd = CreateWindowEx(0,
		L"Scintilla", L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_CLIPCHILDREN,
		0, 0, 100, 100, this->m_hWnd , NULL, NULL, NULL);

	if (mEditorHwnd != NULL) {
		mEditorFunc = (SciFnDirectStatus)SendMessage(
			mEditorHwnd, SCI_GETDIRECTSTATUSFUNCTION, 0, 0);

		mEditorPtr = (sptr_t)SendMessage(mEditorHwnd, SCI_GETDIRECTPOINTER, 0, 0);
	}
	else {
		mEditorFunc = NULL;
		mEditorPtr = NULL;
		bHandled = TRUE;
		return S_OK;
	}


	Scintilla::ScintillaCall sc;
	sc.SetFnPtr(mEditorFunc, mEditorPtr);


	sc.SetMarginTypeN(0, Scintilla::MarginType::Number);
	sc.SetMarginWidthN(0, 80);
	sc.StyleSetFont(STYLE_DEFAULT, "Consolas");
	sc.StyleSetSize(STYLE_DEFAULT, 10);
	sc.SetTabWidth(4);

	FileLexInfo* fi = fileExt(CStringA(mFileName));


	if (fi != NULL) {
		Scintilla::ILexer5* lexer = CreateLexer(fi->lex);
		sc.SetILexer(lexer);


		auto editorFunc = (SciFnDirect)SendMessage(
			mEditorHwnd, SCI_GETDIRECTFUNCTION, 0, 0);



		setThemeMonokai(editorFunc, mEditorPtr, fi->lex);

		sc.SetKeyWords(0, fi->keywords[0]);
		sc.SetKeyWords(1, fi->keywords[0]);
	}

	SetEditorText();
	sc.SetReadOnly(true);


	/*
	if (mEditorFunc != NULL) {
		mEditorFunc(mEditorPtr, SCI_SETMARGINTYPEN, 0, SC_MARGIN_NUMBER);
		mEditorFunc(mEditorPtr, SCI_SETMARGINWIDTHN, 0, 80);
		mEditorFunc(mEditorPtr, SCI_STYLESETFONT, STYLE_DEFAULT, (intptr_t)"Consolas");
		mEditorFunc(mEditorPtr, SCI_STYLESETSIZE, STYLE_DEFAULT, 10);
		mEditorFunc(mEditorPtr, SCI_STYLESETSIZE, STYLE_DEFAULT, 10);
		mEditorFunc(mEditorPtr, SCI_SETTABWIDTH, 4, 0);

		FileLexInfo* fi = fileExt(mFileName);
		if (fi != NULL) {
			//::MessageBox(NULL, fi->lex, _T("lex"), 0);
			setThemeMonokai(mEditorFunc, mEditorPtr, fi->lex);
			USES_CONVERSION;
			mEditorFunc(mEditorPtr, SCI_SETKEYWORDS, 0, (sptr_t)(CT2CA(fi->keywords[0]).m_psz));
			mEditorFunc(mEditorPtr, SCI_SETKEYWORDS, 1, (sptr_t)(CT2CA(fi->keywords[1]).m_psz));
		}
		else {
			//::MessageBox(NULL, _T("not found"), _T("lex"), 0);
		}
		SetEditorText();
		mEditorFunc(mEditorPtr, SCI_SETREADONLY, 1, 0);
	}
	*/

	bHandled = TRUE;
	return 0;
}

LRESULT CGoodPreviewerCtrl::OnSize( UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {

	int width = LOWORD(lParam);
	int height = HIWORD(lParam);

	::MoveWindow(mEditorHwnd, 0, 0, width, height, TRUE);

	bHandled = TRUE;
	return 0;
}



void CGoodPreviewerCtrl::SetEditorText() {
	if (mFileName.IsEmpty()) {
		return;
	}
	if (mEditorFunc == NULL || mEditorPtr == NULL || mEditorHwnd == NULL) {
		return;
	}
	Scintilla::ScintillaCall sc;
	sc.SetFnPtr(mEditorFunc, mEditorPtr);

	auto hFile = CreateFile(mFileName,
		GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		auto err = GetLastError();

		LPSTR msg = nullptr;

		auto size= FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&msg , 0, NULL);

		// mEditorFunc(mEditorPtr, SCI_SETTEXT, NULL, (sptr_t)msg);
		sc.SetText(msg);
		LocalFree(msg);
		return;
	}

	DWORD dwSizeHigh;
	DWORD dwSizeLow = GetFileSize(hFile, &dwSizeHigh);

	char* buff = (char*)malloc(static_cast<size_t>(dwSizeLow) + 1);
	if (buff != NULL && ReadFile(hFile, buff, dwSizeLow, &dwSizeLow, NULL)) {
		buff[dwSizeLow] = 0;
		//mEditorFunc(mEditorPtr, SCI_SETTEXT, NULL, (sptr_t)buff);
		sc.SetText(buff);
		free(buff);
	}

	CloseHandle(hFile);
}
