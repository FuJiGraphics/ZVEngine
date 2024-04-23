#include "stdafx.h"
#include "zvMotionCfg.h"


mutex g_mutexMotionCfg;

CString CzvMotionCfg::m_strLanguage = zvStrEnglish;
CString CzvMotionCfg::m_strVersion = zvStrNull;



CzvMotionCfg::CzvMotionCfg()
{
}


CzvMotionCfg::~CzvMotionCfg()
{
}

CString CzvMotionCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvMotionCfg::SetLanguage(CString strLanguage)
{
	g_mutexMotionCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexMotionCfg.unlock();
}

CString CzvMotionCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("19.1105.1");

	return m_strVersion;
}
