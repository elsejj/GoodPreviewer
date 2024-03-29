﻿#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED

#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的

#ifdef _MANAGED
#error 不能作为托管程序集生成文件类型处理程序。  请在项目属性中将“公共语言运行时”选项设置为“没有 CLR 支持”。
#endif

#ifndef _UNICODE
#error 文件类型处理程序必须以 Unicode 的形式生成。  请在项目属性中将“字符集”选项设置为“Unicode”。
#endif

#define SHARED_HANDLERS


#define ATL_NO_ASSERT_ON_DESTROY_NONEXISTENT_WINDOW

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
