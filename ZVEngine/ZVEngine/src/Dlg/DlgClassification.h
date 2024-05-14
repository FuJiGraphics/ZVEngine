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
		m_iTotal = 4;
		m_iClassified = 4;
		m_iIndex = 4;

		CzvDialog dlg(m_strLabel, m_tDialogInfo);
		{
			DzvUI_Bullet_Text("Total: %d", m_iTotal);
			DzvUI_Bullet_Text("Classified: %d", m_iClassified);
			DzvUI_Bullet_Text("Index: %d", m_iIndex);
		}
	};

	virtual void OnMainMenuBar()
	{

	};

};

GENERATE_LAYER(CDlgClassification);