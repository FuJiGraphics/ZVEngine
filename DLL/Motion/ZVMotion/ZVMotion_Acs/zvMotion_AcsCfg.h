#pragma once
class AFX_EXT_CLASS CzvMotion_AcsCfg
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;
public:

	//// member functions
private:

public:
	CzvMotion_AcsCfg();
	~CzvMotion_AcsCfg();
	CzvMotion_AcsCfg(CzvMotion_AcsCfg& zvMotionCfgSrc) = delete;
	CzvMotion_AcsCfg& operator=(CzvMotion_AcsCfg& zvMotionCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

