#include "pch.h"
#include "zvMotion_VirtualCfg.h"

mutex g_mutexMotionCfg;

CString CzvMotion_VirtualCfg::m_strLanguage = zvStrEnglish;
CString CzvMotion_VirtualCfg::m_strVersion = zvStrNull;

CzvMotion_VirtualCfg::CzvMotion_VirtualCfg()
{
}

CzvMotion_VirtualCfg::~CzvMotion_VirtualCfg()
{
}

CString CzvMotion_VirtualCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvMotion_VirtualCfg::SetLanguage(CString strLanguage)
{
	g_mutexMotionCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexMotionCfg.unlock();
}

CString CzvMotion_VirtualCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("19.1105.1");

	return m_strVersion;
}
