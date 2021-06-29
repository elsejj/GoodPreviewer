#pragma once


struct FileLexInfo {
	LPCTSTR exts;
	LPCTSTR lex;
	LPCTSTR keywords[2];
};

extern FileLexInfo knonwLexInfos[];
