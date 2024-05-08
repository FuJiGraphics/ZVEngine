#include "ZVCore.h"
#include "GUI_Liberator.h"
#include "Motion/ZVMotionAct.h"
#include "IO/ZVIoSystemAct.h"

using namespace ZVLab;

class Sidebar_left : public ZVLab::CzvLayer
{
private:
	CzvMotionAct	m_motionAct;
	CzvIoSystemAct	m_ioAct;

public:
	virtual void OnAttach() 
	{
		m_motionAct.Initialize();
		m_ioAct.Initialize();
	};
	 
	virtual void OnGUI() 
	{
		TzvDialogInfo info;
		info.SetNoDocking(false);
		CzvDialog dlgDialog("Sidebar", info);

		dlgDialog.Button(m_motionAct.GetButton());
		dlgDialog.Button(m_ioAct.GetButton());

		m_motionAct.OnButton();
		m_ioAct.OnButton();
	};

	virtual void OnMainMenuBar() 
	{
	};

};

GENERATE_LAYER(Sidebar_left);