#include "ZVIoSystemAct.h"

CzvIoSystemAct::CzvIoSystemAct()
	: m_isOpen(false)
	, ibStage()
{
}

CzvIoSystemAct::~CzvIoSystemAct()
{
	m_Contec.BoardFinish();
}

void CzvIoSystemAct::Initialize()
{
	ibStage.SetTexture("D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG.png",
					   "D:\\Dev\\ZVLab\\ZVEngine\\Resources\\IDB_BUTTON_DLG_MENU_JOG_PRESSED.png");

	m_Contec.BoardInit();
}

void CzvIoSystemAct::OnButton()
{

}
