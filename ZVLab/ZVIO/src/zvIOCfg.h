#pragma once
class AFX_EXT_CLASS CzvIOCfg final
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:


public:
	CzvIOCfg();
	~CzvIOCfg();
	CzvIOCfg(CzvIOCfg& zvIOCfgSrc) = delete;
	CzvIOCfg& operator=(CzvIOCfg& zvIOCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

