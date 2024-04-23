#pragma once
class AFX_EXT_CLASS CzvIO_ContecCfg
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:

public:
	CzvIO_ContecCfg();
	~CzvIO_ContecCfg();
	CzvIO_ContecCfg(CzvIO_ContecCfg& zvIOCfgSrc) = delete;
	CzvIO_ContecCfg& operator=(CzvIO_ContecCfg& zvIOCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

