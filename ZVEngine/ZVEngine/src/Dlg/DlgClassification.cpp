#include "DlgClassification.h"

void CDlgClassification::OnAttach()
{
	m_strLabel = "Classification";
	m_iTotal = 4;
	m_iClassified = 4;
	m_iIndex = 4;
};

void CDlgClassification::OnGUI()
{
	DProfile_StartRecord(m_strLabel);

	CzvDialog dlg(m_strLabel, m_tDialogInfo);
	{
		DzvUI_Bullet_Text("Total: %d", m_iTotal);
		DzvUI_Bullet_Text("Classified: %d", m_iClassified);
		DzvUI_Bullet_Text("Index: %d", m_iIndex);
	}

	std::string result;

	TzvComboBoxInfo comboInfo;
	comboInfo.SetHeightSmall(true);
	comboInfo.SetWidthFitPreview(true);
	result = dlg.ComboBox("Separate", { "AAA", "BBB" }, comboInfo); DzvUI_SameLine
	result = dlg.ComboBox("index", { "ALL", "0", "1" }, comboInfo);

	DProfile_EndRecord;
};

GENERATE_LAYER(CDlgClassification);