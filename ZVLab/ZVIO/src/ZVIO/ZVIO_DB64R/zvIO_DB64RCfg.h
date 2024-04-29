#pragma once
class AFX_EXT_CLASS CzvIO_DB64RCfg final
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:

public:
	CzvIO_DB64RCfg();
	~CzvIO_DB64RCfg();
	CzvIO_DB64RCfg(CzvIO_DB64RCfg& zvIOCfgSrc) = delete;
	CzvIO_DB64RCfg& operator=(CzvIO_DB64RCfg& zvIOCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

