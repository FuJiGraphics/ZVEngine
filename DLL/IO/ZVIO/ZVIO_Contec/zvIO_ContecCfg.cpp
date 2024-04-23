#include "stdafx.h"
#include "zvIO_ContecCfg.h"


mutex g_mutexIOCfg;

CString CzvIO_ContecCfg::m_strLanguage = zvStrEnglish;
CString CzvIO_ContecCfg::m_strVersion = zvStrNull;

CzvIO_ContecCfg::CzvIO_ContecCfg()
{
}


CzvIO_ContecCfg::~CzvIO_ContecCfg()
{
}

CString CzvIO_ContecCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvIO_ContecCfg::SetLanguage(CString strLanguage)
{
	g_mutexIOCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexIOCfg.unlock();
}

CString CzvIO_ContecCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("22.0824.1");

	return m_strVersion;
}
