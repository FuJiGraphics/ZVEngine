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

	CzvToggleButton red("red");
	CzvToggleButton green("green");
	CzvToggleButton orange("orange");
	CzvToggleButton motor("motor");
	CzvToggleButton ActivateProfiler("ActivateProfiler");

	ImGui::Text("Lamp");

	red.Bind();
	ImGui::SameLine();
	ImGui::Text("Red");
	m_Contec.SetOutput(24, red.GetStatus());

	green.Bind();
	ImGui::SameLine();
	ImGui::Text("Green");
	m_Contec.SetOutput(25, green.GetStatus());

	orange.SetPosition(200, 500);
	orange.Bind();
	ImGui::Text("Orange");
	m_Contec.SetOutput(26, orange.GetStatus());

	motor.Bind();
	ImGui::SameLine();
	ImGui::Text("Motor");
	m_Contec.SetOutput(18, motor.GetStatus());

	ActivateProfiler.Bind();
	DProfile_Activate(ActivateProfiler.GetStatus())
	ImGui::SameLine();
	ImGui::Text("ActivateProfiler");
}
