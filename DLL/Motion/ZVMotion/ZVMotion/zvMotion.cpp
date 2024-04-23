#include "stdafx.h"
#include "zvMotion.h"

CzvMotion::CzvMotion()
{
}


CzvMotion::~CzvMotion()
{
}

void CzvMotion::Init(void)
{
	ZeroMemory(m_strBoardType, sizeof(char) * DMotionNameSize);
	m_iMaxUseAxis = 0;
}

CzvMotion * CreateMotion()
{
	return nullptr;
}
