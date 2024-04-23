#pragma once
class AFX_EXT_CLASS CzvMotionCfg final
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:

public:
	CzvMotionCfg();
	~CzvMotionCfg();
	CzvMotionCfg(CzvMotionCfg& zvMotionCfgSrc) = delete;
	CzvMotionCfg& operator=(CzvMotionCfg& zvMotionCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

