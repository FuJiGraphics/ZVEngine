#include "pch.h"
#include "zvErr__.h"
#include "zvMotion_AD8158Cfg.h"

// Err names
const CString CzvErr__::m_rgstrEng[] =
{
	//// add Err names here

	// general
	_T("Not defined exception"),					
	_T("Check index range"),
	_T("Check pointer"),

	//acs
	_T("Not initialize board"),
	_T("Axis not intialized"),
	_T("position setting failed"),
	_T("Read motion signal failed"),
	_T("Read motion position failed"),
	_T("Read home result failed"),
	_T("Parameter setting failed"),
	_T("Moving axis failed"),
	_T("Axis home failed"),
	_T("Motion stop failed"),
	_T("Hold on off failed"),
	_T("Failed to reboot controller"),

};

const CString CzvErr__::m_rgstrKor[] =
{
	//// add Err names here

	// general
	_T(""),

};

const CString CzvErr__::m_rgstrChn[] =
{
	//// add Err names here

	// general
	_T(""),

};


CzvErr__::CzvErr__()
{
}


CzvErr__::~CzvErr__()
{
}


//// private


//// public
// get / set
CString CzvErr__::GetName(EzvErr ezvErr)
{
	unsigned int uiIndex = (unsigned int)ezvErr;
	if (CzvMotion_AD8158Cfg::GetLanguage() == zvStrKorean) return m_rgstrKor[uiIndex];
	else if (CzvMotion_AD8158Cfg::GetLanguage() == zvStrChinese) return m_rgstrChn[uiIndex];

	return m_rgstrEng[uiIndex];
}
