#include "stdafx.h"
#include "zvErr__.h"
#include "zvMotion_AjinCfg.h"


// Err names
const CString CzvErr__::m_rgstrEng[] =
{
	// general
	_T("Not Defined Exception"),
	_T("Check Index Range"),
	_T("Check Pointer"),

	//ajin
	_T("Not Initialize Board"),
	_T("Axis Not Intialized"),
	_T("Position Setting Failed"),
	_T("Read Motion Signal Failed"),
	_T("Read Motion Position Failed"),
	_T("Read Home Result Failed"),
	_T("Parameter Setting Failed"),
	_T("Moving Axis Failed"),
	_T("Axis Home Failed"),
	_T("Motion Stop Failed"),
	_T("Hold OnOff Failed"),
	_T("Trigger Setting Failed"),

	// max.

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
	if (CzvMotion_AjinCfg::GetLanguage() == zvStrKorean) return m_rgstrKor[uiIndex];
	else if (CzvMotion_AjinCfg::GetLanguage() == zvStrChinese) return m_rgstrChn[uiIndex];

	return m_rgstrEng[uiIndex];
}
