#pragma once

class AFX_EXT_CLASS CzvMotion_AD8158Cfg
{
	//// member variables
private:
	static CString m_strLanguage;
	static CString m_strVersion;
public:

	//// member functions
private:

public:
	CzvMotion_AD8158Cfg();
	~CzvMotion_AD8158Cfg();
	CzvMotion_AD8158Cfg(CzvMotion_AD8158Cfg& zvMotionCfgSrc) = delete;
	CzvMotion_AD8158Cfg& operator=(CzvMotion_AD8158Cfg& zvMotionCfgSrc) = delete;

	// get / set
	static CString GetLanguage(void);
	static void SetLanguage(CString strLanguage);
	static CString GetVersion(void);
};

