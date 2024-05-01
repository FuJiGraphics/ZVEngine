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

void ToggleButton(const char* str_id, bool* v)
{
	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.50f;

	if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
		*v = !*v;
	ImU32 col_bg;
	if (ImGui::IsItemHovered())
		col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
	else
		col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);

	draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
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
}
