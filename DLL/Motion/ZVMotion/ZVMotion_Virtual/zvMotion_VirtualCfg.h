#pragma once
class AFX_EXT_CLASS CzvMotion_VirtualCfg
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;

public:

	//// member functions
private:

public:
	CzvMotion_VirtualCfg();
	~CzvMotion_VirtualCfg();
	CzvMotion_VirtualCfg(CzvMotion_VirtualCfg& zvMotionCfgSrc) = delete;
	CzvMotion_VirtualCfg& operator=(CzvMotion_VirtualCfg& zvMotionCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

