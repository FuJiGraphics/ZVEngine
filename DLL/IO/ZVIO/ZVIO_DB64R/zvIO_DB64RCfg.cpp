#include "pch.h"
#include "zvIO_DB64RCfg.h"

mutex g_mutexIOCfg;

CString CzvIO_DB64RCfg::m_strLanguage = zvStrEnglish;
CString CzvIO_DB64RCfg::m_strVersion = zvStrNull;

CzvIO_DB64RCfg::CzvIO_DB64RCfg()
{
}

CzvIO_DB64RCfg::~CzvIO_DB64RCfg()
{
}

//// private

//// public

CString CzvIO_DB64RCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvIO_DB64RCfg::SetLanguage(CString strLanguage)
{
	g_mutexIOCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexIOCfg.unlock();
}

CString CzvIO_DB64RCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("22.0824.1");

	return m_strVersion;
}
