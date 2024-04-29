#pragma once
#include "ZVCore.h"
#include "ZVIO/src/ZVIO/ZVIO_Contec/zvIO_Contec.h"

using namespace ZVLab;

class CzvIoSystemAct
{
private:
	bool					m_isOpen;
	CzvImageButton			ibStage;
	CzvIO_Contec			m_Contec;

public:
	CzvIoSystemAct();
	~CzvIoSystemAct();

	void Initialize();
	void OnButton();
	void IsClicked() { (m_isOpen) ? m_isOpen = false : m_isOpen = true; }
	CzvImageButton& GetButton() { return (ibStage); }
};

