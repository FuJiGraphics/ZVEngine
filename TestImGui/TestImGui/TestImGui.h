
// TestImGui.h: TestImGui 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 주 기호입니다.

// zvui
#define ZV_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#include "export/EntryPoint.h"
#include "GLFW/glfw3native.h"

// CTestImGuiApp:
// 이 클래스의 구현에 대해서는 TestImGui.cpp을(를) 참조하세요.
//


class CTestImGuiApp : public CWinApp
{
public:
	CTestImGuiApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnAppExit();
};

extern CTestImGuiApp theApp;
