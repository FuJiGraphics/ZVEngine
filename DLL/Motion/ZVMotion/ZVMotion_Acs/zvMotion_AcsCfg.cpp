#include "stdafx.h"
#include "zvMotion_AcsCfg.h"

mutex g_mutexMotionAcsCfg;

CString CzvMotion_AcsCfg::m_strLanguage = zvStrEnglish;
CString CzvMotion_AcsCfg::m_strVersion = zvStrNull;

CzvMotion_AcsCfg::CzvMotion_AcsCfg()
{
}

CzvMotion_AcsCfg::~CzvMotion_AcsCfg()
{
}

CString CzvMotion_AcsCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvMotion_AcsCfg::SetLanguage(CString strLanguage)
{
	g_mutexMotionAcsCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexMotionAcsCfg.unlock();
}

CString CzvMotion_AcsCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("19.1105.1");

	return m_strVersion;
}
