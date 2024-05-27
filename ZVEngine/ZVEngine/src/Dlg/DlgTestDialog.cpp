#include "DlgTestDialog.h"

CDlgTestDialog::CDlgTestDialog()
{
}

void CDlgTestDialog::OnAttach()
{
}

void CDlgTestDialog::OnGUI()
{
	TzvDialogInfo info;
	info.SetDocsNoTabBar(false);
	CzvDialog dialog("TestDialog", info);

	if (dialog.Button("TestButton"))
	{
		FZLOG_INFO("Button Click!");
	}

	dialog.ToggleButton("Test Toggle");
}

GENERATE_LAYER(CDlgTestDialog);