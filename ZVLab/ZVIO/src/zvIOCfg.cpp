#include "stdafx.h"
#include "zvIOCfg.h"

mutex g_mutexIOCfg;

CString CzvIOCfg::m_strLanguage = zvStrEnglish;
CString CzvIOCfg::m_strVersion = zvStrNull;

CzvIOCfg::CzvIOCfg()
{
}


CzvIOCfg::~CzvIOCfg()
{
}

CString CzvIOCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvIOCfg::SetLanguage(CString strLanguage)
{
	g_mutexIOCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexIOCfg.unlock();
}

CString CzvIOCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("22.0824.1");

	return m_strVersion;
}
