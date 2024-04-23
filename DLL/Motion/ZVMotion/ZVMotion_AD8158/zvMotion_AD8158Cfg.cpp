#include "pch.h"
#include "zvMotion_AD8158Cfg.h"

mutex g_mutexMotionADCfg;

CString CzvMotion_AD8158Cfg::m_strLanguage = zvStrEnglish;
CString CzvMotion_AD8158Cfg::m_strVersion = zvStrNull;

CzvMotion_AD8158Cfg::CzvMotion_AD8158Cfg()
{
}

CzvMotion_AD8158Cfg::~CzvMotion_AD8158Cfg()
{
}

//// public
CString CzvMotion_AD8158Cfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvMotion_AD8158Cfg::SetLanguage(CString strLanguage)
{
	g_mutexMotionADCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexMotionADCfg.unlock();
}

CString CzvMotion_AD8158Cfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("19.1105.1");

	return m_strVersion;
}
