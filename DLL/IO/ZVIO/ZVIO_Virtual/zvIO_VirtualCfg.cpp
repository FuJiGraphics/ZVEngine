#include "pch.h"
#include "zvIO_VirtualCfg.h"

mutex g_mutexIOCfg;

CString CzvIO_VirtualCfg::m_strLanguage = zvStrEnglish;
CString CzvIO_VirtualCfg::m_strVersion = zvStrNull;

CzvIO_VirtualCfg::CzvIO_VirtualCfg()
{
}

CzvIO_VirtualCfg::~CzvIO_VirtualCfg()
{
}

CString CzvIO_VirtualCfg::GetLanguage(void)
{
	return m_strLanguage;
}

void CzvIO_VirtualCfg::SetLanguage(CString strLanguage)
{
	g_mutexIOCfg.lock();

	m_strLanguage = strLanguage;

	g_mutexIOCfg.unlock();
}

CString CzvIO_VirtualCfg::GetVersion(void)
{
	// "Year.MonthDay.Index"
	m_strVersion = _T("22.0824.1");

	return m_strVersion;
}
