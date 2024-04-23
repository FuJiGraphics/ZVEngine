#include "pch.h"
#include "zvErr__.h"
#include "ZVIO_DB64RCfg.h"

// Err names
const CString CzvErr__::m_rgstrEng[] =
{
	//// add Err names here

	// general
	_T("Not defined exception"),
	_T("Check index range"),
	_T("Check image pointer"),
	_T("Check image size"),
	_T("Check image stride"),
	
	//contec
	_T("Check input index"),
	_T("Check output index"),
	_T("Not initialize board"),
	_T("Not connected any board"),

	
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
	if (CzvIO_DB64RCfg::GetLanguage() == zvStrKorean) return m_rgstrKor[uiIndex];
	else if (CzvIO_DB64RCfg::GetLanguage() == zvStrChinese) return m_rgstrChn[uiIndex];

	return m_rgstrEng[uiIndex];
}
