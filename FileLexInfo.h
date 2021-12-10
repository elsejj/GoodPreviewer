#pragma once


struct FileLexInfo {
	LPCSTR exts;
	LPCSTR lex;
	LPCSTR keywords[2];
};

extern FileLexInfo knonwLexInfos[];
