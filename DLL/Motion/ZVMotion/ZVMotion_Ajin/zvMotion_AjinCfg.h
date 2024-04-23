#pragma once
class AFX_EXT_CLASS CzvMotion_AjinCfg
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:

public:
	CzvMotion_AjinCfg();
	~CzvMotion_AjinCfg();
	CzvMotion_AjinCfg(CzvMotion_AjinCfg& zvMotionCfgSrc) = delete;
	CzvMotion_AjinCfg& operator=(CzvMotion_AjinCfg& zvMotionCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

