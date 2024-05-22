#pragma once

#include "ZVCore.h"
#include "GUI_Liberator.h"

using namespace ZVLab;

class CDlgClassification final : public ZVLab::CzvLayer
{
//// Member Variables
private:
	std::string		m_strLabel;
	TzvDialogInfo	m_tDialogInfo;
	int				m_iTotal;
	int				m_iClassified;
	int				m_iIndex;

//// Member Functions
public:
	virtual void OnAttach()
	{
		m_strLabel = "Classification";
	};

	virtual void OnGUI()
	{
		DProfile_StartRecord(m_strLabel);
		m_iTotal = 4;
		m_iClassified = 4;
		m_iIndex = 4;

		CzvDialog dlg(m_strLabel, m_tDialogInfo);
		{
			DzvUI_Bullet_Text("Total: %d", m_iTotal);
			DzvUI_Bullet_Text("Classified: %d", m_iClassified);
			DzvUI_Bullet_Text("Index: %d", m_iIndex);
		}

		dlg.Button("rel");
		dlg.Button("rel2");
		dlg.Button("rel3");

		//static ImGuiComboFlags flags = 0;
		//ImGui::CheckboxFlags("ImGuiComboFlags_PopupAlignLeft", &flags, ImGuiComboFlags_PopupAlignLeft);
		//ImGui::SameLine();
		//if (ImGui::CheckboxFlags("ImGuiComboFlags_NoArrowButton", &flags, ImGuiComboFlags_NoArrowButton))
		//	flags &= ~ImGuiComboFlags_NoPreview;     // Clear incompatible flags
		//if (ImGui::CheckboxFlags("ImGuiComboFlags_NoPreview", &flags, ImGuiComboFlags_NoPreview))
		//	flags &= ~(ImGuiComboFlags_NoArrowButton | ImGuiComboFlags_WidthFitPreview); // Clear incompatible flags
		//if (ImGui::CheckboxFlags("ImGuiComboFlags_WidthFitPreview", &flags, ImGuiComboFlags_WidthFitPreview))
		//	flags &= ~ImGuiComboFlags_NoPreview;

		//// Override default popup height
		//if (ImGui::CheckboxFlags("ImGuiComboFlags_HeightSmall", &flags, ImGuiComboFlags_HeightSmall))
		//	flags &= ~(ImGuiComboFlags_HeightMask_ & ~ImGuiComboFlags_HeightSmall);
		//if (ImGui::CheckboxFlags("ImGuiComboFlags_HeightRegular", &flags, ImGuiComboFlags_HeightRegular))
		//	flags &= ~(ImGuiComboFlags_HeightMask_ & ~ImGuiComboFlags_HeightRegular);
		//if (ImGui::CheckboxFlags("ImGuiComboFlags_HeightLargest", &flags, ImGuiComboFlags_HeightLargest))

		//	flags &= ~(ImGuiComboFlags_HeightMask_ & ~ImGuiComboFlags_HeightLargest);
		//const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO" };
		//static int item_current_idx = 0; // Here we store our selection data as an index.

		//// Pass in the preview value visible before opening the combo (it could technically be different contents or not pulled from items[])
		//const char* combo_preview_value = items[item_current_idx];

		//if (ImGui::BeginCombo("Separate", combo_preview_value, flags))
		//{
		//	for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		//	{
		//		const bool is_selected = (item_current_idx == n);
		//		if (ImGui::Selectable(items[n], is_selected))
		//			item_current_idx = n;

		//		// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
		//		if (is_selected)
		//			ImGui::SetItemDefaultFocus();
		//	}
		//	ImGui::EndCombo();
		//}

		TzvComboBoxInfo comboInfo;
		comboInfo.SetHeightSmall(true);
		comboInfo.SetWidthFitPreview(true);
		CzvComboBox combo("Separate", comboInfo);
		CzvComboBox combo2("index", comboInfo);
		combo.SetItems({ "AAA", "BBB" });
		combo2.SetItems({ "ALL", "0", "1" });
		combo.Bind(); DzvUI_SameLine
		combo2.Bind();

		DProfile_EndRecord;
	};

	virtual void OnMainMenuBar()
	{

	};

};

GENERATE_LAYER(CDlgClassification);