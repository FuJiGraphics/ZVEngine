#include "stdafx.h"
#include "zvMotion_AjinCfg.h"

mutex g_mutexMotionAjinCfg;

CString CzvMotion_AjinCfg::m_strLanguage = zvStrEnglish;
CString CzvMotion_AjinCfg::m_strVersion = zvStrNull;


CzvMotion_AjinCfg::CzvMotion_AjinCfg()
{
}


CzvMotion_AjinCfg::~CzvMotion_AjinCfg()
{
}

CString CzvMotion_AjinCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvMotion_AjinCfg::SetLanguage(CString strLanguage)
{
	g_mutexMotionAjinCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexMotionAjinCfg.unlock();
}

CString CzvMotion_AjinCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("19.1105.1");

	return m_strVersion;
}
