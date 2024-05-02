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
	ibStage.SetTexture("..\\..\\Resources\\IDB_BUTTON_DLG_MENU_JOG.png",
					   "..\\..\\Resources\\IDB_BUTTON_DLG_MENU_JOG_PRESSED.png");

	m_Contec.BoardInit();
	ibStage.SetCallbackFunc(DBindMemberCallback(CzvIoSystemAct::IsClicked, this));
}

void CzvIoSystemAct::OnButton()
{
	if (m_isOpen == false)
		return;
	CzvDialog dlg_io("IO System");

	static bool red = false;
	static bool green = false;
	static bool orange = false;
	static bool motorFlag = false;
	static bool ActivateProfiler = false;

	ImGui::Text("Lamp");
	ToggleButton("Red", &red);
	ImGui::SameLine();
	ImGui::Text("Red");
	m_Contec.SetOutput(24, red);

	ToggleButton("Orange", &orange);
	ImGui::SameLine();
	ImGui::Text("Orange");
	m_Contec.SetOutput(25, orange);

	ToggleButton("Green", &green);
	ImGui::SameLine();
	ImGui::Text("Green");
	m_Contec.SetOutput(26, green);

	ToggleButton("Motor", &motorFlag);
	ImGui::SameLine();
	ImGui::Text("Motor");
	m_Contec.SetOutput(18, motorFlag);

	ToggleButton("ActivateProfiler", &ActivateProfiler);
	DProfile_Activate(ActivateProfiler)
	ImGui::SameLine();
	ImGui::Text("ActivateProfiler");
}
