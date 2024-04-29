#pragma once

class AFX_EXT_CLASS CzvIO_VirtualCfg final
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:

public:
	CzvIO_VirtualCfg();
	~CzvIO_VirtualCfg();
	CzvIO_VirtualCfg(CzvIO_VirtualCfg& zvIOCfgSrc) = delete;
	CzvIO_VirtualCfg& operator=(CzvIO_VirtualCfg& zvIOCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

